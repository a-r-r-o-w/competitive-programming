# [139] Word Break

**[hash-table, string, dynamic-programming, trie, memoization]**

### Statement

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.


**Example 1:**

```

**Input:** s = "leetcode", wordDict = ["leet","code"]
**Output:** true
**Explanation:** Return true because "leetcode" can be segmented as "leet code".

```

**Example 2:**

```

**Input:** s = "applepenapple", wordDict = ["apple","pen"]
**Output:** true
**Explanation:** Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

```

**Example 3:**

```

**Input:** s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
**Output:** false

```

**Constraints:**
* `1 <= s.length <= 300`
* `1 <= wordDict.length <= 1000`
* `1 <= wordDict[i].length <= 20`
* `s` and `wordDict[i]` consist of only lowercase English letters.
* All the strings of `wordDict` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool wordBreak (string s, vector <string>& wordDict) {
      int n = s.length();
      int m = wordDict.size();
      std::vector <int> have (n, -1);
      
      auto dfs = [&] (auto self, int index) -> bool {
        if (index >= n)
          return true;
        if (have[index] != -1)
          return have[index];
        
        bool found = false;
        
        for (int i = 0; i < m and not found; ++i) {
          int k = wordDict[i].length();
          
          if (index + k > n)
            continue;
          
          int j = 0;
          
          while (j < k and s[index + j] == wordDict[i][j])
            ++j;
          
          if (j == k)
            found |= self(self, index + k);
        }
        
        have[index] = found;
        return have[index];
      };
      
      return dfs(dfs, 0);
    }
};
```

<br>

### Statistics

- total accepted: 1201295
- total submissions: 2653720
- acceptance rate: 45.3%
- likes: 12254
- dislikes: 524

<br>

### Similar Problems

- [Word Break II](https://leetcode.com/problems/word-break-ii) (Hard)
