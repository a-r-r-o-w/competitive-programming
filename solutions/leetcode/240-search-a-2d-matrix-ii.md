# [240] Search a 2D Matrix II

**[array, binary-search, divide-and-conquer, matrix]**

### Statement

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg)

```

**Input:** matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg)

```

**Input:** matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
**Output:** false

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= n, m <= 300`
* `-109 <= matrix[i][j] <= 109`
* All the integers in each row are **sorted** in ascending order.
* All the integers in each column are **sorted** in ascending order.
* `-109 <= target <= 109`


<br>

### Hints

None

<br>

### Solution

**O(m.log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool searchMatrix (vector <vector <int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix.front().size();
      
      for (int i = 0; i < m; ++i) {
        int low = 0, high = n;
        
        while (low < high) {
          int mid = (low + high) / 2;
          if (matrix[i][mid] < target)
            low = mid + 1;
          else
            high = mid;
        }
        
        if (low < n and matrix[i][low] == target)
          return true;
      }
      
      return false;
    }
};
```

**O(m + n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool searchMatrix (vector <vector <int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix.front().size();
      int x = 0, y = n - 1;
      
      while (x < m and y >= 0) {
        if (target == matrix[x][y])
          return true;
        else if (target < matrix[x][y])
          --y;
        else
          ++x;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 666147
- total submissions: 1340447
- acceptance rate: 49.7%
- likes: 8514
- dislikes: 141

<br>

### Similar Problems

- [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) (Medium)
