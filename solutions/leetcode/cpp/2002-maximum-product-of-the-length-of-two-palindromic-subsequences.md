# [2002] Maximum Product of the Length of Two Palindromic Subsequences

**[string, dynamic-programming, backtracking, bit-manipulation, bitmask]**

### Statement

Given a string `s`, find two **disjoint palindromic subsequences** of `s` such that the **product** of their lengths is **maximized**. The two subsequences are **disjoint** if they do not both pick a character at the same index.

Return *the **maximum** possible **product** of the lengths of the two palindromic subsequences*.

A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is **palindromic** if it reads the same forward and backward.


**Example 1:**
![example-1](https://assets.leetcode.com/uploads/2021/08/24/two-palindromic-subsequences.png)

```

**Input:** s = "leetcodecom"
**Output:** 9
**Explanation**: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.

```

**Example 2:**

```

**Input:** s = "bb"
**Output:** 1
**Explanation**: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
The product of their lengths is: 1 * 1 = 1.

```

**Example 3:**

```

**Input:** s = "accbcaxxcxx"
**Output:** 25
**Explanation**: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
The product of their lengths is: 5 * 5 = 25.

```

**Constraints:**
* `2 <= s.length <= 12`
* `s` consists of lowercase English letters only.


<br>

### Hints

- Could you generate all possible pairs of disjoint subsequences?
- Could you find the maximum length palindrome in each subsequence for a pair of disjoint subsequences?

<br>

### Solution

```cpp
class Solution {
  public:
    int maxProduct (string s) {
      int n = s.length(), max = 0;
      std::string a, b;

      for (int i = 0; i < 1 << n; ++i) {
        for (int bit = 0; bit < 12; ++bit) {
          if (i & (1 << bit))
            a += s[bit];
        }

        int p = a.length();
        bool okay = true;

        for (int k = 0; k < p / 2; ++k) {
          if (a[k] != a[p - k - 1]) {
            okay = false;
            break;
          }
        }

        a.clear();
        
        if (not okay) {
          continue;
        }

        for (int j = 0; j < 1 << n; ++j) {
          if (i & j)
            continue;
          
          for (int bit = 0; bit < 12; ++bit) {
            if (j & (1 << bit))
              b += s[bit];
          }

          int q = b.length();
          okay = true;
          
          for (int k = 0; k < q / 2; ++k) {
            if (b[k] != b[q - k - 1]) {
              okay = false;
              break;
            }
          }
          if (okay)
            max = std::max(max, p * q);
          
          b.clear();
        }
      }

      return max;
    }
};
```

<br>

### Statistics

- total accepted: 15969
- total submissions: 29803
- acceptance rate: 53.6%
- likes: 633
- dislikes: 42

<br>

### Similar Problems

- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) (Easy)
- [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) (Medium)
- [Maximum Product of the Length of Two Palindromic Substrings](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings) (Hard)
- [Maximum Points in an Archery Competition](https://leetcode.com/problems/maximum-points-in-an-archery-competition) (Medium)
