# [2062] Count Vowel Substrings of a String

**[hash-table, string]**

### Statement

A **substring** is a contiguous (non-empty) sequence of characters within a string.

A **vowel substring** is a substring that **only** consists of vowels (`'a'`, `'e'`, `'i'`, `'o'`, and `'u'`) and has **all five** vowels present in it.

Given a string `word`, return *the number of **vowel substrings** in* `word`.


**Example 1:**

```

**Input:** word = "aeiouu"
**Output:** 2
**Explanation:** The vowel substrings of word are as follows (underlined):
- "**aeiou**u"
- "**aeiouu**"

```

**Example 2:**

```

**Input:** word = "unicornarihan"
**Output:** 0
**Explanation:** Not all 5 vowels are present, so there are no vowel substrings.

```

**Example 3:**

```

**Input:** word = "cuaieuouac"
**Output:** 7
**Explanation:** The vowel substrings of word are as follows (underlined):
- "c**uaieuo**uac"
- "c**uaieuou**ac"
- "c**uaieuoua**c"
- "cu**aieuo**uac"
- "cu**aieuou**ac"
- "cu**aieuoua**c"
- "cua**ieuoua**c"

```

**Constraints:**
* `1 <= word.length <= 100`
* `word` consists of lowercase English letters only.


<br>

### Hints

- While generating substrings starting at any index, do you need to continue generating larger substrings if you encounter a consonant?
- Can you store the count of characters to avoid generating substrings altogether?

<br>

### Solution

```cpp
class Solution {
  public:
    int countVowelSubstrings (string word) {
      int n = word.length(), count = 0;
      std::unordered_map <char, int> m;
      m['a'] = 0;
      m['e'] = 1;
      m['i'] = 2;
      m['o'] = 3;
      m['u'] = 4;

      auto is_vowel = [] (char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
      };

      for (int i = 0; i < n; ++i) {
        int have = 0;
        for (int j = i; j < n; ++j) {
          if (not is_vowel(word[j]))
            break;
          have |= 1 << m[word[j]];
          if (__builtin_popcount(have) == 5)
            ++count;
        }
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 24955
- total submissions: 37784
- acceptance rate: 66.0%
- likes: 648
- dislikes: 161

<br>

### Similar Problems

- [Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences) (Medium)
- [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers) (Hard)
- [Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s) (Medium)
- [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order) (Medium)
- [Total Appeal of A String](https://leetcode.com/problems/total-appeal-of-a-string) (Hard)
