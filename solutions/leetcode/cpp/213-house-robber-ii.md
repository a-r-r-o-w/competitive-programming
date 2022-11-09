# [213] House Robber II

**[array, dynamic-programming]**

### Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and**it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.


**Example 1:**

```

**Input:** nums = [2,3,2]
**Output:** 3
**Explanation:** You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

```

**Example 2:**

```

**Input:** nums = [1,2,3,1]
**Output:** 4
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

**Example 3:**

```

**Input:** nums = [1,2,3]
**Output:** 3

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`


<br>

### Hints

- Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the <a href ="https://leetcode.com/problems/house-robber/description/">House Robber</a>, which is already been solved.

<br>

### Solution

O(n) space

```cpp
class Solution {
  public:
    int rob (vector <int>& nums) {
      int n = nums.size();
      
      if (n <= 2)
        return *std::max_element(nums.begin(), nums.end());
      
      std::vector <int> dp1 (n + 1), dp2 (n + 1);
      
      dp1[1] = nums[0];
      dp1[2] = std::max(dp1[2 - 1], dp1[2 - 2] + nums[2 - 1]);
      dp2[2] = nums[1];
      
      for (int i = 3; i <= n; ++i) {
        dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
        dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
      }
      
      return std::max(dp1[n - 1], dp2[n]);
    }
};
```

O(1) space

```cpp
class Solution {
  public:
    int rob (vector <int>& nums) {
      int n = nums.size();
      
      if (n <= 2)
        return *std::max_element(nums.begin(), nums.end());
      
      int x1 = nums[0], y1 = std::max(x1, nums[1]);
      int x2 = 0, y2 = nums[1];
      
      for (int i = 3; i <= n; ++i) {
        int t1 = std::max(y1, x1 + nums[i - 1]);
        x1 = y1;
        y1 = t1;
        
        int t2 = std::max(y2, x2 + nums[i - 1]);
        x2 = y2;
        y2 = t2;
      }
      
      return std::max(x1, y2);
    }
};
```

<br>

### Statistics

- total accepted: 472535
- total submissions: 1166899
- acceptance rate: 40.5%
- likes: 6717
- dislikes: 104

<br>

### Similar Problems

- [House Robber](https://leetcode.com/problems/house-robber) (Medium)
- [Paint House](https://leetcode.com/problems/paint-house) (Medium)
- [Paint Fence](https://leetcode.com/problems/paint-fence) (Medium)
- [House Robber III](https://leetcode.com/problems/house-robber-iii) (Medium)
- [Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones) (Hard)
- [Coin Path](https://leetcode.com/problems/coin-path) (Hard)
