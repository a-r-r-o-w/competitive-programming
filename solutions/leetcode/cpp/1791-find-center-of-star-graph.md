# [1791] Find Center of Star Graph

**[graph]**

### Statement

There is an undirected **star** graph consisting of `n` nodes labeled from `1` to `n`. A star graph is a graph where there is one **center** node and **exactly** `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/24/star_graph.png)

```

**Input:** edges = [[1,2],[2,3],[4,2]]
**Output:** 2
**Explanation:** As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

```

**Example 2:**

```

**Input:** edges = [[1,2],[5,1],[1,3],[1,4]]
**Output:** 1

```

**Constraints:**
* `3 <= n <= 105`
* `edges.length == n - 1`
* `edges[i].length == 2`
* `1 <= ui, vi <= n`
* `ui != vi`
* The given `edges` represent a valid star graph.


<br>

### Hints

- The center is the only node that has more than one edge.
- The center is also connected to all other nodes.
- Any two edges must have a common node, which is the center.

<br>

### Solution

Finding degree of nodes

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findCenter (vector <vector <int>>& edges) {
      int n = edges.size() + 1;
      std::vector <int> degree (n);
      
      for (auto &e: edges) {
        ++degree[e[0] - 1];
        ++degree[e[1] - 1];
      }
      
      int ans = -1;
      
      for (int i = 0; i < n; ++i)
        if (degree[i] != 1) {
          ans = i + 1;
          break;
        }
      
      return ans;
    }
};
```

Since it's a star graph, the center node must occur in any two edges

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findCenter (vector <vector <int>>& edges) {
      auto &a = edges[0];
      auto &b = edges[1];
      
      if (a[0] == b[0] || a[0] == b[1])
        return a[0];
      else
        return a[1];
    }
};
```

<br>

### Statistics

- total accepted: 96130
- total submissions: 115069
- acceptance rate: 83.5%
- likes: 699
- dislikes: 89

<br>

### Similar Problems

None
