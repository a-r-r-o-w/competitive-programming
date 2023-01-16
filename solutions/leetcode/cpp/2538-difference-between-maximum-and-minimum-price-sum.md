# [2538] Difference Between Maximum and Minimum Price Sum



### Statement

There exists an undirected and initially unrooted tree with `n` nodes indexed from `0` to `n - 1`. You are given the integer `n` and a 2D integer array `edges` of length `n - 1`, where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the tree.

Each node has an associated price. You are given an integer array `price`, where `price[i]` is the price of the `ith` node.

The **price sum** of a given path is the sum of the prices of all nodes lying on that path.

The tree can be rooted at any node `root` of your choice. The incurred **cost** after choosing `root` is the difference between the maximum and minimum **price sum** amongst all paths starting at `root`.

Return *the **maximum** possible **cost*** *amongst all possible root choices*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/12/01/example14.png)

```

**Input:** n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
**Output:** 24
**Explanation:** The diagram above denotes the tree after rooting it at node 2. The first part (colored in red) shows the path with the maximum price sum. The second part (colored in blue) shows the path with the minimum price sum.
- The first path contains nodes [2,1,3,4]: the prices are [7,8,6,10], and the sum of the prices is 31.
- The second path contains the node [2] with the price [7].
The difference between the maximum and minimum price sum is 24. It can be proved that 24 is the maximum cost.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/24/p1_example2.png)

```

**Input:** n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
**Output:** 2
**Explanation:** The diagram above denotes the tree after rooting it at node 0. The first part (colored in red) shows the path with the maximum price sum. The second part (colored in blue) shows the path with the minimum price sum.
- The first path contains nodes [0,1,2]: the prices are [1,1,1], and the sum of the prices is 3.
- The second path contains node [0] with a price [1].
The difference between the maximum and minimum price sum is 2. It can be proved that 2 is the maximum cost.

```

**Constraints:**
* `1 <= n <= 105`
* `edges.length == n - 1`
* `0 <= ai, bi <= n - 1`
* `edges` represents a valid tree.
* `price.length == n`
* `1 <= price[i] <= 105`


<br>

### Hints

- The minimum price sum is always the price of a rooted node.
- Let’s root the tree at vertex 0 and find the answer from this perspective.
- In the optimal answer maximum price is the sum of the prices of nodes on the path from “u” to “v” where either “u” or “v” is the parent of the second one or neither is a parent of the second one.
- The first case is easy to find. For the second case, notice that in the optimal path, “u” and “v” are both leaves. Then we can use dynamic programming to find such a path.
- Let DP(v,1) denote “the maximum price sum from node v to leaf, where v is a parent of that leaf” and let DP(v,0) denote “the maximum price sum from node v to leaf, where v is a parent of that leaf - price[leaf]”. Then the answer is maximum of DP(u,0) + DP(v,1) + price[parent] where u, v are directly connected to vertex “parent”.

<br>

### Solution

```cpp
class Solution {
  public:
    long long maxOutput (int n, vector <vector <int>>& edges, vector <int>& price) {
      std::vector <std::vector <int>> graph (n);
      
      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      auto dfs = [&] (auto self, int u, std::vector <int64_t> &depth) -> void {
        for (int v: graph[u]) {
          if (depth[v] == -1) {
            depth[v] = depth[u] + price[v];
            self(self, v, depth);
          }
        }
      };
      
      std::vector <int64_t> depth_x (n, -1);
      depth_x[0] = price[0];
      dfs(dfs, 0, depth_x);
      
      auto u = std::max_element(depth_x.begin(), depth_x.end()) - depth_x.begin();
      
      std::vector <int64_t> depth_y (n, -1);
      depth_y[u] = price[u];
      dfs(dfs, u, depth_y);
      
      auto v = std::max_element(depth_y.begin(), depth_y.end()) - depth_y.begin();
      
      depth_x = std::vector <int64_t> (n, -1);
      depth_x[v] = price[v];
      dfs(dfs, v, depth_x);
      
      int64_t ans = 0;
      
      for (int i = 0; i < n; ++i) {
        ans = std::max(ans, depth_x[i] - price[i]);
        ans = std::max(ans, depth_y[i] - price[i]);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1405
- total submissions: 5005
- acceptance rate: 28.1%
- likes: 71
- dislikes: 2

<br>

### Similar Problems

- [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) (Hard)
