# [2482] Difference Between Ones and Zeros in Row and Column



### Statement

You are given a **0-indexed** `m x n` binary matrix `grid`.

A **0-indexed** `m x n` difference matrix `diff` is created with the following procedure:

* Let the number of ones in the `ith` row be `onesRowi`.
* Let the number of ones in the `jth` column be `onesColj`.
* Let the number of zeros in the `ith` row be `zerosRowi`.
* Let the number of zeros in the `jth` column be `zerosColj`.
* `diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj`



Return *the difference matrix* `diff`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/11/06/image-20221106171729-5.png)

```

**Input:** grid = [[0,1,1],[1,0,1],[0,0,1]]
**Output:** [[0,0,4],[0,0,4],[-2,-2,2]]
**Explanation:**
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/06/image-20221106171747-6.png)

```

**Input:** grid = [[1,1,1],[1,1,1]]
**Output:** [[5,5,5],[5,5,5]]
**Explanation:**
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 105`
* `1 <= m * n <= 105`
* `grid[i][j]` is either `0` or `1`.


<br>

### Hints

- You need to reuse information about a row or a column many times. Try storing it to avoid computing it multiple times.
- Use an array to store the number of 1’s in each row and another array to store the number of 1’s in each column. Once you know the number of 1’s in each row or column, you can also easily calculate the number of 0’s.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> onesMinusZeros (vector <vector <int>>& grid) {
      int m = grid.size(), n = grid.front().size();
      std::vector <int> one_row (m), zero_row (m), one_col (n), zero_col (n);
      
      for (int i = 0; i < m; ++i) {
        int o = 0, z = 0;
        for (int j = 0; j < n; ++j)
          (grid[i][j] == 0 ? z : o)++;
        one_row[i] = o;
        zero_row[i] = z;
      }
      
      for (int i = 0; i < n; ++i) {
        int o = 0, z = 0;
        for (int j = 0; j < m; ++j)
          (grid[j][i] == 0 ? z : o)++;
        one_col[i] = o;
        zero_col[i] = z;
      }
      
      std::vector <std::vector <int>> diff (m, std::vector <int> (n));
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          diff[i][j] = one_row[i] + one_col[j] - zero_row[i] - zero_col[j];
      }
      
      return diff;
    }
};
```

<br>

### Statistics

- total accepted: 9150
- total submissions: 11784
- acceptance rate: 77.6%
- likes: 78
- dislikes: 3

<br>

### Similar Problems

- [01 Matrix](https://leetcode.com/problems/01-matrix) (Medium)
- [Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix) (Easy)
- [Remove All Ones With Row and Column Flips](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips) (Medium)
