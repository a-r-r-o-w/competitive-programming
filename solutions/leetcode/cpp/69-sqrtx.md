# [69] Sqrt(x)

**[math, binary-search]**

### Statement

Given a non-negative integer `x`,compute and return *the square root of* `x`.

Since the return typeis an integer, the decimal digits are **truncated**, and only **the integer part** of the resultis returned.

**Note:**You are not allowed to use any built-in exponent function or operator, such as `pow(x, 0.5)` or`x ** 0.5`.


**Example 1:**

```

**Input:** x = 4
**Output:** 2

```

**Example 2:**

```

**Input:** x = 8
**Output:** 2
**Explanation:** The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

**Constraints:**
* `0 <= x <= 231 - 1`


<br>

### Hints

- Try exploring all integers. (Credits: @annujoshi)
- Use the sorted property of integers to reduced the search space. (Credits: @annujoshi)

<br>

### Solution

**Using 64-bit integer**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int mySqrt (int x) {
      int64_t low = 0, high = 1 << 16;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (mid * mid <= x)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

**Without using 64-bit integer**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int mySqrt (int x) {
      if (x == 0)
        return 0;
      
      int low = 0, high = 1 << 16;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (mid <= x / mid)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

<br>

### Statistics

- total accepted: 1132492
- total submissions: 3079686
- acceptance rate: 36.8%
- likes: 4388
- dislikes: 3407

<br>

### Similar Problems

- [Pow(x, n)](https://leetcode.com/problems/powx-n) (Medium)
- [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square) (Easy)
