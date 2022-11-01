# [304] Range Sum Query 2D - Immutable

**[array, design, matrix, prefix-sum]**

### Statement

Given a 2D matrix `matrix`, handle multiple queries of the following type:

* Calculate the **sum** of the elements of `matrix` inside the rectangle defined by its **upper left corner** `(row1, col1)` and **lower right corner** `(row2, col2)`.



Implement the `NumMatrix` class:

* `NumMatrix(int[][] matrix)` Initializes the object with the integer matrix `matrix`.
* `int sumRegion(int row1, int col1, int row2, int col2)` Returns the **sum** of the elements of `matrix` inside the rectangle defined by its **upper left corner** `(row1, col1)` and **lower right corner** `(row2, col2)`.



You must design an algorithm where `sumRegion` works on `O(1)` time complexity.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/14/sum-grid.jpg)

```

**Input**
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
**Output**
[null, 8, 11, 12]

**Explanation**
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 200`
* `-104 <= matrix[i][j] <= 104`
* `0 <= row1 <= row2 < m`
* `0 <= col1 <= col2 < n`
* At most `104` calls will be made to `sumRegion`.


<br>

### Hints

None

<br>

### Solution

```cpp
class NumMatrix {
  public:
    int m;
    int n;
    std::vector <std::vector <int>>& matrix;
  
    NumMatrix (vector <vector <int>>& mat)
      : matrix (mat) {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
        
      m = matrix.size();
      n = matrix.front().size();
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i and j)
            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
          else if (i)
            matrix[i][j] += matrix[i - 1][j];
          else if (j)
            matrix[i][j] += matrix[i][j - 1];
        }
      }
    }
    
    int sumRegion (int row1, int col1, int row2, int col2) {
      int ans = matrix[row2][col2];
      
      if (row1 and col1)
        ans += matrix[row1 - 1][col1 - 1];
      if (row1)
        ans -= matrix[row1 - 1][col2];
      if (col1)
        ans -= matrix[row2][col1 - 1];
      
      return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```

<br>

### Statistics

- total accepted: 297450
- total submissions: 573311
- acceptance rate: 51.9%
- likes: 3987
- dislikes: 310

<br>

### Similar Problems

- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable) (Easy)
- [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable) (Hard)
