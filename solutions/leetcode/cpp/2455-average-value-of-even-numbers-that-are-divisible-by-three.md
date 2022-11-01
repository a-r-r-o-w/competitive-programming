# [2455] Average Value of Even Numbers That Are Divisible by Three



### Statement

Given an integer array `nums` of **positive** integers, return *the average value of all even integers that are divisible by* `3`*.*

Note that the **average** of `n` elements is the **sum** of the `n` elements divided by `n` and **rounded down** to the nearest integer.


**Example 1:**

```

**Input:** nums = [1,3,6,10,12,15]
**Output:** 9
**Explanation:** 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.

```

**Example 2:**

```

**Input:** nums = [1,2,4,7,10]
**Output:** 0
**Explanation:** There is no single number that satisfies the requirement, so return 0.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`


<br>

### Hints

- What is the property of a number if it is divisible by both 2 and 3 at the same time?
- It is equivalent to finding all the numbers that are divisible by 6.

<br>

### Solution

```cpp
class Solution {
  public:
    int averageValue (vector <int>& nums) {
      int sum = 0, count = 0;
      
      for (int i: nums) {
        if (i % 6 == 0) {
          sum += i;
          count += 1;
        }
      }
      
      if (count == 0)
        return 0;
      
      return sum / count;
    }
};
```

<br>

### Statistics

- total accepted: 17432
- total submissions: 29790
- acceptance rate: 58.5%
- likes: 84
- dislikes: 5

<br>

### Similar Problems

- [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5) (Easy)
