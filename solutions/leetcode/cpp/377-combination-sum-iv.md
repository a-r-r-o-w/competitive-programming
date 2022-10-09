# [377] Combination Sum IV

**[array, dynamic-programming]**

### Statement

Given an array of **distinct** integers `nums` and a target integer `target`, return *the number of possible combinations that add up to*`target`.

The test cases are generated so that the answer can fit in a **32-bit** integer.


**Example 1:**

```

**Input:** nums = [1,2,3], target = 4
**Output:** 7
**Explanation:**
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

```

**Example 2:**

```

**Input:** nums = [9], target = 3
**Output:** 0

```

**Constraints:**
* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 1000`
* All the elements of `nums` are **unique**.
* `1 <= target <= 1000`


**Follow up:** What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int combinationSum4 (vector <int>& nums, int target) {
      const int max = 1000 + 1;
      std::vector <uint64_t> dp (max);
      dp[0] = 1;
      
      for (int i = 1; i <= target; ++i) {
        for (int x: nums) {
          if (i >= x)
            dp[i] += dp[i - x];
        }
      }
      
      return dp[target];
    }
};
```

<br>

### Statistics

- total accepted: 279976
- total submissions: 553264
- acceptance rate: 50.6%
- likes: 4238
- dislikes: 460

<br>

### Similar Problems

- [Combination Sum](https://leetcode.com/problems/combination-sum) (Medium)
