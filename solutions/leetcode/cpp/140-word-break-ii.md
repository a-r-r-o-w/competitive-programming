# [140] Word Break II

**[hash-table, string, dynamic-programming, backtracking, trie, memoization]**

### Statement

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.


**Example 1:**

```

**Input:** s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
**Output:** ["cats and dog","cat sand dog"]

```

**Example 2:**

```

**Input:** s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
**Output:** ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
**Explanation:** Note that you are allowed to reuse a dictionary word.

```

**Example 3:**

```

**Input:** s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
**Output:** []

```

**Constraints:**
* `1 <= s.length <= 20`
* `1 <= wordDict.length <= 1000`
* `1 <= wordDict[i].length <= 10`
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
    vector <string> wordBreak (string s, vector <string>& wordDict) {
      int n = s.length(), m = wordDict.size();
      std::unordered_map <std::string, int> corpus;
      std::vector <std::string> ans;

      for (int i = 0; i < m; ++i)
        corpus[wordDict[i]] = i;
      
      auto dfs = [&] (auto self, int index, std::vector <int> &indices) -> void {
        if (index >= n) {
          std::string result;
          for (int i: indices)
            result += wordDict[i] + ' ';
          result.pop_back();
          ans.emplace_back(std::move(result));
          return;
        }
        
        std::string prefix;
        
        for (int i = index; i < n; ++i) {
          prefix += s[i];
          
          if (corpus.count(prefix)) {
            indices.push_back(corpus[prefix]);
            self(self, i + 1, indices);
            indices.pop_back();
          }
        }
      };

      std::vector <int> indices;
      dfs(dfs, 0, indices);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 500955
- total submissions: 1114820
- acceptance rate: 44.9%
- likes: 5757
- dislikes: 497

<br>

### Similar Problems

- [Word Break](https://leetcode.com/problems/word-break) (Medium)
- [Concatenated Words](https://leetcode.com/problems/concatenated-words) (Hard)
