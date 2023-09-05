# [1941] Check if All Characters Have Equal Number of Occurrences

**[hash-table, string, counting]**

### Statement

Given a string `s`, return `true` *if* `s` *is a **good** string, or* `false` *otherwise*.

A string `s` is **good** if **all** the characters that appear in `s` have the **same** number of occurrences (i.e., the same frequency).


**Example 1:**

```

**Input:** s = "abacbc"
**Output:** true
**Explanation:** The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

```

**Example 2:**

```

**Input:** s = "aaabb"
**Output:** false
**Explanation:** The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters.


<br>

### Hints

- Build a dictionary containing the frequency of each character appearing in s
- Check if all values in the dictionary are the same.

<br>

### Solution

```cpp
class Solution {
  public:
    bool areOccurrencesEqual (string s) {
      std::vector <int> freq (26);
      int value = -1;

      for (char c: s)
        ++freq[c - 'a'];
      
      for (int i: freq) {
        if (i != 0) {
          if (value == -1)
            value = i;
          else if (i != value)
            return false;
        }
      }

      return true;
    }
};
```

<br>

### Statistics

- total accepted: 52984
- total submissions: 68993
- acceptance rate: 76.8%
- likes: 554
- dislikes: 14

<br>

### Similar Problems

- [Rings and Rods](https://leetcode.com/problems/rings-and-rods) (Easy)
