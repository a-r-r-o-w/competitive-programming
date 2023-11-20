# [1706] Where Will the Ball Fall

**[array, dynamic-programming, depth-first-search, matrix, simulation]**

### Statement

You have a 2-D `grid` of size `m x n` representing a box, and you have `n` balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

* A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as `1`.
* A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as `-1`.



We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return *an array* `answer` *of size* `n` *where* `answer[i]` *is the column that the ball falls out of at the bottom after dropping the ball from the* `ith` *column at the top, or `-1` *if the ball gets stuck in the box*.*
**Example 1:**
**![](https://assets.leetcode.com/uploads/2019/09/26/ball.jpg)**

```

**Input:** grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
**Output:** [1,-1,-1,-1,-1]
**Explanation:** This example is shown in the photo.
Ball b0 is dropped at column 0 and falls out of the box at column 1.
Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.

```

**Example 2:**

```

**Input:** grid = [[-1]]
**Output:** [-1]
**Explanation:** The ball gets stuck against the left wall.

```

**Example 3:**

```

**Input:** grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
**Output:** [0,1,2,3,4,-1]

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 100`
* `grid[i][j]` is `1` or `-1`.


<br>

### Hints

- Use DFS.
- Traverse the path of the ball downwards until you reach the bottom or get stuck.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> findBall (vector <vector <int>>& grid) {
      int m = grid.size(), n = grid.front().size();
      std::vector <int> ans (n, -1);
      
      for (int col = 0; col < n; ++col) {
        int r = 0, c = col;
        
        while (true) {
          if (r >= m)
            break;
          else if (c != n - 1 and grid[r][c] == 1 and grid[r][c + 1] != -1) {
            r += 1;
            c += 1;
          }
          else if (c != 0 and grid[r][c] == -1 and grid[r][c - 1] != 1) {
            r += 1;
            c -= 1;
          }
          else
            break;
        }
        
        if (r >= m)
          ans[col] = c;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 86486
- total submissions: 122685
- acceptance rate: 70.5%
- likes: 2139
- dislikes: 136

<br>

### Similar Problems

None
