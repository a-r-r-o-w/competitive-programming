# [2707] Extra Characters in a String

**[array, hash-table, string, dynamic-programming, trie]**

### Statement

You are given a **0-indexed** string `s` and a dictionary of words `dictionary`. You have to break `s` into one or more **non-overlapping** substrings such that each substring is present in `dictionary`. There may be some **extra characters** in `s` which are not present in any of the substrings.

Return *the **minimum** number of extra characters left over if you break up* `s` *optimally.*
**Example 1:**

```

**Input:** s = "leetscode", dictionary = ["leet","code","leetcode"]
**Output:** 1
**Explanation:** We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.


```

**Example 2:**

```

**Input:** s = "sayhelloworld", dictionary = ["hello","world"]
**Output:** 3
**Explanation:** We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

```

**Constraints:**
* `1 <= s.length <= 50`
* `1 <= dictionary.length <= 50`
* `1 <= dictionary[i].length <= 50`
* `dictionary[i]`and `s` consists of only lowercase English letters
* `dictionary` contains distinct words


<br />

### Hints

- Can we use Dynamic Programming here?
- Define DP[i] as the min extra character if breaking up s[0:i] optimally.

<br />

### Solution

```cpp
class Solution {
  public:
    int minExtraChar(string s, vector<string>& dictionary) {
      int n = s.length(), m = dictionary.size();
      std::vector <int> dp(n, -1);
      std::unordered_set <std::string> have(dictionary.begin(), dictionary.end());

      auto dfs = [&] (auto self, int index) -> int {
        if (index >= n)
          return 0;
        if (dp[index] != -1)
          return dp[index];
        int ans = 1 + self(self, index + 1);
        for (int i = index; i < n; ++i) {
          std::string x = s.substr(index, i - index + 1);
          if (have.count(x))
            ans = std::min(ans, self(self, i + 1));
        }
        return dp[index] = ans;
      };

      return dfs(dfs, 0);
    }
};
```

<br />

### Statistics

- total accepted: 69953
- total submissions: 130744
- acceptance rate: 53.5%
- likes: 1814
- dislikes: 76

<br />

### Similar Problems

- [Word Break](https://leetcode.com/problems/word-break) (Medium)
