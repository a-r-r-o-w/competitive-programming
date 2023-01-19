# [303] Range Sum Query - Immutable

**[array, design, prefix-sum]**

### Statement

Given an integer array `nums`, handle multiple queries of the following type:

1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.



Implement the `NumArray` class:

* `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
* `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).


**Example 1:**

```

**Input**
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
**Output**
[null, 1, -1, -3]

**Explanation**
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-105 <= nums[i] <= 105`
* `0 <= left <= right < nums.length`
* At most `104` calls will be made to `sumRange`.


<br>

### Hints

None

<br>

### Solution

```cpp
class NumArray {
    std::vector <int> v;
  public:
    NumArray (vector <int>& nums) {
      int n = nums.size();
      v.resize(n + 1);

      for (int i = 1; i <= n; ++i)
        v[i] = v[i - 1] + nums[i - 1];
    }
    
    int sumRange (int left, int right) {
      return v[right + 1] - v[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```

<br>

### Statistics

- total accepted: 412051
- total submissions: 701946
- acceptance rate: 58.7%
- likes: 2545
- dislikes: 1764

<br>

### Similar Problems

- [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable) (Medium)
- [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable) (Medium)
- [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k) (Medium)
