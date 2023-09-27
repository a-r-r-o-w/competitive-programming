# [1283] Find the Smallest Divisor Given a Threshold

**[array, binary-search]**

### Statement

Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer `divisor`, divide all the array by it, and sum the division's result. Find the **smallest** `divisor` such that the result mentioned above is less than or equal to `threshold`.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: `7/3 = 3` and `10/2 = 5`).

The test cases are generated sothat there will be an answer.


**Example 1:**

```

**Input:** nums = [1,2,5,9], threshold = 6
**Output:** 5
**Explanation:** We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

```

**Example 2:**

```

**Input:** nums = [44,22,33,11,1], threshold = 5
**Output:** 44

```

**Constraints:**
* `1 <= nums.length <= 5 * 10^4`
* `1 <= nums[i] <= 10^6`
* `nums.length <= threshold <= 10^6`


<br />

### Hints

- Examine every possible number for solution. Choose the largest of them.
- Use binary search to reduce the time complexity.

<br />

### Solution

```cpp
class Solution {
  public:
    int smallestDivisor (vector <int>& nums, int threshold) {
      int low = 1, high = 1000000 + 42;

      auto cost = [&] (int x) {
        int64_t sum = 0;
        for (int i: nums)
          sum += (i + x - 1) / x;
        return sum <= threshold;
      };

      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }

      return low;
    }
};
```

<br />

### Statistics

- total accepted: 115536
- total submissions: 203447
- acceptance rate: 56.8%
- likes: 2260
- dislikes: 172

<br />

### Similar Problems

- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
