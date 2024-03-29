# [1262] Greatest Sum Divisible by Three

**[array, dynamic-programming, greedy]**

### Statement

Given an integer array `nums`, return *the **maximum possible sum** of elements of the array such that it is divisible by three*.


**Example 1:**

```

**Input:** nums = [3,6,5,1,8]
**Output:** 18
**Explanation:** Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
```

**Example 2:**

```

**Input:** nums = [4]
**Output:** 0
**Explanation:** Since 4 is not divisible by 3, do not pick any number.

```

**Example 3:**

```

**Input:** nums = [1,2,3,4,4]
**Output:** 12
**Explanation:** Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).

```

**Constraints:**
* `1 <= nums.length <= 4 * 10^4`
* `1 <= nums[i] <= 10^4`


<br />

### Hints

- Represent the state as DP[pos][mod]: maximum possible sum starting in the position "pos" in the array where the current sum modulo 3 is equal to mod.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxSumDivThree (vector <int>& nums) {
      const int inf32 = 1 << 30;
      int n = nums.size(), ans = 0;
      std::vector <std::vector <int>> dp (3, std::vector <int> (n + 1, -inf32));

      dp[0][0] = 0;

      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
          dp[(j + nums[i - 1]) % 3][i] = std::max(dp[(j + nums[i - 1]) % 3][i - 1], dp[j][i - 1] + nums[i - 1]);
        }
      }

      return dp[0][n] < 0 ? 0 : dp[0][n];
    }
};
```

<br />

### Statistics

- total accepted: 44405
- total submissions: 87327
- acceptance rate: 50.8%
- likes: 1490
- dislikes: 36

<br />

### Similar Problems

None
