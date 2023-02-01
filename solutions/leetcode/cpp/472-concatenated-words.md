# [472] Concatenated Words

**[array, string, dynamic-programming, depth-first-search, trie]**

### Statement

Given an array of strings `words` (**without duplicates**), return *all the **concatenated words** in the given list of* `words`.

A **concatenated word** is defined as a string that is comprised entirely of at least two shorter words in the given array.


**Example 1:**

```

**Input:** words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
**Output:** ["catsdogcats","dogcatsdog","ratcatdogcat"]
**Explanation:** "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```

**Example 2:**

```

**Input:** words = ["cat","dog","catdog"]
**Output:** ["catdog"]

```

**Constraints:**
* `1 <= words.length <= 104`
* `1 <= words[i].length <= 30`
* `words[i]` consists of only lowercase English letters.
* All the strings of `words` are **unique**.
* `1 <= sum(words[i].length) <= 105`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> findAllConcatenatedWordsInADict (vector <string>& words) {
      int m = words.size();
      std::unordered_set <std::string> corpus (words.begin(), words.end());

      auto dfs = [&] (auto self, int index, int count, const std::string &s, std::vector <int> &have) -> bool {
        int k = s.length();

        if (index >= k)
          return count > 1;
        if (have[index] != -1)
          return have[index];
        
        bool found = false;
        std::string prefix;
        
        for (int i = 0; index + i < k and not found; ++i) {
          prefix += s[index + i];
          if (corpus.count(prefix) and self(self, index + i + 1, count + 1, s, have))
            found = true;
        }

        have[index] = found;
        return have[index];
      };

      std::vector <std::string> ans;

      for (auto &word: words) {
        std::vector <int> have (word.length(), -1);

        if (dfs(dfs, 0, 0, word, have))
          ans.push_back(word);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 160358
- total submissions: 347963
- acceptance rate: 46.1%
- likes: 2423
- dislikes: 240

<br>

### Similar Problems

- [Word Break II](https://leetcode.com/problems/word-break-ii) (Hard)
