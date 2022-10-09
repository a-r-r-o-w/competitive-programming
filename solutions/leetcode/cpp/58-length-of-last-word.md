# [58] Length of Last Word

**[string]**

### Statement

Given a string `s` consisting of words and spaces, return *the length of the **last** word in the string.*

A **word** is a maximal substring consisting of non-space characters only.


**Example 1:**

```

**Input:** s = "Hello World"
**Output:** 5
**Explanation:** The last word is "World" with length 5.

```

**Example 2:**

```

**Input:** s = "   fly me   to   the moon  "
**Output:** 4
**Explanation:** The last word is "moon" with length 4.

```

**Example 3:**

```

**Input:** s = "luffy is still joyboy"
**Output:** 6
**Explanation:** The last word is "joyboy" with length 6.

```

**Constraints:**
* `1 <= s.length <= 10^4`
* `s` consists of only English letters and spaces `' '`.
* There will be at least one word in `s`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int lengthOfLastWord (string s) {
      int len = 0;
      bool space = false;
      
      for (char c: s) {
        if (c == ' ') {
          space = true;
        }
        else {
          if (space) {
            len = 1;
            space = false;
          }
          else
            ++len;
        }
      }
      
      return len;
    }
};
```

<br>

### Statistics

- total accepted: 843709
- total submissions: 2136453
- acceptance rate: 39.5%
- likes: 1625
- dislikes: 113

<br>

### Similar Problems

None
