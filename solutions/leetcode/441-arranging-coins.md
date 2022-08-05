# [441] Arranging Coins

**[math, binary-search]**

### Statement

You have `n` coins and you want to build a staircase with these coins. The staircase consists of `k` rows where the `ith` row has exactly `i` coins. The last row of the staircase **may be** incomplete.

Given the integer `n`, return *the number of **complete rows** of the staircase you will build*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins1-grid.jpg)

```

**Input:** n = 5
**Output:** 2
**Explanation:** Because the 3rd row is incomplete, we return 2.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins2-grid.jpg)

```

**Input:** n = 8
**Output:** 3
**Explanation:** Because the 4th row is incomplete, we return 3.

```

**Constraints:**
* `1 <= n <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int arrangeCoins (int n) {
      int low = 1, high = 1 << 16;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (mid * (mid + 1) / 2 <= n)
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

- total accepted: 299386
- total submissions: 654119
- acceptance rate: 45.8%
- likes: 2512
- dislikes: 1080

<br>

### Similar Problems

None
