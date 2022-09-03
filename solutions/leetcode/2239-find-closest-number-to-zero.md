# [2239] Find Closest Number to Zero

**[array]**

### Statement

Given an integer array `nums` of size `n`, return *the number with the value **closest** to* `0` *in* `nums`. If there are multiple answers, return *the number with the **largest** value*.

**Example 1:**

```

**Input:** nums = [-4,-2,1,4,8]
**Output:** 1
**Explanation:**
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.

```

**Example 2:**

```

**Input:** nums = [2,-1,1]
**Output:** 1
**Explanation:** 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.

```

**Constraints:**
* `1 <= n <= 1000`
* `-105 <= nums[i] <= 105`


<br>

### Hints

- Keep track of the number closest to 0 as you iterate through the array.
- Ensure that if multiple numbers are closest to 0, you store the one with the largest value.

<br>

### Solution

```cpp
class Solution {
  public:
    int findClosestNumber (vector <int>& nums) {
      const int inf32 = 1 << 30;
      int n = nums.size();
      int min = inf32, val = 0;
      
      for (int i = 0; i < n; ++i) {
        if (std::abs(nums[i]) < min) {
          min = std::abs(nums[i]);
          val = nums[i];
        }
        else if (std::abs(nums[i]) == min and nums[i] > val)
          val = nums[i];
      }
      
      return val;
    }
};
```

<br>

### Statistics

- total accepted: 26580
- total submissions: 57938
- acceptance rate: 45.9%
- likes: 245
- dislikes: 18

<br>

### Similar Problems

- [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements) (Medium)
