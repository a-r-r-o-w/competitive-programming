# [1514] Path with Maximum Probability

**[array, graph, heap-priority-queue, shortest-path]**

### Statement

You are given an undirected weighted graph of`n`nodes (0-indexed), represented by an edge list where`edges[i] = [a, b]`is an undirected edge connecting the nodes`a`and`b`with a probability of success of traversing that edge`succProb[i]`.

Given two nodes`start`and`end`, find the path with the maximum probability of success to go from`start`to`end`and return its success probability.

If there is no path from`start`to`end`, **return0**. Your answer will be accepted if it differs from the correct answer by at most **1e-5**.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png)**

```

**Input:** n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
**Output:** 0.25000
**Explanation:**There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2019/09/20/1558_ex2.png)**

```

**Input:** n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
**Output:** 0.30000

```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2019/09/20/1558_ex3.png)**

```

**Input:** n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
**Output:** 0.00000
**Explanation:**There is no path between 0 and 2.

```

**Constraints:**
* `2 <= n <= 10^4`
* `0 <= start, end < n`
* `start != end`
* `0 <= a, b < n`
* `a != b`
* `0 <= succProb.length == edges.length <= 2*10^4`
* `0 <= succProb[i] <= 1`
* There is at most one edge between every two nodes.


<br />

### Hints

- Multiplying probabilities will result in precision errors.
- Take log probabilities to sum up numbers instead of multiplying them.
- Use Dijkstra's algorithm to find the minimum path between the two nodes after negating all costs.

<br />

### Solution

```cpp
class Solution {
  public:
    double maxProbability (int n, vector <vector <int>>& edges, vector <double>& succProb, int start, int end) {
      std::vector graph (n, std::vector <std::pair <int, long double>> ());
      int index = 0;

      for (auto &e: edges) {
        graph[e[0]].emplace_back(e[1], succProb[index]);
        graph[e[1]].emplace_back(e[0], succProb[index]);
        ++index;
      }

      std::vector <long double> dist (n);
      std::queue <int> q;

      dist[start] = 1;
      q.push(start);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &[v, w]: graph[u]) {
          long double p = w * dist[u];
          if (p > dist[v]) {
            dist[v] = p;
            q.push(v);
          }
        }
      }

      return dist[end];
    }
};
```

<br />

### Statistics

- total accepted: 106737
- total submissions: 196486
- acceptance rate: 54.3%
- likes: 2729
- dislikes: 59

<br />

### Similar Problems

- [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) (Medium)
