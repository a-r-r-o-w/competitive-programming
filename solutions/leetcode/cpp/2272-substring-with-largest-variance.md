# [2272] Substring With Largest Variance

**[array, dynamic-programming]**

### Statement

The **variance** of a string is defined as the largest difference between the number of occurrences of **any** `2` characters present in the string. Note the two characters may or may not be the same.

Given a string `s` consisting of lowercase English letters only, return *the **largest variance** possible among all **substrings** of* `s`.

A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** s = "aababbb"
**Output:** 3
**Explanation:**
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

```

**Example 2:**

```

**Input:** s = "abcde"
**Output:** 0
**Explanation:**
No letter occurs more than once in s, so the variance of every substring is 0.

```

**Constraints:**
* `1 <= s.length <= 10^4`
* `s` consists of lowercase English letters.


<br />

### Hints

- Think about how to solve the problem if the string had only two distinct characters.
- If we replace all occurrences of the first character by +1 and those of the second character by -1, can we efficiently calculate the largest possible variance of a string with only two distinct characters?
- Now, try finding the optimal answer by taking all possible pairs of characters into consideration.

<br />

### Solution

```cpp
class Solution {
  public:
    int largestVariance (string s) {
      int ans = 0;
      std::unordered_set <char> have (s.begin(), s.end());

      for (char c: have) {
        for (char d: have) {
          if (c == d)
            continue;
          
          int count = 0, x = 0, m = 1 << 30;

          for (char i: s) {
            if (i == c)
              ++count;
            else if (i == d) {
              m = std::min(m, x);
              --count;
              x = count;
            }
            ans = std::max(ans, count - m);
          }
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 25723
- total submissions: 68798
- acceptance rate: 37.4%
- likes: 759
- dislikes: 91

<br />

### Similar Problems

- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) (Medium)
