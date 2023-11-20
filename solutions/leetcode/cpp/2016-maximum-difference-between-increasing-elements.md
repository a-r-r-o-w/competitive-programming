# [2016] Maximum Difference Between Increasing Elements

**[array]**

### Statement

Given a **0-indexed** integer array `nums` of size `n`, find the **maximum difference** between `nums[i]` and `nums[j]` (i.e., `nums[j] - nums[i]`), such that `0 <= i < j < n` and `nums[i] < nums[j]`.

Return *the **maximum difference**.* If no such `i` and `j` exists, return `-1`.


**Example 1:**

```

**Input:** nums = [7,**1**,**5**,4]
**Output:** 4
**Explanation:**
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

```

**Example 2:**

```

**Input:** nums = [9,4,3,2]
**Output:** -1
**Explanation:**
There is no i and j such that i < j and nums[i] < nums[j].

```

**Example 3:**

```

**Input:** nums = [**1**,5,2,**10**]
**Output:** 9
**Explanation:**
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

```

**Constraints:**
* `n == nums.length`
* `2 <= n <= 1000`
* `1 <= nums[i] <= 109`


<br>

### Hints

- Could you keep track of the minimum element visited while traversing?
- We have a potential candidate for the answer if the prefix min is lesser than nums[i].

<br>

### Solution

O(N^2)

```cpp
class Solution {
  public:
    int maximumDifference (vector <int>& nums) {
      int max = 0, n = nums.size();

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
          max = std::max(max, nums[j] - nums[i]);
      }

      if (max <= 0)
        max = -1;
      
      return max;
    }
};
```

O(N)

```cpp


O(N)

```cpp
class Solution {
  public:
    int maximumDifference (vector <int>& nums) {
      int n = nums.size(), max = 0, min = nums[0];

      for (int i = 1; i < n; ++i) {
        max = std::max(max, nums[i] - min);
        min = std::min(min, nums[i]);
      }

      if (max <= 0)
        max = -1;
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 52338
- total submissions: 97470
- acceptance rate: 53.7%
- likes: 702
- dislikes: 24

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors) (Easy)
