# [2256] Minimum Average Difference

**[array, prefix-sum]**

### Statement

You are given a **0-indexed** integer array `nums` of length `n`.

The **average difference** of the index `i` is the **absolute** **difference** between the average of the **first** `i + 1` elements of `nums` and the average of the **last** `n - i - 1` elements. Both averages should be **rounded down** to the nearest integer.

Return *the index with the **minimum average difference***. If there are multiple such indices, return the **smallest** one.

**Note:**
* The **absolute difference** of two numbers is the absolute value of their difference.
* The **average** of `n` elements is the **sum** of the `n` elements divided (**integer division**) by `n`.
* The average of `0` elements is considered to be `0`.


**Example 1:**

```

**Input:** nums = [2,5,3,9,5,3]
**Output:** 3
**Explanation:**
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.

```

**Example 2:**

```

**Input:** nums = [0]
**Output:** 0
**Explanation:**
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 105`


<br>

### Hints

- How can we use precalculation to efficiently calculate the average difference at an index?
- Create a prefix and/or suffix sum array.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumAverageDifference (vector <int>& nums) {
      int64_t rsum = std::accumulate(nums.begin(), nums.end(), int64_t(0)), lsum = 0, min = 1LL << 60;
      int n = nums.size(), index = -1;
      
      for (int i = 0; i < n; ++i) {
        rsum -= nums[i];
        lsum += nums[i];
        int64_t x = std::abs(lsum / (i + 1) - (n - i - 1 == 0 ? 0 : rsum / (n - i - 1)));
        if (x < min) {
          min = x;
          index = i;
        }
      }
      
      return index;
    }
};
```

<br>

### Statistics

- total accepted: 40741
- total submissions: 98526
- acceptance rate: 41.4%
- likes: 760
- dislikes: 90

<br>

### Similar Problems

- [Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average) (Hard)
- [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array) (Medium)
