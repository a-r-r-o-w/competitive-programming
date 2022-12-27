# [2373] Largest Local Values in a Matrix



### Statement

You are given an `n x n` integer matrix `grid`.

Generate an integer matrix `maxLocal` of size `(n - 2) x (n - 2)` such that:

* `maxLocal[i][j]` is equal to the **largest** value of the `3 x 3` matrix in `grid` centered around row `i + 1` and column `j + 1`.



In other words, we want to find the largest value in every contiguous `3 x 3` matrix in `grid`.

Return *the generated matrix*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/06/21/ex1.png)

```

**Input:** grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
**Output:** [[9,9],[8,6]]
**Explanation:** The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/07/02/ex2new2.png)

```

**Input:** grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
**Output:** [[2,2,2],[2,2,2],[2,2,2]]
**Explanation:** Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.

```

**Constraints:**
* `n == grid.length == grid[i].length`
* `3 <= n <= 100`
* `1 <= grid[i][j] <= 100`


<br>

### Hints

- Use nested loops to run through all possible 3 x 3 windows in the matrix.
- For each 3 x 3 window, iterate through the values to get the maximum value within the window.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> largestLocal (vector <vector <int>>& grid) {
      int n = grid.size();
      std::multiset <int> window;
      std::vector <std::vector <int>> ans (n - 2, std::vector <int> (n - 2));
      
      for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k)
            window.insert(grid[i + k][j]);
        }
        
        for (int j = 3; j < n; ++j) {
          ans[i][j - 3] = *window.rbegin();
          
          for (int k = 0; k < 3; ++k) {
            window.erase(window.find(grid[i + k][j - 3]));
            window.insert(grid[i + k][j]);
          }
        }
        
        ans[i][n - 3] = *window.rbegin();
        
        window.clear();
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 15227
- total submissions: 18156
- acceptance rate: 83.9%
- likes: 111
- dislikes: 11

<br>

### Similar Problems

None
