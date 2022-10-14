# [740] Delete and Earn

**[array, hash-table, dynamic-programming]**

### Statement

You are given an integer array `nums`. You want to maximize the number of points you get by performing the following operation any number of times:

* Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete **every** element equal to `nums[i] - 1` and **every** element equal to `nums[i] + 1`.



Return *the **maximum number of points** you can earn by applying the above operation some number of times*.


**Example 1:**

```

**Input:** nums = [3,4,2]
**Output:** 6
**Explanation:** You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

```

**Example 2:**

```

**Input:** nums = [2,2,3,3,3,4]
**Output:** 9
**Explanation:** You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```

**Constraints:**
* `1 <= nums.length <= 2 * 104`
* `1 <= nums[i] <= 104`


<br>

### Hints

- If you take a number, you might as well take them all.  Keep track of what the value is of the subset of the input with maximum M when you either take or don't take M.

<br>

### Solution

```cpp
class Solution {
  public:
    int deleteAndEarn (vector <int>& nums) {
      const int max = 10000 + 1;
      std::vector <int> points (max);
      
      for (int i: nums)
        points[i] += i;
      
      int x = 0, y = points[1];
      int ans = y;
      
      for (int i = 2; i < max; ++i) {
        int z = std::max(y, x + points[i]);
        x = y;
        y = z;
        ans = std::max(ans, y);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 224413
- total submissions: 390766
- acceptance rate: 57.4%
- likes: 5539
- dislikes: 293

<br>

### Similar Problems

- [House Robber](https://leetcode.com/problems/house-robber) (Medium)
