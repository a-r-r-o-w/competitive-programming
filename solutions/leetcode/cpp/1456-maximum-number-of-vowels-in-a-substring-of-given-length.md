# [1456] Maximum Number of Vowels in a Substring of Given Length

**[string, sliding-window]**

### Statement

Given a string `s` and an integer `k`, return *the maximum number of vowel letters in any substring of* `s` *with length* `k`.

**Vowel letters** in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.


**Example 1:**

```

**Input:** s = "abciiidef", k = 3
**Output:** 3
**Explanation:** The substring "iii" contains 3 vowel letters.

```

**Example 2:**

```

**Input:** s = "aeiou", k = 2
**Output:** 2
**Explanation:** Any substring of length 2 contains 2 vowels.

```

**Example 3:**

```

**Input:** s = "leetcode", k = 3
**Output:** 2
**Explanation:** "lee", "eet" and "ode" contain 2 vowels.

```

**Constraints:**
* `1 <= s.length <= 10^5`
* `s` consists of lowercase English letters.
* `1 <= k <= s.length`


<br />

### Hints

- Keep a window of size k and maintain the number of vowels in it.
- Keep moving the window and update the number of vowels while moving. Answer is max number of vowels of any window.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxVowels (string s, int k) {
      int n = s.length(), count = 0, max = 0;
      auto is_vowel = [] (char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
      };

      for (int i = 0; i < k; ++i) {
        if (is_vowel(s[i]))
          ++count;
      }
      max = count;
      for (int i = k; i < n; ++i) {
        if (is_vowel(s[i]))
          ++count;
        if (is_vowel(s[i - k]))
          --count;
        if (count > max)
          max = count;
      }

      return max;
    }
};
```

<br />

### Statistics

- total accepted: 80284
- total submissions: 133978
- acceptance rate: 59.9%
- likes: 1556
- dislikes: 61

<br />

### Similar Problems

- [Maximum White Tiles Covered by a Carpet](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet) (Medium)
- [Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks) (Easy)
- [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring) (Medium)
