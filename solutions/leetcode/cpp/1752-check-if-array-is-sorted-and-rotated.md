# [1752] Check if Array Is Sorted and Rotated

**[array]**

### Statement

Given an array `nums`, return `true` *if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)*. Otherwise, return `false`.

There may be **duplicates** in the original array.

**Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `A[i] == B[(i+x) % A.length]`, where `%` is the modulo operation.


**Example 1:**

```

**Input:** nums = [3,4,5,1,2]
**Output:** true
**Explanation:** [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

```

**Example 2:**

```

**Input:** nums = [2,1,3,4]
**Output:** false
**Explanation:** There is no sorted array once rotated that can make nums.

```

**Example 3:**

```

**Input:** nums = [1,2,3]
**Output:** true
**Explanation:** [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`


<br>

### Hints

- Brute force and check if it is possible for a sorted array to start from each position.

<br>

### Solution

```cpp
class Solution {
  public:
    bool check (vector <int>& nums) {
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        if (std::is_sorted(nums.begin(), nums.end()))
          return true;
        std::rotate(nums.begin(), nums.begin() + 1, nums.end());
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 64103
- total submissions: 129846
- acceptance rate: 49.4%
- likes: 1245
- dislikes: 64

<br>

### Similar Problems

- [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs) (Easy)
