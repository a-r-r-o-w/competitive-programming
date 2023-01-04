# [1986] Minimum Number of Work Sessions to Finish the Tasks

**[array, dynamic-programming, backtracking, bit-manipulation, bitmask]**

### Statement

There are `n` tasks assigned to you. The task times are represented as an integer array `tasks` of length `n`, where the `ith` task takes `tasks[i]` hours to finish. A **work session** is when you work for **at most** `sessionTime` consecutive hours and then take a break.

You should finish the given tasks in a way that satisfies the following conditions:

* If you start a task in a work session, you must complete it in the **same** work session.
* You can start a new task **immediately** after finishing the previous one.
* You may complete the tasks in **any order**.



Given `tasks` and `sessionTime`, return *the **minimum** number of **work sessions** needed to finish all the tasks following the conditions above.*

The tests are generated such that `sessionTime` is **greater** than or **equal** to the **maximum** element in `tasks[i]`.


**Example 1:**

```

**Input:** tasks = [1,2,3], sessionTime = 3
**Output:** 2
**Explanation:** You can finish the tasks in two work sessions.
- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
- Second work session: finish the third task in 3 hours.

```

**Example 2:**

```

**Input:** tasks = [3,1,3,1,1], sessionTime = 8
**Output:** 2
**Explanation:** You can finish the tasks in two work sessions.
- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
- Second work session: finish the last task in 1 hour.

```

**Example 3:**

```

**Input:** tasks = [1,2,3,4,5], sessionTime = 15
**Output:** 1
**Explanation:** You can finish all the tasks in one work session.

```

**Constraints:**
* `n == tasks.length`
* `1 <= n <= 14`
* `1 <= tasks[i] <= 10`
* `max(tasks[i]) <= sessionTime <= 15`


<br>

### Hints

- Try all possible ways of assignment.
- If we can store the assignments in form of a state then we can reuse that state and solve the problem in a faster way.

<br>

### Solution

```cpp
class Solution {
  public:
    int minSessions (vector <int>& tasks, int sessionTime) {
      constexpr int inf32 = 1 << 30;
      int n = tasks.size(), ans = inf32;
      std::vector <std::vector <int>> dp (1 << n, std::vector <int> (sessionTime + 1, inf32));

      auto dfs = [&] (auto self, int have_mask, int remain_time) -> int {
        if (have_mask == 0)
          return 0;
        else if (dp[have_mask][remain_time] < inf32)
          return dp[have_mask][remain_time];
        
        int min = inf32;

        for (int i = 0; i < n; ++i) {
          if (!(have_mask & (1 << i)))
            continue;
          
          min = std::min(min, 1 + self(self, have_mask ^ (1 << i), sessionTime - tasks[i]));
          
          if (remain_time - tasks[i] >= 0)
            min = std::min(min, self(self, have_mask ^ (1 << i), remain_time - tasks[i]));
        }

        dp[have_mask][remain_time] = min;
        return min;
      };

      dfs(dfs, (1 << n) - 1, sessionTime);

      return 1 + *std::min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end());
    }
};
```

<br>

### Statistics

- total accepted: 18247
- total submissions: 55283
- acceptance rate: 33.0%
- likes: 811
- dislikes: 53

<br>

### Similar Problems

- [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team) (Hard)
- [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies) (Medium)
- [Find Minimum Time to Finish All Jobs](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs) (Hard)
- [Find Minimum Time to Finish All Jobs II](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii) (Medium)
