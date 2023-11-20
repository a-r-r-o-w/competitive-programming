# [1337] The K Weakest Rows in a Matrix

**[array, binary-search, sorting, heap-priority-queue, matrix]**

### Statement

You are given an `m x n` binary matrix `mat` of `1`'s (representing soldiers) and `0`'s (representing civilians). The soldiers are positioned **in front** of the civilians. That is, all the `1`'s will appear to the **left** of all the `0`'s in each row.

A row `i` is **weaker** than a row `j` if one of the following is true:

* The number of soldiers in row `i` is less than the number of soldiers in row `j`.
* Both rows have the same number of soldiers and `i < j`.



Return *the indices of the* `k` ***weakest** rows in the matrix ordered from weakest to strongest*.


**Example 1:**

```

**Input:** mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
**Output:** [2,0,3]
**Explanation:** 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].

```

**Example 2:**

```

**Input:** mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
**Output:** [0,2]
**Explanation:** 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].

```

**Constraints:**
* `m == mat.length`
* `n == mat[i].length`
* `2 <= n, m <= 100`
* `1 <= k <= m`
* `matrix[i][j]` is either 0 or 1.


<br>

### Hints

- Sort the matrix row indexes by the number of soldiers and then row indexes.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> kWeakestRows (vector <vector <int>>& mat, int k) {
      int m = mat.size(), n = mat.front().size();
      std::vector <int> order (m), count (m);

      for (int i = 0; i < m; ++i) {
        count[i] = mat[i].rbegin() - std::lower_bound(mat[i].rbegin(), mat[i].rend(), 1) + 1;
        order[i] = i;
      }

      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        if (count[l] < count[r])
          return true;
        if (count[l] > count[r])
          return false;
        return l < r;
      });

      order.resize(k);
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 227290
- total submissions: 313897
- acceptance rate: 72.4%
- likes: 3020
- dislikes: 178

<br>

### Similar Problems

None
