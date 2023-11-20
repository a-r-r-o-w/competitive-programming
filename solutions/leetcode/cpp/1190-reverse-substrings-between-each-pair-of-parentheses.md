# [1190] Reverse Substrings Between Each Pair of Parentheses

**[string, stack]**

### Statement

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.


**Example 1:**

```

**Input:** s = "(abcd)"
**Output:** "dcba"

```

**Example 2:**

```

**Input:** s = "(u(love)i)"
**Output:** "iloveu"
**Explanation:** The substring "love" is reversed first, then the whole string is reversed.

```

**Example 3:**

```

**Input:** s = "(ed(et(oc))el)"
**Output:** "leetcode"
**Explanation:** First, we reverse the substring "oc", then "etco", and finally, the whole string.

```

**Constraints:**
* `1 <= s.length <= 2000`
* `s` only contains lower case English characters and parentheses.
* It is guaranteed that all parentheses are balanced.


<br>

### Hints

- Find all brackets in the string.
- Does the order of the reverse matter ?
- The order does not matter.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string reverseParentheses (string s) {
      int d = 0;
      std::stack <int> open;
      std::string ans;
      
      for (char c: s) {
        if (c == '(') {
          ++d;
          open.push(ans.length());
        }
        else if (c == ')') {
          int offset = open.top();
          open.pop();
          std::reverse(ans.begin() + offset, ans.end());
          --d;
        }
        else
          ans += c;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 52573
- total submissions: 79787
- acceptance rate: 65.9%
- likes: 1404
- dislikes: 39

<br>

### Similar Problems

None
