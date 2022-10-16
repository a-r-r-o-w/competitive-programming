# [2439] Minimize Maximum of Array



### Statement

You are given a **0-indexed** array `nums` comprising of `n` non-negative integers.

In one operation, you must:

* Choose an integer `i` such that `1 <= i < n` and `nums[i] > 0`.
* Decrease `nums[i]` by 1.
* Increase `nums[i - 1]` by 1.



Return *the **minimum** possible value of the **maximum** integer of* `nums` *after performing **any** number of operations*.


**Example 1:**

```

**Input:** nums = [3,7,1,6]
**Output:** 5
**Explanation:**
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.

```

**Example 2:**

```

**Input:** nums = [10,1]
**Output:** 10
**Explanation:**
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.

```

**Constraints:**
* `n == nums.length`
* `2 <= n <= 105`
* `0 <= nums[i] <= 109`


<br>

### Hints

- Try a binary search approach.
- Perform a binary search over the minimum value that can be achieved for the maximum number of the array.
- In each binary search iteration, iterate through the array backwards, greedily decreasing the current element until it is within the limit.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimizeArrayValue (vector <int>& nums) {
      int64_t low = 0, high = 1e9 + 1;
      
      auto cost = [&] (int64_t x) {
        int n = nums.size();
        int64_t possible_increase = 0;
        
        for (int i = n - 1; i >= 1; --i) {
          if (nums[i] > x) {
            // set nums[i] to x
            possible_increase += nums[i] - x;
          }
          else {
            // try and use up as much of possible_increase as possible
            int diff = x - nums[i];
            possible_increase -= std::min((int64_t)diff, possible_increase);
          }
        }
        
        return nums[0] + possible_increase <= x;
      };
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        
        if (!cost(mid))
          low = mid + 1;
        else
          high = mid;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 4329
- total submissions: 16171
- acceptance rate: 26.8%
- likes: 142
- dislikes: 34

<br>

### Similar Problems

- [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children) (Medium)
- [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time) (Medium)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)
