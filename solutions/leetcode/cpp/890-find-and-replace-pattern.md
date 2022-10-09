# [890] Find and Replace Pattern

**[array, hash-table, string]**

### Statement

Given a list of strings `words` and a string `pattern`, return *a list of* `words[i]` *that match* `pattern`. You may return the answer in **any order**.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


**Example 1:**

```

**Input:** words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
**Output:** ["mee","aqq"]
**Explanation:** "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

```

**Example 2:**

```

**Input:** words = ["a","b","c"], pattern = "a"
**Output:** ["a","b","c"]

```

**Constraints:**
* `1 <= pattern.length <= 20`
* `1 <= words.length <= 50`
* `words[i].length == pattern.length`
* `pattern` and `words[i]` are lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <string> findAndReplacePattern (vector <string>& words, string pattern) {
      int n = pattern.length();
      std::vector <std::string> ans;
      std::unordered_map <char, char> x, y;
      
      for (auto &word: words) {
        bool bad = false;
        
        for (int i = 0; i < n and !bad; ++i) {
          int j = i;
          
          while (j < n and pattern[j] == pattern[i]) {
            if (word[j] != word[i]) {
              bad = true;
              break;
            }
            ++j;
          }
          
          int p = x.count(word[i]);
          int q = y.count(pattern[i]);
          
          if (p and q) {
            if (x[word[i]] != pattern[i] or y[pattern[i]] != word[i])
              bad = true;
          }
          else if (p or q)
            bad = true;
          else {
            x[word[i]] = pattern[i];
            y[pattern[i]] = word[i];
          }
          
          i = j - 1;
        }
        
        if (!bad)
          ans.push_back(word);
        
        x.clear();
        y.clear();
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 104927
- total submissions: 138188
- acceptance rate: 75.9%
- likes: 2013
- dislikes: 124

<br>

### Similar Problems

None
