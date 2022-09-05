# [217] Contains Duplicate

**[array, hash-table, sorting]**

### Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.


**Example 1:**

```
**Input:** nums = [1,2,3,1]
**Output:** true

```
**Example 2:**

```
**Input:** nums = [1,2,3,4]
**Output:** false

```
**Example 3:**

```
**Input:** nums = [1,1,1,3,3,4,3,2,4,2]
**Output:** true

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-109 <= nums[i] <= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool containsDuplicate (vector <int>& nums) {
      std::sort(nums.begin(), nums.end());
      
      bool occurs_twice = false;
      
      for (int i = 0; i < (int)nums.size() - 1; ++i)
        if (nums[i] == nums[i + 1]) {
          occurs_twice = true;
          break;
        }
      
      return occurs_twice;
    }
};
```

<br>

### Statistics

- total accepted: 2000428
- total submissions: 3271660
- acceptance rate: 61.1%
- likes: 6379
- dislikes: 1018

<br>

### Similar Problems

- [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) (Easy)
- [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii) (Medium)
- [Make Array Zero by Subtracting Equal Amounts](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts) (Easy)
