# [844] Backspace String Compare

**[two-pointers, string, stack, simulation]**

### Statement

Given two strings `s` and `t`, return `true` *if they are equal when both are typed into empty text editors*. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.


**Example 1:**

```

**Input:** s = "ab#c", t = "ad#c"
**Output:** true
**Explanation:** Both s and t become "ac".

```

**Example 2:**

```

**Input:** s = "ab##", t = "c#d#"
**Output:** true
**Explanation:** Both s and t become "".

```

**Example 3:**

```

**Input:** s = "a#c", t = "b"
**Output:** false
**Explanation:** s becomes "c" while t becomes "b".

```

**Constraints:**
* `1 <= s.length, t.length <= 200`
* `s` and `t` only contain lowercase letters and `'#'` characters.


**Follow up:** Can you solve it in `O(n)` time and `O(1)` space?

<br>

### Hints

None

<br>

### Solution

Simulation

```cpp
class Solution {
  public:
    bool backspaceCompare (string s, string t) {
      std::string rs, rt;
      
      for (char c: s) {
        if (c != '#')
          rs.push_back(c);
        else if (not rs.empty())
          rs.pop_back();
      }
      
      for (char c: t) {
        if (c != '#')
          rt.push_back(c);
        else if (not rt.empty())
          rt.pop_back();
      }
      
      return rs == rt;
    }
};
```

<br>

### Statistics

- total accepted: 541605
- total submissions: 1128667
- acceptance rate: 48.0%
- likes: 5524
- dislikes: 244

<br>

### Similar Problems

- [Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder) (Easy)
- [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) (Medium)
