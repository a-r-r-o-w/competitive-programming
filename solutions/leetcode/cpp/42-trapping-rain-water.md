# [42] Trapping Rain Water

**[array, two-pointers, dynamic-programming, stack, monotonic-stack]**

### Statement

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```

**Input:** height = [0,1,0,2,1,0,1,3,2,1,2,1]
**Output:** 6
**Explanation:** The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

**Example 2:**

```

**Input:** height = [4,2,0,3,2,5]
**Output:** 9

```

**Constraints:**
* `n == height.length`
* `1 <= n <= 2 * 104`
* `0 <= height[i] <= 105`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int trap (vector <int>& height) {
      int n = height.size();
      std::vector <int> left_max (n), right_max (n);
      
      left_max.front() = height.front();
      right_max.back() = height.back();
      
      for (int i = 1; i < n; ++i)
        left_max[i] = std::max(left_max[i - 1], height[i]);
      
      for (int i = n - 2; i >= 0; --i)
        right_max[i] = std::max(right_max[i + 1], height[i]);
      
      int trapped = 0;
      
      for (int i = 0; i < n; ++i)
        trapped += std::min(left_max[i], right_max[i]) - height[i];
      
      return trapped;
    }
};
```

<br>

### Statistics

- total accepted: 1319238
- total submissions: 2259190
- acceptance rate: 58.4%
- likes: 22630
- dislikes: 305

<br>

### Similar Problems

- [Container With Most Water](https://leetcode.com/problems/container-with-most-water) (Medium)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) (Medium)
- [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii) (Hard)
- [Pour Water](https://leetcode.com/problems/pour-water) (Medium)
