# [1738] Find Kth Largest XOR Coordinate Value

**[array, divide-and-conquer, bit-manipulation, heap-priority-queue, matrix, prefix-sum, quickselect]**

### Statement

You are given a 2D `matrix` of size `m x n`, consisting of non-negative integers. You are also given an integer `k`.

The **value** of coordinate `(a, b)` of the matrix is the XOR of all `matrix[i][j]` where `0 <= i <= a < m` and `0 <= j <= b < n` **(0-indexed)**.

Find the `kth` largest value **(1-indexed)** of all the coordinates of `matrix`.


**Example 1:**

```

**Input:** matrix = [[5,2],[1,6]], k = 1
**Output:** 7
**Explanation:** The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.

```

**Example 2:**

```

**Input:** matrix = [[5,2],[1,6]], k = 2
**Output:** 5
**Explanation:** The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.

```

**Example 3:**

```

**Input:** matrix = [[5,2],[1,6]], k = 3
**Output:** 4
**Explanation:** The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 1000`
* `0 <= matrix[i][j] <= 10^6`
* `1 <= k <= m * n`


<br>

### Hints

- Use a 2D prefix sum to precalculate the xor-sum of the upper left submatrix.

<br>

### Solution

```cpp
class Solution {
  public:
    int kthLargestValue (vector <vector <int>>& matrix, int k) {
      int m = matrix.size(), n = matrix.front().size();

      for (int i = 1; i < n; ++i)
        matrix[0][i] ^= matrix[0][i - 1];
      for (int i = 1; i < m; ++i)
        matrix[i][0] ^= matrix[i - 1][0];
      
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j)
          matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
      }

      std::priority_queue <int> pq;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          pq.push(matrix[i][j]);
      }

      while (--k)
        pq.pop();
      
      return pq.top();
    }
};
```

<br>

### Statistics

- total accepted: 17553
- total submissions: 28808
- acceptance rate: 60.9%
- likes: 413
- dislikes: 59

<br>

### Similar Problems

None
