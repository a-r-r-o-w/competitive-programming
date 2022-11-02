# [766] Toeplitz Matrix

**[array, matrix]**

### Statement

Given an `m x n` `matrix`, return*`true`if the matrix is Toeplitz. Otherwise, return `false`.*

A matrix is **Toeplitz** if every diagonal from top-left to bottom-right has the same elements.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg)

```

**Input:** matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
**Output:** true
**Explanation:**
In the above grid, thediagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg)

```

**Input:** matrix = [[1,2],[2,2]]
**Output:** false
**Explanation:**
The diagonal "[1, 2]" has different elements.

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 20`
* `0 <= matrix[i][j] <= 99`


**Follow up:**
* What if the `matrix` is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
* What if the `matrix` is so large that you can only load up a partial row into the memory at once?


<br>

### Hints

- Check whether each value is equal to the value of it's top-left neighbor.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isToeplitzMatrix (vector <vector <int>>& matrix) {
      int m = matrix.size(), n = matrix.front().size();
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i and j and matrix[i][j] != matrix[i - 1][j - 1])
            return false;
        }
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 250202
- total submissions: 363705
- acceptance rate: 68.8%
- likes: 2884
- dislikes: 146

<br>

### Similar Problems

- [Valid Word Square](https://leetcode.com/problems/valid-word-square) (Easy)
