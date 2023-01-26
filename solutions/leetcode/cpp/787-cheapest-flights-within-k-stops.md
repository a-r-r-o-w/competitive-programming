# [787] Cheapest Flights Within K Stops

**[dynamic-programming, depth-first-search, breadth-first-search, graph, heap-priority-queue, shortest-path]**

### Statement

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return ***the cheapest price** from* `src` *to* `dst` *with at most* `k` *stops.* If there is no such route, return`-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png)

```

**Input:** n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
**Output:** 700
**Explanation:**
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png)

```

**Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
**Output:** 200
**Explanation:**
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png)

```

**Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
**Output:** 500
**Explanation:**
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

```

**Constraints:**
* `1 <= n <= 100`
* `0 <= flights.length <= (n * (n - 1) / 2)`
* `flights[i].length == 3`
* `0 <= fromi, toi < n`
* `fromi != toi`
* `1 <= pricei <= 104`
* There will not be any multiple flights between two cities.
* `0 <= src, dst, k < n`
* `src != dst`


<br>

### Hints

None

<br>

### Solution

Dijkstra

```cpp
class Solution {
  public:
    int findCheapestPrice (int n, vector <vector <int>>& flights, int src, int dst, int k) {
      std::vector <std::vector <std::array <int, 2>>> graph (n);
      std::vector <int> dist (n, 1 << 30);
      std::priority_queue <std::array <int, 3>> q;

      for (auto &f: flights)
        graph[f[0]].push_back({f[1], f[2]});
      q.push({0, 0, src});

      while (!q.empty()) {
        auto [cost, depth, u] = q.top();
        q.pop();

        if (u == dst)
          return -cost;
        if (depth > k or depth > dist[u])
          continue;
        dist[u] = depth;

        for (auto &[v, w]: graph[u])
          q.push({cost - w, depth + 1, v});
      }

      return -1;
    }
};
```

Bellman Ford

```cpp
class Solution {
  public:
    int findCheapestPrice (int n, vector <vector <int>>& flights, int src, int dst, int k) {
      constexpr int inf32 = 1 << 30;
      std::vector <int> dist (n, inf32);
      dist[src] = 0;

      for (int i = 0; i < k + 1; ++i) {
        auto newdist = dist;

        for (auto &f: flights) {
          if (dist[f[0]] == inf32 or newdist[f[1]] < dist[f[0]] + f[2])
            continue;
          newdist[f[1]] = dist[f[0]] + f[2];
        }

        dist = newdist;
      }

      return dist[dst] == inf32 ? -1 : dist[dst];
    }
};
```

<br>

### Statistics

- total accepted: 306018
- total submissions: 851179
- acceptance rate: 36.0%
- likes: 6552
- dislikes: 297

<br>

### Similar Problems

- [Maximum Vacation Days](https://leetcode.com/problems/maximum-vacation-days) (Hard)
- [Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts) (Medium)
