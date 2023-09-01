# [403] Frog Jump

**[array, dynamic-programming]**

### Statement

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of `stones`' positions (in units) in sorted **ascending order**, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be `1` unit.

If the frog's last jump was `k` units, its next jump must be either `k - 1`, `k`, or `k + 1` units. The frog can only jump in the forward direction.


**Example 1:**

```

**Input:** stones = [0,1,3,5,6,8,12,17]
**Output:** true
**Explanation:** The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

```

**Example 2:**

```

**Input:** stones = [0,1,2,3,4,8,9,11]
**Output:** false
**Explanation:** There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

```

**Constraints:**
* `2 <= stones.length <= 2000`
* `0 <= stones[i] <= 2^31 - 1`
* `stones[0] == 0`
* `stones`is sorted in a strictly increasing order.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    bool canCross(vector <int>& stones) {
      int n = stones.size();
      std::vector dp(n, std::vector <int>(n, -1));
      std::map <int, int> have;

      for (int i = 0; i < n; ++i)
        have[stones[i]] = i;

      auto dfs = [&] (auto self, int index, int64_t last_diff) -> bool {
        if (index >= n - 1)
          return true;
        if (dp[index][last_diff] != -1)
          return dp[index][last_diff];
        bool ans = false;
        for (int64_t i = std::max((int64_t)1, last_diff - 1); i <= last_diff + 1; ++i) {
          if (have.count(stones[index] + i))
            ans |= self(self, have[stones[index] + i], i);
        }
        return dp[index][last_diff] = ans;
      };

      return dfs(dfs, 0, 0);
    }
};
```

<br />

### Statistics

- total accepted: 207378
- total submissions: 468719
- acceptance rate: 44.2%
- likes: 4535
- dislikes: 212

<br />

### Similar Problems

- [Minimum Sideway Jumps](https://leetcode.com/problems/minimum-sideway-jumps) (Medium)
- [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower) (Medium)
- [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index) (Medium)
