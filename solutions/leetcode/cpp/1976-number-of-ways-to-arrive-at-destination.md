# [1976] Number of Ways to Arrive at Destination

**[dynamic-programming, graph, topological-sort, shortest-path]**

### Statement

You are in a city that consists of `n` intersections numbered from `0` to `n - 1` with **bi-directional** roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer `n` and a 2D integer array `roads` where `roads[i] = [ui, vi, timei]` means that there is a road between intersections `ui` and `vi` that takes `timei` minutes to travel. You want to know in how many ways you can travel from intersection `0` to intersection `n - 1` in the **shortest amount of time**.

Return *the **number of ways** you can arrive at your destination in the **shortest amount of time***. Since the answer may be large, return it **modulo** `109 + 7`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/17/graph2.png)

```

**Input:** n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
**Output:** 4
**Explanation:** The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

```

**Example 2:**

```

**Input:** n = 2, roads = [[1,0,10]]
**Output:** 1
**Explanation:** There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.

```

**Constraints:**
* `1 <= n <= 200`
* `n - 1 <= roads.length <= n * (n - 1) / 2`
* `roads[i].length == 3`
* `0 <= ui, vi <= n - 1`
* `1 <= timei <= 109`
* `ui != vi`
* There is at most one road connecting any two intersections.
* You can reach any intersection from any other intersection.


<br>

### Hints

- First use any shortest path algorithm to get edges where dist[u] + weight = dist[v], here dist[x] is the shortest distance between node 0 and x
- Using those edges only the graph turns into a dag now we just need to know the number of ways to get from node 0 to node n - 1 on a dag using dp

<br>

### Solution

```cpp
class Solution {
  public:
    int countPaths (int n, vector <vector <int>>& roads) {
      const int mod = 1000000007;
      const int64_t inf64 = (int64_t)1 << 60;
      
      std::vector <std::vector <std::pair <int, int>>> graph (n);
      std::vector <std::pair <int64_t, int64_t>> dp (n, {inf64, 0});
      
      for (auto &e: roads) {
        graph[e[0]].emplace_back(e[1], e[2]);
        graph[e[1]].emplace_back(e[0], e[2]);
      }
      
      std::priority_queue <std::pair <int64_t, int>> pq;
      
      dp[0] = {0, 1};
      pq.push({-0, 0});
      
      while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();
        
        if (-c != dp[u].first)
          continue;
        
        for (auto &[v, w]: graph[u]) {
          if (dp[u].first + w < dp[v].first) {
            dp[v] = {dp[u].first + w, dp[u].second};
            pq.emplace(-dp[v].first, v);
          }
          else if (dp[u].first + w == dp[v].first) {
            dp[v].second += dp[u].second;
            if (dp[v].second >= mod)
              dp[v].second -= mod;
          }
        }
      }
      
      return dp[n - 1].second;
    }
};
```

<br>

### Statistics

- total accepted: 22575
- total submissions: 69883
- acceptance rate: 32.3%
- likes: 1437
- dislikes: 43

<br>

### Similar Problems

- [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) (Medium)
- [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability) (Medium)
- [Second Minimum Time to Reach Destination](https://leetcode.com/problems/second-minimum-time-to-reach-destination) (Hard)
