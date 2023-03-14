# [2587] Rearrange Array to Maximize Prefix Score

**[array, greedy, sorting, prefix-sum]**

### Statement

You are given a **0-indexed** integer array `nums`. You can rearrange the elements of `nums` to **any order** (including the given order).

Let `prefix` be the array containing the prefix sums of `nums` after rearranging it. In other words, `prefix[i]` is the sum of the elements from `0` to `i` in `nums` after rearranging it. The **score** of `nums` is the number of positive integers in the array `prefix`.

Return *the maximum score you can achieve*.


**Example 1:**

```

**Input:** nums = [2,-1,0,1,-3,3,-3]
**Output:** 6
**Explanation:** We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
prefix = [2,5,6,5,2,2,-1], so the score is 6.
It can be shown that 6 is the maximum score we can obtain.

```

**Example 2:**

```

**Input:** nums = [-2,-3,0]
**Output:** 0
**Explanation:** Any rearrangement of the array will result in a score of 0.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^6 <= nums[i] <= 10^6`


<br />

### Hints

- The best order of the array is in decreasing order.
- Sort the array in decreasing order and count the number of positive values in the prefix sum array.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxScore (vector <int>& nums) {
      std::vector <int> negative;
      int64_t sum = 0;
      int count = 0;
      
      for (int i: nums) {
        if (i <= 0)
          negative.push_back(-i);
        else {
          ++count;
          sum += i;
        }
      }
      
      std::sort(negative.begin(), negative.end());
      
      for (int i: negative) {
        sum -= i;
        if (sum <= 0)
          break;
        ++count;
      }
      
      return count;
    }
};
```

<br />

### Statistics

- total accepted: 17094
- total submissions: 43855
- acceptance rate: 39.0%
- likes: 148
- dislikes: 14

<br />

### Similar Problems

- [Two City Scheduling](https://leetcode.com/problems/two-city-scheduling) (Medium)
