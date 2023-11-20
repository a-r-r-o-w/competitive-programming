# [1106] Parsing A Boolean Expression

**[string, stack, recursion]**

### Statement

A **boolean expression** is an expression that evaluates to either `true` or `false`. It can be in one of the following shapes:

* `'t'` that evaluates to `true`.
* `'f'` that evaluates to `false`.
* `'!(subExpr)'` that evaluates to **the logical NOT** of the inner expression `subExpr`.
* `'&(subExpr1, subExpr2, ..., subExprn)'` that evaluates to **the logical AND** of the inner expressions `subExpr1, subExpr2, ..., subExprn` where `n >= 1`.
* `'|(subExpr1, subExpr2, ..., subExprn)'` that evaluates to **the logical OR** of the inner expressions `subExpr1, subExpr2, ..., subExprn` where `n >= 1`.



Given a string `expression` that represents a **boolean expression**, return *the evaluation of that expression*.

It is **guaranteed** that the given expression is valid and follows the given rules.


**Example 1:**

```

**Input:** expression = "&(|(f))"
**Output:** false
**Explanation:** 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.

```

**Example 2:**

```

**Input:** expression = "|(f,f,f,t)"
**Output:** true
**Explanation:** The evaluation of (false OR false OR false OR true) is true.

```

**Example 3:**

```

**Input:** expression = "!(&(f,t))"
**Output:** true
**Explanation:** 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

```

**Constraints:**
* `1 <= expression.length <= 2 * 10^4`
* expression[i] is one following characters: `'('`, `')'`, `'&'`, `'|'`, `'!'`, `'t'`, `'f'`, and `','`.


<br />

### Hints

- Write a function "parse" which calls helper functions "parse_or", "parse_and", "parse_not".

<br />

### Solution

```cpp
class Solution {
  public:
    bool parseBoolExpr (string expression) {
      std::stack <char> operations;
      std::stack <bool> operands;
      std::stack <int> count;
      int n = expression.length(), tokens = 0;

      for (int i = 0; i < n; ++i) {
        switch (expression[i]) {
          case '(':
            count.push(tokens);
            tokens = 0;
            break;
          
          case ')': {
            char op = operations.top();

            operations.pop();

            if (op == '!') {
              bool x = operands.top();
              operands.pop();
              operands.push(!x);
            }
            else {
              bool result = op == '&';

              while (!operands.empty() and tokens > 0) {
                --tokens;
                int t = operands.top();
                operands.pop();
                if (op == '&')
                  result &= t;
                else if (op == '|')
                  result |= t;
              }

              operands.push(result);
            }
            
            tokens = count.top() + 1;
            count.pop();
            break;
          }
          
          case '&':
            operations.push('&');
            break;
          
          case '|':
            operations.push('|');
            break;
          
          case '!':
            operations.push('!');
            break;
          
          case 't':
            operands.push(true);
            ++tokens;
            break;
          
          case 'f':
            operands.push(false);
            ++tokens;
            break;
          
          default:
            break;
        }
      }

      return operands.top();
    }
};
```

<br />

### Statistics

- total accepted: 22038
- total submissions: 37614
- acceptance rate: 58.6%
- likes: 854
- dislikes: 44

<br />

### Similar Problems

None
