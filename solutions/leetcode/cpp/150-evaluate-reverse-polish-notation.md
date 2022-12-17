# [150] Evaluate Reverse Polish Notation

**[array, math, stack]**

### Statement

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or another expression.

**Note** that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.


**Example 1:**

```

**Input:** tokens = ["2","1","+","3","*"]
**Output:** 9
**Explanation:** ((2 + 1) * 3) = 9

```

**Example 2:**

```

**Input:** tokens = ["4","13","5","/","+"]
**Output:** 6
**Explanation:** (4 + (13 / 5)) = 6

```

**Example 3:**

```

**Input:** tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
**Output:** 22
**Explanation:** ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

```

**Constraints:**
* `1 <= tokens.length <= 104`
* `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int evalRPN (vector <string>& tokens) {
      std::stack <int64_t> values;

      for (auto &s: tokens) {
        if ((int)s.length() == 1 and (s[0] == '+' or s[0] == '-' or s[0] == '*' or s[0] == '/')) {
          int64_t x = values.top(); values.pop();
          int64_t y = values.top(); values.pop();
          int64_t result = 0;
          
          switch (s[0]) {
            case '+': result = y + x; break;
            case '-': result = y - x; break;
            case '*': result = y * x; break;
            case '/': result = y / x; break;
            default: break;
          }

          values.push(result);
        }
        else
          values.push(std::stoi(s));
      }

      return values.top();
    }
};
```

<br>

### Statistics

- total accepted: 549447
- total submissions: 1238727
- acceptance rate: 44.4%
- likes: 4458
- dislikes: 767

<br>

### Similar Problems

- [Basic Calculator](https://leetcode.com/problems/basic-calculator) (Hard)
- [Expression Add Operators](https://leetcode.com/problems/expression-add-operators) (Hard)
