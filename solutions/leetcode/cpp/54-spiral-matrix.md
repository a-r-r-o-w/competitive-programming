# [54] Spiral Matrix

**[array, matrix, simulation]**

### Statement

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```

**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** [1,2,3,6,9,8,7,4,5]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```

**Input:** matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
**Output:** [1,2,3,4,8,12,11,10,9,5,6,7]

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`


<br />

### Hints

- Well for some problems, the best way really is to come up with some algorithms for simulation. Basically, you need to simulate what the problem asks us to do.
- We go boundary by boundary and move inwards. That is the essential operation. First row, last column, last row, first column, and then we move inwards by 1 and repeat. That's all. That is all the simulation that we need.
- Think about when you want to switch the progress on one of the indexes. If you progress on i out of [i, j], you'll shift in the same column. Similarly, by changing values for j, you'd be shifting in the same row.
Also, keep track of the end of a boundary so that you can move inwards and then keep repeating. It's always best to simulate edge cases like a single column or a single row to see if anything breaks or not.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> spiralOrder (vector <vector <int>>& matrix) {
      int m = matrix.size(), n = matrix.front().size();
      int l = 0, r = n - 1, u = 0, d = m - 1, index = 0, total = n * m;
      std::vector <int> ans (total);

      while (index < total) {
        for (int i = l; i <= r and index < total; ++i)
          ans[index++] = matrix[u][i];
        for (int i = u + 1; i <= d and index < total; ++i)
          ans[index++] = matrix[i][r];
        for (int i = r - 1; i >= l and index < total; --i)
          ans[index++] = matrix[d][i];
        for (int i = d - 1; i >= u + 1 and index < total; --i)
          ans[index++] = matrix[i][l];
        ++l;
        --r;
        ++u;
        --d;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 960926
- total submissions: 2157956
- acceptance rate: 44.5%
- likes: 10401
- dislikes: 1003

<br />

### Similar Problems

- [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii) (Medium)
- [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii) (Medium)
- [Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv) (Medium)
