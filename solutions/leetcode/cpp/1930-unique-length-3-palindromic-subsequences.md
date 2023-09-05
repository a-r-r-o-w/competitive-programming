# [1930] Unique Length-3 Palindromic Subsequences

**[hash-table, string, prefix-sum]**

### Statement

Given a string `s`, return *the number of **unique palindromes of length three** that are a **subsequence** of* `s`.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted **once**.

A **palindrome** is a string that reads the same forwards and backwards.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.


**Example 1:**

```

**Input:** s = "aabca"
**Output:** 3
**Explanation:** The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")

```

**Example 2:**

```

**Input:** s = "adc"
**Output:** 0
**Explanation:** There are no palindromic subsequences of length 3 in "adc".

```

**Example 3:**

```

**Input:** s = "bbcbaba"
**Output:** 4
**Explanation:** The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")

```

**Constraints:**
* `3 <= s.length <= 105`
* `s` consists of only lowercase English letters.


<br>

### Hints

- What is the maximum number of length-3 palindromic strings?
- How can we keep track of the characters that appeared to the left of a given position?

<br>

### Solution

```cpp
class Solution {
  public:
    int countPalindromicSubsequence (string s) {
      int n = s.length();
      std::vector <std::vector <bool>> prefix (26, std::vector <bool> (n + 1));
      std::vector <std::vector <bool>> suffix (26, std::vector <bool> (n + 1));
      int count = 0;

      for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= n; ++j) {
          prefix[i][j] = prefix[i][j - 1];
          suffix[i][n - j] = suffix[i][n - j + 1];
          
          if (i + 'a' == s[j - 1])
            prefix[i][j] = true;
          if (i + 'a' == s[n - j])
            suffix[i][n - j] = true;
        }
      }

      std::vector <bool> have (26);

      for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= n - 1; ++j) {
          if (prefix[i][j - 1] and suffix[i][j] and not have[s[j - 1] - 'a']) {
            ++count;
            have[s[j - 1] - 'a'] = true;
          }
        }
        for (int j = 0; j < 26; ++j)
          have[j] = false;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 21489
- total submissions: 41451
- acceptance rate: 51.8%
- likes: 601
- dislikes: 18

<br>

### Similar Problems

- [Count Palindromic Subsequences](https://leetcode.com/problems/count-palindromic-subsequences) (Hard)
