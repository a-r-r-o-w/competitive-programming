# [2569] Handling Sum Queries After Update



### Statement

You are given two **0-indexed** arrays `nums1` and `nums2` and a 2D array `queries` of queries. There are three types of queries:

1. For a query of type 1, `queries[i]= [1, l, r]`. Flip the values from `0` to `1` and from `1` to `0` in `nums1` from index `l` to index `r`. Both `l` and `r` are **0-indexed**.
2. For a query of type 2, `queries[i]= [2, p, 0]`. For every index `0 <= i < n`, set`nums2[i] =nums2[i]+ nums1[i]* p`.
3. For a query of type 3, `queries[i]= [3, 0, 0]`. Find the sum of the elements in `nums2`.



Return *an array containing all the answers to the third typequeries.*
**Example 1:**

```

**Input:** nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
**Output:** [3]
**Explanation:** After the first query nums1 becomes [1,1,1]. After the second query, nums2 becomes [1,1,1], so the answer to the third query is 3. Thus, [3] is returned.

```

**Example 2:**

```

**Input:** nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
**Output:** [5]
**Explanation:** After the first query, nums2 remains [5], so the answer to the second query is 5. Thus, [5] is returned.

```

**Constraints:**
* `1 <= nums1.length,nums2.length <= 10^5`
* `nums1.length = nums2.length`
* `1 <= queries.length <= 10^5`
* `queries[i].length = 3`
* `0 <= l <= r <= nums1.length - 1`
* `0 <= p <= 10^6`
* `0 <= nums1[i] <= 1`
* `0 <= nums2[i] <= 10^9`


<br />

### Hints

- Use the Lazy Segment Tree to process the queries quickly.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <long long> handleQuery (vector <int>& nums1, vector <int>& nums2, vector <vector <int>>& queries) {
      int n = nums1.size();
      int64_t answer = std::accumulate(nums2.begin(), nums2.end(), int64_t(0));
      std::vector <long long> results;
      
      struct node {
        int value = 0;
        bool lazy = false;
      };
      
      std::vector <node> tree (4 * n);
      
      auto build = [&] (auto self, int v, int tl, int tr) -> void {
        if (tl == tr)
          tree[v].value = nums1[tl] == 1;
        else {
          int tm = (tl + tr) / 2;
          self(self, 2 * v + 1, tl, tm);
          self(self, 2 * v + 2, tm + 1, tr);
          tree[v].value = tree[2 * v + 1].value + tree[2 * v + 2].value;
        }
      };
      
      auto push = [&] (int v, int tl, int tr) {
        if (not tree[v].lazy)
          return;
        int tm = (tl + tr) / 2;
        tree[2 * v + 1].value = tm - tl + 1 - tree[2 * v + 1].value;
        tree[2 * v + 2].value = tr - tm - tree[2 * v + 2].value;
        tree[2 * v + 1].lazy ^= true;
        tree[2 * v + 2].lazy ^= true;
        tree[v].lazy = false;
      };
      
      auto update = [&] (auto self, int v, int tl, int tr, int l, int r) -> void {
        if (l > r)
          return;
        if (tl == l and tr == r) {
          tree[v].value = tr - tl + 1 - tree[v].value;
          tree[v].lazy ^= true;
          return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        self(self, 2 * v + 1, tl, tm, l, std::min(r, tm));
        self(self, 2 * v + 2, tm + 1, tr, std::max(l, tm + 1), r);
        tree[v].value = tree[2 * v + 1].value + tree[2 * v + 2].value;
      };
      
      build(build, 0, 0, n - 1);
      
      for (auto &v: queries) {
        if (v[0] == 1)
          update(update, 0, 0, n - 1, v[1], v[2]);
        else if (v[0] == 2)
          answer += (int64_t)tree[0].value * v[1];
        else
          results.push_back(answer);
      }
      
      return results;
    }
};
```

<br />

### Statistics

- total accepted: 1451
- total submissions: 7792
- acceptance rate: 18.6%
- likes: 53
- dislikes: 11

<br />

### Similar Problems

None
