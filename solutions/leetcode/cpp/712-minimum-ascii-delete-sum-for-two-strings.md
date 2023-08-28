# [712] Minimum ASCII Delete Sum for Two Strings

**[string, dynamic-programming]**

### Statement

Given two strings `s1` and`s2`, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.


**Example 1:**

```

**Input:** s1 = "sea", s2 = "eat"
**Output:** 231
**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

```

**Example 2:**

```

**Input:** s1 = "delete", s2 = "leet"
**Output:** 403
**Explanation:** Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

```

**Constraints:**
* `1 <= s1.length, s2.length <= 1000`
* `s1` and `s2` consist of lowercase English letters.


<br />

### Hints

- Let dp(i, j) be the answer for inputs s1[i:] and s2[j:].

<br />

### Solution

```cpp
class Solution {
  public:
    int minimumDeleteSum (string s1, string s2) {
      int n = s1.size(), m = s2.size();
      std::vector dp (n + 1, std::vector(m + 1, -1));
      
      auto dfs = [&] (auto self, int i, int j) -> int {
        if (i < 0 and j < 0)
          return 0;
        if (dp[i + 1][j + 1] != -1)
          return dp[i + 1][j + 1];
        if (i < 0) {
          int sum = 0;
          while (j >= 0) {
            sum += s2[j];
            --j;
          }
          return dp[i + 1][j + 1] = sum;
        }
        if (j < 0) {
          int sum = 0;
          while (i >= 0) {
            sum += s1[i];
            --i;
          }
          return dp[i + 1][j + 1] = sum;
        }

        int ans = 1 << 30;
        if (s1[i] == s2[j])
          ans = std::min(ans, self(self, i - 1, j - 1));
        ans = std::min(ans, self(self, i - 1, j) + s1[i]);
        ans = std::min(ans, self(self, i, j - 1) + s2[j]);
        return dp[i + 1][j + 1] = ans;
      };

      return dfs(dfs, n - 1, m - 1);
    }
};
```

<br />

### Statistics

- total accepted: 101108
- total submissions: 157458
- acceptance rate: 64.2%
- likes: 3156
- dislikes: 83

<br />

### Similar Problems

- [Edit Distance](https://leetcode.com/problems/edit-distance) (Medium)
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
- [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) (Medium)
