# [2507] Smallest Value After Replacing With Sum of Prime Factors



### Statement

You are given a positive integer `n`.

Continuously replace `n` with the sum of its **prime factors**.

* Note that if a prime factor divides `n` multiple times, it should be included in the sum as many times as it divides `n`.



Return *the smallest value* `n` *will take on.*
**Example 1:**

```

**Input:** n = 15
**Output:** 5
**Explanation:** Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.

```

**Example 2:**

```

**Input:** n = 3
**Output:** 3
**Explanation:** Initially, n = 3.
3 is the smallest value n will take on.

```

**Constraints:**
* `2 <= n <= 105`


<br>

### Hints

- Every time you replace n, it will become smaller until it is a prime number, where it will keep the same value each time you replace it.
- n decreases logarithmically, allowing you to simulate the process.
- To find the prime factors, iterate through all numbers less than n from least to greatest and find the maximum number of times each number divides n.

<br>

### Solution

```cpp
class Solution {
  public:
    int smallestValue (int n) {
      while (true) {
        int sum = 0, x = n;
        
        for (int i = 2; i <= n; ++i) {
          if (n % i == 0) {
            while (n % i == 0) {
              sum += i;
              n /= i;
            }
          }
        }
        
        if (sum == x)
          return x;
        
        n = sum;
      }
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 8247
- total submissions: 18687
- acceptance rate: 44.1%
- likes: 62
- dislikes: 14

<br>

### Similar Problems

- [Happy Number](https://leetcode.com/problems/happy-number) (Easy)
- [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard) (Medium)
- [Count Ways to Make Array With Product](https://leetcode.com/problems/count-ways-to-make-array-with-product) (Hard)
