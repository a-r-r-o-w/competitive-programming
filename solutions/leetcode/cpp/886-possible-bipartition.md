# [886] Possible Bipartition

**[depth-first-search, breadth-first-search, union-find, graph]**

### Statement

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where `dislikes[i] = [ai, bi]` indicates that the person labeled `ai` does not like the person labeled `bi`, return `true` *if it is possible to split everyone into two groups in this way*.


**Example 1:**

```

**Input:** n = 4, dislikes = [[1,2],[1,3],[2,4]]
**Output:** true
**Explanation:** group1 [1,4] and group2 [2,3].

```

**Example 2:**

```

**Input:** n = 3, dislikes = [[1,2],[1,3],[2,3]]
**Output:** false

```

**Example 3:**

```

**Input:** n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
**Output:** false

```

**Constraints:**
* `1 <= n <= 2000`
* `0 <= dislikes.length <= 104`
* `dislikes[i].length == 2`
* `1 <= dislikes[i][j] <= n`
* `ai < bi`
* All the pairs of `dislikes` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool possibleBipartition (int n, vector <vector <int>>& dislikes) {
      std::vector <std::vector <int>> graph (n);

      for (auto &e: dislikes) {
        --e[0]; --e[1];
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      std::vector <int> color (n, -1);
      bool possible = true;

      auto dfs = [&] (auto self, int u, int c) -> void {
        color[u] = c;

        for (int v: graph[u]) {
          if (color[v] == -1)
            self(self, v, c ^ 1);
          else if (color[v] == c)
            possible = false;
        }
      };

      for (int i = 0; i < n; ++i) {
        if (color[i] == -1)
          dfs(dfs, i, 0);
      }

      return possible;
    }
};
```

<br>

### Statistics

- total accepted: 131404
- total submissions: 270108
- acceptance rate: 48.6%
- likes: 2925
- dislikes: 65

<br>

### Similar Problems

None
