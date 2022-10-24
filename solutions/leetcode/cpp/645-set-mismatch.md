# [645] Set Mismatch

**[array, hash-table, bit-manipulation, sorting]**

### Statement

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return *them in the form of an array*.


**Example 1:**

```
**Input:** nums = [1,2,2,4]
**Output:** [2,3]

```
**Example 2:**

```
**Input:** nums = [1,1]
**Output:** [1,2]

```

**Constraints:**
* `2 <= nums.length <= 104`
* `1 <= nums[i] <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> findErrorNums (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> have (n);
      
      for (int i = 0; i < n; ++i)
        have[nums[i] - 1] += 1;
      
      int duplicate = -1, missing = -1;
      
      for (int i = 0; i < n; ++i) {
        if (have[i] == 0)
          missing = i + 1;
        else if (have[i] == 2)
          duplicate = i + 1;
      }
      
      return {duplicate, missing};
    }
};
```

<br>

### Statistics

- total accepted: 203372
- total submissions: 484979
- acceptance rate: 41.9%
- likes: 2585
- dislikes: 646

<br>

### Similar Problems

- [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) (Medium)
