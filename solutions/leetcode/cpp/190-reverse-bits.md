# [190] Reverse Bits

**[divide-and-conquer, bit-manipulation]**

### Statement

Reverse bits of a given 32 bits unsigned integer.

**Note:**
* Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
* In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in **Example 2** above, the input represents the signed integer `-3` and the output represents the signed integer `-1073741825`.


**Example 1:**

```

**Input:** n = 00000010100101000001111010011100
**Output:**    964176192 (00111001011110000010100101000000)
**Explanation:** The input binary string **00000010100101000001111010011100** represents the unsigned integer 43261596, so return 964176192 which its binary representation is **00111001011110000010100101000000**.

```

**Example 2:**

```

**Input:** n = 11111111111111111111111111111101
**Output:**   3221225471 (10111111111111111111111111111111)
**Explanation:** The input binary string **11111111111111111111111111111101** represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is **10111111111111111111111111111111**.

```

**Constraints:**
* The input must be a **binary string** of length `32`


**Follow up:** If this function is called many times, how would you optimize it?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    uint32_t reverseBits (uint32_t n) {
      uint32_t m = 0;
      for (int i = 0; i < 32; ++i) {
        m = (m << 1) | (n & 1);
        n >>= 1;
      }
      return m;
    }
};
```

<br>

### Statistics

- total accepted: 534427
- total submissions: 1038740
- acceptance rate: 51.4%
- likes: 3599
- dislikes: 916

<br>

### Similar Problems

- [Reverse Integer](https://leetcode.com/problems/reverse-integer) (Medium)
- [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) (Easy)
- [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal) (Easy)
