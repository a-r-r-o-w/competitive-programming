# [59] Spiral Matrix II

**[array, matrix, simulation]**

### Statement

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n^2` in spiral order.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

```

**Input:** n = 3
**Output:** [[1,2,3],[8,9,4],[7,6,5]]

```

**Example 2:**

```

**Input:** n = 1
**Output:** [[1]]

```

**Constraints:**
* `1 <= n <= 20`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> generateMatrix (int n) {
      int l = 0, r = n - 1, u = 0, d = n - 1, index = 0, total = n * n;
      std::vector <std::vector <int>> ans (n, std::vector <int> (n));

      while (index < total) {
        for (int i = l; i <= r and index < total; ++i)
          ans[u][i] = ++index;
        for (int i = u + 1; i <= d and index < total; ++i)
          ans[i][r] = ++index;
        for (int i = r - 1; i >= l and index < total; --i)
          ans[d][i] = ++index;
        for (int i = d - 1; i >= u + 1 and index < total; --i)
          ans[i][l] = ++index;
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

- total accepted: 421156
- total submissions: 627440
- acceptance rate: 67.1%
- likes: 4594
- dislikes: 203

<br />

### Similar Problems

- [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) (Medium)
- [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii) (Medium)
- [Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv) (Medium)
