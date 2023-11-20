# [1446] Consecutive Characters

**[string]**

### Statement

The **power** of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string `s`, return *the **power** of* `s`.


**Example 1:**

```

**Input:** s = "leetcode"
**Output:** 2
**Explanation:** The substring "ee" is of length 2 with the character 'e' only.

```

**Example 2:**

```

**Input:** s = "abbcccddddeeeeedcba"
**Output:** 5
**Explanation:** The substring "eeeee" is of length 5 with the character 'e' only.

```

**Constraints:**
* `1 <= s.length <= 500`
* `s` consists of only lowercase English letters.


<br>

### Hints

- Keep an array power where power[i] is the maximum power of the i-th character.
- The answer is max(power[i]).

<br>

### Solution

```cpp
class Solution {
  public:
    int maxPower (string s) {
      char prev = ' ';
      int len = 1, max = 1;

      for (char c: s) {
        if (c == prev)
          ++len;
        else {
          prev = c;
          max = std::max(max, len);
          len = 1;
        }
      }

      return std::max(max, len);
    }
};
```

<br>

### Statistics

- total accepted: 133003
- total submissions: 216129
- acceptance rate: 61.5%
- likes: 1425
- dislikes: 28

<br>

### Similar Problems

- [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) (Easy)
- [Check if an Array Is Consecutive](https://leetcode.com/problems/check-if-an-array-is-consecutive) (Easy)
- [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings) (Medium)
- [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character) (Hard)
