# [137] Single Number II

**[array, bit-manipulation]**

### Statement

Given an integer array `nums` whereevery element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

You mustimplement a solution with a linear runtime complexity and useonly constantextra space.


**Example 1:**

```
**Input:** nums = [2,2,3,2]
**Output:** 3

```
**Example 2:**

```
**Input:** nums = [0,1,0,1,0,1,99]
**Output:** 99

```

**Constraints:**
* `1 <= nums.length <= 3 * 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`
* Each element in `nums` appears exactly **three times** except for one element which appears **once**.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int singleNumber (vector <int>& nums) {
      int n = nums.size();
      int ans = 0;
      
      for (int bit = 0; bit < 32; ++bit) {
        unsigned int x = 1u << bit;
        int count = 0;

        for (int i = 0; i < n; ++i) {
          if (nums[i] & x)
            ++count;
        }

        if (count % 3)
          ans |= x;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 471401
- total submissions: 778311
- acceptance rate: 60.6%
- likes: 6751
- dislikes: 602

<br />

### Similar Problems

- [Single Number](https://leetcode.com/problems/single-number) (Easy)
- [Single Number III](https://leetcode.com/problems/single-number-iii) (Medium)
