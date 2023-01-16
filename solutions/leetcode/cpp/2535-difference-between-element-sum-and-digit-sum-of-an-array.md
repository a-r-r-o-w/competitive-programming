# [2535] Difference Between Element Sum and Digit Sum of an Array



### Statement

You are given a positive integer array `nums`.

* The **element sum** is the sum of all the elements in `nums`.
* The **digit sum** is the sum of all the digits (not necessarily distinct) that appear in `nums`.



Return *the **absolute** difference between the **element sum** and **digit sum** of* `nums`.

**Note** that the absolute difference between two integers `x` and `y` is defined as `|x - y|`.


**Example 1:**

```

**Input:** nums = [1,15,6,3]
**Output:** 9
**Explanation:** 
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.

```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** 0
**Explanation:**
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.

```

**Constraints:**
* `1 <= nums.length <= 2000`
* `1 <= nums[i] <= 2000`


<br>

### Hints

- Use a simple for loop to iterate each number.
- How you can get the digit for each number?

<br>

### Solution

```cpp
class Solution {
  public:
    int differenceOfSum (vector <int>& nums) {
      int sum = std::accumulate(nums.begin(), nums.end(), 0);
      int digitsum = 0;
      
      for (int i: nums) {
        while (i) {
          digitsum += i % 10;
          i /= 10;
        }
      }
      
      return std::abs(sum - digitsum);
    }
};
```

<br>

### Statistics

- total accepted: 14336
- total submissions: 15808
- acceptance rate: 90.7%
- likes: 31
- dislikes: 0

<br>

### Similar Problems

- [Add Digits](https://leetcode.com/problems/add-digits) (Easy)
- [Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits) (Easy)
