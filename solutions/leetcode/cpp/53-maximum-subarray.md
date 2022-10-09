# [53] Maximum Subarray

**[array, divide-and-conquer, dynamic-programming]**

### Statement

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.

A **subarray** is a **contiguous** part of an array.


**Example 1:**

```

**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]
**Output:** 6
**Explanation:** [4,-1,2,1] has the largest sum = 6.

```

**Example 2:**

```

**Input:** nums = [1]
**Output:** 1

```

**Example 3:**

```

**Input:** nums = [5,4,-1,7,8]
**Output:** 23

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-104 <= nums[i] <= 104`


**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

<br>

### Hints

None

<br>

### Solution

**Kadane's algorithm - O(n)**

```cpp
class Solution {
  public:
    int maxSubArray (vector <int>& nums) {
      int n = nums.size();
      int sum = 0, best = -(1 << 30);
      
      for (int i = 0; i < n; ++i) {
        sum = std::max(nums[i], sum + nums[i]);
        best = std::max(best, sum);
      }
      
      return best;
    }
};
```

**Divide and Conquer - O(n.log(n))**

```cpp
class Solution {
  public:
    int maxSubArray (vector <int>& nums) {
      int n = nums.size();
      
      struct node {
        int prefix = 0;
        int suffix = 0;
        int sum = 0;
        int subsegment = 0;
        
        void combine (const node& l, const node& r) {
          prefix = std::max(l.prefix, l.sum + r.prefix);
          suffix = std::max(l.suffix + r.sum, r.suffix);
          sum = l.sum + r.sum;
          subsegment = std::max({l.subsegment, r.subsegment, l.suffix + r.prefix});
        }
      };
      
      std::vector <node> tree (4 * n);
      
      auto build = [&] (auto self, int v, int l, int r) -> void {
        if (l == r)
          tree[v] = {nums[l], nums[l], nums[l], nums[l]};
        else {
          int m = (l + r) / 2;
          self(self, 2 * v + 1, l, std::min(r, m));
          self(self, 2 * v + 2, std::max(l, m + 1), r);
          tree[v].combine(tree[2 * v + 1], tree[2 * v + 2]);
        }
      };
      
      build(build, 0, 0, n - 1);
      
      return tree[0].subsegment;
    }
};
```

<br>

### Statistics

- total accepted: 2411614
- total submissions: 4862485
- acceptance rate: 49.6%
- likes: 21433
- dislikes: 1061

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray) (Medium)
- [Degree of an Array](https://leetcode.com/problems/degree-of-an-array) (Easy)
- [Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray) (Medium)
- [Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray) (Medium)
- [Maximum Subarray Sum After One Operation](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation) (Medium)
- [Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance) (Hard)
