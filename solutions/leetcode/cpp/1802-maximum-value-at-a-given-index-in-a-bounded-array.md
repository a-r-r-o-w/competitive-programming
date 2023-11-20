# [1802] Maximum Value at a Given Index in a Bounded Array

**[binary-search, greedy]**

### Statement

You are given three positive integers:`n`, `index`, and `maxSum`. You want to construct an array `nums` (**0-indexed**)that satisfies the following conditions:

* `nums.length == n`
* `nums[i]` is a **positive** integer where `0 <= i < n`.
* `abs(nums[i] - nums[i+1]) <= 1` where `0 <= i < n-1`.
* The sum of all the elements of `nums` does not exceed `maxSum`.
* `nums[index]` is **maximized**.



Return `nums[index]` *of the constructed array*.

Note that `abs(x)` equals `x` if `x >= 0`, and `-x` otherwise.


**Example 1:**

```

**Input:** n = 4, index = 2,  maxSum = 6
**Output:** 2
**Explanation:** nums = [1,2,**2**,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

```

**Example 2:**

```

**Input:** n = 6, index = 1,  maxSum = 10
**Output:** 3

```

**Constraints:**
* `1 <= n <= maxSum <= 10^9`
* `0 <= index < n`


<br />

### Hints

- What if the problem was instead determining if you could generate a valid array with nums[index] == target?
- To generate the array, set nums[index] to target, nums[index-i] to target-i, and nums[index+i] to target-i. Then, this will give the minimum possible sum, so check if the sum is less than or equal to maxSum.
- n is too large to actually generate the array, so you can use the formula 1 + 2 + ... + n = n * (n+1) / 2 to quickly find the sum of nums[0...index] and nums[index...n-1].
- Binary search for the target. If it is possible, then move the lower bound up. Otherwise, move the upper bound down.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxValue(int n, int index, int maxSum) {
      int64_t low = 1, high = 1e9 + 42;

      while (low < high) {
        int64_t mid = (low + high) / 2;
        int64_t sum = 0, rindex = n - index - 1;
        if (mid > index) {
          int64_t r = mid - index - 1;
          sum += mid * (mid + 1) / 2 - r * (r + 1) / 2;
        }
        else {
          int64_t r = index - mid + 1;
          sum += mid * (mid + 1) / 2 + r;
        }
        if (mid > rindex) {
          int64_t r = mid - rindex - 1;
          sum += mid * (mid + 1) / 2 - r * (r + 1) / 2;
        }
        else {
          int64_t r = rindex - mid + 1;
          sum += mid * (mid + 1) / 2 + r;
        }
        sum -= mid;
        if (sum > maxSum)
          high = mid;
        else
          low = mid + 1;
      }

      return low - 1;
    }
};
```

<br />

### Statistics

- total accepted: 38023
- total submissions: 100826
- acceptance rate: 37.7%
- likes: 1726
- dislikes: 275

<br />

### Similar Problems

None
