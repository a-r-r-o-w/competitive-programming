# [20] Valid Parentheses

**[string, stack]**

### Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.


**Example 1:**

```

**Input:** s = "()"
**Output:** true

```

**Example 2:**

```

**Input:** s = "()[]{}"
**Output:** true

```

**Example 3:**

```

**Input:** s = "(]"
**Output:** false

```

**Constraints:**
* `1 <= s.length <= 104`
* `s` consists of parentheses only `'()[]{}'`.


<br>

### Hints

- An interesting property about a valid parenthesis expression is that a sub-expression of a valid expression should also be a valid expression. (Not every sub-expression) e.g.

<pre>
{ { } [ ] [ [ [ ] ] ] } is VALID expression
          [ [ [ ] ] ]    is VALID sub-expression
  { } [ ]                is VALID sub-expression
</pre>

Can we exploit this recursive structure somehow?
- What if whenever we encounter a matching pair of parenthesis in the expression, we simply remove it from the expression? This would keep on shortening the expression. e.g.

<pre>
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|

VALID EXPRESSION!
</pre>
- The <b>stack</b> data structure can come in handy here in representing this recursive structure of the problem. We can't really process this from the inside out because we don't have an idea about the overall structure. But, the stack can help us process this recursively i.e. from outside to inwards.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isValid (string s) {
      int n = s.length();
      std::stack <char> st;
      
      for (int i = 0; i < n; ++i) {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
          st.push(s[i]);
        else if (st.empty())
          return false;
        else {
          char t = st.top();
          st.pop();
          if ((s[i] == ')' and t != '(') or
              (s[i] == '}' and t != '{') or
              (s[i] == ']' and t != '['))
            return false;
        }
      }
      
      return st.empty();
    }
};
```

<br>

### Statistics

- total accepted: 2288451
- total submissions: 5601138
- acceptance rate: 40.9%
- likes: 13347
- dislikes: 596

<br>

### Similar Problems

- [Generate Parentheses](https://leetcode.com/problems/generate-parentheses) (Medium)
- [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) (Hard)
- [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses) (Hard)
- [Check If Word Is Valid After Substitutions](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions) (Medium)
- [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid) (Medium)
