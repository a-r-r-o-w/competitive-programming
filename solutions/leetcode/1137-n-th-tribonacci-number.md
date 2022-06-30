# [1137] N-th Tribonacci Number

**[math, dynamic-programming, memoization]**

### Statement

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given `n`, return the value of Tn.


**Example 1:**

```

**Input:** n = 4
**Output:** 4
**Explanation:**
T\_3 = 0 + 1 + 1 = 2
T\_4 = 1 + 1 + 2 = 4

```

**Example 2:**

```

**Input:** n = 25
**Output:** 1389537

```

**Constraints:**
* `0 <= n <= 37`
* The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.


<br>

### Hints

- Make an array F of length 38, and set F[0] = 0, F[1] = F[2] = 1.
- Now write a loop where you set F[n+3] = F[n] + F[n+1] + F[n+2], and return F[n].

<br>

### Solution

```cpp
class Solution {
  public:
    int tribonacci (int n) {
      if (n == 0)
        return n;
      if (n == 1 or n == 2)
        return 1;
      
      int a = 0, b = 1, c = 1, d;
      n -= 2;
      
      while (n) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
        --n;
      }
      
      return d;
    }
};
```

<br>

### Statistics

- total accepted: 294051
- total submissions: 465556
- acceptance rate: 63.2%
- likes: 1917
- dislikes: 110

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) (Easy)
