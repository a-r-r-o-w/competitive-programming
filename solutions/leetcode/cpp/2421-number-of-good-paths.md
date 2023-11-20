# [2421] Number of Good Paths

**[array, tree, union-find, graph]**

### Statement

There is a tree (i.e. a connected, undirected graph with no cycles) consisting of `n` nodes numbered from `0` to `n - 1` and exactly `n - 1` edges.

You are given a **0-indexed** integer array `vals` of length `n` where `vals[i]` denotes the value of the `ith` node. You are also given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting nodes `ai` and `bi`.

A **good path** is a simple path that satisfies the following conditions:

1. The starting node and the ending node have the **same** value.
2. All nodes between the starting node and the ending node have values **less than or equal to** the starting node (i.e. the starting node's value should be the maximum value along the path).



Return *the number of distinct good paths*.

Note that a path and its reverse are counted as the **same** path. For example, `0 -> 1` is considered to be the same as `1 -> 0`. A single node is also considered as a valid path.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/08/04/f9caaac15b383af9115c5586779dec5.png)

```

**Input:** vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
**Output:** 6
**Explanation:** There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/08/04/149d3065ec165a71a1b9aec890776ff.png)

```

**Input:** vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
**Output:** 7
**Explanation:** There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2022/08/04/31705e22af3d9c0a557459bc7d1b62d.png)

```

**Input:** vals = [1], edges = []
**Output:** 1
**Explanation:** The tree consists of only one node, so there is one good path.

```

**Constraints:**
* `n == vals.length`
* `1 <= n <= 3 * 104`
* `0 <= vals[i] <= 105`
* `edges.length == n - 1`
* `edges[i].length == 2`
* `0 <= ai, bi < n`
* `ai != bi`
* `edges` represents a valid tree.


<br>

### Hints

- Can you process nodes from smallest to largest value?
- Try to build the graph from nodes with the smallest value to the largest value.
- May union find help?

<br>

### Solution

```cpp
class Solution {
  public:
    int numberOfGoodPaths (vector <int>& vals, vector <vector <int>>& edges) {
      int n = vals.size();
      std::vector <std::vector <int>> graph (n);
      std::vector <int> parent (n), rank (n);

      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);
        if (rank[u] < rank[v])
          std::swap(u, v);
        ++rank[u];
        parent[v] = u;
      };

      std::map <int, std::vector <int>> order;
      std::unordered_map <int, int> buckets;
      int64_t ans = 0;

      for (int i = 0; i < n; ++i)
        order[vals[i]].push_back(i);
      
      for (auto &[value, nodes]: order) {
        for (int u: nodes) {
          for (int v: graph[u]) {
            if (value >= vals[v])
              unite(u, v);
          }
        }

        for (int u: nodes)
          ++buckets[find(find, u)];
        for (auto &[x, y]: buckets)
          ans += int64_t(y) * (y + 1) / 2;
        buckets.clear();
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 18304
- total submissions: 36535
- acceptance rate: 50.1%
- likes: 970
- dislikes: 44

<br>

### Similar Problems

- [Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths) (Hard)
- [Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii) (Hard)
- [Longest Nice Substring](https://leetcode.com/problems/longest-nice-substring) (Easy)
- [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array) (Hard)
- [Count Pairs Of Similar Strings](https://leetcode.com/problems/count-pairs-of-similar-strings) (Easy)
