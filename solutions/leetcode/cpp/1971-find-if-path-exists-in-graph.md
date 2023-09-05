# [1971] Find if Path Exists in Graph

**[depth-first-search, breadth-first-search, union-find, graph]**

### Statement

There is a **bi-directional** graph with `n` vertices, where each vertex is labeled from `0` to `n - 1` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by **at most one** edge, and no vertex has an edge to itself.

You want to determine if there is a **valid path** that exists from vertex `source` to vertex `destination`.

Given `edges` and the integers `n`, `source`, and `destination`, return `true` *if there is a **valid path** from* `source` *to* `destination`*, or* `false` *otherwise**.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png)

```

**Input:** n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
**Output:** true
**Explanation:** There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png)

```

**Input:** n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
**Output:** false
**Explanation:** There is no path from vertex 0 to vertex 5.

```

**Constraints:**
* `1 <= n <= 2 * 105`
* `0 <= edges.length <= 2 * 105`
* `edges[i].length == 2`
* `0 <= ui, vi <= n - 1`
* `ui != vi`
* `0 <= source, destination <= n - 1`
* There are no duplicate edges.
* There are no self edges.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool validPath (int n, vector <vector <int>>& edges, int source, int destination) {
      std::vector <int> parent (n), rank (n);
      
      std::iota(parent.begin(), parent.end(), 0);
      
      auto find = [&] (auto self, int u) -> int {
        return u == parent[u] ? u : self(self, parent[u]);
      };
      
      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);
        
        if (u == v)
          return;
        
        if (rank[u] < rank[v])
          std::swap(u, v);
        
        parent[v] = u;
        ++rank[u];
      };
      
      for (auto &e: edges)
        unite(e[0], e[1]);
      
      return find(find, source) == find(find, destination);
    }
};
```

<br>

### Statistics

- total accepted: 149524
- total submissions: 296486
- acceptance rate: 50.4%
- likes: 1678
- dislikes: 91

<br>

### Similar Problems

- [Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs) (Hard)
- [Paths in Maze That Lead to Same Room](https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room) (Medium)
