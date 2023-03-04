# [10] Regular Expression Matching

**[string, dynamic-programming, recursion]**

### Statement

Given an input string `s`and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

* `'.'` Matches any single character.​​​​
* `'*'` Matches zero or more of the preceding element.



The matching should cover the **entire** input string (not partial).


**Example 1:**

```

**Input:** s = "aa", p = "a"
**Output:** false
**Explanation:** "a" does not match the entire string "aa".

```

**Example 2:**

```

**Input:** s = "aa", p = "a*"
**Output:** true
**Explanation:** '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

```

**Example 3:**

```

**Input:** s = "ab", p = ".*"
**Output:** true
**Explanation:** ".*" means "zero or more (*) of any character (.)".

```

**Constraints:**
* `1 <= s.length<= 20`
* `1 <= p.length<= 30`
* `s` contains only lowercase English letters.
* `p` contains only lowercase English letters, `'.'`, and`'*'`.
* It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isMatch (string s, string p) {
      int n = s.length(), m = p.length();
      std::vector <std::vector <int>> dp (n, std::vector <int> (m, -1));

      auto dfs = [&] (auto self, int i, int j) -> int {
        if (i >= n and j >= m)
          return 1;
        if (i < n and j < m and dp[i][j] != -1)
          return dp[i][j];
        
        int result = 0;

        if (j + 1 < m) {
          if (p[j + 1] == '*') {
            result = self(self, i, j + 2);
            
            int k = 0;
            while (i + k < n and (s[i + k] == p[j] or p[j] == '.')) {
              ++k;
              result |= self(self, i + k, j + 2);
            }
          }
          else {
            if (i < n and (s[i] == p[j] or p[j] == '.'))
              result = self(self, i + 1, j + 1);
          }
        }
        else {
          if (i < n and (s[i] == p[j] or p[j] == '.'))
            result = self(self, i + 1, j + 1);
        }

        if (i < n and j < m)
          dp[i][j] = result;
        
        return result;
      };

      dfs(dfs, 0, 0);

      return dp[0][0] == 1;
    }
};
```

<br>

### Statistics

- total accepted: 776746
- total submissions: 2755054
- acceptance rate: 28.2%
- likes: 9888
- dislikes: 1604

<br>

### Similar Problems

- [Wildcard Matching](https://leetcode.com/problems/wildcard-matching) (Hard)
