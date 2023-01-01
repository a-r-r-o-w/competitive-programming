# [2520] Count the Digits That Divide a Number



### Statement

Given an integer `num`, return *the number of digits in `num` that divide* `num`.

An integer `val` divides `nums` if `nums % val == 0`.


**Example 1:**

```

**Input:** num = 7
**Output:** 1
**Explanation:** 7 divides itself, hence the answer is 1.

```

**Example 2:**

```

**Input:** num = 121
**Output:** 2
**Explanation:** 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.

```

**Example 3:**

```

**Input:** num = 1248
**Output:** 4
**Explanation:** 1248 is divisible by all of its digits, hence the answer is 4.

```

**Constraints:**
* `1 <= num <= 109`
* `num` does not contain `0` as one of its digits.


<br>

### Hints

- Use mod by 10 to retrieve the least significant digit of the number
- Divide the number by 10, then round it down so that the second least significant digit becomes the least significant digit of the number
- Use your language’s mod operator to see if a number is a divisor of another.

<br>

### Solution

```cpp
class Solution {
  public:
    int countDigits (int num) {
      int x = num, count = 0;
      while (num) {
        int d = num % 10;
        num /= 10;
        if (x % d == 0)
          ++count;
      }
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 11527
- total submissions: 13729
- acceptance rate: 84.0%
- likes: 41
- dislikes: 2

<br>

### Similar Problems

- [Happy Number](https://leetcode.com/problems/happy-number) (Easy)
- [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers) (Easy)
