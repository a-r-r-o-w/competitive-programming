# [33] Search in Rotated Sorted Array

**[array, binary-search]**

### Statement

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.


**Example 1:**

```
**Input:** nums = [4,5,6,7,0,1,2], target = 0
**Output:** 4

```
**Example 2:**

```
**Input:** nums = [4,5,6,7,0,1,2], target = 3
**Output:** -1

```
**Example 3:**

```
**Input:** nums = [1], target = 0
**Output:** -1

```

**Constraints:**
* `1 <= nums.length <= 5000`
* `-104 <= nums[i] <= 104`
* All values of `nums` are **unique**.
* `nums` is an ascending array that is possibly rotated.
* `-104 <= target <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int search (vector <int>& nums, int target) {
      int n = nums.size(), low = 0, high = n - 1;

      while (low < high) {
        if (nums[low] < nums[high])
          break;
        int mid = (low + high) / 2;
        if (nums[mid] > nums[low] or mid == low)
          low = mid + 1;
        else
          high = mid;
      }

      int start = low;
      high = n;

      while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
          low = mid + 1;
        else
          high = mid;
      }

      if (low != n and nums[low] == target)
        return low;
      
      low = 0, high = start;

      while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
          low = mid + 1;
        else
          high = mid;
      }

      if (low != n and nums[low] == target)
        return low;
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 1882890
- total submissions: 4849325
- acceptance rate: 38.8%
- likes: 19413
- dislikes: 1174

<br>

### Similar Problems

- [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii) (Medium)
- [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array) (Medium)
- [Pour Water Between Buckets to Make Water Levels Equal](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal) (Medium)
