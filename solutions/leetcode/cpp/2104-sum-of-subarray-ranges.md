# [2104] Sum of Subarray Ranges

**[array, stack, monotonic-stack]**

### Statement

You are given an integer array `nums`. The **range** of a subarray of `nums` is the difference between the largest and smallest element in the subarray.

Return *the **sum of all** subarray ranges of* `nums`*.*

A subarray is a contiguous **non-empty** sequence of elements within an array.


**Example 1:**

```

**Input:** nums = [1,2,3]
**Output:** 4
**Explanation:** The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
```

**Example 2:**

```

**Input:** nums = [1,3,3]
**Output:** 4
**Explanation:** The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

```

**Example 3:**

```

**Input:** nums = [4,-2,-3,4,1]
**Output:** 59
**Explanation:** The sum of all subarray ranges of nums is 59.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `-10^9 <= nums[i] <= 10^9`


**Follow-up:** Could you find a solution with `O(n)` time complexity?

<br />

### Hints

- Can you get the max/min of a certain subarray by using the max/min of a smaller subarray within it?
- Notice that the max of the subarray from index i to j is equal to max of (max of the subarray from index i to j-1) and nums[j].

<br />

### Solution

```cpp
class Solution {
  public:
    long long subArrayRanges (vector <int>& nums) {
      int n = nums.size();
      int64_t sum = 0;

      for (int i = 0; i < n; ++i) {
        int min = 1 << 30, max = -min;

        for (int j = i; j < n; ++j) {
          min = std::min(min, nums[j]);
          max = std::max(max, nums[j]);
          sum += max - min;
        }
      }

      return sum;
    }
};
```

<br />

### Statistics

- total accepted: 66234
- total submissions: 109911
- acceptance rate: 60.3%
- likes: 1631
- dislikes: 86

<br />

### Similar Problems

- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) (Easy)
- [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums) (Medium)
- [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue) (Hard)
- [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings) (Medium)
- [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards) (Hard)
