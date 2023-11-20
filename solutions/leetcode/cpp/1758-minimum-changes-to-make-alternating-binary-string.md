# [1758] Minimum Changes To Make Alternating Binary String

**[string]**

### Statement

You are given a string `s` consisting only of the characters `'0'` and `'1'`. In one operation, you can change any `'0'` to `'1'` or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string `"010"` is alternating, while the string `"0100"` is not.

Return *the **minimum** number of operations needed to make* `s` *alternating*.


**Example 1:**

```

**Input:** s = "0100"
**Output:** 1
**Explanation:** If you change the last character to '1', s will be "0101", which is alternating.

```

**Example 2:**

```

**Input:** s = "10"
**Output:** 0
**Explanation:** s is already alternating.

```

**Example 3:**

```

**Input:** s = "1111"
**Output:** 2
**Explanation:** You need two operations to reach "0101" or "1010".

```

**Constraints:**
* `1 <= s.length <= 104`
* `s[i]` is either `'0'` or `'1'`.


<br>

### Hints

- Think about how the final string will look like.
- It will either start with a '0' and be like '010101010..' or with a '1' and be like '10101010..'
- Try both ways, and check for each way, the number of changes needed to reach it from the given string. The answer is the minimum of both ways.

<br>

### Solution

```cpp
class Solution {
  public:
    int minOperations (string s) {
      int n = s.length();
      int a = 0, b = 0;
      
      for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
          if (i & 1)
            ++a;
          else
            ++b;
        }
        else {
          if (i & 1)
            ++b;
          else
            ++a;
        }
      }
      
      return std::min(a, b);
    }
};
```

<br>

### Statistics

- total accepted: 32147
- total submissions: 55033
- acceptance rate: 58.4%
- likes: 476
- dislikes: 16

<br>

### Similar Problems

None
