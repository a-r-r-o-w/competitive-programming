# [2316] Count Unreachable Pairs of Nodes in an Undirected Graph

**[depth-first-search, breadth-first-search, union-find, graph]**

### Statement

You are given an integer `n`. There is an **undirected** graph with `n` nodes, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting nodes `ai` and `bi`.

Return *the **number of pairs** of different nodes that are **unreachable** from each other*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/05/05/tc-3.png)

```

**Input:** n = 3, edges = [[0,1],[0,2],[1,2]]
**Output:** 0
**Explanation:** There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/05/05/tc-2.png)

```

**Input:** n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
**Output:** 14
**Explanation:** There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

```

**Constraints:**
* `1 <= n <= 10^5`
* `0 <= edges.length <= 2 * 10^5`
* `edges[i].length == 2`
* `0 <= ai, bi < n`
* `ai != bi`
* There are no repeated edges.


<br />

### Hints

- Find the connected components of the graph. To find connected components, you can use Union Find (Disjoint Sets), BFS, or DFS.
- For a node u, the number of nodes that are unreachable from u is the number of nodes that are not in the same connected component as u.
- The number of unreachable nodes from node u will be the same for the number of nodes that are unreachable from node v if nodes u and v belong to the same connected component.

<br />

### Solution

```cpp
class Solution {
  public:
    long long countPairs (int n, vector <vector <int>>& edges) {
      std::vector <int> parent (n), size (n, 1);
      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);
        if (u == v)
          return;
        if (size[u] < size[v])
          std::swap(u, v);
        size[u] += size[v];
        parent[v] = u;
      };

      for (auto &e: edges)
        unite(e[0], e[1]);
      
      std::map <int, int> groups;

      for (int i = 0; i < n; ++i) {
        int x = find(find, i);
        groups[x] = size[x];
      }

      std::vector <std::pair <int, int>> values (groups.begin(), groups.end());
      int k = values.size();
      int64_t ans = 0, sum = 0;

      for (int i = 0; i < k; ++i)
        sum += values[i].second;

      for (int i = 0; i < k; ++i) {
        sum -= values[i].second;
        ans += (int64_t)values[i].second * sum;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 61706
- total submissions: 123530
- acceptance rate: 50.0%
- likes: 1559
- dislikes: 31

<br />

### Similar Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands) (Medium)
