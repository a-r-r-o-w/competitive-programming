# [2497] Maximum Star Sum of a Graph



### Statement

There is an undirected graph consisting of `n` nodes numbered from `0` to `n - 1`. You are given a **0-indexed** integer array `vals` of length `n` where `vals[i]` denotes the value of the `ith` node.

You are also given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting nodes `ai` and `bi.`

A **star graph** is a subgraph of the given graph having a center node containing `0` or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.

The image below shows star graphs with `3` and `4` neighbors respectively, centered at the blue node.
![](https://assets.leetcode.com/uploads/2022/11/07/max-star-sum-descdrawio.png)
The **star sum** is the sum of the values of all the nodes present in the star graph.

Given an integer `k`, return *the **maximum star sum** of a star graph containing **at most*** `k` *edges.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/11/07/max-star-sum-example1drawio.png)

```

**Input:** vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
**Output:** 16
**Explanation:** The above diagram represents the input graph.
The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and 4.
It can be shown it is not possible to get a star graph with a sum greater than 16.

```

**Example 2:**

```

**Input:** vals = [-5], edges = [], k = 0
**Output:** -5
**Explanation:** There is only one possible star graph, which is node 0 itself.
Hence, we return -5.

```

**Constraints:**
* `n == vals.length`
* `1 <= n <= 105`
* `-104 <= vals[i] <= 104`
* `0 <= edges.length <= min(n * (n - 1) / 2``, 105)`
* `edges[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* `0 <= k <= n - 1`


<br>

### Hints

- A star graph doesn’t necessarily include all of its neighbors.
- For each node, sort its neighbors in descending order and take k max valued neighbors.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxStarSum (vector <int>& vals, vector <vector <int>>& edges, int k) {
      int n = vals.size();
      std::vector <std::vector <int>> graph (n);
      
      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      std::vector <int> use;
      int max = -(1 << 30);
      
      for (int i = 0; i < n; ++i) {
        for (int j: graph[i])
          use.push_back(vals[j]);
        
        std::sort(use.rbegin(), use.rend());
        int count = 0, index = 0, sum = vals[i];
        
        while (count < k and index < (int)use.size()) {
          if (use[index] < 0)
            break;
          sum += use[index];
          ++index;
          ++count;
        }
        
        max = std::max(max, sum);
        use.clear();
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 5826
- total submissions: 17644
- acceptance rate: 33.0%
- likes: 73
- dislikes: 8

<br>

### Similar Problems

- [Number Of Ways To Reconstruct A Tree](https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree) (Hard)
- [Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph) (Easy)
