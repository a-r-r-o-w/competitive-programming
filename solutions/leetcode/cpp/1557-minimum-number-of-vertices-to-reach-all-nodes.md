# [1557] Minimum Number of Vertices to Reach All Nodes

**[graph]**

### Statement

Given a**directed acyclic graph**,with`n`vertices numbered from`0`to`n-1`,and an array`edges`where`edges[i] = [fromi, toi]`represents a directed edge from node`fromi`to node`toi`.

Find *the smallest set of vertices from which all nodes in the graph are reachable*. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/07/07/untitled22.png)

```

**Input:** n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
**Output:** [0,3]
**Explanation:** It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/07/07/untitled.png)

```

**Input:** n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
**Output:** [0,2,3]
**Explanation:** Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.

```

**Constraints:**
* `2 <= n <= 10^5`
* `1 <= edges.length <= min(10^5, n * (n - 1) / 2)`
* `edges[i].length == 2`
* `0 <= fromi,toi < n`
* All pairs `(fromi, toi)` are distinct.


<br>

### Hints

- A node that does not have any incoming edge can only be reached by itself.
- Any other node with incoming edges can be reached from some other node.
- We only have to count the number of nodes with zero incoming edges.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> findSmallestSetOfVertices (int n, vector <vector <int>>& edges) {
      std::vector <int> degree (n);
      
      for (auto &e: edges)
        ++degree[e[1]];
      
      std::vector <int> ans;
      
      for (int i = 0; i < n; ++i)
        if (degree[i] == 0)
          ans.push_back(i);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 68366
- total submissions: 86233
- acceptance rate: 79.3%
- likes: 1650
- dislikes: 62

<br>

### Similar Problems

None
