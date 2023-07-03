# [864] Shortest Path to Get All Keys

**[array, bit-manipulation, breadth-first-search, matrix]**

### Statement

You are given an `m x n` grid `grid` where:

* `'.'` is an empty cell.
* `'#'` is a wall.
* `'@'` is the starting point.
* Lowercase letters represent keys.
* Uppercase letters represent locks.



You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some `1 <= k <= 6`, there is exactly one lowercase and one uppercase letter of the first `k` letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return *the lowest number of moves to acquire all keys*. If it is impossible, return `-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-keys2.jpg)

```

**Input:** grid = ["@.a..","###.#","b.A.B"]
**Output:** 8
**Explanation:** Note that the goal is to obtain all the keys not to open all the locks.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-key2.jpg)

```

**Input:** grid = ["@..aA","..B#.","....b"]
**Output:** 6

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-keys3.jpg)

```

**Input:** grid = ["@Aa"]
**Output:** -1

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 30`
* `grid[i][j]` is either an English letter, `'.'`, `'#'`, or `'@'`.
* The number of keys in the grid is in the range `[1, 6]`.
* Each key in the grid is **unique**.
* Each key in the grid has a matching lock.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int shortestPathAllKeys (vector <string>& grid) {
      int m = grid.size(), n = grid.front().size();
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      std::queue <std::tuple <int, int, int>> q;
      int start_x = -1, start_y = -1, k = 0;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '@') {
            start_x = i;
            start_y = j;
          }
          else if (grid[i][j] >= 'a' and grid[i][j] <= 'z')
            ++k;
        }
      }

      std::vector visited(m, std::vector(n, std::vector<bool> (1 << k)));
      int steps = -1;

      q.emplace(start_x, start_y, 0);
      visited[start_x][start_y][0] = true;

      while (!q.empty()) {
        int size = q.size();

        while (size--) {
          auto [x, y, mask] = q.front();
          q.pop();
          std::cout << x << ' ' << y << ' ' << mask << '\n';

          if (__builtin_popcount(mask) == k)
            return steps;
          if (grid[x][y] >= 'A' and grid[x][y] <= 'Z' and !(mask & (1 << (grid[x][y] - 'A'))))
            continue;
          
          if (grid[x][y] >= 'a' and grid[x][y] <= 'z')
            mask |= 1 << (grid[x][y] - 'a');
          
          for (int p = 0; p < 4; ++p) {
            int nx = x + dx[p];
            int ny = y + dy[p];
            if (nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] == '#' or visited[nx][ny][mask])
              continue;
            q.emplace(nx, ny, mask);
            visited[nx][ny][mask] = true;
          }
        }

        ++steps;
      }

      return -1;
    }
};
```

<br />

### Statistics

- total accepted: 53363
- total submissions: 102582
- acceptance rate: 52.0%
- likes: 1767
- dislikes: 80

<br />

### Similar Problems

None
