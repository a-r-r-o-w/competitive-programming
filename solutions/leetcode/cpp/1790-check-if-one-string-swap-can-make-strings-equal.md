# [1790] Check if One String Swap Can Make Strings Equal

**[hash-table, string, counting]**

### Statement

You are given two strings `s1` and `s2` of equal length. A **string swap** is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return `true` *if it is possible to make both strings equal by performing **at most one string swap** on **exactly one** of the strings.* Otherwise, return `false`.


**Example 1:**

```

**Input:** s1 = "bank", s2 = "kanb"
**Output:** true
**Explanation:** For example, swap the first character with the last character of s2 to make "bank".

```

**Example 2:**

```

**Input:** s1 = "attack", s2 = "defend"
**Output:** false
**Explanation:** It is impossible to make them equal with one string swap.

```

**Example 3:**

```

**Input:** s1 = "kelb", s2 = "kelb"
**Output:** true
**Explanation:** The two strings are already equal, so no string swap operation is required.

```

**Constraints:**
* `1 <= s1.length, s2.length <= 100`
* `s1.length == s2.length`
* `s1` and `s2` consist of only lowercase English letters.


<br>

### Hints

- The answer is false if the number of nonequal positions in the strings is not equal to 0 or 2.
- Check that these positions have the same set of characters.

<br>

### Solution

```cpp
class Solution {
  public:
    bool areAlmostEqual (string s1, string s2) {
      int n = s1.size();
      int p1 = -1, p2 = -1;
      int count = 0;
      
      for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i])
          continue;
        else if (p1 == -1)
          p1 = i;
        else if (p2 == -1)
          p2 = i;
        ++count;
      }
      
      if (count == 0 or (count == 2 and p1 != -1 and p2 != -1 and s1[p1] == s2[p2] and s1[p2] == s2[p1]))
        return true;
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 58349
- total submissions: 128204
- acceptance rate: 45.5%
- likes: 635
- dislikes: 28

<br>

### Similar Problems

- [Buddy Strings](https://leetcode.com/problems/buddy-strings) (Easy)
