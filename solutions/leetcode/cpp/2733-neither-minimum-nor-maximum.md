# [2733] Neither Minimum nor Maximum

**[array, sorting]**

### Statement

Given an integer array `nums` containing **distinct** **positive** integers, find and return **any** number from the array that is neither the **minimum** nor the **maximum** value in the array, or **`-1`** if there is no such number.

Return *the selected integer.*
**Example 1:**

```

**Input:** nums = [3,2,1,4]
**Output:** 2
**Explanation:** In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.

```

**Example 2:**

```

**Input:** nums = [1,2]
**Output:** -1
**Explanation:** Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.

```

**Example 3:**

```

**Input:** nums = [2,1,3]
**Output:** 2
**Explanation:** Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer. 

```

**Constraints:**
* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* All values in `nums` are distinct


<br />

### Hints

- Find any value in the array that is not the minimum or the maximum value.

<br />

### Solution

```cpp
class Solution {
  public:
    int findNonMinOrMax (vector <int>& nums) {
      if ((int)nums.size() <= 2)
        return -1;
      std::sort(nums.begin(), nums.begin() + 3);
      return nums[1];
    }
};
```

```cpp
class Solution {
  public:
    int findNonMinOrMax (vector <int>& nums) {
      std::set <int> have (nums.begin(), nums.end());
      if ((int)have.size() <= 2)
        return -1;
      have.erase(have.begin());
      return *have.begin();
    }
};
```

<br />

### Statistics

- total accepted: 41360
- total submissions: 52272
- acceptance rate: 79.1%
- likes: 132
- dislikes: 2

<br />

### Similar Problems

- [Third Maximum Number](https://leetcode.com/problems/third-maximum-number) (Easy)
