# [258] Add Digits

**[math, simulation, number-theory]**

### Statement

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.


**Example 1:**

```

**Input:** num = 38
**Output:** 2
**Explanation:** The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

```

**Example 2:**

```

**Input:** num = 0
**Output:** 0

```

**Constraints:**
* `0 <= num <= 2^31 - 1`


**Follow up:** Could you do it without any loop/recursion in `O(1)` runtime?

<br />

### Hints

- A naive implementation of the above process is trivial. Could you come up with other methods?
- What are all the possible results?
- How do they occur, periodically or randomly?
- You may find this <a href="https://en.wikipedia.org/wiki/Digital_root" target="_blank">Wikipedia article</a> useful.

<br />

### Solution

```cpp
class Solution {
  public:
    int addDigits (int num) {
      if (num == 0)
        return 0;
      while (true) {
        int sum = 0, count = 0;
        while (num) {
          sum += num % 10;
          num /= 10;
          ++count;
        }
        num = sum;
        if (count == 1)
          break;
      }

      return num;
    }
};
```

<br />

### Statistics

- total accepted: 560230
- total submissions: 875196
- acceptance rate: 64.0%
- likes: 3287
- dislikes: 1763

<br />

### Similar Problems

- [Happy Number](https://leetcode.com/problems/happy-number) (Easy)
- [Sum of Digits in the Minimum Number](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number) (Easy)
- [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert) (Easy)
- [Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits) (Easy)
- [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string) (Easy)
- [Difference Between Element Sum and Digit Sum of an Array](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array) (Easy)
- [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum) (Easy)
