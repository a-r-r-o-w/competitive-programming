# [2508] Add Edges to Make Degrees of All Nodes Even



### Statement

There is an **undirected** graph consisting of `n` nodes numbered from `1` to `n`. You are given the integer `n` and a **2D** array `edges` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi`. The graph can be disconnected.

You can add **at most** two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.

Return `true` *if it is possible to make the degree of each node in the graph even, otherwise return* `false`*.*

The degree of a node is the number of edges connected to it.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/10/26/agraphdrawio.png)

```

**Input:** n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
**Output:** true
**Explanation:** The above diagram shows a valid way of adding an edge.
Every node in the resulting graph is connected to an even number of edges.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/10/26/aagraphdrawio.png)

```

**Input:** n = 4, edges = [[1,2],[3,4]]
**Output:** true
**Explanation:** The above diagram shows a valid way of adding two edges.
```

**Example 3:**
![](https://assets.leetcode.com/uploads/2022/10/26/aaagraphdrawio.png)

```

**Input:** n = 4, edges = [[1,2],[1,3],[1,4]]
**Output:** false
**Explanation:** It is not possible to obtain a valid graph with adding at most 2 edges.
```

**Constraints:**
* `3 <= n <= 105`
* `2 <= edges.length <= 105`
* `edges[i].length == 2`
* `1 <= ai, bi <= n`
* `ai != bi`
* There are no repeated edges.


<br>

### Hints

- Notice that each edge that we add changes the degree of exactly 2 nodes.
- The number of nodes with an odd degree in the original graph should be either 0, 2, or 4. Try to work on each of these cases.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPossible (int n, vector <vector <int>>& edges) {
      std::vector <int> degree (n);
      std::set <std::pair <int, int>> have;
      
      for (auto &e: edges) {
        --e[0]; --e[1];
        ++degree[e[0]];
        ++degree[e[1]];
        have.insert({e[0], e[1]});
      }

      auto has_edge = [&] (int x, int y) -> bool {
        return have.count({x, y}) or have.count({y, x});
      };
      
      int count = 0;
      std::vector <int> bad;
      
      for (int i = 0; i < n; ++i) {
        if (degree[i] & 1)
          bad.push_back(i);
      }
      
      if ((int)bad.size() == 0)
        return true;
      else if ((int)bad.size() == 2) {
        if (!has_edge(bad[0], bad[1]))
          return true;
        
        for (int i = 0; i < n; ++i) {
          if (i == bad[0] or i == bad[1])
            continue;
          if (!has_edge(bad[0], i) and !has_edge(bad[1], i))
            return true;
        }
      }
      else if ((int)bad.size() == 4) {
        if ((!has_edge(bad[0], bad[1]) and !has_edge(bad[2], bad[3])) or
            (!has_edge(bad[0], bad[2]) and !has_edge(bad[1], bad[3])) or
            (!has_edge(bad[0], bad[3]) and !has_edge(bad[1], bad[2])))
          return true;
      }

      return false;
    }
};
```

<br>

### Statistics

- total accepted: 3562
- total submissions: 13981
- acceptance rate: 25.5%
- likes: 68
- dislikes: 19

<br>

### Similar Problems

- [Minimum Degree of a Connected Trio in a Graph](https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph) (Hard)
