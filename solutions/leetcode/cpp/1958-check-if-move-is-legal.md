# [1958] Check if Move is Legal

**[array, matrix, enumeration]**

### Statement

You are given a **0-indexed** `8 x 8` grid `board`, where `board[r][c]` represents the cell `(r, c)` on a game board. On the board, free cells are represented by `'.'`, white cells are represented by `'W'`, and black cells are represented by `'B'`.

Each move in this game consists of choosing a free cell and changing it to the color you are playing as (either white or black). However, a move is only **legal** if, after changing it, the cell becomes the **endpoint of a good line** (horizontal, vertical, or diagonal).

A **good line** is a line of **three or more cells (including the endpoints)** where the endpoints of the line are **one color**, and the remaining cells in the middle are the **opposite color** (no cells in the line are free). You can find examples for good lines in the figure below:
![](https://assets.leetcode.com/uploads/2021/07/22/goodlines5.png)
Given two integers `rMove` and `cMove` and a character `color` representing the color you are playing as (white or black), return `true` *if changing cell* `(rMove, cMove)` *to color* `color` *is a **legal** move, or* `false` *if it is not legal*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/10/grid11.png)

```

**Input:** board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
**Output:** true
**Explanation:** '.', 'W', and 'B' are represented by the colors blue, white, and black respectively, and cell (rMove, cMove) is marked with an 'X'.
The two good lines with the chosen cell as an endpoint are annotated above with the red rectangles.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/10/grid2.png)

```

**Input:** board = [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], rMove = 4, cMove = 4, color = "W"
**Output:** false
**Explanation:** While there are good lines with the chosen cell as a middle cell, there are no good lines with the chosen cell as an endpoint.

```

**Constraints:**
* `board.length == board[r].length == 8`
* `0 <= rMove, cMove < 8`
* `board[rMove][cMove] == '.'`
* `color` is either `'B'` or `'W'`.


<br>

### Hints

- For each line starting at the given cell check if it's a good line
- To do that iterate over all directions horizontal, vertical, and diagonals then check good lines naively

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkMove (vector <vector <char>>& board, int rMove, int cMove, char color) {
      int i = rMove - 1, count = 1;
      char f = color ^ 'W' ^ 'B';

      int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
      int dy[] = {0, 0, +1, -1, +1, -1, +1, -1};

      for (int i = 0; i < 8; ++i) {
        int r = rMove, c = cMove, count = 1;

        while (true) {
          r += dx[i];
          c += dy[i];

          if (r < 0 or r >= 8 or c < 0 or c >= 8 or board[r][c] != f)
            break;
          
          ++count;
        }

        if (r >= 0 and r < 8 and c >= 0 and c < 8 and board[r][c] == color and count + 1 >= 3)
          return true;
      }

      return false;
    }
};
```

<br>

### Statistics

- total accepted: 8387
- total submissions: 18688
- acceptance rate: 44.9%
- likes: 99
- dislikes: 204

<br>

### Similar Problems

None
