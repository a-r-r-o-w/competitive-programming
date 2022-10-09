# [39] Combination Sum

**[array, backtracking]**

### Statement

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of* `candidates` *where the chosen numbers sum to* `target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.


**Example 1:**

```

**Input:** candidates = [2,3,6,7], target = 7
**Output:** [[2,2,3],[7]]
**Explanation:**
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

```

**Example 2:**

```

**Input:** candidates = [2,3,5], target = 8
**Output:** [[2,2,2,2],[2,3,3],[3,5]]

```

**Example 3:**

```

**Input:** candidates = [2], target = 1
**Output:** []

```

**Constraints:**
* `1 <= candidates.length <= 30`
* `1 <= candidates[i] <= 200`
* All elements of `candidates` are **distinct**.
* `1 <= target <= 500`


<br>

### Hints

None

<br>

### Solution

**Iterative approach**

```cpp
class Solution {
  public:
    vector <vector <int>> combinationSum (vector <int>& candidates, int target) {
      std::vector <std::vector <std::vector <int>>> dp (target + 1);
      dp[0].push_back({});
      for (int c: candidates) {
        for (int i = 0; i <= target - c; ++i) {
          for (auto& copy: dp[i]) {
            copy.push_back(c);
            dp[i + c].push_back(copy);
            copy.pop_back();
          }
        }
      }
      return dp[target];
    }
};
```

**Recursive approach**

```cpp
class Solution {
  public:
    vector <vector <int>> combinationSum (vector <int>& candidates, int target) {
      auto dp = [&] (auto self, int t, int index) -> std::vector <std::vector <int>> {
        if (t == 0)
          return {{}};
        
        std::vector <std::vector <int>> values;
        for (int i = index; i < int(candidates.size()); ++i) {
          int c = candidates[i];
          if (t - c >= 0) {
            auto results = self(self, t - c, i);
            for (auto&& r: results) {
              values.emplace_back(std::move(r));
              values.back().emplace_back(c);
            }
          }
        }
        
        return values;
      };
      
      return dp(dp, target, 0);
    }
};
```

<br>

### Statistics

- total accepted: 1117332
- total submissions: 1692630
- acceptance rate: 66.0%
- likes: 11342
- dislikes: 242

<br>

### Similar Problems

- [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number) (Medium)
- [Combination Sum II](https://leetcode.com/problems/combination-sum-ii) (Medium)
- [Combinations](https://leetcode.com/problems/combinations) (Medium)
- [Combination Sum III](https://leetcode.com/problems/combination-sum-iii) (Medium)
- [Factor Combinations](https://leetcode.com/problems/factor-combinations) (Medium)
- [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv) (Medium)
