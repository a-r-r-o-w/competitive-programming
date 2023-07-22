# [1639] Number of Ways to Form a Target String Given a Dictionary

**[array, string, dynamic-programming]**

### Statement

You are given a list of strings of the **same length** `words` and a string `target`.

Your task is to form `target` using the given `words` under the following rules:

* `target` should be formed from left to right.
* To form the `i^th` character (**0-indexed**) of `target`, you can choose the `k^th` character of the `j^th` string in `words` if `target[i] = words[j][k]`.
* Once you use the `k^th` character of the `j^th` string of `words`, you **can no longer** use the `x^th` character of any string in `words` where `x <= k`. In other words, all characters to the left of or at index `k` become unusuable for every string.
* Repeat the process until you form the string `target`.


**Notice** that you can use **multiple characters** from the **same string** in `words` provided the conditions above are met.

Return *the number of ways to form `target` from `words`*. Since the answer may be too large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** words = ["acca","bbbb","caca"], target = "aba"
**Output:** 6
**Explanation:** There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

```

**Example 2:**

```

**Input:** words = ["abba","baab"], target = "bab"
**Output:** 4
**Explanation:** There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

```

**Constraints:**
* `1 <= words.length <= 1000`
* `1 <= words[i].length <= 1000`
* All strings in `words` have the same length.
* `1 <= target.length <= 1000`
* `words[i]` and `target` contain only lowercase English letters.


<br />

### Hints

- For each index i, store the frequency of each character in the ith row.
- Use dynamic programing to calculate the number of ways to get the target string using the frequency array,

<br />

### Solution

Top Down DP

```cpp
class Solution {
  public:
    int numWays (vector <string>& words, string target) {
      const int mod = 1000000007;
      int n = words.size(), m = words.front().size(), k = target.size();
      std::vector <std::vector <int>> dp (k, std::vector <int> (m, -1));
      std::vector <std::vector <int>> freq (26, std::vector <int> (m));

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          ++freq[words[j][i] - 'a'][i];
      }

      auto dfs = [&] (auto self, int index, int word_index) -> int {
        if (index >= k)
          return 1;
        if (word_index >= m)
          return 0;
        if (dp[index][word_index] != -1)
          return dp[index][word_index];
        int64_t ways = 0, count = freq[target[index] - 'a'][word_index];
        ways = (ways + count * self(self, index + 1, word_index + 1)) % mod;
        ways = (ways + self(self, index, word_index + 1)) % mod;
        return dp[index][word_index] = ways;
      };

      return dfs(dfs, 0, 0);
    }
};
```

Bottom Up DP

```cpp
class Solution {
  public:
    int numWays (vector <string>& words, string target) {
      const int mod = 1000000007;
      int n = words.size(), m = words.front().size(), k = target.size();
      std::vector <std::vector <int>> freq (26, std::vector <int> (m));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          ++freq[words[i][j] - 'a'][j];
      }

      std::vector <std::vector <int>> dp (k + 1, std::vector <int> (m + 1));
      
      for (int i = 0; i <= m; ++i)
        dp[0][i] = 1;
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= m; ++j)
          dp[i][j] = (dp[i][j - 1] + (int64_t)freq[target[i - 1] - 'a'][j - 1] * dp[i - 1][j - 1]) % mod;
      }

      return dp[k][m];
    }
};
```

Space Optimized Bottom Up DP

```cpp
class Solution {
  public:
    int numWays (vector <string>& words, string target) {
      const int mod = 1000000007;
      int n = words.size(), m = words.front().size(), k = target.size();
      std::vector <std::vector <int>> freq (26, std::vector <int> (m));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          ++freq[words[i][j] - 'a'][j];
      }

      std::vector <std::vector <int>> dp (2, std::vector <int> (m + 1));
      
      for (int i = 0; i <= m; ++i)
        dp[0][i] = 1;
      for (int i = 1; i <= k; ++i) {
        int p = i % 2, q = (i + 1) % 2;
        for (int j = 1; j <= m; ++j)
          dp[p][j] = (dp[p][j - 1] + (int64_t)freq[target[i - 1] - 'a'][j - 1] * dp[q][j - 1]) % mod;
        for (int j = 0; j <= m; ++j)
          dp[q][j] = 0;
      }

      return dp[k % 2][m];
    }
};
```

<br />

### Statistics

- total accepted: 18229
- total submissions: 37042
- acceptance rate: 49.2%
- likes: 653
- dislikes: 36

<br />

### Similar Problems

None
