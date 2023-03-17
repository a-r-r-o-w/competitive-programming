# [209] Minimum Size Subarray Sum

**[array, binary-search, sliding-window, prefix-sum]**

### Statement

Given an array of positive integers `nums` and a positive integer `target`, return *the **minimal length** of a* *subarray* *whose sum is greater than or equal to* `target`. If there is no such subarray, return `0` instead.


**Example 1:**

```

**Input:** target = 7, nums = [2,3,1,2,4,3]
**Output:** 2
**Explanation:** The subarray [4,3] has the minimal length under the problem constraint.

```

**Example 2:**

```

**Input:** target = 4, nums = [1,4,4]
**Output:** 1

```

**Example 3:**

```

**Input:** target = 11, nums = [1,1,1,1,1,1,1,1]
**Output:** 0

```

**Constraints:**
* `1 <= target <= 10^9`
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^4`


**Follow up:** If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int minSubArrayLen (int target, vector <int>& nums) {
      constexpr int inf32 = 1 << 30;
      int n = nums.size(), l = 0, r = 0;
      int sum = 0, min = inf32;

      while (l < n) {
        if (r < n and sum < target)
          sum += nums[r++];
        else if (sum >= target) {
          while (l < r and sum - nums[l] >= target)
            sum -= nums[l++];
          min = std::min(min, r - l);
          sum -= nums[l++];
        }
        else
          sum -= nums[l++];
      }

      return min == inf32 ? 0 : min;
    }
};
```

<br />

### Statistics

- total accepted: 673596
- total submissions: 1499128
- acceptance rate: 44.9%
- likes: 8951
- dislikes: 248

<br />

### Similar Problems

- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) (Hard)
- [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k) (Medium)
- [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray) (Medium)
- [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero) (Medium)
- [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages) (Medium)
- [Maximum Product After K Increments](https://leetcode.com/problems/maximum-product-after-k-increments) (Medium)
