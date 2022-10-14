# [74] Search a 2D Matrix

**[array, binary-search, matrix]**

### Statement

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```

**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```

**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
**Output:** false

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 100`
* `-104 <= matrix[i][j], target <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool searchMatrix (vector <vector <int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix.front().size();
      
      int low = 0, high = m - 1;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (matrix[mid][n - 1] < target)
          low = mid + 1;
        else
          high = mid;
      }
      
      if (low == m)
        return false;
      
      int row = low;
      low = 0, high = n - 1;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (matrix[row][mid] < target)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low == n ? false : matrix[row][low] == target;
    }
};
```

<br>

### Statistics

- total accepted: 963590
- total submissions: 2079847
- acceptance rate: 46.3%
- likes: 9503
- dislikes: 302

<br>

### Similar Problems

- [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii) (Medium)
