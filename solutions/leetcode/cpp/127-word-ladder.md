# [127] Word Ladder

**[hash-table, string, breadth-first-search]**

### Statement

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`



Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the **number of words** in the **shortest transformation sequence** from* `beginWord` *to* `endWord`*, or* `0` *if no such sequence exists.*
**Example 1:**

```

**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
**Output:** 5
**Explanation:** One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

```

**Example 2:**

```

**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
**Output:** 0
**Explanation:** The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

```

**Constraints:**
* `1 <= beginWord.length <= 10`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 5000`
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
    int ladderLength (string beginWord, string endWord, vector <string>& wordList) {
      int n = wordList.size(), m = beginWord.length();
      std::vector <std::vector <int>> graph (n + 1);
      int has_begin_word = -1, has_end_word = -1;

      for (int i = 0; i < n; ++i) {
        if (wordList[i] == beginWord)
          has_begin_word = i;
        else if (wordList[i] == endWord)
          has_end_word = i;
      }

      if (has_end_word == -1)
        return 0;
      
      if (has_begin_word == -1) {
        wordList.push_back(beginWord);
        has_begin_word = n;
        ++n;
      }

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          int count = 0;
          for (int k = 0; k < m and count < 2; ++k) {
            if (wordList[i][k] != wordList[j][k])
              ++count;
          }

          if (count == 1) {
            graph[i].push_back(j);
            graph[j].push_back(i);
          }
        }
      }

      std::queue <int> q;
      std::vector <bool> vis (n);
      int depth = 1;

      q.push(has_begin_word);
      vis[has_begin_word] = true;

      while (!q.empty()) {
        int s = q.size();
        
        for (int i = 0; i < s; ++i) {
          int u = q.front();
          q.pop();

          if (u == has_end_word)
            return depth;

          for (int v: graph[u]) {
            if (vis[v])
              continue;
            q.push(v);
            vis[v] = true;
          }
        }
        
        ++depth;
      }

      return 0;
    }
};
```

<br>

### Statistics

- total accepted: 879119
- total submissions: 2381955
- acceptance rate: 36.9%
- likes: 9758
- dislikes: 1761

<br>

### Similar Problems

- [Word Ladder II](https://leetcode.com/problems/word-ladder-ii) (Hard)
- [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) (Medium)
- [Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary) (Medium)
