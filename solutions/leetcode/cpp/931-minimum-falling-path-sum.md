# [931] Minimum Falling Path Sum

**[array, dynamic-programming, matrix]**

### Statement

Given an `n x n` array of integers `matrix`, return *the **minimum sum** of any **falling path** through* `matrix`.

A **falling path** starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/11/03/failing1-grid.jpg)

```

**Input:** matrix = [[2,1,3],[6,5,4],[7,8,9]]
**Output:** 13
**Explanation:** There are two falling paths with a minimum sum as shown.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/11/03/failing2-grid.jpg)

```

**Input:** matrix = [[-19,57],[-40,-5]]
**Output:** -59
**Explanation:** The falling path with a minimum sum is shown.

```

**Constraints:**
* `n == matrix.length == matrix[i].length`
* `1 <= n <= 100`
* `-100 <= matrix[i][j] <= 100`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minFallingPathSum (vector <vector <int>>& matrix) {
      int n = matrix.size();

      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          int min = 1 << 30;
          for (int k: {-1, 0, +1}) {
            if (j + k >= 0 and j + k < n)
              min = std::min(min, matrix[i - 1][j + k]);
          }
          matrix[i][j] += min;
        }
      }

      return *std::min_element(matrix.back().begin(), matrix.back().end());
    }
};
```

<br>

### Statistics

- total accepted: 187169
- total submissions: 271526
- acceptance rate: 68.9%
- likes: 3607
- dislikes: 111

<br>

### Similar Problems

- [Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii) (Hard)
