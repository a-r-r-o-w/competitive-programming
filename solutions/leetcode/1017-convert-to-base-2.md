# [1017] Convert to Base -2

**[math]**

### Statement

Given an integer `n`, return *a binary string representing its representation in base* `-2`.

**Note** that the returned string should not have leading zeros unless the string is `"0"`.


**Example 1:**

```

**Input:** n = 2
**Output:** "110"
**Explantion:** (-2)2 + (-2)1 = 2

```

**Example 2:**

```

**Input:** n = 3
**Output:** "111"
**Explantion:** (-2)2 + (-2)1 + (-2)0 = 3

```

**Example 3:**

```

**Input:** n = 4
**Output:** "100"
**Explantion:** (-2)2 = 4

```

**Constraints:**
* `0 <= n <= 109`


<br>

### Hints

- Figure out whether you need the ones digit placed or not, then shift by two.

<br>

### Solution

```cpp
class Solution {
  public:
    string baseNeg2 (int n) {
      // 0 -> 00000
      // 1 -> 00001
      // 2 -> 00110
      // 3 -> 00111
      // 4 -> 00100
      // 5 -> 00101
      // 6 -> 11010
      // 7 -> 11011
      
      if (n == 0)
        return "0";
      
      std::string ans;
      
      while (n != 0) {
        int d = std::abs(n & 1);
        ans += d + '0';
        n = -(n >> 1);
      }
      
      std::reverse(ans.begin(), ans.end());
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 19939
- total submissions: 32785
- acceptance rate: 60.8%
- likes: 379
- dislikes: 238

<br>

### Similar Problems

- [Encode Number](https://leetcode.com/problems/encode-number) (Medium)
