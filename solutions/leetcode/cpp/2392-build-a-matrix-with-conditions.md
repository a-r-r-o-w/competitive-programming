# [2392] Build a Matrix With Conditions

**[array, graph, topological-sort, matrix]**

### Statement

You are given a **positive** integer `k`. You are also given:

* a 2D integer array `rowConditions` of size `n` where `rowConditions[i] = [abovei, belowi]`, and
* a 2D integer array `colConditions` of size `m` where `colConditions[i] = [lefti, righti]`.



The two arrays contain integers from `1` to `k`.

You have to build a `k x k` matrix that contains each of the numbers from `1` to `k` **exactly once**. The remaining cells should have the value `0`.

The matrix should also satisfy the following conditions:

* The number `abovei` should appear in a **row** that is strictly **above** the row at which the number `belowi` appears for all `i` from `0` to `n - 1`.
* The number `lefti` should appear in a **column** that is strictly **left** of the column at which the number `righti` appears for all `i` from `0` to `m - 1`.



Return ***any** matrix that satisfies the conditions*. If no answer exists, return an empty matrix.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/07/06/gridosdrawio.png)

```

**Input:** k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
**Output:** [[3,0,0],[0,0,1],[0,2,0]]
**Explanation:** The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

```

**Example 2:**

```

**Input:** k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
**Output:** []
**Explanation:** From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.

```

**Constraints:**
* `2 <= k <= 400`
* `1 <= rowConditions.length, colConditions.length <= 104`
* `rowConditions[i].length == colConditions[i].length == 2`
* `1 <= abovei, belowi, lefti, righti <= k`
* `abovei != belowi`
* `lefti != righti`


<br>

### Hints

- Can you think of the problem in terms of graphs?
- What algorithm allows you to find the order of nodes in a graph?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> buildMatrix (int k, vector <vector <int>>& rowConditions, vector <vector <int>>& colConditions) {
      int n = rowConditions.size(), m = colConditions.size();
      std::vector <std::set <int>> graph1 (k), graph2 (k);
      
      for (int i = 0; i < n; ++i) {
        auto &row = rowConditions[i];
        --row[0];
        --row[1];
        graph1[row[0]].insert(row[1]);
      }
      
      for (int i = 0; i < m; ++i) {
        auto &col = colConditions[i];
        --col[0];
        --col[1];
        graph2[col[0]].insert(col[1]);
      }
      
      std::vector <int> visited1 (k), visited2 (k);
      std::vector <int> order1, order2;
      bool has_cycle1 = false, has_cycle2 = false;
      
      auto dfs = [] (auto self, auto &graph, auto &visited, auto &order, auto &has_cycle, int u) -> void {
        visited[u] = 1;
        for (int v: graph[u]) {
          if (has_cycle)
            break;
          else if (visited[v] == 0)
            self(self, graph, visited, order, has_cycle, v);
          else if (visited[v] == 1) {
            has_cycle = true;
            return;
          }
        }
        visited[u] = 2;
        order.push_back(u);
      };
      
      for (int i = 0; i < k and not has_cycle1; ++i)
        if (visited1[i] == 0)
          dfs(dfs, graph1, visited1, order1, has_cycle1, i);
      if (has_cycle1)
        return {};
      
      for (int i = 0; i < k and not has_cycle2; ++i)
        if (visited2[i] == 0)
          dfs(dfs, graph2, visited2, order2, has_cycle2, i);
      if (has_cycle2)
        return {};
      
      std::vector <std::vector <int>> ans (k, std::vector <int> (k));
      std::vector <int> loc1 (k), loc2 (k);
      
      for (int i = k - 1; i >= 0; --i) {
        loc1[order1[i]] = k - i - 1;
        loc2[order2[i]] = k - i - 1;
      }
      
      for (int i = 0; i < k; ++i)
        ans[loc1[i]][loc2[i]] = i + 1;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 9901
- total submissions: 16730
- acceptance rate: 59.2%
- likes: 563
- dislikes: 3

<br>

### Similar Problems

- [Course Schedule](https://leetcode.com/problems/course-schedule) (Medium)
- [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) (Medium)
- [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states) (Medium)
- [Loud and Rich](https://leetcode.com/problems/loud-and-rich) (Medium)
