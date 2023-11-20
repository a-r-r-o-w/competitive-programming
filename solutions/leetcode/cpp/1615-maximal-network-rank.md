# [1615] Maximal Network Rank

**[graph]**

### Statement

There is an infrastructure of `n` cities with some number of `roads` connecting these cities. Each `roads[i] = [ai, bi]` indicates that there is a bidirectional road between cities `ai` and `bi`.

The **network rank**of **two different cities** is defined as the total number of**directly** connected roads to **either** city. If a road is directly connected to both cities, it is only counted **once**.

The **maximal network rank** of the infrastructure is the **maximum network rank** of all pairs of different cities.

Given the integer `n` and the array `roads`, return *the **maximal network rank** of the entire infrastructure*.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2020/09/21/ex1.png)**

```

**Input:** n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
**Output:** 4
**Explanation:** The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2020/09/21/ex2.png)**

```

**Input:** n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
**Output:** 5
**Explanation:** There are 5 roads that are connected to cities 1 or 2.

```

**Example 3:**

```

**Input:** n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
**Output:** 5
**Explanation:** The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.

```

**Constraints:**
* `2 <= n <= 100`
* `0 <= roads.length <= n * (n - 1) / 2`
* `roads[i].length == 2`
* `0 <= ai, bi<= n-1`
* `ai!=bi`
* Eachpair of cities has **at most one** road connecting them.


<br>

### Hints

- Try every pair of different cities and calculate its network rank.
- The network rank of two vertices is <i>almost</i> the sum of their degrees.
- How can you efficiently check if there is a road connecting two different cities?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximalNetworkRank (int n, vector<vector<int>>& roads) {
      std::unordered_set <int> have;
      std::vector <int> degree (n);
      
      for (auto &x: roads) {
        int min = std::min(x[0], x[1]);
        int max = std::max(x[0], x[1]);
        have.insert((min << 16) + max);
        ++degree[x[0]];
        ++degree[x[1]];
      }
      
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          ans = std::max <int> (ans, degree[i] + degree[j] - have.count((i << 16) + j));
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 46713
- total submissions: 80943
- acceptance rate: 57.7%
- likes: 824
- dislikes: 149

<br>

### Similar Problems

None
