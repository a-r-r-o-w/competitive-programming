# [2571] Minimum Operations to Reduce an Integer to 0

**[dynamic-programming, greedy, bit-manipulation]**

### Statement

You are given a positive integer `n`, you can do the following operation **any** number of times:

* Add or subtract a **power** of `2` from `n`.



Return *the **minimum** number of operations to make* `n` *equal to* `0`.

A number `x` is power of `2` if `x == 2^i`where `i >= 0`*.*
**Example 1:**

```

**Input:** n = 39
**Output:** 3
**Explanation:** We can do the following operations:
- Add 2^0 = 1 to n, so now n = 40.
- Subtract 2^3 = 8 from n, so now n = 32.
- Subtract 2^5 = 32 from n, so now n = 0.
It can be shown that 3 is the minimum number of operations we need to make n equal to 0.

```

**Example 2:**

```

**Input:** n = 54
**Output:** 3
**Explanation:** We can do the following operations:
- Add 2^1 = 2 to n, so now n = 56.
- Add 2^3 = 8 to n, so now n = 64.
- Subtract 2^6 = 64 from n, so now n = 0.
So the minimum number of operations is 3.

```

**Constraints:**
* `1 <= n <= 10^5`


<br />

### Hints

- Can we set/unset the bits in binary representation?
- If there are multiple adjacent ones, how can we optimally add and subtract in 2 operations such that all ones get unset?
- Bonus: Try to solve the problem with higher constraints: n ≤ 10^18.

<br />

### Solution

```cpp
class Solution {
  public:
    int minOperations (int n) {
      std::string bin;
      while (n) {
        bin += '0' + (n & 1);
        n /= 2;
      }
      bin += '0';
      int size = bin.size(), ans = 0;

      for (int i = 0; i < size; ++i) {
        if (bin[i] == '0')
          continue;
        int j = i;
        while (j < size and bin[j] == '1')
          ++j;
        if (j < size and j - i > 1)
          bin[j] = '1';
        i = j - 1;
        ++ans;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 15018
- total submissions: 30291
- acceptance rate: 49.6%
- likes: 315
- dislikes: 176

<br />

### Similar Problems

- [Plus One](https://leetcode.com/problems/plus-one) (Easy)
