# [1678] Goal Parser Interpretation

**[string]**

### Statement

You own a **Goal Parser** that can interpret a string `command`. The `command` consists of an alphabet of `"G"`, `"()"` and/or `"(al)"` in some order. The Goal Parser will interpret `"G"` as the string `"G"`, `"()"` as the string `"o"`, and `"(al)"` as the string `"al"`. The interpreted strings are then concatenated in the original order.

Given the string `command`, return *the **Goal Parser**'s interpretation of* `command`.


**Example 1:**

```

**Input:** command = "G()(al)"
**Output:** "Goal"
**Explanation:**The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

```

**Example 2:**

```

**Input:** command = "G()()()()(al)"
**Output:** "Gooooal"

```

**Example 3:**

```

**Input:** command = "(al)G(al)()()G"
**Output:** "alGalooG"

```

**Constraints:**
* `1 <= command.length <= 100`
* `command` consists of `"G"`, `"()"`, and/or `"(al)"` in some order.


<br>

### Hints

- You need to check at most 2 characters to determine which character comes next.

<br>

### Solution

```cpp
class Solution {
  public:
    string interpret (string command) {
      std::string result;
      int n = command.length(), i = 0;
      
      while (i < n) {
        if (command[i] == 'G') {
          result += 'G';
          ++i;
        }
        else if (command[i + 1] == ')') {
          result += "o";
          i += 2;
        }
        else {
          result += "al";
          i += 4;
        }
      }
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 125086
- total submissions: 145514
- acceptance rate: 86.0%
- likes: 837
- dislikes: 67

<br>

### Similar Problems

None
