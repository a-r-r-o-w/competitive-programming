# [35] Search Insert Position

**[array, binary-search]**

### Statement

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You mustwrite an algorithm with`O(log n)` runtime complexity.


**Example 1:**

```

**Input:** nums = [1,3,5,6], target = 5
**Output:** 2

```

**Example 2:**

```

**Input:** nums = [1,3,5,6], target = 2
**Output:** 1

```

**Example 3:**

```

**Input:** nums = [1,3,5,6], target = 7
**Output:** 4

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` contains **distinct** values sorted in **ascending** order.
* `-104 <= target <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int searchInsert (vector <int>& nums, int target) {
      int n = nums.size();
      int low = 0, high = n;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 1542033
- total submissions: 3649782
- acceptance rate: 42.3%
- likes: 8463
- dislikes: 433

<br>

### Similar Problems

- [First Bad Version](https://leetcode.com/problems/first-bad-version) (Easy)
