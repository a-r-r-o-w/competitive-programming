# [1697] Checking Existence of Edge Length Limited Paths

**[array, union-find, graph, sorting]**

### Statement

An undirected graph of `n` nodes is defined by `edgeList`, where `edgeList[i] = [ui, vi, disi]` denotes an edge between nodes `ui` and `vi` with distance `disi`. Note that there may be **multiple** edges between two nodes.

Given an array `queries`, where `queries[j] = [pj, qj, limitj]`, your task is to determine for each `queries[j]` whether there is a path between `pj` and `qj`such that each edge on the path has a distance **strictly less than** `limitj` .

Return *a **boolean array*** `answer`*, where* `answer.length == queries.length` *and the* `j^th` *value of* `answer` *is* `true` *if there is a path for* `queries[j]` *is* `true`*, and* `false` *otherwise*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/12/08/h.png)

```

**Input:** n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
**Output:** [false,true]
**Explanation:** The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/12/08/q.png)

```

**Input:** n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
**Output:** [true,false]
**Exaplanation:** The above figure shows the given graph.

```

**Constraints:**
* `2 <= n <= 10^5`
* `1 <= edgeList.length, queries.length <= 10^5`
* `edgeList[i].length == 3`
* `queries[j].length == 3`
* `0 <= ui, vi, pj, qj <= n - 1`
* `ui != vi`
* `pj != qj`
* `1 <= disi, limitj <= 10^9`
* There may be **multiple** edges between two nodes.


<br />

### Hints

- All the queries are given in advance. Is there a way you can reorder the queries to avoid repeated computations?

<br />

### Solution

```cpp
class Solution {
  public:
    vector <bool> distanceLimitedPathsExist (int n, vector <vector <int>>& edgeList, vector <vector <int>>& queries) {
      int m = queries.size();
      std::vector <int> indices (m);
      
      std::iota(indices.begin(), indices.end(), 0);
      std::sort(edgeList.begin(), edgeList.end(), [&] (auto &l, auto &r) {
        return l[2] < r[2];
      });
      std::sort(indices.begin(), indices.end(), [&] (int l, int r) {
        return queries[l][2] < queries[r][2];
      });

      std::vector <int> parent (n), rank (n);
      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v)
          return;
        if (rank[u] < rank[v])
          std::swap(u, v);
        ++rank[u];
        parent[v] = u;
      };

      int index = 0, k = edgeList.size();
      std::vector <bool> ans (m);

      for (int i = 0; i < m; ++i) {
        int j = indices[i];
        while (index < k and edgeList[index][2] < queries[j][2]) {
          unite(edgeList[index][0], edgeList[index][1]);
          ++index;
        }
        if (find(find, queries[j][0]) == find(find, queries[j][1]))
          ans[j] = true;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 37513
- total submissions: 59902
- acceptance rate: 62.6%
- likes: 1515
- dislikes: 38

<br />

### Similar Problems

- [Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii) (Hard)
- [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) (Hard)
- [Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities) (Medium)
