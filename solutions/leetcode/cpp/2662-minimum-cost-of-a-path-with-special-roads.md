# [2662] Minimum Cost of a Path With Special Roads



### Statement

You are given an array `start` where `start = [startX, startY]` represents your initial position `(startX, startY)` in a 2D space. You are also given the array `target` where `target = [targetX, targetY]` represents your target position `(targetX, targetY)`.

The cost of going from a position `(x1, y1)` to any other position in the space `(x2, y2)` is `|x2 - x1| + |y2 - y1|`.

There are also some special roads. You are given a 2D array `specialRoads` where `specialRoads[i] = [x1i, y1i, x2i, y2i, costi]` indicates that the `i^th` special road can take you from `(x1i, y1i)` to `(x2i, y2i)` with a cost equal to `costi`. You can use each special road any number of times.

Return *the minimum cost required to go from* `(startX, startY)` to `(targetX, targetY)`.


**Example 1:**

```

**Input:** start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
**Output:** 5
**Explanation:** The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.

```

**Example 2:**

```

**Input:** start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
**Output:** 7
**Explanation:** It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.

```

**Constraints:**
* `start.length == target.length == 2`
* `1 <= startX <= targetX <= 10^5`
* `1 <= startY <= targetY <= 10^5`
* `1 <= specialRoads.length <= 200`
* `specialRoads[i].length == 5`
* `startX <= x1i, x2i <= targetX`
* `startY <= y1i, y2i <= targetY`
* `1 <= costi <= 10^5`


<br />

### Hints

- It can be proven that it is optimal to go only to the positions that are either the start or the end of a special road or the target position.
- Consider all positions given to you as nodes in a graph, and the edges of the graph are the special roads.
- Now the problem is equivalent to finding the shortest path in a directed graph.

<br />

### Solution

```cpp
class Solution {
  public:
    int minimumCost (vector <int>& start, vector <int>& target, vector <vector <int>>& specialRoads) {
      std::map <std::pair <int, int>, int> compress;
      std::map <int, std::pair <int, int>> decompress;
      int n = specialRoads.size();
      
      compress[{start[0], start[1]}];
      compress[{target[0], target[1]}];
      for (int i = 0; i < n; ++i) {
        compress[{specialRoads[i][0], specialRoads[i][1]}];
        compress[{specialRoads[i][2], specialRoads[i][3]}];
      }
      
      int size = 0;
      for (auto &[p, q]: compress) {
        q = size++;
        decompress[q] = p;
      }
      
      std::vector <std::vector <std::pair <int, int64_t>>> graph (size);
      int s = compress[{start[0], start[1]}], t = compress[{target[0], target[1]}];
      
      for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
          auto &[a, b] = decompress[i];
          auto &[p, q] = decompress[j];
          int cost = std::abs(a - p) + std::abs(b - q);
          graph[i].emplace_back(j, cost);
          graph[j].emplace_back(i, cost);
        }
      }
      
      for (int i = 0; i < n; ++i) {
        int a = specialRoads[i][0], b = specialRoads[i][1];
        int p = specialRoads[i][2], q = specialRoads[i][3];
        int x = compress[{a, b}];
        int y = compress[{p, q}];
        int c = std::min(specialRoads[i][4], std::abs(a - p) + std::abs(b - q));
        graph[x].emplace_back(y, c);
      }
      
      const int inf32 = 1 << 30;
      std::priority_queue <std::pair <int, int64_t>> pq;
      std::vector <int64_t> dist (size, inf32);
      
      pq.emplace(s, 0);
      dist[s] = 0;
      
      while (!pq.empty()) {
        auto [u, c] = pq.top();
        pq.pop();
        if (-c != dist[u])
          continue;
        for (auto &[v, w]: graph[u]) {
          if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.emplace(v, -dist[v]);
          }
        }
      }
      
      return dist[t];
    }
};
```

<br />

### Statistics

- total accepted: 1675
- total submissions: 8932
- acceptance rate: 18.8%
- likes: 34
- dislikes: 35

<br />

### Similar Problems

- [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum) (Medium)
- [Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node) (Medium)
