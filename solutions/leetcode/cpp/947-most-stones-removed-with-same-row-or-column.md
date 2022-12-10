# [947] Most Stones Removed with Same Row or Column

**[depth-first-search, union-find, graph]**

### Statement

On a 2D plane, we place `n` stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either **the same row or the same column** as another stone that has not been removed.

Given an array `stones` of length `n` where `stones[i] = [xi, yi]` represents the location of the `ith` stone, return *the largest possible number of stones that can be removed*.


**Example 1:**

```

**Input:** stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
**Output:** 5
**Explanation:** One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

```

**Example 2:**

```

**Input:** stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
**Output:** 3
**Explanation:** One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

```

**Example 3:**

```

**Input:** stones = [[0,0]]
**Output:** 0
**Explanation:** [0,0] is the only stone on the plane, so you cannot remove it.

```

**Constraints:**
* `1 <= stones.length <= 1000`
* `0 <= xi, yi <= 104`
* No two stones are at the same coordinate point.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int removeStones (vector <vector <int>>& stones) {
      int n = stones.size();
      std::vector <bool> visited (n);
      
      auto hash = [] (int x, int y) {
        return (x << 12) + y;
      };
      
      auto dfs = [&] (auto self, int u) -> void {
        visited[u] = true;
        int x = stones[u][0];
        int y = stones[u][1];
        
        for (int i = 0; i < n; ++i) {
          if (visited[i])
            continue;
          if (stones[i][0] != x and stones[i][1] != y)
            continue;
          self(self, i);
        }
      };
      
      int count = 0;
      
      for (int i = 0; i < n; ++i) {
        if (visited[i])
          continue;
        ++count;
        dfs(dfs, i);
      }
      
      return n - count;
    }
};
```

<br>

### Statistics

- total accepted: 123314
- total submissions: 215892
- acceptance rate: 57.1%
- likes: 3074
- dislikes: 535

<br>

### Similar Problems

None
