# [413] Arithmetic Slices

**[array, dynamic-programming]**

### Statement

An integer array is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

* For example, `[1,3,5,7,9]`, `[7,7,7,7]`, and `[3,-1,-5,-9]` are arithmetic sequences.



Given an integer array `nums`, return *the number of arithmetic **subarrays** of* `nums`.

A **subarray** is a contiguous subsequence of the array.


**Example 1:**

```

**Input:** nums = [1,2,3,4]
**Output:** 3
**Explanation:** We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

```

**Example 2:**

```

**Input:** nums = [1]
**Output:** 0

```

**Constraints:**
* `1 <= nums.length <= 5000`
* `-1000 <= nums[i] <= 1000`


<br>

### Hints

None

<br>

### Solution

Time: O(n^2)
Space: O(1)

```cpp
class Solution {
  public:
    int numberOfArithmeticSlices (vector <int>& nums) {
      int n = nums.size();
      int count = 0;
      
      for (int l = 0; l + 1 < n; ++l) {
        int difference = nums[l + 1] - nums[l];
        
        for (int r = l + 2; r < n; ++r) {
          if (nums[r] - nums[r - 1] == difference)
            ++count;
          else
            break;
        }
      }
      
      return count;
    }
};
```

Time: O(n)
Space: O(n)

```cpp
class Solution {
  public:
    int numberOfArithmeticSlices (vector <int>& nums) {
      int n = nums.size();
      int count = 0;
      
      if (n < 3)
        return 0;
      
      // dp[i] is the number of arithmetic subarrays ending at i
      std::vector <int> dp (n);
      int best = 0;
      
      for (int i = 2; i < n; ++i) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
          dp[i] = dp[i - 1] + 1;
        best += dp[i];
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 248819
- total submissions: 382973
- acceptance rate: 65.0%
- likes: 4246
- dislikes: 262

<br>

### Similar Problems

- [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence) (Hard)
- [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays) (Medium)
- [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays) (Medium)
