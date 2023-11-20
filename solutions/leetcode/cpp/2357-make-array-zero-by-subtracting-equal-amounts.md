# [2357] Make Array Zero by Subtracting Equal Amounts



### Statement

You are given a non-negative integer array `nums`. In one operation, you must:

* Choose a positive integer `x` such that `x` is less than or equal to the **smallest non-zero** element in `nums`.
* Subtract `x` from every **positive** element in `nums`.



Return *the **minimum** number of operations to make every element in* `nums` *equal to* `0`.


**Example 1:**

```

**Input:** nums = [1,5,0,3,5]
**Output:** 3
**Explanation:**
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

```

**Example 2:**

```

**Input:** nums = [0]
**Output:** 0
**Explanation:** Each element in nums is already 0 so no operations are needed.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`


<br>

### Hints

- It is always best to set x as the smallest non-zero element in nums.
- Elements with the same value will always take the same number of operations to become 0. Contrarily, elements with different values will always take a different number of operations to become 0.
- The answer is the number of unique non-zero numbers in nums.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumOperations (vector <int>& nums) {
      std::unordered_set <int> set (nums.begin(), nums.end());
      return set.size() - set.count(0);
    }
};
```

<br>

### Statistics

- total accepted: 13400
- total submissions: 20209
- acceptance rate: 66.3%
- likes: 26
- dislikes: 2

<br>

### Similar Problems

- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) (Easy)
