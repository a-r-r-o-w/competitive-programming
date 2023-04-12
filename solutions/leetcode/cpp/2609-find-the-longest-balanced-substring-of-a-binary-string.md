# [2609] Find the Longest Balanced Substring of a Binary String



### Statement

You are given a binary string `s` consisting only of zeroes and ones.

A substring of `s` is considered balanced if **all zeroes are before ones** and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return *the length of the longest balanced substring of* `s`.

A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** s = "01000111"
**Output:** 6
**Explanation:** The longest balanced substring is "000111", which has length 6.

```

**Example 2:**

```

**Input:** s = "00111"
**Output:** 4
**Explanation:** The longest balanced substring is "0011", which has length 4.

```

**Example 3:**

```

**Input:** s = "111"
**Output:** 0
**Explanation:** There is no balanced substring except the empty substring, so the answer is 0.

```

**Constraints:**
* `1 <= s.length <= 50`
* `'0' <= s[i] <= '1'`


<br />

### Hints

- Consider iterating over each subarray and checking if it’s balanced or not.
- Among all balanced subarrays, the answer is the longest one of them.

<br />

### Solution

```cpp
class Solution {
  public:
    int findTheLongestBalancedSubstring (string s) {
      int n = s.length(), ans = 0;
      
      for (int i = 0; i < n; ++i) {
        int j = i, zero = 0, one = 0;
        while (j < n and s[j] == '0')
          ++j, ++zero;
        while (j < n and s[j] == '1')
          ++j, ++one;
        ans = std::max(ans, std::min(zero, one) * 2);
        i = j - 1;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 15253
- total submissions: 34501
- acceptance rate: 44.2%
- likes: 134
- dislikes: 12

<br />

### Similar Problems

None
