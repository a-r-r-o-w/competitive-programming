# [921] Minimum Add to Make Parentheses Valid

**[string, stack, greedy]**

### Statement

A parentheses string is valid if and only if:

* It is the empty string,
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
* It can be written as `(A)`, where `A` is a valid string.



You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

* For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(**(**)))"` or a closing parenthesis to be `"())**)**)"`.



Return *the minimum number of moves required to make* `s` *valid*.


**Example 1:**

```

**Input:** s = "())"
**Output:** 1

```

**Example 2:**

```

**Input:** s = "((("
**Output:** 3

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s[i]` is either `'('` or `')'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minAddToMakeValid (string s) {
      int d = 0;
      int ans = 0;
      for (char c: s) {
        if (c == '(')
          ++d;
        else
          --d;
        if (d < 0) {
          d = 0;
          ++ans;
        }
      }
      return ans + d;
    }
};
```

<br>

### Statistics

- total accepted: 225777
- total submissions: 294585
- acceptance rate: 76.6%
- likes: 2810
- dislikes: 158

<br>

### Similar Problems

- [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced) (Medium)
