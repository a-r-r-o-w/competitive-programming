# [704] Binary Search

**[array, binary-search]**

### Statement

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.


**Example 1:**

```

**Input:** nums = [-1,0,3,5,9,12], target = 9
**Output:** 4
**Explanation:** 9 exists in nums and its index is 4

```

**Example 2:**

```

**Input:** nums = [-1,0,3,5,9,12], target = 2
**Output:** -1
**Explanation:** 2 does not exist in nums so return -1

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-104 < nums[i], target < 104`
* All the integers in `nums` are **unique**.
* `nums` is sorted in ascending order.


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
  
    int search (vector <int>& nums, int target) {
      int n = nums.size();
      int low = 0, high = n;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
          low = mid + 1;
        else
          high = mid;
      }
      
      if (low == n or nums[low] != target)
        return -1;
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 1088112
- total submissions: 1970675
- acceptance rate: 55.2%
- likes: 5761
- dislikes: 132

<br>

### Similar Problems

- [Search in a Sorted Array of Unknown Size](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size) (Medium)
