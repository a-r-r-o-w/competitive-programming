# [1991] Find the Middle Index in Array

**[array, prefix-sum]**

### Statement

Given a **0-indexed** integer array `nums`, find the **leftmost** `middleIndex` (i.e., the smallest amongst all the possible ones).

A `middleIndex` is an index where `nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1]`.

If `middleIndex == 0`, the left side sum is considered to be `0`. Similarly, if `middleIndex == nums.length - 1`, the right side sum is considered to be `0`.

Return *the **leftmost*** `middleIndex` *that satisfies the condition, or* `-1` *if there is no such index*.


**Example 1:**

```

**Input:** nums = [2,3,-1,8,4]
**Output:** 3
**Explanation:** The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

```

**Example 2:**

```

**Input:** nums = [1,-1,4]
**Output:** 2
**Explanation:** The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0

```

**Example 3:**

```

**Input:** nums = [2,5]
**Output:** -1
**Explanation:** There is no valid middleIndex.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `-1000 <= nums[i] <= 1000`


**Note:** This question is the same as724:<https://leetcode.com/problems/find-pivot-index/>

<br>

### Hints

- Could we go from left to right and check to see if an index is a middle index?
- Do we need to sum every number to the left and right of an index each time?
- Use a prefix sum array where prefix[i] = nums[0] + nums[1] + ... + nums[i].

<br>

### Solution

```cpp
class Solution {
  public:
    int findMiddleIndex (vector <int>& nums) {
      int l = 0, r = 0, n = nums.size();

      for (int i = 0; i < n; ++i)
        r += nums[i];

      r -= nums[0];

      for (int i = 0; i < n - 1; ++i) {
        if (l == r)
          return i;
        l += nums[i];
        r -= nums[i + 1];
      }

      return l == r ? n - 1 : -1;
    }
};
```

<br>

### Statistics

- total accepted: 51599
- total submissions: 76682
- acceptance rate: 67.3%
- likes: 873
- dislikes: 35

<br>

### Similar Problems

- [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) (Easy)
- [Partition Array Into Three Parts With Equal Sum](https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum) (Easy)
- [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array) (Medium)
- [Maximum Sum Score of Array](https://leetcode.com/problems/maximum-sum-score-of-array) (Medium)
