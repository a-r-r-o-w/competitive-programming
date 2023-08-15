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

```py
def binary_search (low: int, high: int, cost_function) -> int:
  while low < high:
    mid = (low + high) // 2
    if cost_function(mid):
      low = mid + 1
    else:
      high = mid
  return low

class Solution:
  def searchRange (self, nums: List[int], target: int) -> List[int]:
    n = len(nums)
    first = binary_search(0, n, lambda x: nums[x] < target)
    
    if first == n or nums[first] != target:
      return [-1, -1]
    
    second = binary_search(first, n, lambda x: nums[x] <= target) - 1
    return [first, second]
```

<br>

### Statistics

- total accepted: 1367449
- total submissions: 3291042
- acceptance rate: 41.6%
- likes: 14617
- dislikes: 357

<br>

### Similar Problems

- [First Bad Version](https://leetcode.com/problems/first-bad-version) (Easy)
- [Plates Between Candles](https://leetcode.com/problems/plates-between-candles) (Medium)
- [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array) (Easy)
