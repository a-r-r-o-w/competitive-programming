# [1203] Sort Items by Groups Respecting Dependencies

**[depth-first-search, breadth-first-search, graph, topological-sort]**

### Statement

There are`n`items eachbelonging to zero or one of`m`groups where `group[i]`is the group that the `i`-th item belongs to and it's equal to `-1`if the `i`-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

* The items that belong to the same group are next to each other in the sorted list.
* There are somerelationsbetween these items where`beforeItems[i]`is a list containing all the items that should come before the`i`-th item in the sorted array (to the left of the`i`-th item).



Return any solution if there is more than one solution and return an **empty list**if there is no solution.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2019/09/11/1359_ex1.png)**

```

**Input:** n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
**Output:** [6,3,4,1,5,2,0,7]

```

**Example 2:**

```

**Input:** n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
**Output:** []
**Explanation:**This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

```

**Constraints:**
* `1 <= m <= n <= 3 * 10^4`
* `group.length == beforeItems.length == n`
* `-1 <= group[i] <= m - 1`
* `0 <= beforeItems[i].length <= n - 1`
* `0 <= beforeItems[i][j] <= n - 1`
* `i != beforeItems[i][j]`
* `beforeItems[i]`does not containduplicates elements.


<br />

### Hints

- Think of it as a graph problem.
- We need to find a topological order on the dependency graph.
- Build two graphs, one for the groups and another for the items.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> sortItems(int n, int m, vector <int>& group, vector <vector <int>>& beforeItems) {
      std::vector graph(n + m, std::vector <int>());
      std::vector <int> indegree(n + m);

      for (int i = 0; i < n; ++i) {
        if (group[i] == -1)
          continue;
        graph[n + group[i]].push_back(i);
        ++indegree[i];
      }

      for (int i = 0; i < n; ++i) {
        for (int x: beforeItems[i]) {
          int p = group[i] == -1 ? i : n + group[i];
          int q = group[x] == -1 ? x : n + group[x];
          if (p == q)
            graph[x].push_back(i), ++indegree[i];
          else
            graph[q].push_back(p), ++indegree[p];
        }
      }

      std::vector <int> order;
      order.reserve(n);

      auto dfs = [&] (auto self, int u) -> void {
        if (u < n)
          order.push_back(u);
        indegree[u] = -1;
        for (int v: graph[u]) {
          --indegree[v];
          if (indegree[v] == 0)
            self(self, v);
        }
      };

      for (int i = 0; i < n + m; ++i) {
        if (indegree[i] == 0)
          dfs(dfs, i);
      }

      if ((int)order.size() < n)
        return {};

      return order;
    }
};
```

<br />

### Statistics

- total accepted: 28509
- total submissions: 46723
- acceptance rate: 61.0%
- likes: 1168
- dislikes: 187

<br />

### Similar Problems

None
