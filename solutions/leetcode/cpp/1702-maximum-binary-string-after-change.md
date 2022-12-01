# [1702] Maximum Binary String After Change

**[string, greedy]**

### Statement

You are given a binary string `binary` consisting of only `0`'s or `1`'s. You can apply each of the following operations any number of times:

* Operation 1: If the number contains the substring `"00"`, you can replace it with `"10"`.
	+ For example, `"00010" -> "10010`"
* Operation 2: If the number contains the substring `"10"`, you can replace it with `"01"`.
	+ For example, `"00010" -> "00001"`


*Return the **maximum binary string** you can obtain after any number of operations. Binary string `x` is greater than binary string `y` if `x`'s decimal representation is greater than `y`'s decimal representation.*
**Example 1:**

```

**Input:** binary = "000110"
**Output:** "111011"
**Explanation:** A valid transformation sequence can be:
"000110" -> "000101" 
"000101" -> "100101" 
"100101" -> "110101" 
"110101" -> "110011" 
"110011" -> "111011"

```

**Example 2:**

```

**Input:** binary = "01"
**Output:** "01"
**Explanation:**"01" cannot be transformed any further.

```

**Constraints:**
* `1 <= binary.length <= 105`
* `binary` consist of `'0'` and `'1'`.


<br>

### Hints

- Note that with the operations, you can always make the string only contain at most 1 zero.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string maximumBinaryString (string binary) {
      int n = binary.length(), z = 0, o = 0;
      
      for (int i = 0; i < n; ++i) {
        if (binary[i] == '0')
          ++z;
        else if (z == 0)
          ++o;
        binary[i] = '1';
      }
      
      if (o != n)
        binary[z + o - 1] = '0';
      
      return binary;
    }
};
```

<br>

### Statistics

- total accepted: 10090
- total submissions: 21836
- acceptance rate: 46.2%
- likes: 402
- dislikes: 41

<br>

### Similar Problems

- [Longest Binary Subsequence Less Than or Equal to K](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k) (Medium)
