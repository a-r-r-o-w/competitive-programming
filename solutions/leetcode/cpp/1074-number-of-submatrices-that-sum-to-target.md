# [1074] Number of Submatrices That Sum to Target

**[array, hash-table, matrix, prefix-sum]**

### Statement

Given a `matrix`and a `target`, return the number of non-empty submatrices that sum to target.

A submatrix `x1, y1, x2, y2` is the set of all cells `matrix[x][y]` with `x1 <= x <= x2` and `y1 <= y <= y2`.

Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinatethat is different: for example, if `x1 != x1'`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg)

```

**Input:** matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
**Output:** 4
**Explanation:** The four 1x1 submatrices that only contain 0.

```

**Example 2:**

```

**Input:** matrix = [[1,-1],[-1,1]], target = 0
**Output:** 5
**Explanation:** The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

```

**Example 3:**

```

**Input:** matrix = [[904]], target = 0
**Output:** 0

```

**Constraints:**
* `1 <= matrix.length <= 100`
* `1 <= matrix[0].length <= 100`
* `-1000 <= matrix[i] <= 1000`
* `-10^8 <= target <= 10^8`


<br>

### Hints

- Using a 2D prefix sum, we can query the sum of any submatrix in O(1) time.
Now for each (r1, r2), we can find the largest sum of a submatrix that uses every row in [r1, r2] in linear time using a sliding window.

<br>

### Solution

```cpp
class Solution {
  public:
    int numSubmatrixSumTarget (vector <vector <int>>& matrix, int target) {
      // sum[a:b] = sum[a - 1:b] + sum[a:b - 1] - sum[a - 1:b - 1] + value[a:b]
      
      int n = matrix.size();
      int m = matrix.front().size();
      int ans = 0;
      std::vector <int> row (m);
      std::unordered_map <int, int> have;
      
      for (int k = 0; k < n; ++k) {
        std::fill(row.begin(), row.end(), 0);
        
        for (int i = k; i < n; ++i) {
          int sum = 0;
          
          for (int j = 0; j < m; ++j) {
            row[j] += matrix[i][j];
            sum += row[j];
            
            if (sum == target)
              ans += 1;
            if (have.count(sum - target))
              ans += have[sum - target];
            
            have[sum] += 1;
          }
          
          have.clear();
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 76945
- total submissions: 110431
- acceptance rate: 69.7%
- likes: 2525
- dislikes: 56

<br>

### Similar Problems

None
