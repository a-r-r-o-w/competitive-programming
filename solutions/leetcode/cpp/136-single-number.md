# [136] Single Number

**[array, bit-manipulation]**

### Statement

Given a **non-empty**array of integers `nums`, every element appears *twice* except for one. Find that single one.

You mustimplement a solution with a linear runtime complexity and useonly constantextra space.


**Example 1:**

```
**Input:** nums = [2,2,1]
**Output:** 1

```
**Example 2:**

```
**Input:** nums = [4,1,2,1,2]
**Output:** 4

```
**Example 3:**

```
**Input:** nums = [1]
**Output:** 1

```

**Constraints:**
* `1 <= nums.length <= 3 * 104`
* `-3 * 104 <= nums[i] <= 3 * 104`
* Each element in the array appears twice except for one element which appears only once.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int singleNumber (vector <int>& nums) {
      int x = 0;
      std::for_each(nums.begin(), nums.end(), [&] (int v) {
        x ^= v;
      });
      return x;
    }
};
```

<br>

### Statistics

- total accepted: 1843413
- total submissions: 2635806
- acceptance rate: 69.9%
- likes: 11408
- dislikes: 433

<br>

### Similar Problems

- [Single Number II](https://leetcode.com/problems/single-number-ii) (Medium)
- [Single Number III](https://leetcode.com/problems/single-number-iii) (Medium)
- [Missing Number](https://leetcode.com/problems/missing-number) (Easy)
- [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) (Medium)
- [Find the Difference](https://leetcode.com/problems/find-the-difference) (Easy)
