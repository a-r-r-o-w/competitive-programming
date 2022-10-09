# [1192] Critical Connections in a Network

**[depth-first-search, graph, biconnected-component]**

### Statement

There are `n` servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between servers `ai` and `bi`. Any server can reach other servers directly or indirectly through the network.

A *critical connection* is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png)

```

**Input:** n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
**Output:** [[1,3]]
**Explanation:** [[3,1]] is also accepted.

```

**Example 2:**

```

**Input:** n = 2, connections = [[0,1]]
**Output:** [[0,1]]

```

**Constraints:**
* `2 <= n <= 105`
* `n - 1 <= connections.length <= 105`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* There are no repeated connections.


<br>

### Hints

- Use Tarjan's algorithm.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> criticalConnections (int n, vector <vector <int>>& connections) {
      std::vector <bool> visited (n);
      std::vector <int> in_time (n), lowest_time (n);
      int time = 0;
      std::vector <std::vector <int>> graph (n), bridges;
      
      for (auto &connection: connections) {
        int u = connection[0];
        int v = connection[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
      }
      
      auto dfs = [&] (auto self, int u, int p) -> void {
        visited[u] = true;
        in_time[u] = time;
        lowest_time[u] = time;
        ++time;
        
        for (int v: graph[u]) {
          if (v == p)
            continue;
          
          if (visited[v])
            lowest_time[u] = std::min(lowest_time[u], in_time[v]);
          else {
            self(self, v, u);
            
            lowest_time[u] = std::min(lowest_time[u], lowest_time[v]);
            
            if (lowest_time[v] > in_time[u])
              bridges.push_back({u, v});
          }
        }
      };
      
      dfs(dfs, 0, -1);
      
      return bridges;
    }
};
```

<br>

### Statistics

- total accepted: 185826
- total submissions: 341127
- acceptance rate: 54.5%
- likes: 4917
- dislikes: 166

<br>

### Similar Problems

None
