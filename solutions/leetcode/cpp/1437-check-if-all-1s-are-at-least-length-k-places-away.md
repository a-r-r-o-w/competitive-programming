# [1437] Check If All 1's Are at Least Length K Places Away

**[array]**

### Statement

Given an binary array `nums` and an integer `k`, return `true` *if all* `1`*'s are at least* `k` *places away from each other, otherwise return* `false`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png)

```

**Input:** nums = [1,0,0,0,1,0,0,1], k = 2
**Output:** true
**Explanation:** Each of the 1s are at least 2 places away from each other.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png)

```

**Input:** nums = [1,0,0,1,0,1], k = 2
**Output:** false
**Explanation:** The second 1 and third 1 are only one apart from each other.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `0 <= k <= nums.length`
* `nums[i]` is `0` or `1`


<br>

### Hints

- Each time you find a number 1, check whether or not it is K or more places away from the next one. If it's not, return false.

<br>

### Solution

```cpp
class Solution {
  public:
    bool kLengthApart (vector <int>& nums, int k) {
      int n = nums.size(), last = -(1 << 30);

      for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
          if (i - last - 1 < k)
            return false;
          last = i;
        }
      }

      return true;
    }
};
```

<br>

### Statistics

- total accepted: 63852
- total submissions: 108111
- acceptance rate: 59.1%
- likes: 485
- dislikes: 205

<br>

### Similar Problems

- [Task Scheduler II](https://leetcode.com/problems/task-scheduler-ii) (Medium)
