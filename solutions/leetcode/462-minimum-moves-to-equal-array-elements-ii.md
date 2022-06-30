# [462] Minimum Moves to Equal Array Elements II

**[array, math, sorting]**

### Statement

Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.

In one move, you can increment or decrement an element of the array by `1`.

Test cases are designed so that the answer will fit in a **32-bit** integer.


**Example 1:**

```

**Input:** nums = [1,2,3]
**Output:** 2
**Explanation:**
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

```

**Example 2:**

```

**Input:** nums = [1,10,2,9]
**Output:** 16

```

**Constraints:**
* `n == nums.length`
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
    int minMoves2 (vector <int>& nums) {
      int n = nums.size();
      
      std::sort(nums.begin(), nums.end());
      
      int median = nums[n / 2], ans = 0;
      
      for (int i = 0; i < n; ++i)
        ans += std::abs(nums[i] - median);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 102524
- total submissions: 176691
- acceptance rate: 58.0%
- likes: 1707
- dislikes: 80

<br>

### Similar Problems

- [Best Meeting Point](https://leetcode.com/problems/best-meeting-point) (Hard)
- [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements) (Medium)
- [Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid) (Medium)
- [Removing Minimum Number of Magic Beans](https://leetcode.com/problems/removing-minimum-number-of-magic-beans) (Medium)
