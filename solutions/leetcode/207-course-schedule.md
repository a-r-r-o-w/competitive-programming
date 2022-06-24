# [207] Course Schedule

**[depth-first-search, breadth-first-search, graph, topological-sort]**

### Statement

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.



Return `true` if you can finish all courses. Otherwise, return `false`.


**Example 1:**

```

**Input:** numCourses = 2, prerequisites = [[1,0]]
**Output:** true
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

```

**Example 2:**

```

**Input:** numCourses = 2, prerequisites = [[1,0],[0,1]]
**Output:** false
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

```

**Constraints:**
* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= 5000`
* `prerequisites[i].length == 2`
* `0 <= ai, bi < numCourses`
* All the pairs prerequisites[i] are **unique**.


<br>

### Hints

- This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
- <a href="https://class.coursera.org/algo-003/lecture/52" target="_blank">Topological Sort via DFS</a> - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
- Topological sort could also be done via <a href="http://en.wikipedia.org/wiki/Topological_sorting#Algorithms" target="_blank">BFS</a>.

<br>

### Solution

```cpp
class Solution {
  public:
    bool canFinish (int numCourses, vector <vector <int>>& prerequisites) {
      std::vector <int> degree (numCourses), state (numCourses);
      std::vector <std::vector <int>> graph (numCourses);
      
      for (int i = 0; i < (int)prerequisites.size(); ++i) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        ++degree[prerequisites[i][0]];
      }
      
      std::queue <int> q;
      int done = 0;
      for (int i = 0; i < numCourses; ++i)
        if (degree[i] == 0) {
          q.push(i);
          state[i] = 1;
        }
      
      while (not q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v: graph[u]) {
          if (state[v] != 0)
            return false;
          --degree[v];
          if (degree[v] == 0)
            q.push(v);
        }
        
        state[u] = 2;
        ++done;
      }
      
      return done == numCourses;
    }
};
```

<br>

### Statistics

- total accepted: 904382
- total submissions: 2003564
- acceptance rate: 45.1%
- likes: 9767
- dislikes: 398

<br>

### Similar Problems

- [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) (Medium)
- [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree) (Medium)
- [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees) (Medium)
- [Course Schedule III](https://leetcode.com/problems/course-schedule-iii) (Hard)
