# [834] Sum of Distances in Tree

**[dynamic-programming, tree, depth-first-search, graph]**

### Statement

There is an undirected connected tree with `n` nodes labeled from `0` to `n - 1` and `n - 1` edges.

You are given the integer `n` and the array `edges` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the tree.

Return an array `answer` of length `n` where `answer[i]` is the sum of the distances between the `ith` node in the tree and all other nodes.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist1.jpg)

```

**Input:** n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
**Output:** [8,12,6,10,10,10]
**Explanation:** The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist2.jpg)

```

**Input:** n = 1, edges = []
**Output:** [0]

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist3.jpg)

```

**Input:** n = 2, edges = [[1,0]]
**Output:** [1,1]

```

**Constraints:**
* `1 <= n <= 3 * 104`
* `edges.length == n - 1`
* `edges[i].length == 2`
* `0 <= ai, bi < n`
* `ai != bi`
* The given input represents a valid tree.


<br>

### Hints

None

<br>

### Solution

Rerooting DP

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> sumOfDistancesInTree (int n, vector <vector <int>>& edges) {
      std::vector <std::vector <int>> graph (n);
      std::vector <int> subtree_size (n), ans (n), parent (n), order (n);
      int sum = 0, index = 0;
      
      for (auto& e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      auto dfs = [&] (auto self, int u, int p, int d) -> void {
        subtree_size[u] = 1;
        parent[u] = p;
        sum += d;
        
        for (int v: graph[u]) {
          if (v != p) {
            self(self, v, u, d + 1);
            subtree_size[u] += subtree_size[v];
          }
        }
        
        order[index++] = u;
      };
      
      dfs(dfs, 0, 0, 0);
      ans[0] = sum;
      
      std::reverse(order.begin(), order.end());
      
      for (int i = 1; i < n; ++i) {
        int u = order[i];
        ans[u] = ans[parent[u]] + (n - subtree_size[u]) - subtree_size[u];
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 43690
- total submissions: 81648
- acceptance rate: 53.5%
- likes: 2751
- dislikes: 61

<br>

### Similar Problems

- [Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree) (Medium)
- [Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score) (Medium)
