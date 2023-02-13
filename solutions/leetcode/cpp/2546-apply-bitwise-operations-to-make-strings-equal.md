# [2546] Apply Bitwise Operations to Make Strings Equal



### Statement

You are given two **0-indexed binary** strings `s` and `target` of the same length `n`. You can do the following operation on `s` **any** number of times:

* Choose two **different** indices `i` and `j` where `0 <= i, j < n`.
* Simultaneously, replace `s[i]` with (`s[i]` **OR** `s[j]`) and `s[j]` with (`s[i]` **XOR** `s[j]`).



For example, if `s = "0110"`, you can choose `i = 0` and `j = 2`, then simultaneously replace `s[0]` with (`s[0]` **OR** `s[2]` = `0` **OR** `1` = `1`), and `s[2]` with (`s[0]` **XOR** `s[2]` = `0` **XOR** `1` = `1`), so we will have `s = "1110"`.

Return `true` *if you can make the string* `s` *equal to* `target`*, or* `false` *otherwise*.


**Example 1:**

```

**Input:** s = "1010", target = "0110"
**Output:** true
**Explanation:** We can do the following operations:
- Choose i = 2 and j = 0. We have now s = "**0**0**1**0".
- Choose i = 2 and j = 1. We have now s = "0**11**0".
Since we can make s equal to target, we return true.

```

**Example 2:**

```

**Input:** s = "11", target = "00"
**Output:** false
**Explanation:** It is not possible to make s equal to target with any number of operations.

```

**Constraints:**
* `n == s.length == target.length`
* `2 <= n <= 105`
* `s` and `target` consist of only the digits `0` and `1`.


<br>

### Hints

- Think of when it is impossible to convert the string to the target.
- If exactly one of the strings is having all 0’s, then it is impossible. And it is possible in all other cases. Why is that true?

<br>

### Solution

```cpp
class Solution {
  public:
    bool makeStringsEqual (string s, string target) {
      // 0 ... 0 => 0 ... 0
      // 0 ... 1 => 1 ... 1
      // 1 ... 0 => 1 ... 1
      // 1 ... 1 => 1 ... 0 or 0 ... 1
      // any 0 can be converted to 1 as long as there is atleast one 1
      // any 1 can be converted to 0 as long as there is atleast two 1's
      // max zeroes in s => count_0_in_s + count_1_in_s - 1

      int a = std::count(s.begin(), s.end(), '0');
      int b = std::count (target.begin(), target.end(), '0');
      int n = s.length();

      if (a == n and b == n)
        return true;

      return !(a == n or b == n);
    }
};
```

<br>

### Statistics

- total accepted: 10094
- total submissions: 26715
- acceptance rate: 37.8%
- likes: 92
- dislikes: 62

<br>

### Similar Problems

- [Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero) (Hard)
