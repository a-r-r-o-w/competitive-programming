# [34] Find First and Last Position of Element in Sorted Array

**[array, binary-search]**

### Statement

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You mustwrite an algorithm with`O(log n)` runtime complexity.


**Example 1:**

```
**Input:** nums = [5,7,7,8,8,10], target = 8
**Output:** [3,4]

```
**Example 2:**

```
**Input:** nums = [5,7,7,8,8,10], target = 6
**Output:** [-1,-1]

```
**Example 3:**

```
**Input:** nums = [], target = 0
**Output:** [-1,-1]

```

**Constraints:**
* `0 <= nums.length <= 105`
* `-109<= nums[i]<= 109`
* `nums` is a non-decreasing array.
* `-109<= target<= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
  vector <int> searchRange (vector <int>& nums, int target) {
      auto lb = std::lower_bound(nums.begin(), nums.end(), target);
      auto rb = std::upper_bound(nums.begin(), nums.end(), target);
      
      if (lb == nums.end() or *lb != target)
        return {-1, -1};
      
      int x = lb - nums.begin();
      int y = rb - nums.begin() - 1;
      
      return {x, y};
    }
};
```

<br>

### Statistics

- total accepted: 1214079
- total submissions: 2968989
- acceptance rate: 40.9%
- likes: 12455
- dislikes: 318

<br>

### Similar Problems

- [First Bad Version](https://leetcode.com/problems/first-bad-version) (Easy)
- [Plates Between Candles](https://leetcode.com/problems/plates-between-candles) (Medium)
- [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array) (Easy)
