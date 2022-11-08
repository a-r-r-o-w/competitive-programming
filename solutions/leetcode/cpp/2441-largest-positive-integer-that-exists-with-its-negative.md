# [2441] Largest Positive Integer That Exists With Its Negative



### Statement

Given an integer array `nums` that **does not contain** any zeros, find **the largest positive** integer `k` such that `-k` also exists in the array.

Return *the positive integer* `k`. If there is no such integer, return `-1`.


**Example 1:**

```

**Input:** nums = [-1,2,-3,3]
**Output:** 3
**Explanation:** 3 is the only valid k we can find in the array.

```

**Example 2:**

```

**Input:** nums = [-1,10,6,7,-7,1]
**Output:** 7
**Explanation:** Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.

```

**Example 3:**

```

**Input:** nums = [-10,8,6,7,-2,-3]
**Output:** -1
**Explanation:** There is no a single valid k, we return -1.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `-1000 <= nums[i] <= 1000`
* `nums[i] != 0`


<br>

### Hints

- What data structure can help you to determine if an element exists?
- Would a hash table help?

<br>

### Solution

```cpp
class Solution {
  public:
    int findMaxK (vector <int>& nums) {
      std::unordered_set <int> have;
      int max = -1;
      
      for (int i: nums) {
        if (have.count(-i))
          max = std::max(max, std::abs(i));
        have.insert(i);
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 16595
- total submissions: 24236
- acceptance rate: 68.5%
- likes: 96
- dislikes: 2

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
