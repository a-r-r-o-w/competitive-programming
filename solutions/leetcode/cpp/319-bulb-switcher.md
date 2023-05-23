# [319] Bulb Switcher

**[math, brainteaser]**

### Statement

There are `n` bulbs that are initially off. You first turn on all the bulbs, thenyou turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the `i^th` round, you toggle every `i` bulb. For the `n^th` round, you only toggle the last bulb.

Return *the number of bulbs that are on after `n` rounds*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/05/bulb.jpg)

```

**Input:** n = 3
**Output:** 1
**Explanation:** At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.
```

**Example 2:**

```

**Input:** n = 0
**Output:** 0

```

**Example 3:**

```

**Input:** n = 1
**Output:** 1

```

**Constraints:**
* `0 <= n <= 10^9`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int bulbSwitch (int n) {
      return std::sqrt(n);
    }
};
```

<br />

### Statistics

- total accepted: 132771
- total submissions: 273240
- acceptance rate: 48.6%
- likes: 1247
- dislikes: 1927

<br />

### Similar Problems

- [Bulb Switcher II](https://leetcode.com/problems/bulb-switcher-ii) (Medium)
- [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips) (Hard)
- [Number of Times Binary String Is Prefix-Aligned](https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned) (Medium)
- [Find the Pivot Integer](https://leetcode.com/problems/find-the-pivot-integer) (Easy)
