# [956] Tallest Billboard

**[array, dynamic-programming]**

### Statement

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of `rods` that can be welded together. For example, if you have rods of lengths `1`, `2`, and `3`, you can weld them together to make a support of length `6`.

Return *the largest possible height of your billboard installation*. If you cannot support the billboard, return `0`.


**Example 1:**

```

**Input:** rods = [1,2,3,6]
**Output:** 6
**Explanation:** We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

```

**Example 2:**

```

**Input:** rods = [1,2,3,4,5,6]
**Output:** 10
**Explanation:** We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

```

**Example 3:**

```

**Input:** rods = [1,2]
**Output:** 0
**Explanation:** The billboard cannot be supported, so we return 0.

```

**Constraints:**
* `1 <= rods.length <= 20`
* `1 <= rods[i] <= 1000`
* `sum(rods[i]) <= 5000`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int tallestBillboard (vector<int>& rods) {
      const int inf32 = 1 << 30;
      int n = rods.size();
      std::vector dp(n, std::unordered_map<int, int>());
      
      auto dfs = [&] (auto self, int index, int moving_sum) -> int {
        if (index >= n)
          return moving_sum == 0 ? 0 : -inf32;
        if (dp[index].count(moving_sum))
          return dp[index][moving_sum];
        
        int ans = -inf32;
        int m = std::min(moving_sum, rods[index]);
        ans = std::max(ans, self(self, index + 1, moving_sum + rods[index]));
        ans = std::max(ans, self(self, index + 1, std::abs(moving_sum - rods[index])) + m);
        ans = std::max(ans, self(self, index + 1, moving_sum));
        return dp[index][moving_sum] = ans;
      };

      return dfs(dfs, 0, 0);
    }
};
```

<br />

### Statistics

- total accepted: 33765
- total submissions: 71015
- acceptance rate: 47.5%
- likes: 1631
- dislikes: 45

<br />

### Similar Problems

- [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) (Hard)
