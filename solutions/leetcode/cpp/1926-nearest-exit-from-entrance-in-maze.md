# [1926] Nearest Exit from Entrance in Maze

**[array, breadth-first-search, matrix]**

### Statement

You are given an `m x n` matrix `maze` (**0-indexed**) with empty cells (represented as `'.'`) and walls (represented as `'+'`). You are also given the `entrance` of the maze, where `entrance = [entrancerow, entrancecol]` denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell **up**, **down**, **left**, or **right**. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the **nearest exit** from the `entrance`. An **exit** is defined as an **empty cell** that is at the **border** of the `maze`. The `entrance` **does not count** as an exit.

Return *the **number of steps** in the shortest path from the* `entrance` *to the nearest exit, or* `-1` *if no such path exists*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/04/nearest1-grid.jpg)

```

**Input:** maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
**Output:** 1
**Explanation:** There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/06/04/nearesr2-grid.jpg)

```

**Input:** maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
**Output:** 2
**Explanation:** There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/06/04/nearest3-grid.jpg)

```

**Input:** maze = [[".","+"]], entrance = [0,0]
**Output:** -1
**Explanation:** There are no exits in this maze.

```

**Constraints:**
* `maze.length == m`
* `maze[i].length == n`
* `1 <= m, n <= 100`
* `maze[i][j]` is either `'.'` or `'+'`.
* `entrance.length == 2`
* `0 <= entrancerow < m`
* `0 <= entrancecol < n`
* `entrance` will always be an empty cell.


<br>

### Hints

- Which type of traversal lets you find the distance from a point?
- Try using a Breadth First Search.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int nearestExit (vector <vector <char>>& maze, vector <int>& entrance) {
      const int inf32 = 1 << 30;
      
      int m = maze.size(), n = maze.front().size();
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      int depth = 0;
      std::queue <std::tuple <int, int, int>> q;
      
      maze[entrance[0]][entrance[1]] = '+';
      q.push({entrance[0], entrance[1], 0});
      
      while (!q.empty()) {
        auto [x, y, depth] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          
          if (nx < 0 or ny < 0 or nx >= m or ny >= n or maze[nx][ny] == '+')
            continue;
          
          if (nx == 0 or nx == m - 1 or ny == 0 or ny == n - 1)
            return depth + 1;
          
          maze[nx][ny] = '+';
          q.push({nx, ny, depth + 1});
        }
      }
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 34658
- total submissions: 77664
- acceptance rate: 44.6%
- likes: 813
- dislikes: 39

<br>

### Similar Problems

None
