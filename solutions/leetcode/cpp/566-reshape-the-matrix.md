# [566] Reshape the Matrix

**[array, matrix, simulation]**

### Statement

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg)

```

**Input:** mat = [[1,2],[3,4]], r = 1, c = 4
**Output:** [[1,2,3,4]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg)

```

**Input:** mat = [[1,2],[3,4]], r = 2, c = 4
**Output:** [[1,2],[3,4]]

```

**Constraints:**
* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 100`
* `-1000 <= mat[i][j] <= 1000`
* `1 <= r, c <= 300`


<br>

### Hints

- Do you know how 2d matrix is stored in 1d memory? Try to map 2-dimensions into one.
- M[i][j]=M[n*i+j] , where n is the number of cols. 
This is the one way of converting 2-d indices into one 1-d index.  
Now, how will you convert 1-d index into 2-d indices?
- Try to use division and modulus to convert 1-d index into 2-d indices.
- M[i] =>  M[i/n][i%n] Will it result in right mapping? Take some example and check this formula.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> matrixReshape (vector <vector <int>>& mat, int r, int c) {
      int n = mat.size();
      int m = mat.front().size();
      
      if (n * m != r * c)
        return mat;
      
      std::vector <std::vector <int>> grid (r, std::vector <int> (c));
      int mi = 0, mj = 0;
      
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          grid[i][j] = mat[mi][mj];
          ++mj;
          if (mj == m) {
            mj = 0;
            ++mi;
          }
        }
      }
      
      return grid;
    }
};
```

<br>

### Statistics

- total accepted: 281914
- total submissions: 450142
- acceptance rate: 62.6%
- likes: 2680
- dislikes: 301

<br>

### Similar Problems

- [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) (Easy)
