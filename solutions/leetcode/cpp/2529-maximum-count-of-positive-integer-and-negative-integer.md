# [2529] Maximum Count of Positive Integer and Negative Integer



### Statement

Given an array `nums` sorted in **non-decreasing** order, return *the maximum between the number of positive integers and the number of negative integers.*
* In other words, if the number of positive integers in `nums` is `pos` and the number of negative integers is `neg`, then return the maximum of `pos` and `neg`.


**Note** that `0` is neither positive nor negative.


**Example 1:**

```

**Input:** nums = [-2,-1,-1,1,2,3]
**Output:** 3
**Explanation:** There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

```

**Example 2:**

```

**Input:** nums = [-3,-2,-1,0,0,1,2]
**Output:** 3
**Explanation:** There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

```

**Example 3:**

```

**Input:** nums = [5,20,66,1314]
**Output:** 4
**Explanation:** There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

```

**Constraints:**
* `1 <= nums.length <= 2000`
* `-2000 <= nums[i] <= 2000`
* `nums` is sorted in a **non-decreasing order**.


<br>

### Hints

- Count how many positive integers and negative integers are in the array.
- Since the array is sorted, can we use the binary search?

<br>

### Solution

```cpp
class Solution {
  public:
    int maximumCount (vector <int>& nums) {
      int n = nums.size(), neg = 0, pos = 0;
      
      for (int i: nums) {
        if (i < 0)
          ++neg;
        if (i > 0)
          ++pos;
      }
      
      return std::max(neg, pos);
    }
};
```

<br>

### Statistics

- total accepted: 15287
- total submissions: 18991
- acceptance rate: 80.5%
- likes: 47
- dislikes: 2

<br>

### Similar Problems

- [Binary Search](https://leetcode.com/problems/binary-search) (Easy)
- [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix) (Easy)
