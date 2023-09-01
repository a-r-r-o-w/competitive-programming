# [664] Strange Printer

**[string, dynamic-programming]**

### Statement

There is a strange printer with the following two special properties:

* The printer can only print a sequence of **the same character** each time.
* At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.



Given a string `s`, return *the minimum number of turns the printer needed to print it*.


**Example 1:**

```

**Input:** s = "aaabbb"
**Output:** 2
**Explanation:** Print "aaa" first and then print "bbb".

```

**Example 2:**

```

**Input:** s = "aba"
**Output:** 2
**Explanation:** Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

```

**Constraints:**
* `1 <= s.length <= 100`
* `s` consists of lowercase English letters.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int strangePrinter (string s) {
      int n = s.length();
      std::vector dp (n, std::vector(n, -1));
      
      auto dfs = [&] (auto self, int l, int r) -> int {
        if (dp[l][r] != -1)
          return dp[l][r];
        
        int which = -1, ans = 1 << 30;
        
        for (int i = l; i < r; ++i) {
          if (s[i] != s[r]) {
            which = i;
            break;
          }
        }

        if (which == -1)
          ans = 0;
        else {
          for (int i = which; i < r; ++i)
            ans = std::min(ans, 1 + self(self, which, i) + self(self, i + 1, r));
        }
        
        return dp[l][r] = ans;
      };

      return dfs(dfs, 0, n - 1) + 1;
    }
};
```

<br />

### Statistics

- total accepted: 48044
- total submissions: 93456
- acceptance rate: 51.4%
- likes: 1594
- dislikes: 151

<br />

### Similar Problems

- [Remove Boxes](https://leetcode.com/problems/remove-boxes) (Hard)
- [Strange Printer II](https://leetcode.com/problems/strange-printer-ii) (Hard)
