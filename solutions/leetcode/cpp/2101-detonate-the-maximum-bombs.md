# [2101] Detonate the Maximum Bombs

**[array, math, depth-first-search, breadth-first-search, graph, geometry]**

### Statement

You are given a list of bombs. The **range** of a bomb is defined as the area where its effect can be felt. This area is in the shape of a **circle** with the center as the location of the bomb.

The bombs are represented by a **0-indexed** 2D integer array `bombs` where `bombs[i] = [xi, yi, ri]`. `xi` and `yi` denote the X-coordinate and Y-coordinate of the location of the `i^th` bomb, whereas `ri` denotes the **radius** of its range.

You may choose to detonate a **single** bomb. When a bomb is detonated, it will detonate **all bombs** that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of `bombs`, return *the **maximum** number of bombs that can be detonated if you are allowed to detonate **only one** bomb*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-3.png)

```

**Input:** bombs = [[2,1,3],[6,1,4]]
**Output:** 2
**Explanation:**
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-2.png)

```

**Input:** bombs = [[1,1,5],[10,10,5]]
**Output:** 1
**Explanation:**Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/11/07/desmos-eg1.png)

```

**Input:** bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
**Output:** 5
**Explanation:**
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.

```

**Constraints:**
* `1 <= bombs.length<= 100`
* `bombs[i].length == 3`
* `1 <= xi, yi, ri <= 10^5`


<br />

### Hints

- How can we model the relationship between different bombs? Can "graphs" help us?
- Bombs are nodes and are connected to other bombs in their range by directed edges.
- If we know which bombs will be affected when any bomb is detonated, how can we find the total number of bombs that will be detonated if we start from a fixed bomb?
- Run a Depth First Search (DFS) from every node, and all the nodes it reaches are the bombs that will be detonated.

<br />

### Solution

```cpp
class Solution {
  public:
    int maximumDetonation (vector <vector <int>>& bombs) {
      int n = bombs.size();
      std::vector <std::vector <int>> graph (n);

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == j)
            continue;
          int64_t x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
          int64_t x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
          int64_t x = x1 - x2, y = y1 - y2;
          int64_t dist = x * x + y * y, r = r1 * r1;
          if (dist <= r)
            graph[i].push_back(j);
        }
      }

      std::unordered_set <int> visited;

      auto dfs = [&] (auto self, int u) -> int {
        visited.insert(u);
        int count = 1;
        for (int v: graph[u]) {
          if (not visited.count(v))
            count += self(self, v);
        }
        return count;
      };

      int ans = 0;
      for (int i = 0; i < n; ++i) {
        ans = std::max(ans, dfs(dfs, i));
        visited.clear();
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 70661
- total submissions: 143176
- acceptance rate: 49.4%
- likes: 2217
- dislikes: 117

<br />

### Similar Problems

- [Minesweeper](https://leetcode.com/problems/minesweeper) (Medium)
- [Number of Provinces](https://leetcode.com/problems/number-of-provinces) (Medium)
- [Max Area of Island](https://leetcode.com/problems/max-area-of-island) (Medium)
- [Rotting Oranges](https://leetcode.com/problems/rotting-oranges) (Medium)
