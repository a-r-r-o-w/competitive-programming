# [2359] Find Closest Node to Given Two Nodes

**[depth-first-search, graph]**

### Statement

You are given a **directed** graph of `n` nodes numbered from `0` to `n - 1`, where each node has **at most one** outgoing edge.

The graph is represented with a given **0-indexed** array `edges` of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from `i`, then `edges[i] == -1`.

You are also given two integers `node1` and `node2`.

Return *the **index** of the node that can be reached from both* `node1` *and* `node2`*, such that the **maximum** between the distance from* `node1` *to that node, and from* `node2` *to that node is **minimized***. If there are multiple answers, return the node with the **smallest** index, and if no possible answer exists, return `-1`.

Note that `edges` may contain cycles.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-2.png)

```

**Input:** edges = [2,2,3,-1], node1 = 0, node2 = 1
**Output:** 2
**Explanation:** The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-4.png)

```

**Input:** edges = [1,2,-1], node1 = 0, node2 = 2
**Output:** 2
**Explanation:** The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.

```

**Constraints:**
* `n == edges.length`
* `2 <= n <= 105`
* `-1 <= edges[i] < n`
* `edges[i] != i`
* `0 <= node1, node2 < n`


<br>

### Hints

- How can you find the shortest distance from one node to all nodes in the graph?
- Use BFS to find the shortest distance from both node1 and node2 to all nodes in the graph. Then iterate over all nodes, and find the node with the minimum max distance.

<br>

### Solution

```cpp
class Solution {
  public:
    int closestMeetingNode (vector <int>& edges, int node1, int node2) {
      int n = edges.size();
      std::vector <std::vector <int>> graph (n);

      for (int i = 0; i < n; ++i) {
        if (edges[i] == -1)
          continue;
        graph[i].push_back(edges[i]);
      }

      auto dfs = [&] (auto self, int u, int d, std::vector <int> &depth) -> void {
        depth[u] = d;
        for (int v: graph[u]) {
          if (depth[v] != -1)
            continue;
          self(self, v, d + 1, depth);
        }
      };

      std::vector <int> depth1 (n, -1), depth2 (n, -1);
      int min = 1 << 30, node = -1;

      dfs(dfs, node1, 0, depth1);
      dfs(dfs, node2, 0, depth2);

      for (int i = 0; i < n; ++i) {
        if (depth1[i] == -1 or depth2[i] == -1)
          continue;
        int m = std::max(depth1[i], depth2[i]);
        if (m < min) {
          min = m;
          node = i;
        }
      }
      
      return node;
    }
};
```

<br>

### Statistics

- total accepted: 21990
- total submissions: 60265
- acceptance rate: 36.5%
- likes: 528
- dislikes: 119

<br>

### Similar Problems

None
