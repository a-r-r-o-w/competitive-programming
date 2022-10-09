# [867] Transpose Matrix

**[array, matrix, simulation]**

### Statement

Given a 2D integer array `matrix`, return *the **transpose** of* `matrix`.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

![](https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png)
**Example 1:**

```

**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** [[1,4,7],[2,5,8],[3,6,9]]

```

**Example 2:**

```

**Input:** matrix = [[1,2,3],[4,5,6]]
**Output:** [[1,4],[2,5],[3,6]]

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 1000`
* `1 <= m * n <= 105`
* `-109 <= matrix[i][j] <= 109`


<br>

### Hints

- We don't need any special algorithms to do this. You just need to know what the transpose of a matrix looks like. Rows become columns and vice versa!

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> transpose (vector <vector <int>>& matrix) {
      int n = matrix.size();
      int m = matrix.front().size();
      std::vector <std::vector <int>> t (m, std::vector <int> (n));
      
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          t[j][i] = matrix[i][j];
      
      return t;
    }
};
```

<br>

### Statistics

- total accepted: 202614
- total submissions: 316981
- acceptance rate: 63.9%
- likes: 2111
- dislikes: 400

<br>

### Similar Problems

None
