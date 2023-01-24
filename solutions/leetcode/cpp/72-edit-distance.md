# [72] Edit Distance

**[string, dynamic-programming]**

### Statement

Given two strings `word1` and `word2`, return *the minimum number of operations required to convert `word1` to `word2`*.

You have the following three operations permitted on a word:

* Insert a character
* Delete a character
* Replace a character


**Example 1:**

```

**Input:** word1 = "horse", word2 = "ros"
**Output:** 3
**Explanation:** 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

```

**Example 2:**

```

**Input:** word1 = "intention", word2 = "execution"
**Output:** 5
**Explanation:** 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

```

**Constraints:**
* `0 <= word1.length, word2.length <= 500`
* `word1` and `word2` consist of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minDistance (string word1, string word2) {
      int n = word1.length();
      int m = word2.length();
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (m + 1));

      for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
      for (int i = 1; i <= m; ++i)
        dp[0][i] = i;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (word1[i - 1] != word2[j - 1])
            dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          else
            dp[i][j] = dp[i - 1][j - 1];
        }
      }
      
      return dp[n][m];
    }
};
```

Space Optimized

```
class Solution {
  public:
    int minDistance (string word1, string word2) {
      if (word1.length() < word2.length())
        word1.swap(word2);
      
      int n = word1.length();
      int m = word2.length();
      std::vector <std::vector <int>> dp (2, std::vector <int> (m + 1));

      for (int i = 1; i <= m; ++i)
        dp[0][i] = i;
      
      for (int i = 1; i <= n; ++i) {
        dp[i % 2][0] = i;

        for (int j = 1; j <= m; ++j) {
          if (word1[i - 1] == word2[j - 1])
            dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
          else
            dp[i % 2][j] = std::min({dp[(i + 1) % 2][j], dp[i % 2][j - 1], dp[(i + 1) % 2][j - 1]}) + 1;
        }
      }
      
      return dp[n % 2][m];
    }
};
```

<br>

### Statistics

- total accepted: 570836
- total submissions: 1076606
- acceptance rate: 53.0%
- likes: 10888
- dislikes: 126

<br>

### Similar Problems

- [One Edit Distance](https://leetcode.com/problems/one-edit-distance) (Medium)
- [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) (Medium)
- [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings) (Medium)
- [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines) (Medium)
- [Minimum White Tiles After Covering With Carpets](https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets) (Hard)
