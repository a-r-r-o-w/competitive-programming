# [210] Course Schedule II

**[depth-first-search, breadth-first-search, graph, topological-sort]**

### Statement

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.



Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.


**Example 1:**

```

**Input:** numCourses = 2, prerequisites = [[1,0]]
**Output:** [0,1]
**Explanation:** There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

```

**Example 2:**

```

**Input:** numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
**Output:** [0,2,1,3]
**Explanation:** There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

```

**Example 3:**

```

**Input:** numCourses = 1, prerequisites = []
**Output:** [0]

```

**Constraints:**
* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
* `prerequisites[i].length == 2`
* `0 <= ai, bi < numCourses`
* `ai != bi`
* All the pairs `[ai, bi]` are **distinct**.


<br>

### Hints

- This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
- <a href="https://class.coursera.org/algo-003/lecture/52" target="_blank">Topological Sort via DFS</a> - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
- Topological sort could also be done via <a href="http://en.wikipedia.org/wiki/Topological_sorting#Algorithms" target="_blank">BFS</a>.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> findOrder (int numCourses, vector <vector <int>>& prerequisites) {
      std::vector <int> degree (numCourses), state (numCourses), order;
      std::vector <std::vector <int>> graph (numCourses);
      
      for (int i = 0; i < (int)prerequisites.size(); ++i) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        ++degree[prerequisites[i][0]];
      }
      
      std::queue <int> q;
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
            return {};
          --degree[v];
          if (degree[v] == 0)
            q.push(v);
        }
        
        state[u] = 2;
        order.push_back(u);
      }
      
      return (int)order.size() == numCourses ? order : std::vector <int> {};
    }
};
```

<br>

### Statistics

- total accepted: 646688
- total submissions: 1377215
- acceptance rate: 47.0%
- likes: 6968
- dislikes: 243

<br>

### Similar Problems

- [Course Schedule](https://leetcode.com/problems/course-schedule) (Medium)
- [Alien Dictionary](https://leetcode.com/problems/alien-dictionary) (Hard)
- [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees) (Medium)
- [Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction) (Medium)
- [Course Schedule III](https://leetcode.com/problems/course-schedule-iii) (Hard)
- [Parallel Courses](https://leetcode.com/problems/parallel-courses) (Medium)
- [Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies) (Medium)
