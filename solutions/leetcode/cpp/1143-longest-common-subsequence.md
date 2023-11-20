# [1143] Longest Common Subsequence

**[string, dynamic-programming]**

### Statement

Given two strings `text1` and `text2`, return *the length of their longest **common subsequence**.* If there is no **common subsequence**, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.



A **common subsequence** of two strings is a subsequence that is common to both strings.


**Example 1:**

```

**Input:** text1 = "abcde", text2 = "ace" 
**Output:** 3  
**Explanation:** The longest common subsequence is "ace" and its length is 3.

```

**Example 2:**

```

**Input:** text1 = "abc", text2 = "abc"
**Output:** 3
**Explanation:** The longest common subsequence is "abc" and its length is 3.

```

**Example 3:**

```

**Input:** text1 = "abc", text2 = "def"
**Output:** 0
**Explanation:** There is no such common subsequence, so the result is 0.

```

**Constraints:**
* `1 <= text1.length, text2.length <= 1000`
* `text1` and `text2` consist of only lowercase English characters.


<br>

### Hints

- Try dynamic programming. 
DP[i][j] represents the longest common subsequence of text1[0 ... i] & text2[0 ... j].
- DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j]
DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestCommonSubsequence (string text1, string text2) {
      int m = text1.length();
      int n = text2.length();
      std::vector <std::vector <int>> dp (m + 1, std::vector <int> (n + 1));
      
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (text1[i - 1] == text2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
      
      return dp[m][n];
    }
};
```

Memory optimisation

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestCommonSubsequence (string text1, string text2) {
      int m = text1.length();
      int n = text2.length();
      
      if (m < n) {
        std::swap(m, n);
        std::swap(text1, text2);
      }
      
      std::vector <std::vector <int>> dp (2, std::vector <int> (n + 1));
      
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (text1[i - 1] == text2[j - 1])
            dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
          else
            dp[i % 2][j] = std::max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
      }
      
      return dp[m % 2][n];
    }
};
```

<br>

### Statistics

- total accepted: 486830
- total submissions: 825910
- acceptance rate: 58.9%
- likes: 7727
- dislikes: 87

<br>

### Similar Problems

- [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) (Medium)
- [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) (Medium)
- [Shortest Common Supersequence ](https://leetcode.com/problems/shortest-common-supersequence) (Hard)
- [Maximize Number of Subsequences in a String](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string) (Medium)
