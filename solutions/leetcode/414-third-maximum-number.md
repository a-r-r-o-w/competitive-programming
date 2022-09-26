# [414] Third Maximum Number

**[array, sorting]**

### Statement

Given an integer array `nums`, return *the **third distinct maximum** number in this array. If the third maximum does not exist, return the **maximum** number*.


**Example 1:**

```

**Input:** nums = [3,2,1]
**Output:** 1
**Explanation:**
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

```

**Example 2:**

```

**Input:** nums = [1,2]
**Output:** 2
**Explanation:**
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

```

**Example 3:**

```

**Input:** nums = [2,2,3,1]
**Output:** 1
**Explanation:**
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-231 <= nums[i] <= 231 - 1`


**Follow up:** Can you find an `O(n)` solution?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int thirdMax (vector <int>& nums) {
      const int64_t neginf = std::numeric_limits <int64_t>::min();
      
      int64_t m1 = neginf, m2 = neginf, m3 = neginf;
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        if (nums[i] > m1) {
          m3 = m2;
          m2 = m1;
          m1 = nums[i];
        }
        else if (nums[i] < m1 and nums[i] > m2) {
          m3 = m2;
          m2 = nums[i];
        }
        else if (nums[i] < m2 and nums[i] > m3)
          m3 = nums[i];
      }
      
      if (m3 == neginf)
        return m1;
      
      return m3;
    }
};
```

<br>

### Statistics

- total accepted: 360761
- total submissions: 1118205
- acceptance rate: 32.3%
- likes: 1916
- dislikes: 2453

<br>

### Similar Problems

- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) (Medium)
