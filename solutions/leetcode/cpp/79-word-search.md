# [79] Word Search

**[array, backtracking, matrix]**

### Statement

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```

**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```

**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
**Output:** true

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```

**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
**Output:** false

```

**Constraints:**
* `m == board.length`
* `n = board[i].length`
* `1 <= m, n <= 6`
* `1 <= word.length <= 15`
* `board` and `word` consists of only lowercase and uppercase English letters.


**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

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
  
    bool exist (vector <vector <char>>& board, std::string word) {
      int m = board.size(), n = board.front().size(), k = word.size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      bool has = false;
      
      auto dfs = [&] (auto self, int i, int j, int w, std::string &s) -> void {
        if (board[i][j] != word[w])
          return;
        
        char c = board[i][j];
        
        s.push_back(board[i][j]);
        board[i][j] = '.';
        
        if (w >= k - 1) {
          has = true;
          return;
        }
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (has or ni < 0 or nj < 0 or ni >= m or nj >= n or board[ni][nj] == '.')
            continue;
          
          self(self, ni, nj, w + 1, s);
        }
        
        board[i][j] = c;
        s.pop_back();
      };
      
      std::string s;
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          dfs(dfs, i, j, 0, s);
      
      return has;
    }
};
```

<br>

### Statistics

- total accepted: 1148567
- total submissions: 2885042
- acceptance rate: 39.8%
- likes: 11637
- dislikes: 467

<br>

### Similar Problems

- [Word Search II](https://leetcode.com/problems/word-search-ii) (Hard)
