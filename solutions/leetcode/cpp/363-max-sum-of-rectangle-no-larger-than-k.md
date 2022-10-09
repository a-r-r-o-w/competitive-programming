# [363] Max Sum of Rectangle No Larger Than K

**[array, binary-search, matrix, prefix-sum, ordered-set]**

### Statement

Given an `m x n` matrix `matrix` and an integer `k`, return *the max sum of a rectangle in the matrix such that its sum is no larger than* `k`.

It is **guaranteed** that there will be a rectangle with a sum no larger than `k`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg)

```

**Input:** matrix = [[1,0,1],[0,-2,3]], k = 2
**Output:** 2
**Explanation:** Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

```

**Example 2:**

```

**Input:** matrix = [[2,2,-1]], k = 3
**Output:** 3

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 100`
* `-100 <= matrix[i][j] <= 100`
* `-105 <= k <= 105`


**Follow up:** What if the number of rows is much larger than the number of columns?

<br>

### Hints

None

<br>

### Solution

O(m.m.n.log(n))

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxSumSubmatrix (vector <vector <int>>& matrix, int k) {
      int n = matrix.size();
      int m = matrix.front().size();
      std::vector <int> sum (n);
      std::set <int> have;
      int max = -(1 << 30);
      
      for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
          for (int i = 0; i < n; ++i)
            sum[i] += matrix[i][r];
          
          have.insert(0);
          int current_sum = 0;
          
          for (int s: sum) {
            current_sum += s;
            auto f = have.lower_bound(current_sum - k);
            
            if (f != have.end())
              max = std::max(max, current_sum - *f);
            
            have.insert(current_sum);
          }
          
          have.clear();
        }
        
        for (int i = 0; i < n; ++i)
          sum[i] = 0;
      }
      
      return max;
    }
};
```

Optimisation using Kadane's algorithm

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxSumSubmatrix (vector <vector <int>>& matrix, int k) {
      int n = matrix.size();
      int m = matrix.front().size();
      std::vector <int> sum (n);
      std::set <int> have;
      int max = -(1 << 30);
      
      for (int l = 0; l < m; ++l) {
        for (int r = l; r < m; ++r) {
          int kadane = 0, max_kadane = -(1 << 30);
          
          for (int i = 0; i < n; ++i) {
            sum[i] += matrix[i][r];
            kadane = std::max(kadane + sum[i], sum[i]);
            max_kadane = std::max(max_kadane, kadane);
          }
          
          if (max_kadane <= k) {
            max = std::max(max, max_kadane);
            continue;
          }
          
          have.insert(0);
          int current_sum = 0;
          
          for (int s: sum) {
            current_sum += s;
            auto f = have.lower_bound(current_sum - k);
            
            if (f != have.end())
              max = std::max(max, current_sum - *f);
            
            have.insert(current_sum);
          }
          
          have.clear();
        }
        
        for (int i = 0; i < n; ++i)
          sum[i] = 0;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 102116
- total submissions: 237862
- acceptance rate: 42.9%
- likes: 2799
- dislikes: 143

<br>

### Similar Problems

None
