# [509] Fibonacci Number

**[math, dynamic-programming, recursion, memoization]**

### Statement

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,


```

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

```


Given `n`, calculate `F(n)`.


**Example 1:**

```

**Input:** n = 2
**Output:** 1
**Explanation:** F(2) = F(1) + F(0) = 1 + 0 = 1.

```

**Example 2:**

```

**Input:** n = 3
**Output:** 2
**Explanation:** F(3) = F(2) + F(1) = 1 + 1 = 2.

```

**Example 3:**

```

**Input:** n = 4
**Output:** 3
**Explanation:** F(4) = F(3) + F(2) = 2 + 1 = 3.

```

**Constraints:**
* `0 <= n <= 30`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int fib (int n) {
      if (n == 0 or n == 1)
          return n;
      
      int a = 0, b = 1;
      n -= 1;
      
      while (n) {
        int c = a + b;
        a = b;
        b = c;
        --n;
      }
      
      return b;
    }
};
```

<br>

### Statistics

- total accepted: 827545
- total submissions: 1211525
- acceptance rate: 68.3%
- likes: 3761
- dislikes: 269

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [Split Array into Fibonacci Sequence](https://leetcode.com/problems/split-array-into-fibonacci-sequence) (Medium)
- [Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence) (Medium)
- [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number) (Easy)
