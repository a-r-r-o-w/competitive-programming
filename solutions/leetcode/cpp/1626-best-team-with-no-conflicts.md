# [1626] Best Team With No Conflicts

**[array, dynamic-programming, sorting]**

### Statement

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the **sum** of scores of all the players in the team.

However, the basketball team is not allowed to have **conflicts**. A **conflict** exists if a younger player has a **strictly higher** score than an older player. A conflict does **not** occur between players of the same age.

Given two lists, `scores` and `ages`, where each `scores[i]` and `ages[i]` represents the score and age of the `i^th` player, respectively, return *the highest overall score of all possible basketball teams*.


**Example 1:**

```

**Input:** scores = [1,3,5,10,15], ages = [1,2,3,4,5]
**Output:** 34
**Explanation:**You can choose all the players.

```

**Example 2:**

```

**Input:** scores = [4,5,6,5], ages = [2,1,2,1]
**Output:** 16
**Explanation:**It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

```

**Example 3:**

```

**Input:** scores = [1,2,3,5], ages = [8,9,10,1]
**Output:** 6
**Explanation:**It is best to choose the first 3 players. 

```

**Constraints:**
* `1 <= scores.length, ages.length <= 1000`
* `scores.length == ages.length`
* `1 <= scores[i] <= 10^6`
* `1 <= ages[i] <= 1000`


<br />

### Hints

- First, sort players by age and break ties by their score. You can now consider the players from left to right.
- If you choose to include a player, you must only choose players with at least that score later on.

<br />

### Solution

```cpp
class Solution {
  public:
    int bestTeamScore (vector <int>& scores, vector <int>& ages) {
      int n = scores.size(), ans = 0;
      std::vector <int> order (n);

      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        if (ages[l] > ages[r])
          return true;
        if (ages[l] < ages[r])
          return false;
        return scores[l] > scores[r];
      });

      std::vector <int> dp (n);

      for (int i = 0; i < n; ++i) {
        dp[i] = scores[order[i]];
        for (int j = 0; j < i; ++j) {
          if (scores[order[j]] >= scores[order[i]])
            dp[i] = std::max(dp[i], dp[j] + scores[order[i]]);
        }
        ans = std::max(ans, dp[i]);
      }

      // auto dfs = [&] (auto self, int index, int max_score, int sum) -> void {
      //   if (index >= n) {
      //     ans = std::max(ans, sum);
      //     return;
      //   }

      //   if (scores[order[index]] >= max_score)
      //     self(self, index + 1, scores[order[index]], sum + scores[order[index]]);
      //   self(self, index + 1, max_score, sum);
      // };

      // for (int i = 0; i < n; ++i)
      //   dfs(dfs, i, 0, 0);

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 24906
- total submissions: 59042
- acceptance rate: 42.2%
- likes: 1122
- dislikes: 33

<br />

### Similar Problems

None
