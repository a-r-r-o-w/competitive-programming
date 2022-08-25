# [1662] Check If Two String Arrays are Equivalent

**[array, string]**

### Statement

Given two string arrays `word1` and `word2`, return`true` *if the two arrays **represent** the same string, and* `false` *otherwise.*

A string is **represented** by an array if the array elements concatenated **in order** forms the string.


**Example 1:**

```

**Input:** word1 = ["ab", "c"], word2 = ["a", "bc"]
**Output:** true
**Explanation:**
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
```

**Example 2:**

```

**Input:** word1 = ["a", "cb"], word2 = ["ab", "c"]
**Output:** false

```

**Example 3:**

```

**Input:** word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
**Output:** true

```

**Constraints:**
* `1 <= word1.length, word2.length <= 103`
* `1 <= word1[i].length, word2[i].length <= 103`
* `1 <= sum(word1[i].length), sum(word2[i].length) <= 103`
* `word1[i]` and `word2[i]` consist of lowercase letters.


<br>

### Hints

- Concatenate all strings in the first array into a single string in the given order, the same for the second array.
- Both arrays represent the same string if and only if the generated strings are the same.

<br>

### Solution

```cpp
class Solution {
  public:
    bool arrayStringsAreEqual (vector <string>& word1, vector <string>& word2) {
      std::string x, y;
      for (auto &w: word1)
        x += w;
      for (auto &w: word2)
        y += w;
      return x == y;
    }
};
```

Using O(1) space

```cpp
class Solution {
  public:
    bool arrayStringsAreEqual (vector <string>& word1, vector <string>& word2) {
      int w1 = 0, w2 = 0;
      int i1 = 0, i2 = 0;
      int n1 = word1.size(), n2 = word2.size();
      
      while (w1 < n1 and w2 < n2) {
        while (i1 < (int)word1[w1].length() and i2 < (int)word2[w2].length()) {
          if (word1[w1][i1] != word2[w2][i2])
            return false;
          ++i1;
          ++i2;
        }
        if (i1 == (int)word1[w1].length()) {
          ++w1;
          i1 = 0;
        }
        if (i2 == (int)word2[w2].length()) {
          ++w2;
          i2 = 0;
        }
      }
      
      return w1 == n1 and w2 == n2;
    }
};
```

<br>

### Statistics

- total accepted: 157718
- total submissions: 192682
- acceptance rate: 81.9%
- likes: 935
- dislikes: 116

<br>

### Similar Problems

- [Check if an Original String Exists Given Two Encoded Strings](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings) (Hard)
