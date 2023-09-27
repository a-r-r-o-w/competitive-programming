# [1252] Cells with Odd Values in a Matrix

**[array, math, simulation]**

### Statement

There is an `m x n` matrix that is initialized to all `0`'s. There is also a 2D array `indices` where each `indices[i] = [ri, ci]` represents a **0-indexed location** to perform some increment operations on the matrix.

For each location `indices[i]`, do **both** of the following:

1. Increment **all** the cells on row `ri`.
2. Increment **all** the cells on column `ci`.



Given `m`, `n`, and `indices`, return *the **number of odd-valued cells** in the matrix after applying the increment to all locations in* `indices`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/10/30/e1.png)

```

**Input:** m = 2, n = 3, indices = [[0,1],[1,1]]
**Output:** 6
**Explanation:** Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/10/30/e2.png)

```

**Input:** m = 2, n = 2, indices = [[1,1],[0,0]]
**Output:** 0
**Explanation:** Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.

```

**Constraints:**
* `1 <= m, n <= 50`
* `1 <= indices.length <= 100`
* `0 <= ri < m`
* `0 <= ci < n`


**Follow up:** Could you solve this in `O(n + m + indices.length)` time with only `O(n + m)` extra space?

<br />

### Hints

- Simulation : With small constraints, it is possible to apply changes to each row and column and count odd cells after applying it.
- You can accumulate the number you should add to each row and column and then you can count the number of odd cells.

<br />

### Solution

```cpp
class Solution {
  public:
    int oddCells (int m, int n, vector <vector <int>>& indices) {
      std::vector <std::vector <int>> grid (m, std::vector <int> (n));

      for (auto &index: indices) {
        for (int i = 0; i < n; ++i)
          ++grid[index[0]][i];
        for (int i = 0; i < m; ++i)
          ++grid[i][index[1]];
      }

      int count = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] & 1)
            ++count;
        }
      }

      return count;
    }
};
```

<br />

### Statistics

- total accepted: 92331
- total submissions: 117510
- acceptance rate: 78.6%
- likes: 970
- dislikes: 1326

<br />

### Similar Problems

None
