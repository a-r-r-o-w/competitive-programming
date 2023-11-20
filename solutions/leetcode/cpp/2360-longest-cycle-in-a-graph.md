# [2360] Longest Cycle in a Graph

**[depth-first-search, graph, topological-sort]**

### Statement

You are given a **directed** graph of `n` nodes numbered from `0` to `n - 1`, where each node has **at most one** outgoing edge.

The graph is represented with a given **0-indexed** array `edges` of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from node `i`, then `edges[i] == -1`.

Return *the length of the **longest** cycle in the graph*. If no cycle exists, return `-1`.

A cycle is a path that starts and ends at the **same** node.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png)

```

**Input:** edges = [3,3,4,2,3]
**Output:** 3
**Explanation:** The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png)

```

**Input:** edges = [2,-1,3,1]
**Output:** -1
**Explanation:** There are no cycles in this graph.

```

**Constraints:**
* `n == edges.length`
* `2 <= n <= 105`
* `-1 <= edges[i] < n`
* `edges[i] != i`


<br>

### Hints

- How many cycles can each node at most be part of?
- Each node can be part of at most one cycle. Start from each node and find the cycle that it is part of if there is any. Save the already visited nodes to not repeat visiting the same cycle multiple times.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    int longestCycle (vector <int>& edges) {
      int n = edges.size();
      std::vector <std::vector <int>> graph (n);

      for (int i = 0; i < n; ++i) {
        if (edges[i] == -1)
          continue;
        graph[i].push_back(edges[i]);
      }

      int ans = -1;
      std::vector <int> visited (n), parent (n, -1);

      auto dfs = [&] (auto self, int u, int p) -> void {
        visited[u] = 1;
        parent[u] = p;

        for (int v: graph[u]) {
          if (visited[v] == 0)
            self(self, v, u);
          else if (visited[v] == 1) {
            int size = 1, x = u;
            
            while (x != v) {
              x = parent[x];
              ++size;
            }

            ans = std::max(ans, size);
          }
        }

        visited[u] = 2;
      };

      for (int i = 0; i < n; ++i) {
        if (visited[i] == 0)
          dfs(dfs, i, -1);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 16359
- total submissions: 42197
- acceptance rate: 38.8%
- likes: 647
- dislikes: 9

<br>

### Similar Problems

- [Strange Printer II](https://leetcode.com/problems/strange-printer-ii) (Hard)
- [Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level) (Medium)
