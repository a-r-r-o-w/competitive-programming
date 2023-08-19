# [2815] Max Pair Sum in an Array



### Statement

You are given a **0-indexed** integer array `nums`. You have to find the **maximum** sum of a pair of numbers from `nums` such that the maximum **digit** in both numbers are equal.

Return *the maximum sum or* `-1` *if no such pair exists*.


**Example 1:**

```

**Input:** nums = [51,71,17,24,42]
**Output:** 88
**Explanation:** 
For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.
```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** -1
**Explanation:** No pair exists in nums with equal maximum digits.

```

**Constraints:**
* `2 <= nums.length <= 100`
* `1 <= nums[i] <= 10^4`


<br />

### Hints

- Find the largest and second largest element with maximum digits equal to x where 1<=x<=9.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxSum (vector <int>& nums) {
      std::vector <std::vector <int>> map (10);
      int ans = -1;
      
      for (int i: nums) {
        int m = 0, x = i;
        while (x) {
          m = std::max(m, x % 10);
          x /= 10;
        }
        map[m].push_back(i);
      }
      for (auto &r: map) {
        std::sort(r.begin(), r.end());
        int k = r.size();
        if (k >= 2)
          ans = std::max(ans, r[k - 1] + r[k - 2]);
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 17746
- total submissions: 31524
- acceptance rate: 56.3%
- likes: 56
- dislikes: 24

<br />

### Similar Problems

None
