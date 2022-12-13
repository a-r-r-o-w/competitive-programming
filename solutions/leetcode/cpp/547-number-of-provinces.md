# [547] Number of Provinces

**[depth-first-search, breadth-first-search, union-find, graph]**

### Statement

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return *the total number of **provinces***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg)

```

**Input:** isConnected = [[1,1,0],[1,1,0],[0,0,1]]
**Output:** 2

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg)

```

**Input:** isConnected = [[1,0,0],[0,1,0],[0,0,1]]
**Output:** 3

```

**Constraints:**
* `1 <= n <= 200`
* `n == isConnected.length`
* `n == isConnected[i].length`
* `isConnected[i][j]` is `1` or `0`.
* `isConnected[i][i] == 1`
* `isConnected[i][j] == isConnected[j][i]`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int findCircleNum (vector <vector <int>>& isConnected) {
      int n = isConnected.size();
      
      auto dfs = [&] (auto self, int u, int p) -> void {
        isConnected[u][u] = -1;
        
        for (int i = 0; i < n; ++i) {
          if (i == p or isConnected[u][i] <= 0)
            continue;
          isConnected[u][i] = -1;
          isConnected[i][u] = -1;
          self(self, i, u);
        }
      };
      
      int count = 0;
      
      for (int i = 0; i < n; ++i) {
        if (isConnected[i][i] == 1) {
          dfs(dfs, i, -1);
          ++count;
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 556918
- total submissions: 879708
- acceptance rate: 63.3%
- likes: 6507
- dislikes: 270

<br>

### Similar Problems

- [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph) (Medium)
- [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin) (Easy)
- [Sentence Similarity](https://leetcode.com/problems/sentence-similarity) (Easy)
- [Sentence Similarity II](https://leetcode.com/problems/sentence-similarity-ii) (Medium)
- [The Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends) (Medium)
- [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs) (Medium)
