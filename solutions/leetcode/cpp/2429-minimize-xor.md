# [2429] Minimize XOR

**[greedy, bit-manipulation]**

### Statement

Given two positive integers `num1` and `num2`, find the integer `x` such that:

* `x` has the same number of set bits as `num2`, and
* The value `x XOR num1` is **minimal**.



Note that `XOR` is the bitwise XOR operation.

Return *the integer* `x`. The test cases are generated such that `x` is **uniquely determined**.

The number of **set bits** of an integer is the number of `1`'s in its binary representation.


**Example 1:**

```

**Input:** num1 = 3, num2 = 5
**Output:** 3
**Explanation:**
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer **3** has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

```

**Example 2:**

```

**Input:** num1 = 1, num2 = 12
**Output:** 3
**Explanation:**
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer **3** has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

```

**Constraints:**
* `1 <= num1, num2 <= 109`


<br>

### Hints

- To arrive at a small xor, try to turn off some bits from num1
- If there are still left bits to set, try to set them from the least significant bit

<br>

### Solution

```cpp
class Solution {
  public:
    int minimizeXor (int num1, int num2) {
      int count = __builtin_popcount(num2), min = num1;
      std::vector <bool> used (32);
      
      for (int i = 30; i >= 0 and count > 0; --i) {
        if (min & (1 << i)) {
          used[i] = true;
          --count;
        }
        if (count == 0)
          while (i--)
            min &= ~(1 << i);
      }
      
      for (int i = 0; i <= 30 and count > 0; ++i) {
        if (used[i])
          continue;
        min |= 1 << i;
        --count;
      }
      
      return min;
    }
};
```

<br>

### Statistics

- total accepted: 12897
- total submissions: 32090
- acceptance rate: 40.2%
- likes: 185
- dislikes: 12

<br>

### Similar Problems

- [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array) (Medium)
- [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array) (Hard)
