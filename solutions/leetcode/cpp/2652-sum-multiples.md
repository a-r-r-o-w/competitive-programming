# [2652] Sum Multiples

**[array, math, number-theory]**

### Statement

Given a positive integer `n`, find the sum of all integers in the range `[1, n]` **inclusive** that are divisible by `3`, `5`, or `7`.

Return *an integer denoting the sum of all numbers in the given range satisfyingthe constraint.*
**Example 1:**

```

**Input:** n = 7
**Output:** 21
**Explanation:** Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.

```

**Example 2:**

```

**Input:** n = 10
**Output:** 40
**Explanation:** Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.

```

**Example 3:**

```

**Input:** n = 9
**Output:** 30
**Explanation:** Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.

```

**Constraints:**
* `1 <= n <= 10^3`


<br />

### Hints

- Iterate through the range 1 to n and count numbers divisible by either 3, 5, or 7.

<br />

### Solution

```cpp
class Solution {
  public:
    int sumOfMultiples (int n) {
      int ans = 0;
      for (int i: {3, 5, 7, 105}) {
        int t = n / i;
        ans += i * t * (t + 1) / 2;
      }
      for (int i: {15, 21, 35}) {
        int t = n / i;
        ans -= i * t * (t + 1) / 2;
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 23647
- total submissions: 27637
- acceptance rate: 85.6%
- likes: 105
- dislikes: 9

<br />

### Similar Problems

None
