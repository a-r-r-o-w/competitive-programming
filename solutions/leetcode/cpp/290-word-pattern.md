# [290] Word Pattern

**[hash-table, string]**

### Statement

Given a `pattern` and a string `s`, find if `s`follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.


**Example 1:**

```

**Input:** pattern = "abba", s = "dog cat cat dog"
**Output:** true

```

**Example 2:**

```

**Input:** pattern = "abba", s = "dog cat cat fish"
**Output:** false

```

**Example 3:**

```

**Input:** pattern = "aaaa", s = "dog cat cat dog"
**Output:** false

```

**Constraints:**
* `1 <= pattern.length <= 300`
* `pattern` contains only lower-case English letters.
* `1 <= s.length <= 3000`
* `s` contains only lowercase English letters and spaces `' '`.
* `s` **does not contain** any leading or trailing spaces.
* All the words in `s` are separated by a **single space**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool wordPattern (string pattern, string s) {
      std::unordered_map <char, std::string> match;
      std::stringstream stream (s);
      int index = 0;

      while (stream >> s) {
        if (index >= (int)pattern.size())
          return false;
        
        if (match.count(pattern[index])) {
          if (match[pattern[index]] != s)
            return false;
        }
        else
          match[pattern[index]] = s;
        ++index;
      }

      if (index < (int)pattern.size())
        return false;

      for (char c = 'a'; c <= 'z'; ++c) {
        for (char d = c + 1; d <= 'z'; ++d) {
          if (!match.count(c) or !match.count(d))
            continue;
          if (match[c] == match[d])
            return false;
        }
      }

      return true;
    }
};
```

<br>

### Statistics

- total accepted: 419744
- total submissions: 1035332
- acceptance rate: 40.5%
- likes: 4441
- dislikes: 509

<br>

### Similar Problems

- [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings) (Easy)
- [Word Pattern II](https://leetcode.com/problems/word-pattern-ii) (Medium)
