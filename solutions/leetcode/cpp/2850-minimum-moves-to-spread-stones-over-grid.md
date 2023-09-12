# [2850] Minimum Moves to Spread Stones Over Grid



### Statement

You are given a **0-indexed** 2D integer matrix `grid` of size `3 * 3`, representing the number of stones in each cell. The grid contains exactly `9` stones, and there can be **multiple** stones in a single cell.

In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.

Return *the **minimum number of moves** required to place one stone in each cell*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2023/08/23/example1-3.svg)

```

**Input:** grid = [[1,1,0],[1,1,1],[1,2,1]]
**Output:** 3
**Explanation:** One possible sequence of moves to place one stone in each cell is: 
1- Move one stone from cell (2,1) to cell (2,2).
2- Move one stone from cell (2,2) to cell (1,2).
3- Move one stone from cell (1,2) to cell (0,2).
In total, it takes 3 moves to place one stone in each cell of the grid.
It can be shown that 3 is the minimum number of moves required to place one stone in each cell.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2023/08/23/example2-2.svg)

```

**Input:** grid = [[1,3,0],[1,0,0],[1,0,3]]
**Output:** 4
**Explanation:** One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (0,1) to cell (0,2).
2- Move one stone from cell (0,1) to cell (1,1).
3- Move one stone from cell (2,2) to cell (1,2).
4- Move one stone from cell (2,2) to cell (2,1).
In total, it takes 4 moves to place one stone in each cell of the grid.
It can be shown that 4 is the minimum number of moves required to place one stone in each cell.

```

**Constraints:**
* `grid.length == grid[i].length == 3`
* `0 <= grid[i][j] <= 9`
* Sum of `grid` is equal to `9`.


<br />

### Hints

- There are at most <code>4</code> cells with more than one stone.
- Let <code>a</code> be the number of cells containing more than one stone, and <code>b</code> be the number of cells containing no stones. <code></code>. <code>b^a ≤ 6561</code>. Use this fact to come up with a bruteforce.
- For all empty cells, bruteforce over all possible cells from which a stone can come. Note that a stone will always come from a cell containing at least 2 stones.

<br />

### Solution

```cpp
class Solution {
  public:
    int minimumMoves(vector <vector <int>>& grid) {
      auto dfs = [&] (auto self) -> int {
        int count = 0;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0)
              ++count;
          }
        }
        if (count == 0)
          return 0;
        
        int ans = 1 << 30;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == 0) {
              for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                  if (grid[k][l] <= 1)
                    continue;
                  --grid[k][l];
                  ++grid[i][j];
                  ans = std::min(ans, std::abs(i - k) + std::abs(j - l) + self(self));
                  --grid[i][j];
                  ++grid[k][l];
                }
              }
            }
          }
        }
        return ans;
      };
      
      return dfs(dfs);
    }
};
```

<br />

### Statistics

- total accepted: 5456
- total submissions: 17882
- acceptance rate: 30.5%
- likes: 168
- dislikes: 21

<br />

### Similar Problems

- [Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box) (Medium)
