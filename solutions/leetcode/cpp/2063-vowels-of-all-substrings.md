# [2063] Vowels of All Substrings

**[math, string, dynamic-programming, combinatorics]**

### Statement

Given a string `word`, return *the **sum of the number of vowels** (*`'a'`, `'e'`*,* `'i'`*,* `'o'`*, and* `'u'`*)* *in every substring of* `word`.

A **substring** is a contiguous (non-empty) sequence of characters within a string.

**Note:** Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.


**Example 1:**

```

**Input:** word = "aba"
**Output:** 6
**Explanation:** 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 

```

**Example 2:**

```

**Input:** word = "abc"
**Output:** 3
**Explanation:** 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.

```

**Example 3:**

```

**Input:** word = "ltcd"
**Output:** 0
**Explanation:** There are no vowels in any substring of "ltcd".

```

**Constraints:**
* `1 <= word.length <= 105`
* `word` consists of lowercase English letters.


<br>

### Hints

- Since generating substrings is not an option, can we count the number of substrings a vowel appears in?
- How much does each vowel contribute to the total sum?

<br>

### Solution

```cpp
class Solution {
  public:
    long long countVowels (string word) {
      int n = word.length();
      int64_t ans = 0;

      for (int i = 0; i < n; ++i) {
        char c = word[i];
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
          ans += int64_t(i + 1) * (n - i);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 20076
- total submissions: 36593
- acceptance rate: 54.9%
- likes: 596
- dislikes: 22

<br>

### Similar Problems

- [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters) (Medium)
- [Total Appeal of A String](https://leetcode.com/problems/total-appeal-of-a-string) (Hard)
