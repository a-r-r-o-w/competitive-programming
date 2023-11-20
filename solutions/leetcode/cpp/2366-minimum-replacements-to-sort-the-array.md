# [2366] Minimum Replacements to Sort the Array

**[array, math, greedy]**

### Statement

You are given a **0-indexed** integer array `nums`. In one operation you can replace any element of the array with **any two** elements that **sum** to it.

* For example, consider `nums = [5,6,7]`. In one operation, we can replace `nums[1]` with `2` and `4` and convert `nums` to `[5,2,4,7]`.



Return *the minimum number of operations to make an array that is sorted in **non-decreasing** order*.


**Example 1:**

```

**Input:** nums = [3,9,3]
**Output:** 2
**Explanation:** Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.


```

**Example 2:**

```

**Input:** nums = [1,2,3,4,5]
**Output:** 0
**Explanation:** The array is already in non-decreasing order. Therefore, we return 0. 

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^9`


<br />

### Hints

- It is optimal to never make an operation to the last element of the array.
- You can iterate from the second last element to the first. If the current value is greater than the previous bound, we want to break it into pieces so that the smaller one is as large as possible but not larger than the previous one.

<br />

### Solution

```cpp
class Solution {
  public:
    long long minimumReplacement(vector <int>& nums) {
      int n = nums.size();
      int64_t ans = 0;

      for (int i = n - 2; i >= 0; --i) {
        if (nums[i] <= nums[i + 1])
          continue;
        int64_t x = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
        ans += x - 1;
        nums[i] /= x;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 54999
- total submissions: 101078
- acceptance rate: 54.4%
- likes: 1746
- dislikes: 60

<br />

### Similar Problems

- [Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing) (Easy)
