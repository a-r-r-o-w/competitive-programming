# [583] Delete Operation for Two Strings

**[string, dynamic-programming]**

### Statement

Given two strings `word1` and `word2`, return *the minimum number of **steps** required to make* `word1` *and* `word2` *the same*.

In one **step**, you can delete exactly one character in either string.


**Example 1:**

```

**Input:** word1 = "sea", word2 = "eat"
**Output:** 2
**Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

```

**Example 2:**

```

**Input:** word1 = "leetcode", word2 = "etco"
**Output:** 4

```

**Constraints:**
* `1 <= word1.length, word2.length <= 500`
* `word1` and `word2` consist of only lowercase English letters.


<br>

### Hints

None

<br>

### Solution

**O(nm) space solution**

```cpp
class Solution {
  public:
    int minDistance (string word1, string word2) {
      int n = word1.length();
      int m = word2.length();
      
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (m + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (word1[i - 1] == word2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
      
      return n + m - 2 * dp[n][m];
    }
};
```

**O(m) space solution**

```cpp
class Solution {
  public:
    int minDistance (string word1, string word2) {
      int n = word1.length();
      int m = word2.length();
      
      std::vector <std::vector <int>> dp (2, std::vector <int> (m + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (word1[i - 1] == word2[j - 1])
            dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
          else
            dp[i % 2][j] = std::max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
      }
      
      return n + m - 2 * dp[n % 2][m];
    }
};
```

<br>

### Statistics

- total accepted: 144829
- total submissions: 251329
- acceptance rate: 57.6%
- likes: 3624
- dislikes: 57

<br>

### Similar Problems

- [Edit Distance](https://leetcode.com/problems/edit-distance) (Hard)
- [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings) (Medium)
- [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) (Medium)
