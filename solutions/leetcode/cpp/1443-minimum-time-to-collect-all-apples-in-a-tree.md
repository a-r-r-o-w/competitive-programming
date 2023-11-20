# [1443] Minimum Time to Collect All Apples in a Tree

**[hash-table, tree, depth-first-search, breadth-first-search]**

### Statement

Given an undirected tree consisting of `n` vertices numbered from `0` to `n-1`, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. *Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at **vertex 0** and coming back to this vertex.*

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [ai, bi]` means that exists an edge connecting the vertices `ai` and `bi`. Additionally, there is a boolean array `hasApple`, where `hasApple[i] = true` means that vertex `i` has an apple; otherwise, it does not have any apple.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_1.png)

```

**Input:** n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
**Output:** 8 
**Explanation:** The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_2.png)

```

**Input:** n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
**Output:** 6
**Explanation:** The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

```

**Example 3:**

```

**Input:** n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
**Output:** 0

```

**Constraints:**
* `1 <= n <= 105`
* `edges.length == n - 1`
* `edges[i].length == 2`
* `0 <= ai < bi <= n - 1`
* `fromi < toi`
* `hasApple.length == n`


<br>

### Hints

- Note that if a node u contains an apple then all edges in the path from the root to the node u have to be used forward and backward (2 times).
- Therefore use a depth-first search (DFS) to check if an edge will be used or not.

<br>

### Solution

```cpp
class Solution {
  public:
    int minTime (int n, vector <vector <int>>& edges, vector <bool>& hasApple) {
      std::vector <std::vector <int>> graph (n);
      std::vector <bool> visited (n);
      int ans = 0;

      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      auto dfs = [&] (auto self, int u) -> bool {
        bool r = hasApple[u];
        visited[u] = true;
        
        for (int v: graph[u]) {
          if (visited[v])
            continue;
          r |= self(self, v);
        }

        if (r)
          ans += 2;

        return r;
      };

      visited[0] = true;
      for (int i: graph[0]) {
        if (!visited[i])
          dfs(dfs, i);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 46927
- total submissions: 79923
- acceptance rate: 58.7%
- likes: 1783
- dislikes: 148

<br>

### Similar Problems

None
