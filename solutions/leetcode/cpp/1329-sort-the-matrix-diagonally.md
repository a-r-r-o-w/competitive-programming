# [1329] Sort the Matrix Diagonally

**[array, sorting, matrix]**

### Statement

A **matrix diagonal** is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the **matrix diagonal** starting from `mat[2][0]`, where `mat` is a `6 x 3` matrix, includes cells `mat[2][0]`, `mat[3][1]`, and `mat[4][2]`.

Given an `m x n` matrix `mat` of integers, sort each **matrix diagonal** in ascending order and return *the resulting matrix*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png)

```

**Input:** mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
**Output:** [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

```

**Example 2:**

```

**Input:** mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
**Output:** [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]

```

**Constraints:**
* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 100`
* `1 <= mat[i][j] <= 100`


<br>

### Hints

- Use a data structure to store all values of each diagonal.
- How to index the data structure with the id of the diagonal?
- All cells in the same diagonal (i,j) have the same difference so we can get the diagonal of a cell using the difference i-j.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> diagonalSort (vector <vector <int>>& mat) {
      int m = mat.size();
      int n = mat.front().size();
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n / 2; ++j)
          std::swap(mat[i][j], mat[i][n - j - 1]);
      
      std::unordered_map <int, std::vector <int>> diagonals;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          diagonals[i + j].push_back(mat[i][j]);
      }
      
      std::vector <int> index (diagonals.size());
      
      for (auto &[x, y]: diagonals)
        std::sort(y.begin(), y.end());
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          mat[i][j] = diagonals[i + j][index[i + j]++];
      }
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n / 2; ++j)
          std::swap(mat[i][j], mat[i][n - j - 1]);
      
      return mat;
    }
};
```

Slightly optimised version

```cpp
class Solution {
  public:
    vector <vector <int>> diagonalSort (vector <vector <int>>& mat) {
      int m = mat.size();
      int n = mat.front().size();
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n / 2; ++j)
          std::swap(mat[i][j], mat[i][n - j - 1]);
      
      std::unordered_map <int, std::vector <int>> diagonals;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          diagonals[i + j].push_back(mat[i][j]);
      }
      
      for (auto &[x, y]: diagonals)
        std::sort(y.begin(), y.end(), [&] (int l, int r) {
          return l > r;
        });
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          mat[i][j] = diagonals[i + j].back();
          diagonals[i + j].pop_back();
        }
      }
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n / 2; ++j)
          std::swap(mat[i][j], mat[i][n - j - 1]);
      
      return mat;
    }
};
```

<br>

### Statistics

- total accepted: 90025
- total submissions: 110560
- acceptance rate: 81.4%
- likes: 1793
- dislikes: 182

<br>

### Similar Problems

None
