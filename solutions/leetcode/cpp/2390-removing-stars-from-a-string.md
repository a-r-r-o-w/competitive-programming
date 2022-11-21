# [2390] Removing Stars From a String

**[string, stack, simulation]**

### Statement

You are given a string `s`, which contains stars `*`.

In one operation, you can:

* Choose a star in `s`.
* Remove the closest **non-star** character to its **left**, as well as remove the star itself.



Return *the string after **all** stars have been removed*.

**Note:**
* The input will be generated such that the operation is always possible.
* It can be shown that the resulting string will always be unique.


**Example 1:**

```

**Input:** s = "leet**cod*e"
**Output:** "lecoe"
**Explanation:** Performing the removals from left to right:
- The closest character to the 1st star is 't' in "lee**t****cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "le**e***cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "leco**d***e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```

**Example 2:**

```

**Input:** s = "erase*****"
**Output:** ""
**Explanation:** The entire string is removed, so we return an empty string.

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of lowercase English letters and stars `*`.
* The operation above can be performed on `s`.


<br>

### Hints

- What data structure could we use to efficiently perform these removals?
- Use a stack to store the characters. Pop one character off the stack at each star. Otherwise, we push the character onto the stack.

<br>

### Solution

Using additional memory

```cpp
class Solution {
  public:
    string removeStars (string s) {
      std::vector <char> v;
      
      for (char c: s) {
        if (c == '*')
          v.pop_back();
        else
          v.push_back(c);
      }
      
      return std::string(v.begin(), v.end());
    }
};
```

Two Pointers

```cpp
class Solution {
  public:
    string removeStars (string s) {
      int n = s.length(), i = 0, j = 0;
      
      while (j < n) {
        if (s[j] == '*')
          --i, ++j;
        else
          s[i++] = s[j++];
      }
      
      return s.substr(0, i);
    }
};
```

<br>

### Statistics

- total accepted: 29513
- total submissions: 46724
- acceptance rate: 63.2%
- likes: 426
- dislikes: 22

<br>

### Similar Problems

- [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare) (Easy)
- [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string) (Easy)
