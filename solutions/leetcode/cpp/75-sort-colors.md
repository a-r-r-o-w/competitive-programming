# [75] Sort Colors

**[array, two-pointers, sorting]**

### Statement

Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


**Example 1:**

```

**Input:** nums = [2,0,2,1,1,0]
**Output:** [0,0,1,1,2,2]

```

**Example 2:**

```

**Input:** nums = [2,0,1]
**Output:** [0,1,2]

```

**Constraints:**
* `n == nums.length`
* `1 <= n <= 300`
* `nums[i]` is either `0`, `1`, or `2`.


**Follow up:**Could you come up with a one-pass algorithm using onlyconstant extra space?

<br />

### Hints

- A rather straight forward solution is a two-pass algorithm using counting sort.
- Iterate the array counting number of 0's, 1's, and 2's.
- Overwrite array with the total number of 0's, then 1's and followed by 2's.

<br />

### Solution

```cpp
class Solution {
  public:
    void sortColors (vector <int>& nums) {
      int n = nums.size(), l = 0, r = n - 1;

      for (int i = 0; i <= r; ++i) {
        if (nums[i] == 0) {
          std::swap(nums[i], nums[l]);
          ++l;
        }
        else if (nums[i] == 2) {
          std::swap(nums[i], nums[r]);
          --i;
          --r;
        }
      }
    }
};
```

<br />

### Statistics

- total accepted: 1523375
- total submissions: 2551990
- acceptance rate: 59.7%
- likes: 15943
- dislikes: 559

<br />

### Similar Problems

- [Sort List](https://leetcode.com/problems/sort-list) (Medium)
- [Wiggle Sort](https://leetcode.com/problems/wiggle-sort) (Medium)
- [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii) (Medium)
