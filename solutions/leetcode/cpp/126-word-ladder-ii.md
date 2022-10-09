# [126] Word Ladder II

**[hash-table, string, backtracking, breadth-first-search]**

### Statement

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`



Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *all the **shortest transformation sequences** from* `beginWord` *to* `endWord`*, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words* `[beginWord, s1, s2, ..., sk]`.


**Example 1:**

```

**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
**Output:** [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
**Explanation:**There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

```

**Example 2:**

```

**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
**Output:** []
**Explanation:** The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

```

**Constraints:**
* `1 <= beginWord.length <= 5`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 500`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All the words in `wordList` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    using pair = std::pair <int, int>;
  
    const int inf32 = 1 << 30;
  
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <string>> findLadders (string beginWord, string endWord, vector <string>& wordList) {
      auto endWord_index = std::find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        
      if (endWord_index == wordList.size())
        return {};
      
      auto can_connect = [&] (const std::string &word1, const std::string &word2) {
        int k = word1.size();
        int diff = 0;
        
        for (int i = 0; i < k; ++i)
          if (word1[i] != word2[i])
            ++diff;
        
        return diff == 1;
      };
      
      auto beginWord_index = std::find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
      
      if (beginWord_index == wordList.size())
        wordList.push_back(beginWord);
      
      int n = wordList.size();
      std::vector <std::vector <int>> graph (n);
      
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (can_connect(wordList[i], wordList[j])) {
            graph[i].push_back(j);
            graph[j].push_back(i);
          }
        }
      }
      
      std::vector <bool> visited (n);
      std::vector <int> steps (n, inf32);
      std::priority_queue <pair, std::vector <pair>, std::greater <pair>> pq;
      
      visited[endWord_index] = true;
      pq.push({1, endWord_index});
      
      while (!pq.empty()) {
        auto [level, u] = pq.top();
        pq.pop();
        
        if (steps[u] < level)
          continue;
        
        steps[u] = level;
        
        for (int v: graph[u]) {
          if (!visited[v] or steps[v] > level + 1) {
            steps[v] = level + 1;
            pq.push({steps[v], v});
            visited[v] = true;
          }
        }
      }
      
      std::vector <std::vector <std::string>> paths;
      std::vector <std::string> solution;
      
      auto generate = [&] (auto self, int u) -> void {
        if (steps[u] == 1) {
          paths.push_back(solution);
          return;
        }
        
        for (int v: graph[u]) {
          if (steps[v] == steps[u] - 1) {
            solution.push_back(wordList[v]);
            self(self, v);
            solution.pop_back();
          }
        }
      };
      
      solution.push_back(beginWord);
      generate(generate, beginWord_index);
      
      return paths;
    }
};
```

<br>

### Statistics

- total accepted: 316011
- total submissions: 1155401
- acceptance rate: 27.4%
- likes: 4443
- dislikes: 532

<br>

### Similar Problems

- [Word Ladder](https://leetcode.com/problems/word-ladder) (Hard)
- [Groups of Strings](https://leetcode.com/problems/groups-of-strings) (Hard)
