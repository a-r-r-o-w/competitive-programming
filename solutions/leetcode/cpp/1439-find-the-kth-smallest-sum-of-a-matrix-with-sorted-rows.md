# [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows

**[array, binary-search, heap-priority-queue, matrix]**

### Statement

You are given an `m x n` matrix `mat` that has its rows sorted in non-decreasing order and an integer `k`.

You are allowed to choose **exactly one element** from each row to form an array.

Return *the* `kth` *smallest array sum among all possible arrays*.


**Example 1:**

```

**Input:** mat = [[1,3,11],[2,4,6]], k = 5
**Output:** 7
**Explanation:** Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.

```

**Example 2:**

```

**Input:** mat = [[1,3,11],[2,4,6]], k = 9
**Output:** 17

```

**Example 3:**

```

**Input:** mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
**Output:** 9
**Explanation:** Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  

```

**Constraints:**
* `m == mat.length`
* `n == mat.length[i]`
* `1 <= m, n <= 40`
* `1 <= mat[i][j] <= 5000`
* `1 <= k <= min(200, nm)`
* `mat[i]` is a non-decreasing array.


<br>

### Hints

- Save all visited sums and corresponding indexes in a priority queue. Then, once you pop the smallest sum so far, you can quickly identify the next m candidates for smallest sum by incrementing each row index by 1.

<br>

### Solution

```cpp
class Solution {
  public:
    int kthSmallest (vector <vector <int>>& mat, int k) {
      std::priority_queue <std::pair <int, std::vector <int>>> q;
      std::set <std::vector <int>> visited;
      std::vector <int> indices;
      int sum = 0, m = mat.size(), n = mat.front().size();

      for (int i = 0; i < m; ++i) {
        indices.push_back(0);
        sum += mat[i][0];
      }

      q.emplace(-sum, indices);
      visited.insert(indices);

      while (--k) {
        auto [s, idx] = q.top();
        q.pop();

        for (int i = 0; i < m; ++i) {
          if (idx[i] + 1 < n) {
            auto idx_new = idx;
            idx_new[i] += 1;

            if (visited.count(idx_new))
              continue;
            
            q.push({s + mat[i][idx[i]] - mat[i][idx_new[i]], idx_new});
            visited.insert(idx_new);
          }
        }
      }

      return -q.top().first;
    }
};
```

<br>

### Statistics

- total accepted: 27755
- total submissions: 45224
- acceptance rate: 61.4%
- likes: 1002
- dislikes: 14

<br>

### Similar Problems

None
