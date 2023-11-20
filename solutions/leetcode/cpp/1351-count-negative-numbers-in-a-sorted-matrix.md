# [1351] Count Negative Numbers in a Sorted Matrix

**[array, binary-search, matrix]**

### Statement

Given a `m x n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise, return *the number of **negative** numbers in* `grid`.


**Example 1:**

```

**Input:** grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
**Output:** 8
**Explanation:** There are 8 negatives number in the matrix.

```

**Example 2:**

```

**Input:** grid = [[3,2],[1,0]]
**Output:** 0

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 100`
* `-100 <= grid[i][j] <= 100`


**Follow up:** Could you find an `O(n + m)` solution?

<br>

### Hints

- Use binary search for optimization or simply brute force.

<br>

### Solution

**O(m.n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countNegatives (vector <vector <int>>& grid) {
      int m = grid.size();
      int n = grid.front().size();
      int ans = 0;
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] < 0)
            ++ans;
      
      return ans;
    }
};
```

**O(m.log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countNegatives (vector <vector <int>>& grid) {
      int m = grid.size();
      int n = grid.front().size();
      int ans = 0;
      
      for (int i = 0; i < m; ++i) {
        int low = 0, high = n;
        while (low < high) {
          int mid = (low + high) / 2;
          if (grid[i][mid] >= 0)
            low = mid + 1;
          else
            high = mid;
        }
        ans += n - low;
      }
      
      return ans;
    }
};
```

**O(n + m)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countNegatives (vector <vector <int>>& grid) {
      int m = grid.size();
      int n = grid.front().size();
      int ans = 0;
      int i = m - 1, j = 0;
      
      while (i >= 0 and j < n) {
        if (grid[i][j] >= 0)
          ++j;
        else {
          ans += n - j;
          --i;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 192975
- total submissions: 256743
- acceptance rate: 75.2%
- likes: 2502
- dislikes: 78

<br>

### Similar Problems

None
