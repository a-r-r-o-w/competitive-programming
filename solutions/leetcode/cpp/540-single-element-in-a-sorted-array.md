# [540] Single Element in a Sorted Array

**[array, binary-search]**

### Statement

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return *the single element that appears only once*.

Your solution must run in `O(log n)` time and `O(1)` space.


**Example 1:**

```
**Input:** nums = [1,1,2,3,3,4,4,8,8]
**Output:** 2

```
**Example 2:**

```
**Input:** nums = [3,3,7,7,10,11,11]
**Output:** 10

```

**Constraints:**
* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 105`


<br>

### Hints

None

<br>

### Solution

**O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int singleNonDuplicate (vector <int>& nums) {
      int x = 0;
      for (int n: nums)
        x ^= n;
      return x;
    }
};
```

**O(log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int singleNonDuplicate (vector <int>& nums) {
      if ((int)nums.size() == 1)
        return nums[0];
      
      int n = nums.size();
      int low = 0, high = n;
      
      while (low < high) {
        int mid = (low + high) / 2;
        int len = mid + 1;
        
        if (nums[mid] == nums[mid + (len & 1 ? 1 : -1)])
          low = mid + 1;
        else
          high = mid;
      }
      
      return nums[low];
    }
};
```

<br>

### Statistics

- total accepted: 314926
- total submissions: 537437
- acceptance rate: 58.6%
- likes: 5783
- dislikes: 112

<br>

### Similar Problems

None
