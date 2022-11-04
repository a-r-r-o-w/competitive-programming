# [2420] Find All Good Indices

**[array, dynamic-programming, prefix-sum]**

### Statement

You are given a **0-indexed** integer array `nums` of size `n` and a positive integer `k`.

We call an index `i` in the range `k <= i < n - k` **good** if the following conditions are satisfied:

* The `k` elements that are just **before** the index `i` are in **non-increasing** order.
* The `k` elements that are just **after** the index `i` are in **non-decreasing** order.



Return *an array of all good indices sorted in **increasing** order*.


**Example 1:**

```

**Input:** nums = [2,1,1,1,3,4,1], k = 2
**Output:** [2,3]
**Explanation:** There are two good indices in the array:
- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
Note that the index 4 is not good because [4,1] is not non-decreasing.
```

**Example 2:**

```

**Input:** nums = [2,1,1,2], k = 2
**Output:** []
**Explanation:** There are no good indices in this array.

```

**Constraints:**
* `n == nums.length`
* `3 <= n <= 105`
* `1 <= nums[i] <= 106`
* `1 <= k <= n / 2`


<br>

### Hints

- Iterate over all indices i. How do you quickly check the two conditions?
- Precompute for each index whether the conditions are satisfied on the left and the right of the index. You can do that with two iterations, from left to right and right to left.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> goodIndices (vector <int>& nums, int k) {
      int start = k, n = nums.size();
      std::vector <int> good;
      std::vector <bool> usable_left (n), usable_right (n);
      int count = 1;
      
      for (int i = 0; i < n; ++i) {
        if (i == 0 or nums[i - 1] < nums[i])
          count = 1;
        else
          count += 1;
        if (count >= k)
          usable_left[i] = true;
      }
      
      for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 or nums[i] > nums[i + 1])
          count = 1;
        else
          count += 1;
        if (count >= k)
          usable_right[i] = true;
      }
      
      for (int i = k; i < n - k; ++i)
        if (usable_left[i - 1] and usable_right[i + 1])
          good.push_back(i);
      
      return good;
    }
};
```

<br>

### Statistics

- total accepted: 16284
- total submissions: 44078
- acceptance rate: 36.9%
- likes: 421
- dislikes: 24

<br>

### Similar Problems

- [Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank) (Medium)
- [Abbreviating the Product of a Range](https://leetcode.com/problems/abbreviating-the-product-of-a-range) (Hard)
