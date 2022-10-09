# [797] All Paths From Source to Target

**[backtracking, depth-first-search, breadth-first-search, graph]**

### Statement

Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)

```

**Input:** graph = [[1,2],[3],[3],[]]
**Output:** [[0,1,3],[0,2,3]]
**Explanation:** There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg)

```

**Input:** graph = [[4,3,1],[3,2,4],[3],[4],[]]
**Output:** [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

```

**Constraints:**
* `n == graph.length`
* `2 <= n <= 15`
* `0 <= graph[i][j] < n`
* `graph[i][j] != i` (i.e., there will be no self-loops).
* All the elements of `graph[i]` are **unique**.
* The input graph is **guaranteed** to be a **DAG**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> allPathsSourceTarget (vector <vector <int>>& graph) {
      std::vector <std::vector <int>> paths;
      std::vector <int> path;
      int n = graph.size();
      
      auto dfs = [&] (auto self, int u) -> void {
        path.push_back(u);
        
        if (u == n - 1)
          paths.push_back(path);
        
        for (int v: graph[u])
          self(self, v);
        
        path.pop_back();
      };
      
      dfs(dfs, 0);
      
      return paths;
    }
};
```

<br>

### Statistics

- total accepted: 309315
- total submissions: 381129
- acceptance rate: 81.2%
- likes: 4551
- dislikes: 120

<br>

### Similar Problems

- [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) (Medium)
- [Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid) (Hard)
