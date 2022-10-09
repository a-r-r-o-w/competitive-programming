# [977] Squares of a Sorted Array

**[array, two-pointers, sorting]**

### Statement

Given an integer array `nums` sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.


**Example 1:**

```

**Input:** nums = [-4,-1,0,3,10]
**Output:** [0,1,9,16,100]
**Explanation:** After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

```

**Example 2:**

```

**Input:** nums = [-7,-3,2,3,11]
**Output:** [4,9,9,49,121]

```

**Constraints:**
* `1 <= nums.length <= 10^4`
* `-10^4 <= nums[i] <= 10^4`
* `nums` is sorted in **non-decreasing** order.


**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

<br>

### Hints

None

<br>

### Solution

O(n.log(n))

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> sortedSquares (vector <int>& nums) {
      int n = nums.size();
      
      std::transform(nums.begin(), nums.end(), nums.begin(), [] (int x) {
        return x * x;
      });
      
      std::sort(nums.begin(), nums.end());
      
      return nums;
    }
};
```

O(n)

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> sortedSquares (vector <int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1, index = n - 1;
      std::vector <int> ans (n);
      
      while (l <= r) {
        int x = nums[l];
        int y = nums[r];
        x *= x;
        y *= y;
        
        if (x < y)
          ans[index--] = y, --r;
        else
          ans[index--] = x, ++l;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1151786
- total submissions: 1603790
- acceptance rate: 71.8%
- likes: 6288
- dislikes: 163

<br>

### Similar Problems

- [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) (Easy)
- [Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array) (Medium)
