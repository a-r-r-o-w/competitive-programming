# [22] Generate Parentheses

**[string, dynamic-programming, backtracking]**

### Statement

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.


**Example 1:**

```
**Input:** n = 3
**Output:** ["((()))","(()())","(())()","()(())","()()()"]

```
**Example 2:**

```
**Input:** n = 1
**Output:** ["()"]

```

**Constraints:**
* `1 <= n <= 8`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> generateParenthesis (int n) {
      n = 2 * n;
      
      std::string x (n, ' ');
      std::vector <std::string> ans;
      
      auto dfs = [&] (auto self, int index, int d) -> void {
        if (index == n) {
          if (d == 0)
            ans.push_back(x);
          return;
        }
        if (d + 1 <= n - index) {
          x[index] = '(';
          self(self, index + 1, d + 1);
        }
        if (d - 1 >= 0) {
          x[index] = ')';
          self(self, index + 1, d - 1);
        }
      };
      
      dfs(dfs, 0, 0);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1086136
- total submissions: 1541548
- acceptance rate: 70.5%
- likes: 13238
- dislikes: 505

<br>

### Similar Problems

- [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number) (Medium)
- [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) (Easy)
- [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid) (Medium)
