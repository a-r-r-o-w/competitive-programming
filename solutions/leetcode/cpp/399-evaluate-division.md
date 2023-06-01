# [399] Evaluate Division

**[array, depth-first-search, breadth-first-search, union-find, graph, shortest-path]**

### Statement

You are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [Ai, Bi]` and `values[i]` represent the equation `Ai / Bi = values[i]`. Each `Ai` or `Bi` is a string that represents a single variable.

You are also given some `queries`, where `queries[j] = [Cj, Dj]` represents the `j^th` query where you must find the answer for `Cj / Dj = ?`.

Return *the answers to all queries*. If a single answer cannot be determined, return `-1.0`.

**Note:** The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.


**Example 1:**

```

**Input:** equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
**Output:** [6.00000,0.50000,-1.00000,1.00000,-1.00000]
**Explanation:** 
Given: *a / b = 2.0*, *b / c = 3.0*
queries are: *a / c = ?*, *b / a = ?*, *a / e = ?*, *a / a = ?*, *x / x = ?*
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

```

**Example 2:**

```

**Input:** equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
**Output:** [3.75000,0.40000,5.00000,0.20000]

```

**Example 3:**

```

**Input:** equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
**Output:** [0.50000,2.00000,-1.00000,-1.00000]

```

**Constraints:**
* `1 <= equations.length <= 20`
* `equations[i].length == 2`
* `1 <= Ai.length, Bi.length <= 5`
* `values.length == equations.length`
* `0.0 < values[i] <= 20.0`
* `1 <= queries.length <= 20`
* `queries[i].length == 2`
* `1 <= Cj.length, Dj.length <= 5`
* `Ai, Bi, Cj, Dj` consist of lower case English letters and digits.


<br />

### Hints

- Do you recognize this as a graph problem?

<br />

### Solution

```cpp
class Solution {
  public:
    vector <double> calcEquation (vector <vector <string>>& equations, vector <double>& values, vector <vector <string>>& queries) {
      int n = equations.size();
      std::unordered_map <std::string, std::unordered_map <std::string, double>> graph;
      std::vector <double> ans;
      std::queue <std::pair <std::string, double>> q;
      std::unordered_set <std::string> variables;
      std::unordered_set <std::string> visited (26);

      for (int i = 0; i < n; ++i) {
        auto &e = equations[i];
        graph[e[0]].emplace(e[1], values[i]);
        graph[e[1]].emplace(e[0], 1 / values[i]);
        variables.insert(e[0]);
        variables.insert(e[1]);
      }

      for (auto &query: queries) {
        if (not variables.count(query[0]) or not variables.count(query[1])) {
          ans.emplace_back(-1);
          continue;
        }

        bool complete = false;

        while (not q.empty())
          q.pop();
        visited.clear();
        q.emplace(query[0], 1);

        while (!q.empty()) {
          auto [u, x] = q.front();
          q.pop();

          if (u == query[1]) {
            ans.emplace_back(x);
            complete = true;
            break;
          }

          for (auto &[v, w]: graph[u]) {
            if (visited.count(v))
              continue;
            visited.insert(v);
            q.emplace(v, x * w);
          }
        }

        if (not complete)
          ans.emplace_back(-1);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 338828
- total submissions: 565628
- acceptance rate: 59.9%
- likes: 7149
- dislikes: 636

<br />

### Similar Problems

- [Check for Contradictions in Equations](https://leetcode.com/problems/check-for-contradictions-in-equations) (Hard)
