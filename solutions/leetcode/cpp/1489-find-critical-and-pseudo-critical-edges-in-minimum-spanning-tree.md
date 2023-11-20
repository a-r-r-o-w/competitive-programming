# [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

**[union-find, graph, sorting, minimum-spanning-tree, strongly-connected-component]**

### Statement

Given a weighted undirected connected graph with `n`vertices numbered from `0` to `n - 1`,and an array `edges`where `edges[i] = [ai, bi, weighti]` represents a bidirectional and weighted edge between nodes`ai`and `bi`. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cyclesand with the minimum possible total edge weight.

Find *all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST)*. An MST edge whose deletion from the graph would cause the MST weight to increase is called a*critical edge*. Onthe other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/06/04/ex1.png)

```

**Input:** n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
**Output:** [[0,1],[2,3,4,5]]
**Explanation:** The figure above describes the graph.
The following figure shows all the possible MSTs:
![](https://assets.leetcode.com/uploads/2020/06/04/msts.png)
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/06/04/ex2.png)

```

**Input:** n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
**Output:** [[],[0,1,2,3]]
**Explanation:** We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

```

**Constraints:**
* `2 <= n <= 100`
* `1 <= edges.length <= min(200, n * (n - 1) / 2)`
* `edges[i].length == 3`
* `0 <= ai < bi < n`
* `1 <= weighti<= 1000`
* All pairs `(ai, bi)` are **distinct**.


<br />

### Hints

- Use the Kruskal algorithm to find the minimum spanning tree by sorting the edges and picking edges from ones with smaller weights.
- Use a disjoint set to avoid adding redundant edges that result in a cycle.
- To find if one edge is critical, delete that edge and re-run the MST algorithm and see if the weight of the new MST increases.
- To find if one edge is non-critical (in any MST), include that edge to the accepted edge list and continue the MST algorithm, then see if the resulting MST has the same weight of the initial MST of the entire graph.

<br />

### Solution

```cpp
class dsu {
  public:
    int n;
    std::vector <int> parent;
    std::vector <int> size;

    dsu(int n) {
      this->n = n;
      parent.resize(n);
      size.resize(n, 1);
      std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
      return parent[u] = u == parent[u] ? u : find(parent[u]);
    }

    bool unite(int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v)
        return false;
      if (size[u] < size[v])
        std::swap(u, v);
      size[u] += size[v];
      parent[v] = u;
      return true;
    }
};

class Solution {
  public:
    vector <vector <int>> findCriticalAndPseudoCriticalEdges(int n, vector <vector <int>>& edges) {
      int m = edges.size();
      std::vector <int> order(m);
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return edges[l][2] < edges[r][2];
      });

      int mst = 0;
      dsu d(n);
      
      for (int i = 0; i < m; ++i) {
        int j = order[i];
        int u = edges[j][0], v = edges[j][1], w = edges[j][2];
        if (d.unite(u, v))
          mst += w;
      }

      std::vector <std::vector <int>> ans (2);

      for (int i = 0; i < m; ++i) {
        int mst_ignore = 0;
        dsu ignore(n);

        for (int j = 0; j < m; ++j) {
          int k = order[j];
          if (order[i] == k)
            continue;
          int u = edges[k][0], v = edges[k][1], w = edges[k][2];
          if (ignore.unite(u, v))
            mst_ignore += w;
        }

        if (mst_ignore > mst or ignore.size[ignore.find(0)] < n) {
          ans[0].push_back(order[i]);
          continue;
        }

        int mst_take = 0;
        dsu take(n);

        mst_take += edges[order[i]][2];
        take.unite(edges[order[i]][0], edges[order[i]][1]);

        for (int j = 0; j < m; ++j) {
          int k = order[j];
          int u = edges[k][0], v = edges[k][1], w = edges[k][2];
          if (order[i] == k)
            continue;
          if (take.unite(u, v))
            mst_take += w;
        }

        if (mst_take == mst)
          ans[1].push_back(order[i]);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 14523
- total submissions: 26001
- acceptance rate: 55.9%
- likes: 787
- dislikes: 66

<br />

### Similar Problems

None
