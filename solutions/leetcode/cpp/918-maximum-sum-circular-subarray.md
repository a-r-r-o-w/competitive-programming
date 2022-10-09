# [918] Maximum Sum Circular Subarray

**[array, divide-and-conquer, dynamic-programming, queue, monotonic-queue]**

### Statement

Given a **circular integer array** `nums` of length `n`, return *the maximum possible sum of a non-empty **subarray** of* `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.


**Example 1:**

```

**Input:** nums = [1,-2,3,-2]
**Output:** 3
**Explanation:** Subarray [3] has maximum sum 3.

```

**Example 2:**

```

**Input:** nums = [5,-3,5]
**Output:** 10
**Explanation:** Subarray [5,5] has maximum sum 5 + 5 = 10.

```

**Example 3:**

```

**Input:** nums = [-3,-2,-3]
**Output:** -2
**Explanation:** Subarray [-2] has maximum sum -2.

```

**Constraints:**
* `n == nums.length`
* `1 <= n <= 3 * 10^4`
* `-3 * 10^4 <= nums[i] <= 3 * 10^4`


<br>

### Hints

- For those of you who are familiar with the <b>Kadane's algorithm</b>, think in terms of that. For the newbies, Kadane's algorithm is used to finding the maximum sum subarray from a given array. This problem is a twist on that idea and it is advisable to read up on that algorithm first before starting this problem. Unless you already have a great algorithm brewing up in your mind in which case, go right ahead!
- What is an alternate way of representing a circular array so that it appears to be a straight array?
Essentially, there are two cases of this problem that we need to take care of. Let's look at the figure below to understand those two cases:

<br>
<img src="https://assets.leetcode.com/uploads/2019/10/20/circular_subarray_hint_1.png" width="700"/>
- The first case can be handled by the good old Kadane's algorithm. However, is there a smarter way of going about handling the second case as well?

<br>

### Solution

```cpp
class Solution {
  public:
    int maxSubarraySumCircular (vector <int>& nums) {
      int n = nums.size();
      int max_sum = 0, min_sum = 0;
      int max_best = nums.front(), min_best = nums.front();
      int total = 0;
      
      for (int i = 0; i < n; ++i) {
        max_sum = std::max(max_sum + nums[i], nums[i]);
        min_sum = std::min(min_sum + nums[i], nums[i]);
        max_best = std::max(max_best, max_sum);
        min_best = std::min(min_best, min_sum);
        total += nums[i];
      }
      
      if (max_best < 0)
        return max_best;
      
      return std::max(max_best, total - min_best);
    }
};
```

<br>

### Statistics

- total accepted: 134608
- total submissions: 354950
- acceptance rate: 37.9%
- likes: 3684
- dislikes: 165

<br>

### Similar Problems

None
