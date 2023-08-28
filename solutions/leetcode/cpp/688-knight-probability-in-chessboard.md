# [688] Knight Probability in Chessboard

**[dynamic-programming]**

### Statement

On an `n x n` chessboard, a knight starts at the cell `(row, column)` and attempts to make exactly `k` moves. The rows and columns are **0-indexed**, so the top-left cell is `(0, 0)`, and the bottom-right cell is `(n - 1, n - 1)`.

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
![](https://assets.leetcode.com/uploads/2018/10/12/knight.png)
Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly `k` moves or has moved off the chessboard.

Return *the probability that the knight remains on the board after it has stopped moving*.


**Example 1:**

```

**Input:** n = 3, k = 2, row = 0, column = 0
**Output:** 0.06250
**Explanation:** There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

```

**Example 2:**

```

**Input:** n = 1, k = 0, row = 0, column = 0
**Output:** 1.00000

```

**Constraints:**
* `1 <= n <= 25`
* `0 <= k <= 100`
* `0 <= row, column <= n - 1`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    double knightProbability (int n, int k, int row, int column) {
      std::vector dp (n, std::vector(n, std::vector(k, (long double)-1.0)));

      auto dfs = [&] (auto self, int x, int y, int moves) -> long double {
        if (x < 0 or y < 0 or x >= n or y >= n)
          return 0;
        if (moves <= 0)
          return 1;
        moves -= 1;
        if (dp[x][y][moves] != -1)
          return dp[x][y][moves];
        long double p = 0;
        p += self(self, x + 2, y - 1, moves);
        p += self(self, x + 2, y + 1, moves);
        p += self(self, x - 2, y - 1, moves);
        p += self(self, x - 2, y + 1, moves);
        p += self(self, x + 1, y - 2, moves);
        p += self(self, x + 1, y + 2, moves);
        p += self(self, x - 1, y - 2, moves);
        p += self(self, x - 1, y + 2, moves);
        return dp[x][y][moves] = p / 8;
      };

      return dfs(dfs, row, column, k);
    }
};
```

<br />

### Statistics

- total accepted: 122885
- total submissions: 224314
- acceptance rate: 54.8%
- likes: 3220
- dislikes: 411

<br />

### Similar Problems

- [Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths) (Medium)
