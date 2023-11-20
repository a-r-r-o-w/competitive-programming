# [1704] Determine if String Halves Are Alike

**[string, counting]**

### Statement

You are given a string `s` of even length. Split this string into two halves of equal lengths, and let `a` be the first half and `b` be the second half.

Two strings are **alike** if they have the same number of vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`, `'A'`, `'E'`, `'I'`, `'O'`, `'U'`). Notice that `s` contains uppercase and lowercase letters.

Return `true` *if* `a` *and* `b` *are **alike***. Otherwise, return `false`.


**Example 1:**

```

**Input:** s = "book"
**Output:** true
**Explanation:** a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

```

**Example 2:**

```

**Input:** s = "textbook"
**Output:** false
**Explanation:** a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.

```

**Constraints:**
* `2 <= s.length <= 1000`
* `s.length` is even.
* `s` consists of **uppercase and lowercase** letters.


<br>

### Hints

- Create a function that checks if a character is a vowel, either uppercase or lowercase.

<br>

### Solution

```cpp
class Solution {
  public:
    bool halvesAreAlike (string s) {
      int n = s.length();
      int v = 0;
      
      for (int i = 0; i < n / 2; ++i) {
        char c = std::tolower(s[i]);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
          ++v;
      }
      for (int i = n / 2; i < n; ++i) {
        char c = std::tolower(s[i]);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
          --v;
      }
      
      return v == 0;
    }
};
```

<br>

### Statistics

- total accepted: 123645
- total submissions: 158665
- acceptance rate: 77.9%
- likes: 973
- dislikes: 61

<br>

### Similar Problems

None
