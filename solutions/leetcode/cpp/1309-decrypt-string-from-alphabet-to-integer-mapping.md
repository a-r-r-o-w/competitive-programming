# [1309] Decrypt String from Alphabet to Integer Mapping

**[string]**

### Statement

You are given a string `s` formed by digits and `'#'`. We want to map `s` to English lowercase characters as follows:

* Characters (`'a'` to `'i'`) are represented by (`'1'` to `'9'`) respectively.
* Characters (`'j'` to `'z'`) are represented by (`'10#'` to `'26#'`) respectively.



Return *the string formed after mapping*.

The test cases are generated so that a unique mapping will always exist.


**Example 1:**

```

**Input:** s = "10#11#12"
**Output:** "jkab"
**Explanation:** "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

```

**Example 2:**

```

**Input:** s = "1326#"
**Output:** "acz"

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s` consists of digits and the `'#'` letter.
* `s` will be a valid string such that mapping is always possible.


<br>

### Hints

- Scan from right to left, in each step of the scanning check whether there is a trailing "#" 2 indexes away.

<br>

### Solution

```cpp
class Solution {
  public:
    string freqAlphabets (string s) {
      std::string result;
      int n = s.length();
      
      for (int i = 0; i < n; ++i) {
        if (i + 2 < n and s[i + 2] == '#') {
          result += (s[i] - '0') * 10 + (s[i + 1] - '0') + 'a' - 1;
          i += 2;
        }
        else
          result += s[i] - '0' + 'a' - 1;
      }

      return result;
    }
};
```

<br>

### Statistics

- total accepted: 99877
- total submissions: 125532
- acceptance rate: 79.6%
- likes: 1263
- dislikes: 86

<br>

### Similar Problems

None
