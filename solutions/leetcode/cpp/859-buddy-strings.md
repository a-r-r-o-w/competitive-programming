# [859] Buddy Strings

**[hash-table, string]**

### Statement

Given two strings `s` and `goal`, return `true` *if you can swap two letters in* `s` *so the result is equal to* `goal`*, otherwise, return* `false`*.*

Swapping letters is defined as taking two indices `i` and `j` (0-indexed) such that `i != j` and swapping the characters at `s[i]` and `s[j]`.

* For example, swapping at indices `0` and `2` in `"abcd"` results in `"cbad"`.


**Example 1:**

```

**Input:** s = "ab", goal = "ba"
**Output:** true
**Explanation:** You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

```

**Example 2:**

```

**Input:** s = "ab", goal = "ab"
**Output:** false
**Explanation:** The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

```

**Example 3:**

```

**Input:** s = "aa", goal = "aa"
**Output:** true
**Explanation:** You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

```

**Constraints:**
* `1 <= s.length, goal.length <= 2 * 10^4`
* `s` and `goal` consist of lowercase letters.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    bool buddyStrings (string s, string goal) {
      if ((int)s.length() == 1)
        return false;
      if (s == goal) {
        std::vector <int> freq (26);
        for (char c: s) {
          ++freq[c - 'a'];
          if (freq[c - 'a'] == 2)
            return true;
        }
        return false;
      }
      if (s.length() != goal.length())
        return false;
      
      int count = 0, n = s.length(), p = -1, q = -1;
      for (int i = 0; i < n; ++i) {
        if (s[i] != goal[i]) {
          ++count;
          if (p == -1)
            p = i;
          else
            q = i;
        }
      }
      return count == 2 and s[p] == goal[q] and s[q] == goal[p];
    }
};
```

<br />

### Statistics

- total accepted: 193938
- total submissions: 601831
- acceptance rate: 32.2%
- likes: 2674
- dislikes: 1551

<br />

### Similar Problems

- [Determine if Two Strings Are Close](https://leetcode.com/problems/determine-if-two-strings-are-close) (Medium)
- [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal) (Easy)
- [Make Number of Distinct Characters Equal](https://leetcode.com/problems/make-number-of-distinct-characters-equal) (Medium)
