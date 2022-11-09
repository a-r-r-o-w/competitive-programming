# [212] Word Search II

**[array, string, backtracking, trie, matrix]**

### Statement

Given an `m x n` `board`of characters and a list of strings `words`, return *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)

```

**Input:** board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
**Output:** ["eat","oath"]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)

```

**Input:** board = [["a","b"],["c","d"]], words = ["abcb"]
**Output:** []

```

**Constraints:**
* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 12`
* `board[i][j]` is a lowercase English letter.
* `1 <= words.length <= 3 * 104`
* `1 <= words[i].length <= 10`
* `words[i]` consists of lowercase English letters.
* All the strings of `words` are unique.


<br>

### Hints

- You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
- If the current candidate does not exist in all words&#39; prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: <a href="https://leetcode.com/problems/implement-trie-prefix-tree/">Implement Trie (Prefix Tree)</a> first.

<br>

### Solution

```cpp
class trie {
  public:
    trie* children[26];
    bool end;
    
  public:
    trie ()
      : end (false) {
      for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
    }
  
    ~trie () {
      for (int i = 0; i < 26; ++i)
        if (children[i])
          delete children[i];
    }
    
    void insert (const std::string &s) {
      trie *node = this;
      
      for (char c: s) {
        c -= 'a';
        if (node->children[c] == nullptr)
          node->children[c] = new trie();
        node = node->children[c];
      }
      
      node->end = true;
    }
  
    int find (const std::string &s) {
      trie *node = this;
      
      for (char c: s) {
        c -= 'a';
        if (node->children[c] == nullptr)
          return 0;
        node = node->children[c];
      }
      
      return node->end ? 1 : 2;
    }
};

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <string> findWords (vector <vector <char>>& board, vector <string>& words) {
      trie t;
      int m = board.size(), n = board.front().size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      std::vector <std::string> ans;
      
      for (auto &word: words)
        t.insert(word);
      
      auto dfs = [&] (auto self, int i, int j, std::string &s, trie *node) -> void {
        char c = board[i][j];
        
        node = node->children[board[i][j] - 'a'];
        s.push_back(board[i][j]);
        board[i][j] = '.';
        
        if (node->end) {
          ans.push_back(s);
          node->end = false;
        }
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (ni < 0 or nj < 0 or ni >= m or nj >= n or
              board[ni][nj] == '.' or
              node->children[board[ni][nj] - 'a'] == nullptr)
            continue;
          
          self(self, ni, nj, s, node);
        }
        
        board[i][j] = c;
        s.pop_back();
      };
      
      std::string s;
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (t.children[board[i][j] - 'a'] != nullptr)
            dfs(dfs, i, j, s, &t);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 504738
- total submissions: 1368582
- acceptance rate: 36.9%
- likes: 7447
- dislikes: 327

<br>

### Similar Problems

- [Word Search](https://leetcode.com/problems/word-search) (Medium)
- [Unique Paths III](https://leetcode.com/problems/unique-paths-iii) (Hard)
- [Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings) (Hard)
