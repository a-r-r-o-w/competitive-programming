# [2352] Equal Row and Column Pairs

**[array, hash-table, matrix, simulation]**

### Statement

Given a **0-indexed** `n x n` integer matrix `grid`, *return the number of pairs* `(Ri, Cj)` *such that row* `Ri` *and column* `Cj` *are equal*.

A row and column pair is considered equal if they contain the same elements in the same order (i.e. an equal array).


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg)

```

**Input:** grid = [[3,2,1],[1,7,6],[2,7,7]]
**Output:** 1
**Explanation:** There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg)

```

**Input:** grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
**Output:** 3
**Explanation:** There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]

```

**Constraints:**
* `n == grid.length == grid[i].length`
* `1 <= n <= 200`
* `1 <= grid[i][j] <= 105`


<br>

### Hints

- We can use nested loops to compare every row against every column.
- Another loop is necessary to compare the row and column element by element.
- It is also possible to hash the arrays and compare the hashed values instead.

<br>

### Solution

```cpp
class Solution {
  public:
    int equalPairs (vector <vector <int>>& grid) {
      int n = grid.size(), ans = 0;
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          bool okay = true;
          
          for (int k = 0; k < n; ++k) {
            if (grid[i][k] != grid[k][j]) {
              okay = false;
              break;
            }
          }
          
          if (okay)
            ++ans;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 28989
- total submissions: 40819
- acceptance rate: 71.0%
- likes: 329
- dislikes: 11

<br>

### Similar Problems

None
