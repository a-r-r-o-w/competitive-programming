# [2608] Shortest Cycle in a Graph

**[breadth-first-search, graph]**

### Statement

There is a **bi-directional** graph with `n` vertices, where each vertex is labeled from `0` to `n - 1`. The edges in the graph are represented by a given 2D integer array `edges`, where `edges[i] = [ui, vi]` denotes an edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

Return *the length of the **shortest** cycle in the graph*. If no cycle exists, return `-1`.

A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.


**Example 1:**
![](https://assets.leetcode.com/uploads/2023/01/04/cropped.png)

```

**Input:** n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
**Output:** 3
**Explanation:** The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2023/01/04/croppedagin.png)

```

**Input:** n = 4, edges = [[0,1],[0,2]]
**Output:** -1
**Explanation:** There are no cycles in this graph.

```

**Constraints:**
* `2 <= n <= 1000`
* `1 <= edges.length <= 1000`
* `edges[i].length == 2`
* `0 <= ui, vi < n`
* `ui != vi`
* There are no repeated edges.


<br />

### Hints

- How can BFS be used?
- For each vertex u, calculate the length of the shortest cycle that contains vertex u using BFS

<br />

### Solution

```cpp
class Solution {
  public:
    int findShortestCycle (int n, vector <vector <int>>& edges) {
      const int inf32 = 1 << 30;
      std::vector <std::vector <int>> graph (n);
      int ans = inf32;
      
      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      std::vector <int> parent (n, -1), distance (n, inf32);
      std::queue <int> q;
      
      for (int i = 0; i < n; ++i) {
        q.push(i);
        distance[i] = 0;
        
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int v: graph[u]) {
            if (distance[v] == inf32) {
              q.push(v);
              distance[v] = distance[u] + 1;
              parent[v] = u;
            }
            else if (parent[u] != v and parent[v] != u)
              ans = std::min(ans, distance[u] + distance[v] + 1);
          }
        }
        
        parent.assign(n, -1);
        distance.assign(n, inf32);
      }
      
      if (ans == inf32)
        ans = -1;
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 8422
- total submissions: 21885
- acceptance rate: 38.5%
- likes: 244
- dislikes: 12

<br />

### Similar Problems

- [Redundant Connection](https://leetcode.com/problems/redundant-connection) (Medium)
- [Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph) (Hard)
- [Divide Nodes Into the Maximum Number of Groups](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups) (Hard)
