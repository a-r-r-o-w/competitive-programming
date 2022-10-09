# [709] To Lower Case

**[string]**

### Statement

Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.


**Example 1:**

```

**Input:** s = "Hello"
**Output:** "hello"

```

**Example 2:**

```

**Input:** s = "here"
**Output:** "here"

```

**Example 3:**

```

**Input:** s = "LOVELY"
**Output:** "lovely"

```

**Constraints:**
* `1 <= s.length <= 100`
* `s` consists of printable ASCII characters.


<br>

### Hints

- Most languages support lowercase conversion for a string data type. However, that is certainly not the purpose of the problem. Think about how the implementation of the lowercase function call can be done easily.
- <b>Think ASCII!</b>
- Think about the different capital letters and their ASCII codes and how that relates to their lowercase counterparts. Does there seem to be any pattern there? Any mathematical relationship that we can use?

<br>

### Solution

```cpp
class Solution {
  public:
    string toLowerCase (string s) {
      for (char &c: s) {
        if ('A' <= c and c <= 'Z')
          c = c - 'A' + 'a';
      }
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 360525
- total submissions: 441461
- acceptance rate: 81.7%
- likes: 1205
- dislikes: 2406

<br>

### Similar Problems

- [Capitalize the Title](https://leetcode.com/problems/capitalize-the-title) (Easy)
