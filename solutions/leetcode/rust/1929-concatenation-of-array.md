# [1929] Concatenation of Array

**[array]**

### Statement

Given an integer array `nums` of length `n`, you want to create an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n` (**0-indexed**).

Specifically, `ans` is the **concatenation** of two `nums` arrays.

Return *the array* `ans`.


**Example 1:**

```

**Input:** nums = [1,2,1]
**Output:** [1,2,1,1,2,1]
**Explanation:** The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
```

**Example 2:**

```

**Input:** nums = [1,3,2,1]
**Output:** [1,3,2,1,1,3,2,1]
**Explanation:** The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]

```

**Constraints:**
* `n == nums.length`
* `1 <= n <= 1000`
* `1 <= nums[i] <= 1000`


<br />

### Hints

- Build an array of size 2 * n and assign num[i] to ans[i] and ans[i + n]

<br />

### Solution

```rust
impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
      return nums.repeat(2);
    }
}
```

<br />

### Statistics

- total accepted: 537904
- total submissions: 600722
- acceptance rate: 89.5%
- likes: 2846
- dislikes: 335

<br />

### Similar Problems

None
