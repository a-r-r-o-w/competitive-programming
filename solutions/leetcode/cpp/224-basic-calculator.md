# [224] Basic Calculator

**[math, string, stack, recursion]**

### Statement

Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return *the result of the evaluation*.

**Note:** You are **not** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.


**Example 1:**

```

**Input:** s = "1 + 1"
**Output:** 2

```

**Example 2:**

```

**Input:** s = " 2-1 + 2 "
**Output:** 3

```

**Example 3:**

```

**Input:** s = "(1+(4+5+2)-3)+(6+8)"
**Output:** 23

```

**Constraints:**
* `1 <= s.length <= 3 * 105`
* `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
* `s` represents a valid expression.
* `'+'` is **not** used as a unary operation (i.e., `"+1"` and `"+(2 + 3)"` is invalid).
* `'-'` could be used as a unary operation (i.e., `"-1"` and `"-(2 + 3)"` is valid).
* There will be no two consecutive operators in the input.
* Every number and running calculation will fit in a signed 32-bit integer.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int calculate(string s) {
      std::stack <int> values;
      std::stack <int> ops;
      int num = 0, ans = 0, sign = 1;
      
      for (char c: s) { 
        if (c >= '0' and c <= '9')
          num = num * 10 + (c - '0');
        else {
          ans += sign * num;
          num = 0;
          
          if (c == '+')
            sign = 1;
          else if (c == '-')
            sign = -1;
          else if (c == '(') {
            values.push(ans);
            ops.push(sign);
            ans = 0;
            sign = 1;
          }
          else if (c == ')' && !ops.empty()) {
            ans = ops.top() * ans + values.top();
            ops.pop();
            values.pop();
          }
        }
      }
      
      ans += sign * num;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 337181
- total submissions: 812456
- acceptance rate: 41.5%
- likes: 4500
- dislikes: 345

<br>

### Similar Problems

- [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation) (Medium)
- [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii) (Medium)
- [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses) (Medium)
- [Expression Add Operators](https://leetcode.com/problems/expression-add-operators) (Hard)
- [Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii) (Hard)
- [The Score of Students Solving Math Expression](https://leetcode.com/problems/the-score-of-students-solving-math-expression) (Hard)
- [Minimize Result by Adding Parentheses to Expression](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression) (Medium)
