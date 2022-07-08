# [152] Maximum Product Subarray

**[array, dynamic-programming]**

### Statement

Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return *the product*.

The test cases are generated so that the answer will fit in a **32-bit** integer.

A **subarray** is a contiguous subsequence of the array.


**Example 1:**

```

**Input:** nums = [2,3,-2,4]
**Output:** 6
**Explanation:** [2,3] has the largest product 6.

```

**Example 2:**

```

**Input:** nums = [-2,0,-1]
**Output:** 0
**Explanation:** The result cannot be 2, because [-2,-1] is not a subarray.

```

**Constraints:**
* `1 <= nums.length <= 2 * 104`
* `-10 <= nums[i] <= 10`
* The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int maxProduct (vector <int>& nums) {
      int n = nums.size();
      int max = -(1 << 30), product = 1;
      
      for (int i = 0; i < n; ++i) {
        product *= nums[i];
        max = std::max(max, product);
        if (product == 0)
          product = 1;
      }
      
      product = 1;
      for (int i = n - 1; i >= 0; --i) {
        product *= nums[i];
        max = std::max(max, product);
        if (product == 0)
          product = 1;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 789772
- total submissions: 2276893
- acceptance rate: 34.7%
- likes: 12372
- dislikes: 373

<br>

### Similar Problems

- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) (Medium)
- [House Robber](https://leetcode.com/problems/house-robber) (Medium)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) (Medium)
- [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers) (Easy)
- [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k) (Medium)
