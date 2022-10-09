# [516] Longest Palindromic Subsequence

**[string, dynamic-programming]**

### Statement

Given a string `s`, find *the longest palindromic **subsequence**'s length in* `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** s = "bbbab"
**Output:** 4
**Explanation:** One possible longest palindromic subsequence is "bbbb".

```

**Example 2:**

```

**Input:** s = "cbbd"
**Output:** 2
**Explanation:** One possible longest palindromic subsequence is "bb".

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s` consists only of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

**Time: O(n^2)**
**Space: O(n^2)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestPalindromeSubseq (string s) {
      int n = s.length();
      
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (n + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
          if (s[i - 1] == s[n - j])
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 2);
        }
      }
      
      return dp[n][n] / 2;
    }
};
```

**Time: O(n^2)**
**Space: O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestPalindromeSubseq (string s) {
      int n = s.length();
      
      std::vector <std::vector <int>> dp (2, std::vector <int> (n + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[i % 2][j] = std::max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
          if (s[i - 1] == s[n - j])
            dp[i % 2][j] = std::max(dp[i % 2][j], dp[(i + 1) % 2][j - 1] + 2);
        }
      }
      
      return dp[n % 2][n] / 2;
    }
};
```

<br>

### Statistics

- total accepted: 293505
- total submissions: 485162
- acceptance rate: 60.5%
- likes: 6272
- dislikes: 255

<br>

### Similar Problems

- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) (Medium)
- [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings) (Medium)
- [Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences) (Hard)
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) (Medium)
- [Longest Palindromic Subsequence II](https://leetcode.com/problems/longest-palindromic-subsequence-ii) (Medium)
- [Maximize Palindrome Length From Subsequences](https://leetcode.com/problems/maximize-palindrome-length-from-subsequences) (Hard)
- [Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences) (Medium)
