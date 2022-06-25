# [55] Jump Game

**[array, dynamic-programming, greedy]**

### Statement

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.


**Example 1:**

```

**Input:** nums = [2,3,1,1,4]
**Output:** true
**Explanation:** Jump 1 step from index 0 to 1, then 3 steps to the last index.

```

**Example 2:**

```

**Input:** nums = [3,2,1,0,4]
**Output:** false
**Explanation:** You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

```

**Constraints:**
* `1 <= nums.length <= 104`
* `0 <= nums[i] <= 105`


<br>

### Hints

None

<br>

### Solution

**DP**

```cpp
class Solution {
  public:
    bool canJump (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> dp (n + 1);
      dp[0] = 1;
      dp[std::min(0 + nums[0] + 1, n)] = -1;
      
      for (int i = 1; i < n; ++i) {
        dp[i] += dp[i - 1];
        if (dp[i]) {
          dp[i] += 1;
          dp[std::min(i + nums[i] + 1, n)] -= 1;
        }
      }
      
      return dp[n - 1];
    }
};
```

**Greedy**

```cpp
class Solution {
  public:
    bool canJump (vector <int>& nums) {
      int n = nums.size();
      int max = 0;
      for (int i = 0; i < n; ++i) {
        if (max < i)
          return false;
        max = std::max(max, i + nums[i]);
      }
      
      return max >= n - 1;
    }
};
```

<br>

### Statistics

- total accepted: 1044940
- total submissions: 2747920
- acceptance rate: 38.0%
- likes: 11507
- dislikes: 639

<br>

### Similar Problems

- [Jump Game II](https://leetcode.com/problems/jump-game-ii) (Medium)
- [Jump Game III](https://leetcode.com/problems/jump-game-iii) (Medium)
- [Jump Game VII](https://leetcode.com/problems/jump-game-vii) (Medium)
- [Jump Game VIII](https://leetcode.com/problems/jump-game-viii) (Medium)
