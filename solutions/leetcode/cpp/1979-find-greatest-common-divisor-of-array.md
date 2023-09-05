# [1979] Find Greatest Common Divisor of Array

**[array, math, number-theory]**

### Statement

Given an integer array `nums`, return*the **greatest common divisor** of the smallest number and largest number in* `nums`.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.


**Example 1:**

```

**Input:** nums = [2,5,6,9,10]
**Output:** 2
**Explanation:**
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.

```

**Example 2:**

```

**Input:** nums = [7,5,6,8,3]
**Output:** 1
**Explanation:**
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.

```

**Example 3:**

```

**Input:** nums = [3,3]
**Output:** 3
**Explanation:**
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.

```

**Constraints:**
* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`


<br>

### Hints

- Find the minimum and maximum in one iteration. Let them be mn and mx.
- Try all the numbers in the range [1, mn] and check the largest number which divides both of them.

<br>

### Solution

```cpp
class Solution {
  public:
    int findGCD (vector <int>& nums) {
      int min = 1 << 30, max = -min;
      
      for (int i: nums) {
        min = std::min(min, i);
        max = std::max(max, i);
      }
      
      return std::gcd(min, max);
    }
};
```

<br>

### Statistics

- total accepted: 64505
- total submissions: 84118
- acceptance rate: 76.7%
- likes: 648
- dislikes: 24

<br>

### Similar Problems

- [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings) (Easy)
- [Number of Different Subsequences GCDs](https://leetcode.com/problems/number-of-different-subsequences-gcds) (Hard)
- [Three Divisors](https://leetcode.com/problems/three-divisors) (Easy)
- [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple) (Easy)
- [Number of Subarrays With GCD Equal to K](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k) (Medium)
