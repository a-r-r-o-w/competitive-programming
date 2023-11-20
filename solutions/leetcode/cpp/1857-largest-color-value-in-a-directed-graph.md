# [1857] Largest Color Value in a Directed Graph

**[hash-table, dynamic-programming, graph, topological-sort, memoization, counting]**

### Statement

There is a **directed graph** of `n` colored nodes and `m` edges. The nodes are numbered from `0` to `n - 1`.

You are given a string `colors` where `colors[i]` is a lowercase English letter representing the **color** of the `i^th` node in this graph (**0-indexed**). You are also given a 2D array `edges` where `edges[j] = [aj, bj]` indicates that there is a **directed edge** from node `aj` to node `bj`.

A valid **path** in the graph is a sequence of nodes `x1 -> x2 -> x3 -> ... -> xk` such that there is a directed edge from `xi` to `xi+1` for every `1 <= i < k`. The **color value** of the path is the number of nodes that are colored the **most frequently** occurring color along that path.

Return *the **largest color value** of any valid path in the given graph, or* `-1` *if the graph contains a cycle*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/21/leet1.png)

```

**Input:** colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
**Output:** 3
**Explanation:** The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/04/21/leet2.png)

```

**Input:** colors = "a", edges = [[0,0]]
**Output:** -1
**Explanation:** There is a cycle from 0 to 0.

```

**Constraints:**
* `n == colors.length`
* `m == edges.length`
* `1 <= n <= 10^5`
* `0 <= m <= 10^5`
* `colors` consists of lowercase English letters.
* `0 <= aj, bj< n`


<br />

### Hints

- Use topological sort.
- let dp[u][c] := the maximum count of vertices with color c of any path starting from vertex u. (by JerryJin2905)

<br />

### Solution

```cpp
class Solution {
  public:
    int largestPathValue (string colors, vector <vector <int>>& edges) {
      int n = colors.length();
      std::vector <std::vector <int>> graph (n);

      for (auto &e: edges)
        graph[e[0]].push_back(e[1]);
      
      std::vector <int> visited (n), order;
      bool cycle = false;
      order.reserve(n);
      
      auto dfs = [&] (auto self, int u) -> void {
        visited[u] = 1;
        for (int v: graph[u]) {
          if (visited[v] == 0)
            self(self, v);
          else if (visited[v] == 1)
            cycle = true;
        }
        visited[u] = 2;
        order.push_back(u);
      };

      for (int i = 0; i < n; ++i) {
        if (visited[i] == 0)
          dfs(dfs, i);
      }

      if (cycle)
        return -1;

      std::reverse(order.begin(), order.end());
      visited.assign(n, false);
      std::vector <std::vector <int>> freq (n, std::vector <int> (26));
      int max = 0;

      auto dfs2 = [&] (auto self, int u) -> void {
        if (visited[u] == 0) {
          visited[u] = 1;
          for (int v: graph[u]) {
            self(self, v);
            for (int k = 0; k < 26; ++k)
              freq[u][k] = std::max(freq[u][k], freq[v][k]);
          }
          ++freq[u][colors[u] - 'a'];
        }
        max = std::max(max, freq[u][colors[u] - 'a']);
      };

      for (int i = 0; i < n; ++i) {
        dfs2(dfs2, order[i]);
      }

      return max;
    }
};
```

<br />

### Statistics

- total accepted: 23681
- total submissions: 52137
- acceptance rate: 45.4%
- likes: 958
- dislikes: 34

<br />

### Similar Problems

None
