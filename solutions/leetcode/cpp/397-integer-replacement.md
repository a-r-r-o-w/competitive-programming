# [397] Integer Replacement

**[dynamic-programming, greedy, bit-manipulation, memoization]**

### Statement

Given a positive integer `n`,you can apply one of the followingoperations:

1. If `n` is even, replace `n` with `n / 2`.
2. If `n` is odd, replace `n` with either `n + 1` or `n - 1`.



Return *the minimum number of operations needed for* `n` *to become* `1`.


**Example 1:**

```

**Input:** n = 8
**Output:** 3
**Explanation:** 8 -> 4 -> 2 -> 1

```

**Example 2:**

```

**Input:** n = 7
**Output:** 4
**Explanation:** 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

```

**Example 3:**

```

**Input:** n = 4
**Output:** 2

```

**Constraints:**
* `1 <= n <= 2^31 - 1`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int integerReplacement (int n) {
      int64_t m = n;
      int ans = 0;
      while (m > 1) {
        if (m % 2 == 0)
          m /= 2;
        else if (m == 3 or m % 4 == 1)
          --m;
        else
          ++m;
        ++ans;
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 98315
- total submissions: 279102
- acceptance rate: 35.2%
- likes: 1123
- dislikes: 463

<br />

### Similar Problems

None
