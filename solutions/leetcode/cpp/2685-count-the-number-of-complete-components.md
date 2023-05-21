# [2685] Count the Number of Complete Components



### Statement

You are given an integer `n`. There is an **undirected** graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting vertices `ai` and `bi`.

Return *the number of **complete connected components** of the graph*.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png)**

```

**Input:** n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
**Output:** 3
**Explanation:** From the picture above, one can see that all of the components of this graph are complete.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png)**

```

**Input:** n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
**Output:** 1
**Explanation:** The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

```

**Constraints:**
* `1 <= n <= 50`
* `0 <= edges.length <= n * (n - 1) / 2`
* `edges[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* There are no repeated edges.


<br />

### Hints

- Find the connected components of an undirected graph using depth-first search (DFS) or breadth-first search (BFS).
- For each connected component, count the number of nodes and edges in the component.
- A connected component is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.

<br />

### Solution

```cpp
class Solution {
  public:
    int countCompleteComponents (int n, vector <vector <int>>& edges) {
      std::vector <int> parent (n), size (n), count (n, 1);
      
      std::iota(parent.begin(), parent.end(), 0);
      for (auto &e: edges) {
        ++size[e[0]];
        ++size[e[1]];
      }
      
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
        count[u] += count[v];
        size[u] += size[v];
        parent[v] = u;
      };
      
      for (auto &e: edges)
        unite(e[0], e[1]);
      
      int ans = 0;
      std::set <int> unique;
      
      for (int i = 0; i < n; ++i)
        unique.insert(find(find, i));
      for (int i: unique) {
        if (count[i] * (count[i] - 1) == size[i])
          ++ans;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 8493
- total submissions: 12719
- acceptance rate: 66.8%
- likes: 184
- dislikes: 1

<br />

### Similar Problems

- [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph) (Medium)
