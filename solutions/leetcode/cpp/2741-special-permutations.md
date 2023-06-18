# [2741] Special Permutations



### Statement

You are given a**0-indexed**integer array`nums`containing`n`**distinct** positive integers. A permutation of`nums`is called special if:

* For all indexes`0 <= i < n - 1`, either`nums[i] % nums[i+1] == 0`or`nums[i+1] % nums[i] == 0`.



Return*the total number of special permutations.*As the answer could be large, return it**modulo**`10^9+ 7`.


**Example 1:**

```

**Input:** nums = [2,3,6]
**Output:** 2
**Explanation:** [3,6,2] and [2,6,3] are the two special permutations of nums.

```

**Example 2:**

```

**Input:** nums = [1,4,3]
**Output:** 2
**Explanation:** [3,1,4] and [4,1,3] are the two special permutations of nums.

```

**Constraints:**
* `2 <= nums.length <= 14`
* `1 <= nums[i] <= 10^9`


<br />

### Hints

- Can we solve this problem using DP with bit masking?
- You just need two states in DP which are last_ind in the permutation and the mask of numbers already used.

<br />

### Solution

```cpp
class Solution {
  public:
    int specialPerm (vector <int>& nums) {
      const int mod = 1000000007;
      int n = nums.size();
      std::vector dp (n, std::vector <int> (1 << n, -1));
      
      auto dfs = [&] (auto self, int index, int mask) -> int {
        if (mask == (1 << n) - 1)
          return 1;
        if (dp[index][mask] != -1)
          return dp[index][mask];
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
          if (!(mask & (1 << i)) and
             (mask == 0 or nums[index] % nums[i] == 0 or nums[i] % nums[index] == 0))
            ans = (ans + self(self, i, mask | (1 << i))) % mod;
        }
        return dp[index][mask] = ans;
      };
      
      return dfs(dfs, 0, 0);
    }
};
```

<br />

### Statistics

- total accepted: 5061
- total submissions: 25675
- acceptance rate: 19.7%
- likes: 159
- dislikes: 47

<br />

### Similar Problems

None
