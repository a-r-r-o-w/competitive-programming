# [1071] Greatest Common Divisor of Strings

**[math, string]**

### Statement

For two strings `s` and `t`, we say "`t` divides `s`" if and only if `s = t + ... + t` (i.e., `t` is concatenated with itself one or more times).

Given two strings `str1` and `str2`, return *the largest string* `x` *such that* `x` *divides both* `str1` *and* `str2`.


**Example 1:**

```

**Input:** str1 = "ABCABC", str2 = "ABC"
**Output:** "ABC"

```

**Example 2:**

```

**Input:** str1 = "ABABAB", str2 = "ABAB"
**Output:** "AB"

```

**Example 3:**

```

**Input:** str1 = "LEET", str2 = "CODE"
**Output:** ""

```

**Constraints:**
* `1 <= str1.length, str2.length <= 1000`
* `str1` and `str2` consist of English uppercase letters.


<br />

### Hints

- The greatest common divisor must be a prefix of each string, so we can try all prefixes.

<br />

### Solution

```cpp
class Solution {
  public:
    string gcdOfStrings (string str1, string str2) {
      int n = str1.size(), m = str2.size();

      if (str1 + str2 != str2 + str1)
        return "";
      
      return str1.substr(0, std::gcd(n, m));
    }
};
```

<br />

### Statistics

- total accepted: 87204
- total submissions: 171059
- acceptance rate: 51.0%
- likes: 1583
- dislikes: 315

<br />

### Similar Problems

- [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array) (Easy)
- [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple) (Easy)
