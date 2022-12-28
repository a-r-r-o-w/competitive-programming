# [219] Contains Duplicate II

**[array, hash-table, sliding-window]**

### Statement

Given an integer array `nums` and an integer `k`, return `true` if there are two **distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.


**Example 1:**

```

**Input:** nums = [1,2,3,1], k = 3
**Output:** true

```

**Example 2:**

```

**Input:** nums = [1,0,1,1], k = 1
**Output:** true

```

**Example 3:**

```

**Input:** nums = [1,2,3,1,2,3], k = 2
**Output:** false

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-109 <= nums[i] <= 109`
* `0 <= k <= 105`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool containsNearbyDuplicate (vector <int>& nums, int k) {
      std::map <int, int> have;
      int n = nums.size();
      bool okay = false;
      
      for (int i = 0; i < n; ++i) {
        if (have.count(nums[i])) {
          if (i - have[nums[i]] <= k) {
            okay = true;
            break;
          }
        }
        have[nums[i]] = i;
      }
      
      return okay;
    }
};
```

<br>

### Statistics

- total accepted: 515330
- total submissions: 1260768
- acceptance rate: 40.9%
- likes: 3070
- dislikes: 2083

<br>

### Similar Problems

- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) (Easy)
- [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii) (Medium)
