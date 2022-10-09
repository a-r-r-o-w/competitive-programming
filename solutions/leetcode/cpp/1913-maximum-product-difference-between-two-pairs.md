# [1913] Maximum Product Difference Between Two Pairs

**[array, sorting]**

### Statement

The **product difference** between two pairs `(a, b)` and `(c, d)` is defined as `(a * b) - (c * d)`.

* For example, the product difference between `(5, 6)` and `(2, 7)` is `(5 * 6) - (2 * 7) = 16`.



Given an integer array `nums`, choose four **distinct** indices `w`, `x`, `y`, and `z` such that the **product difference** between pairs `(nums[w], nums[x])` and `(nums[y], nums[z])` is **maximized**.

Return *the **maximum** such product difference*.


**Example 1:**

```

**Input:** nums = [5,6,2,7,4]
**Output:** 34
**Explanation:** We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 \* 7) - (2 \* 4) = 34.

```

**Example 2:**

```

**Input:** nums = [4,2,5,9,7,4,8]
**Output:** 64
**Explanation:** We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 \* 8) - (2 \* 4) = 64.

```

**Constraints:**
* `4 <= nums.length <= 104`
* `1 <= nums[i] <= 104`


<br>

### Hints

- If you only had to find the maximum product of 2 numbers in an array, which 2 numbers should you choose?
- We only need to worry about 4 numbers in the array.

<br>

### Solution

Sorting

```cpp
class Solution {
  public:
    int maxProductDifference (vector <int>& nums) {
      std::sort(nums.begin(), nums.end());
      int n = nums.size();
      return nums[n - 2] * nums[n - 1] - nums[0] * nums[1];
    }
};
```

Maintaining two maximums and two minimums

```cpp
class Solution {
  public:
    int maxProductDifference (vector <int>& nums) {
      const int inf32 = 1e9 + 42;
      int max[2] = {-inf32, -inf32};
      int min[2] = {+inf32, +inf32};
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        if (nums[i] > max[0]) {
          max[1] = max[0];
          max[0] = nums[i];
        }
        else if (nums[i] > max[1]) {
          max[1] = nums[i];
        }
        if (nums[i] < min[0]) {
          min[1] = min[0];
          min[0] = nums[i];
        }
        else if (nums[i] < min[1]) {
          min[1] = nums[i];
        }
      }
      
      return max[0] * max[1] - min[0] * min[1];
    }
};
```

<br>

### Statistics

- total accepted: 60080
- total submissions: 73916
- acceptance rate: 81.3%
- likes: 519
- dislikes: 28

<br>

### Similar Problems

None
