# [287] Find the Duplicate Number

**[array, two-pointers, binary-search, bit-manipulation]**

### Statement

Given an array of integers `nums` containing`n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return *thisrepeatednumber*.

You must solve the problem **without** modifying the array `nums`and uses only constant extra space.


**Example 1:**

```

**Input:** nums = [1,3,4,2,2]
**Output:** 2

```

**Example 2:**

```

**Input:** nums = [3,1,3,4,2]
**Output:** 3

```

**Constraints:**
* `1 <= n <= 10^5`
* `nums.length == n + 1`
* `1 <= nums[i] <= n`
* All the integers in `nums` appear only **once** except for **precisely one integer** which appears **two or more** times.


**Follow up:**
* How can we prove that at least one duplicate number must exist in `nums`?
* Can you solve the problem in linear runtime complexity?


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int findDuplicate(vector <int>& nums) {
      int n = nums.size();
      int slow = nums[0], fast = nums[nums[0]];

      while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      fast = 0;
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};
```

<br />

### Statistics

- total accepted: 1321065
- total submissions: 2235593
- acceptance rate: 59.1%
- likes: 21013
- dislikes: 3476

<br />

### Similar Problems

- [First Missing Positive](https://leetcode.com/problems/first-missing-positive) (Hard)
- [Single Number](https://leetcode.com/problems/single-number) (Easy)
- [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) (Medium)
- [Missing Number](https://leetcode.com/problems/missing-number) (Easy)
- [Set Mismatch](https://leetcode.com/problems/set-mismatch) (Easy)
