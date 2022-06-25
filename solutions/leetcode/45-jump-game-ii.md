# [45] Jump Game II

**[array, dynamic-programming, greedy]**

### Statement

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.


**Example 1:**

```

**Input:** nums = [2,3,1,1,4]
**Output:** 2
**Explanation:** The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

```

**Example 2:**

```

**Input:** nums = [2,3,0,1,4]
**Output:** 2

```

**Constraints:**
* `1 <= nums.length <= 104`
* `0 <= nums[i] <= 1000`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int jump (vector <int>& nums) {
      int n = nums.size();
      int max = 0, next = 0, i = 0, ans = 0;
      
      while (next < n - 1) {
        max = std::max(max, i + nums[i]);
        if (i == next) {
          next = max;
          ++ans;
        }
        ++i;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 631020
- total submissions: 1678321
- acceptance rate: 37.6%
- likes: 8390
- dislikes: 312

<br>

### Similar Problems

- [Jump Game](https://leetcode.com/problems/jump-game) (Medium)
- [Jump Game III](https://leetcode.com/problems/jump-game-iii) (Medium)
- [Jump Game VII](https://leetcode.com/problems/jump-game-vii) (Medium)
- [Jump Game VIII](https://leetcode.com/problems/jump-game-viii) (Medium)
