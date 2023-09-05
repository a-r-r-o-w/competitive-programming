# [1910] Remove All Occurrences of a Substring

**[string]**

### Statement

Given two strings `s` and `part`, perform the following operation on `s` until **all** occurrences of the substring `part` are removed:

* Find the **leftmost** occurrence of the substring `part` and **remove** it from `s`.



Return `s` *after removing all occurrences of* `part`.

A **substring** is a contiguous sequence of characters in a string.


**Example 1:**

```

**Input:** s = "daabcbaabcbc", part = "abc"
**Output:** "dab"
**Explanation**: The following operations are done:
- s = "da**abc**baabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "daba**abc**bc", remove "abc" starting at index 4, so s = "dababc".
- s = "dab**abc**", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

```

**Example 2:**

```

**Input:** s = "axxxxyyyyb", part = "xy"
**Output:** "ab"
**Explanation**: The following operations are done:
- s = "axxx**xy**yyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axx**xy**yyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "ax**xy**yb", remove "xy" starting at index 2 so s = "axyb".
- s = "a**xy**b", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

```

**Constraints:**
* `1 <= s.length <= 1000`
* `1 <= part.length <= 1000`
* `s`​​​​​​ and `part` consists of lowercase English letters.


<br>

### Hints

- Note that a new occurrence of pattern can appear if you remove an old one, For example, s = "ababcc" and pattern = "abc".
- You can maintain a stack of characters and if the last character of the pattern size in the stack match the pattern remove them

<br>

### Solution

```cpp
class Solution {
  public:
    string removeOccurrences (string s, string part) {
      while (true) {
        auto f = s.find(part);
        
        if (f == std::string::npos)
          break;
        
        s.erase(s.begin() + f, s.begin() + f + part.size());
      }
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 45988
- total submissions: 61981
- acceptance rate: 74.2%
- likes: 998
- dislikes: 43

<br>

### Similar Problems

- [Maximum Deletions on a String](https://leetcode.com/problems/maximum-deletions-on-a-string) (Hard)
