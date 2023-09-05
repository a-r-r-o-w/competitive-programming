# [1935] Maximum Number of Words You Can Type

**[hash-table, string]**

### Statement

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string `text` of words separated by a single space (no leading or trailing spaces) and a string `brokenLetters` of all **distinct** letter keys that are broken, return *the **number of words** in* `text` *you can fully type using this keyboard*.


**Example 1:**

```

**Input:** text = "hello world", brokenLetters = "ad"
**Output:** 1
**Explanation:** We cannot type "world" because the 'd' key is broken.

```

**Example 2:**

```

**Input:** text = "leet code", brokenLetters = "lt"
**Output:** 1
**Explanation:** We cannot type "leet" because the 'l' and 't' keys are broken.

```

**Example 3:**

```

**Input:** text = "leet code", brokenLetters = "e"
**Output:** 0
**Explanation:** We cannot type either word because the 'e' key is broken.

```

**Constraints:**
* `1 <= text.length <= 104`
* `0 <= brokenLetters.length <= 26`
* `text` consists of words separated by a single space without any leading or trailing spaces.
* Each word only consists of lowercase English letters.
* `brokenLetters` consists of **distinct** lowercase English letters.


<br>

### Hints

- Check each word separately if it can be typed.
- A word can be typed if all its letters are not broken.

<br>

### Solution

```cpp
class Solution {
  public:
    int canBeTypedWords (string text, string brokenLetters) {
      int count = 0, n = text.size();
      std::vector <bool> bad (26);
      bool use = true;
      
      for (char c: brokenLetters)
        bad[c - 'a'] = true;
      
      for (char c: text) {
        if (c == ' ') {
          if (use)
            ++count;
          use = true;
        }
        else if (bad[c - 'a'])
          use = false;
      }
      
      if (use)
        ++count;
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 38150
- total submissions: 53742
- acceptance rate: 71.0%
- likes: 405
- dislikes: 18

<br>

### Similar Problems

None
