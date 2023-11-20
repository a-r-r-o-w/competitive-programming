# [2444] Count Subarrays With Fixed Bounds

**[array, queue, sliding-window, monotonic-queue]**

### Statement

You are given an integer array `nums` and two integers `minK` and `maxK`.

A **fixed-bound subarray** of `nums` is a subarray that satisfies the following conditions:

* The **minimum** value in the subarray is equal to `minK`.
* The **maximum** value in the subarray is equal to `maxK`.



Return *the **number** of fixed-bound subarrays*.

A **subarray** is a **contiguous** part of an array.


**Example 1:**

```

**Input:** nums = [1,3,5,2,7,5], minK = 1, maxK = 5
**Output:** 2
**Explanation:** The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

```

**Example 2:**

```

**Input:** nums = [1,1,1,1], minK = 1, maxK = 1
**Output:** 10
**Explanation:** Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

```

**Constraints:**
* `2 <= nums.length <= 10^5`
* `1 <= nums[i], minK, maxK <= 10^6`


<br />

### Hints

- Can you solve the problem if all the numbers in the array were between minK and maxK inclusive?
- Think of the inclusion-exclusion principle.
- Divide the array into multiple subarrays such that each number in each subarray is between minK and maxK inclusive, solve the previous problem for each subarray, and sum all the answers.

<br />

### Solution

```cpp
class Solution {
  public:
    long long countSubarrays (vector <int>& nums, int minK, int maxK) {
      int n = nums.size();
      int left = -1, mindex = -1, maxdex = -1;
      int64_t count = 0;

      for (int i = 0; i < n; ++i) {
        if (nums[i] >= minK and nums[i] <= maxK) {
          if (nums[i] == minK)
            mindex = i;
          if (nums[i] == maxK)
            maxdex = i;
          count += std::max <int> (0, std::min(mindex, maxdex) - left);
        }
        else {
          left = i;
          mindex = -1;
          maxdex = -1;
        }
      }

      return count;
    }
};
```

<br />

### Statistics

- total accepted: 45239
- total submissions: 74165
- acceptance rate: 61.0%
- likes: 1811
- dislikes: 36

<br />

### Similar Problems

- [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays) (Medium)
- [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit) (Medium)
