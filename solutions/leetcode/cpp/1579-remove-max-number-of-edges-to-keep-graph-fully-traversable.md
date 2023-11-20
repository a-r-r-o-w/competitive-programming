# [1579] Remove Max Number of Edges to Keep Graph Fully Traversable

**[union-find, graph]**

### Statement

Alice and Bob have an undirected graph of `n` nodes and three types of edges:

* Type 1: Can be traversed by Alice only.
* Type 2: Can be traversed by Bob only.
* Type 3: Can be traversed by both Alice and Bob.



Given an array `edges` where `edges[i] = [typei, ui, vi]` represents a bidirectional edge of type `typei` between nodes `ui` and `vi`, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return *the maximum number of edges you can remove, or return* `-1` *if Alice and Bob cannot fully traverse the graph.*
**Example 1:**
**![](https://assets.leetcode.com/uploads/2020/08/19/ex1.png)**

```

**Input:** n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
**Output:** 2
**Explanation:** If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2020/08/19/ex2.png)**

```

**Input:** n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
**Output:** 0
**Explanation:** Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2020/08/19/ex3.png)**

```

**Input:** n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
**Output:** -1
**Explanation:** In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
```

**Constraints:**
* `1 <= n <= 10^5`
* `1 <= edges.length <= min(10^5, 3 * n * (n - 1) / 2)`
* `edges[i].length == 3`
* `1 <= typei <= 3`
* `1 <= ui < vi <= n`
* All tuples `(typei, ui, vi)` are distinct.


<br />

### Hints

- Build the network instead of removing extra edges.
- Suppose you have the final graph (after removing extra edges). Consider the subgraph with only the edges that Alice can traverse. What structure does this subgraph have? How many edges are there?
- Use disjoint set union data structure for both Alice and Bob.
- Always use Type 3 edges first, and connect the still isolated ones using other edges.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxNumEdgesToRemove (int n, vector <vector <int>>& edges) {
      std::vector <int> a_parent (n), b_parent (n), a_rank (n), b_rank (n);
      
      std::iota(a_parent.begin(), a_parent.end(), 0);
      std::iota(b_parent.begin(), b_parent.end(), 0);
      std::sort(edges.rbegin(), edges.rend());

      auto find = [&] (auto self, int u, auto &parent) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u], parent);
      };

      auto unite = [&] (int u, int v, auto &parent, auto &rank) -> void {
        u = find(find, u, parent);
        v = find(find, v, parent);
        if (u == v)
          return;
        if (rank[u] < rank[v])
          std::swap(u, v);
        ++rank[u];
        parent[v] = u;
      };

      int a_distinct = n, b_distinct = n, remove = 0, index = -1;

      for (auto &e: edges) {
        ++index;
        int t = e[0], u = e[1] - 1, v = e[2] - 1;
        if (a_distinct == 1 and b_distinct == 1) {
          remove += edges.size() - index;
          break;
        }
        if (t == 3) {
          if (
            find(find, u, a_parent) == find(find, v, a_parent) and
            find(find, u, b_parent) == find(find, v, b_parent)
          )
            ++remove;
          else {
            if (find(find, u, a_parent) != find(find, v, a_parent)) {
              unite(u, v, a_parent, a_rank);
              --a_distinct;
            }
            if (find(find, u, b_parent) != find(find, v, b_parent)) {
              unite(u, v, b_parent, b_rank);
              --b_distinct;
            }
          }
        }
        else if (t == 2 and b_distinct > 1) {
          if (find(find, u, b_parent) != find(find, v, b_parent)) {
            unite(u, v, b_parent, b_rank);
            --b_distinct;
          }
          else
            ++remove;
        }
        else if (t == 1 and a_distinct > 1) {
          if (find(find, u, a_parent) != find(find, v, a_parent)) {
            unite(u, v, a_parent, a_rank);
            --a_distinct;
          }
          else
            ++remove;
        }
        else
          ++remove;
      }

      if (a_distinct > 1 or b_distinct > 1)
        return -1;
      return remove;
    }
};
```

<br />

### Statistics

- total accepted: 24532
- total submissions: 42632
- acceptance rate: 57.5%
- likes: 1127
- dislikes: 16

<br />

### Similar Problems

None
