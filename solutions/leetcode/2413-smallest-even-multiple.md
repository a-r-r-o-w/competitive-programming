# [2413] Smallest Even Multiple



### Statement

Given a **positive** integer `n`, return *the smallest positive integer that is a multiple of **both*** `2` *and* `n`.

**Example 1:**

```

**Input:** n = 5
**Output:** 10
**Explanation:** The smallest multiple of both 5 and 2 is 10.

```

**Example 2:**

```

**Input:** n = 6
**Output:** 6
**Explanation:** The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.

```

**Constraints:**
* `1 <= n <= 150`


<br>

### Hints

- A guaranteed way to find a multiple of 2 and n is to multiply them together. When is this the answer, and when is there a smaller answer?
- There is a smaller answer when n is even.

<br>

### Solution

```cpp
class Solution {
  public:
    int smallestEvenMultiple (int n) {
      if (n % 2 == 0)
        return n;
      else
        return 2 * n;
    }
};
```

<br>

### Statistics

- total accepted: 17354
- total submissions: 19780
- acceptance rate: 87.7%
- likes: 54
- dislikes: 4

<br>

### Similar Problems

- [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings) (Easy)
- [Three Divisors](https://leetcode.com/problems/three-divisors) (Easy)
- [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array) (Easy)
