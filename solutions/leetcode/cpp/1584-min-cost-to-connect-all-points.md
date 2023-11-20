# [1584] Min Cost to Connect All Points

**[array, union-find, graph, minimum-spanning-tree]**

### Statement

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the **manhattan distance** between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.

Return *the minimum cost to make all points connected.* All points are connected if there is **exactly one** simple path between any two points.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/26/d.png)

```

**Input:** points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
**Output:** 20
**Explanation:** 
![](https://assets.leetcode.com/uploads/2020/08/26/c.png)
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

```

**Example 2:**

```

**Input:** points = [[3,12],[-2,5],[-4,1]]
**Output:** 18

```

**Constraints:**
* `1 <= points.length <= 1000`
* `-10^6 <= xi, yi <= 10^6`
* All pairs `(xi, yi)` are distinct.


<br />

### Hints

- Connect each pair of points with a weighted edge, the weight being the manhattan distance between those points.
- The problem is now the cost of minimum spanning tree in graph with above edges.

<br />

### Solution

```cpp
class Solution {
  public:
    int minCostConnectPoints (vector <vector <int>>& points) {
      std::map <std::pair <int, int>, int> compress;
      std::vector <std::tuple <int, int, int>> edges;
      int index = 0, n = points.size();

      edges.reserve(n * n);
      for (auto &point: points)
        compress[{point[0], point[1]}];
      for (auto &[x, y]: compress)
        y = index++;
      for (auto &[x, y]: compress) {
        for (auto &[p, q]: compress) {
          int distance = std::abs(x.first - p.first) + std::abs(x.second - p.second);
          edges.emplace_back(distance, y, q);
        }
      }
      
      std::vector <int> parent (index), rank (index);
      
      std::sort(edges.begin(), edges.end());
      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) -> bool {
        u = find(find, u);
        v = find(find, v);

        if (u == v)
          return true;
        if (rank[u] < rank[v])
          std::swap(u, v);
        
        parent[v] = u;
        ++rank[u];
        return false;
      };

      int64_t ans = 0;

      for (auto &[w, u, v]: edges) {
        if (!unite(u, v))
          ans += w;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 147400
- total submissions: 230703
- acceptance rate: 63.9%
- likes: 3339
- dislikes: 83

<br />

### Similar Problems

- [Minimum Number of Lines to Cover Points](https://leetcode.com/problems/minimum-number-of-lines-to-cover-points) (Medium)
