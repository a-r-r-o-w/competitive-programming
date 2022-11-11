# [205] Isomorphic Strings

**[hash-table, string]**

### Statement

Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


**Example 1:**

```
**Input:** s = "egg", t = "add"
**Output:** true

```
**Example 2:**

```
**Input:** s = "foo", t = "bar"
**Output:** false

```
**Example 3:**

```
**Input:** s = "paper", t = "title"
**Output:** true

```

**Constraints:**
* `1 <= s.length <= 5 * 104`
* `t.length == s.length`
* `s` and `t` consist of any valid ascii character.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isIsomorphic (string s, string t) {
      std::vector <int> map (256, -1), used (256);
      int n = s.length();
      
      for (int i = 0; i < n; ++i) {
        int sc = s[i];
        int st = t[i];
        
        if (map[sc] == -1) {
          if (used[st])
            return false;
          map[sc] = st;
          used[st] = true;
        }
        else if (st != map[sc])
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 619391
- total submissions: 1459286
- acceptance rate: 42.4%
- likes: 4667
- dislikes: 851

<br>

### Similar Problems

- [Word Pattern](https://leetcode.com/problems/word-pattern) (Easy)
