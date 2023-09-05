# [1909] Remove One Element to Make the Array Strictly Increasing

**[array]**

### Statement

Given a **0-indexed** integer array `nums`, return `true` *if it can be made **strictly increasing** after removing **exactly one** element, or* `false` *otherwise. If the array is already strictly increasing, return* `true`.

The array `nums` is **strictly increasing** if `nums[i - 1] < nums[i]` for each index `(1 <= i < nums.length).`
**Example 1:**

```

**Input:** nums = [1,2,10,5,7]
**Output:** true
**Explanation:** By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.

```

**Example 2:**

```

**Input:** nums = [2,3,1,2]
**Output:** false
**Explanation:**
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.
```

**Example 3:**

```

**Input:** nums = [1,1,1]
**Output:** false
**Explanation:** The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.

```

**Constraints:**
* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`


<br>

### Hints

- For each index i in nums remove this index.
- If the array becomes sorted return true, otherwise revert to the original array and try different index.

<br>

### Solution

```cpp
class Solution {
  public:
    bool canBeIncreasing (vector <int>& nums) {
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        int count = 0, prev = 0;
        
        for (int j = 0; j < n; ++j) {
          if (j == i)
            continue;
          if (nums[j] <= prev)
            ++count;
          prev = nums[j];
        }
        
        if (count == 0)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 39448
- total submissions: 151443
- acceptance rate: 26.0%
- likes: 824
- dislikes: 252

<br>

### Similar Problems

- [Steps to Make Array Non-decreasing](https://leetcode.com/problems/steps-to-make-array-non-decreasing) (Medium)
