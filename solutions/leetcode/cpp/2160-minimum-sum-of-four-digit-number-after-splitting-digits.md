# [2160] Minimum Sum of Four Digit Number After Splitting Digits

**[math, greedy, sorting]**

### Statement

You are given a **positive** integer `num` consisting of exactly four digits. Split `num` into two new integers `new1` and `new2` by using the **digits** found in `num`. **Leading zeros** are allowed in `new1` and `new2`, and **all** the digits found in `num` must be used.

* For example, given `num = 2932`, you have the following digits: two `2`'s, one `9` and one `3`. Some of the possible pairs `[new1, new2]` are `[22, 93]`, `[23, 92]`, `[223, 9]` and `[2, 329]`.



Return *the **minimum** possible sum of* `new1` *and* `new2`.


**Example 1:**

```

**Input:** num = 2932
**Output:** 52
**Explanation:** Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

```

**Example 2:**

```

**Input:** num = 4009
**Output:** 13
**Explanation:** Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.

```

**Constraints:**
* `1000 <= num <= 9999`


<br>

### Hints

- Notice that the most optimal way to obtain the minimum possible sum using 4 digits is by summing up two 2-digit numbers.
- We can use the two smallest digits out of the four as the digits found in the tens place respectively.
- Similarly, we use the final 2 larger digits as the digits found in the ones place.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumSum (int num) {
      auto s = std::to_string(num);
      std::sort(s.begin(), s.end());
      return (s[0] - '0') * 10 + (s[3] - '0') + (s[1] - '0') * 10 + (s[2] - '0');
    }
};
```

<br>

### Statistics

- total accepted: 44090
- total submissions: 49938
- acceptance rate: 88.3%
- likes: 529
- dislikes: 55

<br>

### Similar Problems

- [Add Digits](https://leetcode.com/problems/add-digits) (Easy)
