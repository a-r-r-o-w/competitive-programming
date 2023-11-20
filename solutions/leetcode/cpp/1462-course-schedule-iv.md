# [1462] Course Schedule IV

**[depth-first-search, breadth-first-search, graph, topological-sort]**

### Statement

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `ai` first if you want to take course `bi`.

* For example, the pair `[0, 1]` indicates that you have to take course `0` before you can take course `1`.



Prerequisites can also be **indirect**. If course `a` is a prerequisite of course `b`, and course `b` is a prerequisite of course `c`, then course `a` is a prerequisite of course `c`.

You are also given an array `queries` where `queries[j] = [uj, vj]`. For the `jth` query, you should answer whether course `uj` is a prerequisite of course `vj` or not.

Return *a boolean array* `answer`*, where* `answer[j]` *is the answer to the* `jth` *query.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2021/05/01/courses4-1-graph.jpg)

```

**Input:** numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
**Output:** [false,true]
**Explanation:** The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

```

**Example 2:**

```

**Input:** numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
**Output:** [false,false]
**Explanation:** There are no prerequisites, and each course is independent.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/05/01/courses4-3-graph.jpg)

```

**Input:** numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
**Output:** [true,true]

```

**Constraints:**
* `2 <= numCourses <= 100`
* `0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)`
* `prerequisites[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`
* All the pairs `[ai, bi]` are **unique**.
* The prerequisites graph has no cycles.
* `1 <= queries.length <= 104`
* `0 <= ui, vi <= n - 1`
* `ui != vi`


<br>

### Hints

- Imagine if the courses are nodes of a graph. We need to build an array isReachable[i][j].
- Start a bfs from each course i and assign for each course j you visit isReachable[i][j] = True.
- Answer the queries from the isReachable array.

<br>

### Solution

**Floyd Warshall**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <bool> checkIfPrerequisite (int n, vector <vector <int>>& prerequisites, vector <vector <int>>& queries) {
      std::vector <std::vector <bool>> is_reachable (n, std::vector <bool> (n));
      
      for (auto &x: prerequisites)
        is_reachable[x[0]][x[1]] = true;
      
      for (int i = 0; i < n; ++i)
        is_reachable[i][i] = true;
      
      for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j)
            is_reachable[i][j] = is_reachable[i][j] or (is_reachable[i][k] and is_reachable[k][j]);
        }
      }
      
      int m = queries.size();
      std::vector <bool> ans (m);
      
      for (int i = 0; i < m; ++i)
        ans[i] = is_reachable[queries[i][0]][queries[i][1]];
      
      return ans;
    }
};
```

**Finding reachable nodes for every node using BFS**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <bool> checkIfPrerequisite (int n, vector <vector <int>>& prerequisites, vector <vector <int>>& queries) {
      std::vector <std::vector <bool>> is_reachable (n, std::vector <bool> (n));
      std::vector <std::vector <int>> graph (n);
      std::queue <int> q;
      std::vector <bool> visited (n);
      
      for (auto &x: prerequisites)
        graph[x[0]].push_back(x[1]);
      
      for (int i = 0; i < n; ++i) {
        q.push(i);
        visited[i] = true;
        is_reachable[i][i] = true;
        
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          
          for (int v: graph[u]) {
            if (!visited[v]) {
              q.push(v);
              visited[v] = true;
              is_reachable[i][v] = true;
            }
          }
        }
        
        for (int j = 0; j < n; ++j)
          visited[j] = false;
      }
      
      int m = queries.size();
      std::vector <bool> ans (m);
      
      for (int i = 0; i < m; ++i)
        ans[i] = is_reachable[queries[i][0]][queries[i][1]];
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 34610
- total submissions: 71478
- acceptance rate: 48.4%
- likes: 911
- dislikes: 50

<br>

### Similar Problems

None
