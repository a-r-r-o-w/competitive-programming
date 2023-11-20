# [2348] Number of Zero-Filled Subarrays

**[array, math]**

### Statement

Given an integer array `nums`, return *the number of **subarrays** filled with* `0`.

A **subarray** is a contiguous non-empty sequence of elements within an array.


**Example 1:**

```

**Input:** nums = [1,3,0,0,2,0,0,4]
**Output:** 6
**Explanation:** 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
```

**Example 2:**

```

**Input:** nums = [0,0,0,2,0,0]
**Output:** 9
**Explanation:**There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

```

**Example 3:**

```

**Input:** nums = [2,10,2019]
**Output:** 0
**Explanation:** There is no subarray filled with 0. Therefore, we return 0.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`


<br />

### Hints

- For each zero, you can calculate the number of zero-filled subarrays that end on that index, which is the number of consecutive zeros behind the current element + 1.
- Maintain the number of consecutive zeros behind the current element, count the number of zero-filled subarrays that end on each index, sum it up to get the answer.

<br />

### Solution

```cpp
class Solution {
  public:
    long long zeroFilledSubarray (vector <int>& nums) {
      int n = nums.size();
      int64_t ans = 0;

      for (int i = 0; i < n; ++i) {
        if (nums[i] != 0)
          continue;
        int j = i;
        while (j < n and nums[j] == 0)
          ++j;
        ans += int64_t(j - i) * (j - i + 1) / 2;
        i = j - 1;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 68017
- total submissions: 104657
- acceptance rate: 65.0%
- likes: 1305
- dislikes: 45

<br />

### Similar Problems

- [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices) (Medium)
- [Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock) (Medium)
- [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring) (Medium)
- [Find Consecutive Integers from a Data Stream](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream) (Medium)
