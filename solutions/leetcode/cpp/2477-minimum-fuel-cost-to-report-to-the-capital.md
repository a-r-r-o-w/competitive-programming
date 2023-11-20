# [2477] Minimum Fuel Cost to Report to the Capital

**[tree, depth-first-search, breadth-first-search, graph]**

### Statement

There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of `n` cities numbered from `0` to `n - 1` and exactly `n - 1` roads. The capital city is city `0`. You are given a 2D integer array `roads` where `roads[i] = [ai, bi]` denotes that there exists a **bidirectional road** connecting cities `ai` and `bi`.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer `seats` that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return *the minimum number of liters of fuel to reach the capital city*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/09/22/a4c380025e3ff0c379525e96a7d63a3.png)

```

**Input:** roads = [[0,1],[0,2],[0,3]], seats = 5
**Output:** 3
**Explanation:** 
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum. 
It can be proven that 3 is the minimum number of liters of fuel needed.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/16/2.png)

```

**Input:** roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
**Output:** 7
**Explanation:** 
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum. 
It can be proven that 7 is the minimum number of liters of fuel needed.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2022/09/27/efcf7f7be6830b8763639cfd01b690a.png)

```

**Input:** roads = [], seats = 1
**Output:** 0
**Explanation:** No representatives need to travel to the capital city.

```

**Constraints:**
* `1 <= n <= 10^5`
* `roads.length == n - 1`
* `roads[i].length == 2`
* `0 <= ai, bi < n`
* `ai != bi`
* `roads` represents a valid tree.
* `1 <= seats <= 10^5`


<br />

### Hints

- Can you record the size of each subtree?
- If n people meet on the same node, what is the minimum number of cars needed?

<br />

### Solution

```cpp
class Solution {
  public:
    long long minimumFuelCost (vector <vector <int>>& roads, int seats) {
      int n = roads.size() + 1;
      std::vector <std::vector <int>> graph (n);
      
      for (auto &e: roads) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      int64_t ans = 0;
      
      auto dfs = [&] (auto self, int u, int p) -> int {
        int count = 1;

        for (int v: graph[u]) {
          if (v == p)
            continue;
          count += self(self, v, u);
        }
        if (u != 0)
          ans += (count + seats - 1) / seats;
        
        return count;
      };
  
      dfs(dfs, 0, -1);
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 19003
- total submissions: 30767
- acceptance rate: 61.8%
- likes: 759
- dislikes: 24

<br />

### Similar Problems

- [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) (Easy)