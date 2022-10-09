# [191] Number of 1 Bits

**[divide-and-conquer, bit-manipulation]**

### Statement

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

**Note:**
* Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
* In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in **Example 3**, the input represents the signed integer. `-3`.


**Example 1:**

```

**Input:** n = 00000000000000000000000000001011
**Output:** 3
**Explanation:** The input binary string **00000000000000000000000000001011** has a total of three '1' bits.

```

**Example 2:**

```

**Input:** n = 00000000000000000000000010000000
**Output:** 1
**Explanation:** The input binary string **00000000000000000000000010000000** has a total of one '1' bit.

```

**Example 3:**

```

**Input:** n = 11111111111111111111111111111101
**Output:** 31
**Explanation:** The input binary string **11111111111111111111111111111101** has a total of thirty one '1' bits.

```

**Constraints:**
* The input must be a **binary string** of length `32`.


**Follow up:** If this function is called many times, how would you optimize it?

<br>

### Hints

None

<br>

### Solution

Loop to count set bits

```cpp
class Solution {
  public:
    int hammingWeight (uint32_t n) {
      int count = 0;
      
      for (int i = 0; i < 32; ++i)
        if (n & (1 << i))
          ++count;
      
      return count;
    }
};
```

Unsetting lowest set bit

```cpp
class Solution {
  public:
    int hammingWeight (uint32_t n) {
      int count = 0;
      
      while (n) {
        ++count;
        n &= n - 1;
      }
      
      return count;
    }
};
```

Builtin GCC popcount function to count bits

```cpp
class Solution {
  public:
    int hammingWeight (uint32_t n) {
      return __builtin_popcount(n);
    }
};
```

<br>

### Statistics

- total accepted: 887924
- total submissions: 1390438
- acceptance rate: 63.9%
- likes: 4145
- dislikes: 916

<br>

### Similar Problems

- [Reverse Bits](https://leetcode.com/problems/reverse-bits) (Easy)
- [Power of Two](https://leetcode.com/problems/power-of-two) (Easy)
- [Counting Bits](https://leetcode.com/problems/counting-bits) (Easy)
- [Binary Watch](https://leetcode.com/problems/binary-watch) (Easy)
- [Hamming Distance](https://leetcode.com/problems/hamming-distance) (Easy)
- [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits) (Easy)
- [Prime Number of Set Bits in Binary Representation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation) (Easy)
