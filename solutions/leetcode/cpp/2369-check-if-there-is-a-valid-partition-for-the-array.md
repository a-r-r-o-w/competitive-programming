# [2369] Check if There is a Valid Partition For The Array

**[array, dynamic-programming]**

### Statement

You are given a **0-indexed** integer array `nums`. You have to partition the array into one or more **contiguous** subarrays.

We call a partition of the array **valid** if each of the obtained subarrays satisfies **one** of the following conditions:

1. The subarray consists of **exactly** `2` equal elements. For example, the subarray `[2,2]` is good.
2. The subarray consists of **exactly** `3` equal elements. For example, the subarray `[4,4,4]` is good.
3. The subarray consists of **exactly** `3` consecutive increasing elements, that is, the difference between adjacent elements is `1`. For example, the subarray `[3,4,5]` is good, but the subarray `[1,3,5]` is not.



Return `true` *if the array has **at least** one valid partition*. Otherwise, return `false`.


**Example 1:**

```

**Input:** nums = [4,4,4,5,6]
**Output:** true
**Explanation:** The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.

```

**Example 2:**

```

**Input:** nums = [1,1,1,2]
**Output:** false
**Explanation:** There is no valid partition for this array.

```

**Constraints:**
* `2 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^6`


<br />

### Hints

- How can you reduce the problem to checking if there is a valid partition for a smaller array?
- Use dynamic programming to reduce the problem until you have an empty array.

<br />

### Solution

```cpp
class Solution {
  public:
    bool validPartition (vector <int>& nums) {
      int n = nums.size();
      std::vector <bool> dp (n + 1);
      dp[0] = true;
      dp[2] = nums[0] == nums[1];

      for (int i = 3; i <= n; ++i) {
        if (nums[i - 1] == nums[i - 2] + 1 and nums[i - 2] == nums[i - 3] + 1)
          dp[i] = dp[i - 3];
        else {
          bool two = nums[i - 1] == nums[i - 2];
          bool three = two and nums[i - 2] == nums[i - 3];
          dp[i] = (two and dp[i - 2]) or (three and dp[i - 3]);
        }
      }

      return dp[n];
    }
};
```

<br />

### Statistics

- total accepted: 35830
- total submissions: 76036
- acceptance rate: 47.1%
- likes: 991
- dislikes: 143

<br />

### Similar Problems

None
