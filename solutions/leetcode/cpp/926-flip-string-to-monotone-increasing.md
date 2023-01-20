# [926] Flip String to Monotone Increasing

**[string, dynamic-programming]**

### Statement

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none), followed by some number of `1`'s (also possibly none).

You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to `0`.

Return *the minimum number of flips to make* `s` *monotone increasing*.


**Example 1:**

```

**Input:** s = "00110"
**Output:** 1
**Explanation:** We flip the last digit to get 00111.

```

**Example 2:**

```

**Input:** s = "010110"
**Output:** 2
**Explanation:** We flip to get 011111, or alternatively 000111.

```

**Example 3:**

```

**Input:** s = "00011000"
**Output:** 2
**Explanation:** We flip to get 00000000.

```

**Constraints:**
* `1 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minFlipsMonoIncr (string s) {
      int n = s.length(), ones_left = 0, zeros_right = 0, ans = 1 << 30;

      for (char c: s) {
        if (c == '0')
          ++zeros_right;
      }

      for (char c: s) {
        ans = std::min(ans, ones_left + zeros_right);
        if (c == '1')
          ++ones_left;
        else
          --zeros_right;
      }
      ans = std::min(ans, ones_left + zeros_right);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 141190
- total submissions: 233072
- acceptance rate: 60.6%
- likes: 3354
- dislikes: 144

<br>

### Similar Problems

None
