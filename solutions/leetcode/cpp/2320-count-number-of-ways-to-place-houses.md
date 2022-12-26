# [2320] Count Number of Ways to Place Houses

**[dynamic-programming]**

### Statement

There is a street with `n * 2` **plots**, where there are `n` plots on each side of the street. The plots on each side are numbered from `1` to `n`. On each plot, a house can be placed.

Return *the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street*. Since the answer may be very large, return it **modulo** `109 + 7`.

Note that if a house is placed on the `ith` plot on one side of the street, a house can also be placed on the `ith` plot on the other side of the street.


**Example 1:**

```

**Input:** n = 1
**Output:** 4
**Explanation:** 
Possible arrangements:
1. All plots are empty.
2. A house is placed on one side of the street.
3. A house is placed on the other side of the street.
4. Two houses are placed, one on each side of the street.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/05/12/arrangements.png)

```

**Input:** n = 2
**Output:** 9
**Explanation:** The 9 possible arrangements are shown in the diagram above.

```

**Constraints:**
* `1 <= n <= 104`


<br>

### Hints

- Try coming up with a DP solution for one side of the street.
- The DP for one side of the street will bear resemblance to the Fibonacci sequence.
- The number of different arrangements on both side of the street is the same.

<br>

### Solution

```cpp
class Solution {
  public:
    int countHousePlacements (int n) {
      constexpr int mod = 1000000007;
      int a = 1, b = 2;

      for (int i = 2; i <= n; ++i) {
        int c = a + b;
        if (c >= mod)
          c -= mod;
        a = b;
        b = c;
      }

      return int64_t(b) * b % mod;
    }
};
```

<br>

### Statistics

- total accepted: 20754
- total submissions: 51466
- acceptance rate: 40.3%
- likes: 410
- dislikes: 179

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [House Robber](https://leetcode.com/problems/house-robber) (Medium)
