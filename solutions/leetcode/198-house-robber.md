# [198] House Robber

**[array, dynamic-programming]**

### Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.


**Example 1:**

```

**Input:** nums = [1,2,3,1]
**Output:** 4
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

**Example 2:**

```

**Input:** nums = [2,7,9,3,1]
**Output:** 12
**Explanation:** Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 400`


<br>

### Hints

None

<br>

### Solution

**DP**

```cpp
class Solution {
  public:
    int rob (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> dp (n + 1);
      
      dp[1] = nums[0];
      
      for (int i = 2; i <= n; ++i)
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
      
      return dp[n];
    }
};
```

**Space optimised DP**

```cpp
class Solution {
  public:
    int rob (vector <int>& nums) {
      int n = nums.size();
      int x = 0;
      int y = nums[0];
      
      for (int i = 2; i <= n; ++i) {
        int z = std::max(y, x + nums[i - 1]);
        x = y;
        y = z;
      }
      
      return y;
    }
};
```

<br>

### Statistics

- total accepted: 1208511
- total submissions: 2529532
- acceptance rate: 47.8%
- likes: 13154
- dislikes: 276

<br>

### Similar Problems

- [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray) (Medium)
- [House Robber II](https://leetcode.com/problems/house-robber-ii) (Medium)
- [Paint House](https://leetcode.com/problems/paint-house) (Medium)
- [Paint Fence](https://leetcode.com/problems/paint-fence) (Medium)
- [House Robber III](https://leetcode.com/problems/house-robber-iii) (Medium)
- [Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones) (Hard)
- [Coin Path](https://leetcode.com/problems/coin-path) (Hard)
- [Delete and Earn](https://leetcode.com/problems/delete-and-earn) (Medium)
- [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower) (Medium)
- [Count Number of Ways to Place Houses](https://leetcode.com/problems/count-number-of-ways-to-place-houses) (Medium)
