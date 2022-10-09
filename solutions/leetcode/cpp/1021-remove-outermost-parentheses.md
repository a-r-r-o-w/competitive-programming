# [1021] Remove Outermost Parentheses

**[string, stack]**

### Statement

A valid parentheses string is either empty `""`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation.

* For example, `""`, `"()"`, `"(())()"`, and `"(()(()))"` are all valid parentheses strings.



A valid parentheses string `s` is primitive if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `s`, consider its primitive decomposition: `s = P1 + P2 + ... + Pk`, where `Pi` are primitive valid parentheses strings.

Return `s` *after removing the outermost parentheses of every primitive string in the primitive decomposition of* `s`.


**Example 1:**

```

**Input:** s = "(()())(())"
**Output:** "()()()"
**Explanation:** 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

```

**Example 2:**

```

**Input:** s = "(()())(())(()(()))"
**Output:** "()()()()(())"
**Explanation:** 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

```

**Example 3:**

```

**Input:** s = "()()"
**Output:** ""
**Explanation:** 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

```

**Constraints:**
* `1 <= s.length <= 105`
* `s[i]` is either `'('` or `')'`.
* `s` is a valid parentheses string.


<br>

### Hints

- Can you find the primitive decomposition?  The number of ( and ) characters must be equal.

<br>

### Solution

```cpp
class Solution {
  public:
    string removeOuterParentheses (string s) {
      std::string result;
      int d = 0;
      
      for (char c: s) {
        if (c == '(') {
          ++d;
          if (d > 1)
            result += '(';
        }
        else {
          if (d > 1)
            result += ')';
          --d;
        }
      }
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 181882
- total submissions: 227371
- acceptance rate: 80.0%
- likes: 1420
- dislikes: 1219

<br>

### Similar Problems

None
