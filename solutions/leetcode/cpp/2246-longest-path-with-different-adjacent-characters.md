# [2246] Longest Path With Different Adjacent Characters

**[array, string, tree, depth-first-search, graph, topological-sort]**

### Statement

You are given a **tree** (i.e. a connected, undirected graph that has no cycles) **rooted** at node `0` consisting of `n` nodes numbered from `0` to `n - 1`. The tree is represented by a **0-indexed** array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node `0` is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

Return *the length of the **longest path** in the tree such that no pair of **adjacent** nodes on the path have the same character assigned to them.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/03/25/testingdrawio.png)

```

**Input:** parent = [-1,0,0,1,1,2], s = "abacbe"
**Output:** 3
**Explanation:** The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
It can be proven that there is no longer path that satisfies the conditions. 

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/03/25/graph2drawio.png)

```

**Input:** parent = [-1,0,0,0], s = "aabc"
**Output:** 3
**Explanation:** The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.

```

**Constraints:**
* `n == parent.length == s.length`
* `1 <= n <= 105`
* `0 <= parent[i] <= n - 1` for all `i >= 1`
* `parent[0] == -1`
* `parent` represents a valid tree.
* `s` consists of only lowercase English letters.


<br>

### Hints

- Do a DFS from the root. At each node, calculate the longest path we can make from two branches of that subtree.
- To do that, we need to find the length of the longest path from each of the node’s children.

<br>

### Solution

```cpp
class Solution {
  public:
    int longestPath (vector <int>& parent, string s) {
      int n = s.length(), ans = 1;
      std::vector <std::vector <int>> graph (n);
      std::vector <int> depth (n);

      for (int i = 1; i < n; ++i) {
        graph[i].push_back(parent[i]);
        graph[parent[i]].push_back(i);
      }

      auto dfs = [&] (auto self, int u, int d, int p) -> int {
        std::vector <int> maxdepth;
        depth[u] = d;
        
        for (int v: graph[u]) {
          if (v != p) {
            int x = self(self, v, d + 1, u);
            if (s[u] != s[v])
              maxdepth.push_back(x);
          }
        }
        
        std::sort(maxdepth.begin(), maxdepth.end());
        int m = maxdepth.empty() ? d : maxdepth.back();
        int k = 2, path = 1;

        while (k > 0 and not maxdepth.empty()) {
          --k;
          path += maxdepth.back() - d;
          maxdepth.pop_back();
        }
        ans = std::max(ans, path);

        return m;
      };

      dfs(dfs, 0, 1, -1);

      return ans;
    }
};
```

Without using Vector+Sorting or Priority Queue

```cpp
class Solution {
  public:
    int longestPath (vector <int>& parent, string s) {
      int n = s.length(), ans = 1;
      std::vector <std::vector <int>> graph (n);

      for (int i = 1; i < n; ++i) {
        graph[i].push_back(parent[i]);
        graph[parent[i]].push_back(i);
      }

      auto dfs = [&] (auto self, int u, int d, int p) -> int {
        int max1 = -1, max2 = -1;
        
        for (int v: graph[u]) {
          if (v != p) {
            int x = self(self, v, d + 1, u);
            
            if (s[u] != s[v]) {
              if (x > max2)
                max2 = x;
              if (max2 > max1)
                std::swap(max1, max2);
            }
          }
        }
        
        int m = max1 == -1 and max2 == -1 ? d : max1;
        int path = 1 + (max1 == -1 ? 0 : max1 - d) + (max2 == -1 ? 0 : max2 - d);
        ans = std::max(ans, path);

        return m;
      };

      dfs(dfs, 0, 1, -1);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 26147
- total submissions: 52024
- acceptance rate: 50.3%
- likes: 1089
- dislikes: 24

<br>

### Similar Problems

- [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) (Easy)
- [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path) (Medium)
- [Choose Edges to Maximize Score in a Tree](https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree) (Medium)
