# [1376] Time Needed to Inform All Employees

**[tree, depth-first-search, breadth-first-search]**

### Statement

A company has `n` employees with a unique ID for each employee from `0` to `n - 1`. The head of the company is the one with `headID`.

Each employee has one direct manager given in the `manager` array where `manager[i]` is the direct manager of the `i-th` employee, `manager[headID] = -1`. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The `i-th` employee needs `informTime[i]` minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return *the number of minutes* needed to inform all the employees about the urgent news.


**Example 1:**

```

**Input:** n = 1, headID = 0, manager = [-1], informTime = [0]
**Output:** 0
**Explanation:** The head of the company is the only employee in the company.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/02/27/graph.png)

```

**Input:** n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
**Output:** 1
**Explanation:** The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

```

**Constraints:**
* `1 <= n <= 105`
* `0 <= headID < n`
* `manager.length == n`
* `0 <= manager[i] < n`
* `manager[headID] == -1`
* `informTime.length == n`
* `0 <= informTime[i] <= 1000`
* `informTime[i] == 0` if employee `i` has no subordinates.
* It is **guaranteed** that all the employees can be informed.


<br>

### Hints

- The company can be represented as a tree, headID is always the root.
- Store for each node the time needed to be informed of the news.
- Answer is the max time a leaf node needs to be informed.

<br>

### Solution

```cpp
class Solution {
  public:
    int numOfMinutes (int n, int headID, vector <int>& manager, vector <int>& informTime) {
      std::vector <std::vector <int>> graph (n);
      int max = 0;
      
      for (int i = 0; i < n; ++i) {
        if (i == headID)
          continue;
        graph[i].push_back(manager[i]);
        graph[manager[i]].push_back(i);
      }

      auto dfs = [&] (auto self, int u, int p, int d) -> void {
        max = std::max(max, d);
        for (int v: graph[u]) {
          if (v == p)
            continue;
          self(self, v, u, d + informTime[u]);
        }
      };

      dfs(dfs, headID, -1, 0);

      return max;
    }
};
```

<br>

### Statistics

- total accepted: 124192
- total submissions: 212716
- acceptance rate: 58.4%
- likes: 2509
- dislikes: 161

<br>

### Similar Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) (Easy)
- [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) (Hard)
