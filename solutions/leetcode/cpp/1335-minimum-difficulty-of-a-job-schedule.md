# [1335] Minimum Difficulty of a Job Schedule

**[array, dynamic-programming]**

### Statement

You want to schedule a list of jobs in `d` days. Jobs are dependent (i.e To work on the `ith` job, you have to finish all the jobs `j` where `0 <= j < i`).

You have to finish **at least** one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the `d` days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array `jobDifficulty` and an integer `d`. The difficulty of the `ith` job is `jobDifficulty[i]`.

Return *the minimum difficulty of a job schedule*. If you cannot find a schedule for the jobs return `-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/16/untitled.png)

```

**Input:** jobDifficulty = [6,5,4,3,2,1], d = 2
**Output:** 7
**Explanation:** First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 

```

**Example 2:**

```

**Input:** jobDifficulty = [9,9,9], d = 4
**Output:** -1
**Explanation:** If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

```

**Example 3:**

```

**Input:** jobDifficulty = [1,1,1], d = 3
**Output:** 3
**Explanation:** The schedule is one job per day. total difficulty will be 3.

```

**Constraints:**
* `1 <= jobDifficulty.length <= 300`
* `0 <= jobDifficulty[i] <= 1000`
* `1 <= d <= 10`


<br>

### Hints

- Use DP. Try to cut the array into d non-empty sub-arrays. Try all possible cuts for the array.
- Use dp[i][j] where DP states are i the index of the last cut and j the number of remaining cuts. Complexity is O(n * n * d).

<br>

### Solution

```cpp
class Solution {
  public:
    int minDifficulty (vector <int>& jobDifficulty, int d) {
      const int inf32 = 1 << 30;
      int n = jobDifficulty.size();
      
      if (d > n)
        return -1;
      
      std::vector <std::vector <int>> dp (n, std::vector <int> (d + 1, -1));
      
      auto dfs = [&] (auto self, int index, int remaining_days) -> int {
        if (remaining_days <= 0)
          return index >= n ? 0 : inf32;
        
        if (dp[index][remaining_days] != -1)
          return dp[index][remaining_days];
        
        int ans = inf32, max = -inf32;
        
        for (int i = index; i <= n - remaining_days; ++i) {
          max = std::max(max, jobDifficulty[i]);
          ans = std::min(ans, max + self(self, i + 1, remaining_days - 1));
        }
        
        dp[index][remaining_days] = ans;
        return ans;
      };
      
      return dfs(dfs, 0, d);
    }
};
```

<br>

### Statistics

- total accepted: 91376
- total submissions: 160393
- acceptance rate: 57.0%
- likes: 1833
- dislikes: 183

<br>

### Similar Problems

None
