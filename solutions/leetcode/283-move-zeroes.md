# [283] Move Zeroes

**[array, two-pointers]**

### Statement

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.


**Example 1:**

```
**Input:** nums = [0,1,0,3,12]
**Output:** [1,3,12,0,0]

```
**Example 2:**

```
**Input:** nums = [0]
**Output:** [0]

```

**Constraints:**
* `1 <= nums.length <= 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`


**Follow up:** Could you minimize the total number of operations done?

<br>

### Hints

- <b>In-place</b> means we should not be allocating any space for extra array. But we are allowed to modify the existing array. However, as a first step, try coming up with a solution that makes use of additional space. For this problem as well, first apply the idea discussed using an additional array and the in-place solution will pop up eventually.
- A <b>two-pointer</b> approach could be helpful here. The idea would be to have one pointer for iterating the array and another pointer that just works on the non-zero elements of the array.

<br>

### Solution

```cpp
class Solution {
  public:
    void moveZeroes (vector <int>& nums) {
      int n = nums.size();
      int left = 0;
      
      for (int i = 0; i < n; ++i) {
        if (nums[i] != 0)
          nums[left++] = nums[i];
      }
      
      while (left < n)
        nums[left++] = 0;
    }
};
```

<br>

### Statistics

- total accepted: 1868355
- total submissions: 3054800
- acceptance rate: 61.2%
- likes: 10816
- dislikes: 261

<br>

### Similar Problems

- [Remove Element](https://leetcode.com/problems/remove-element) (Easy)
