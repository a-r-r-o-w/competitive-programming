# [1319] Number of Operations to Make Network Connected

**[depth-first-search, breadth-first-search, union-find, graph]**

### Statement

There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between computers `ai` and `bi`. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return *the minimum number of times you need to do this in order to make all the computers connected*. If it is not possible, return `-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png)

```

**Input:** n = 4, connections = [[0,1],[0,2],[1,2]]
**Output:** 1
**Explanation:** Remove cable between computer 1 and 2 and place between computers 1 and 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png)

```

**Input:** n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
**Output:** 2

```

**Example 3:**

```

**Input:** n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
**Output:** -1
**Explanation:** There are not enough cables.

```

**Constraints:**
* `1 <= n <= 105`
* `1 <= connections.length <= min(n * (n - 1) / 2, 105)`
* `connections[i].length == 2`
* `0 <= ai, bi < n`
* `ai != bi`
* There are no repeated connections.
* No two computers are connected by more than one cable.


<br>

### Hints

- As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
- Use DFS to determine the number of isolated computer clusters.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int makeConnected (int n, vector <vector <int>>& connections) {
      int m = connections.size();
      
      if (m < n - 1)
        return -1;
      
      std::vector <int> parent (n), rank (n);
      
      std::iota(parent.begin(), parent.end(), 0);
      
      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? parent[u] : self(self, parent[u]);
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
      
      for (auto &x: connections)
        unite(x[0], x[1]);
      
      std::transform(parent.begin(), parent.end(), parent.begin(), [&] (int x) {
        return find(find, x);
      });
      
      return std::set <int> (parent.begin(), parent.end()).size() - 1;
    }
};
```

<br>

### Statistics

- total accepted: 97218
- total submissions: 167042
- acceptance rate: 58.2%
- likes: 2640
- dislikes: 34

<br>

### Similar Problems

None
