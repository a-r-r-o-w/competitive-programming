# [1832] Check if the Sentence Is Pangram

**[hash-table, string]**

### Statement

A **pangram** is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return`true` *if* `sentence` *is a **pangram**, or* `false` *otherwise.*
**Example 1:**

```

**Input:** sentence = "thequickbrownfoxjumpsoverthelazydog"
**Output:** true
**Explanation:** sentence contains at least one of every letter of the English alphabet.

```

**Example 2:**

```

**Input:** sentence = "leetcode"
**Output:** false

```

**Constraints:**
* `1 <= sentence.length <= 1000`
* `sentence` consists of lowercase English letters.


<br>

### Hints

- Iterate over the string and mark each character as found (using a boolean array, bitmask, or any other similar way).
- Check if the number of found characters equals the alphabet length.

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkIfPangram (string sentence) {
      return (int)std::unordered_set <char> (sentence.begin(), sentence.end()).size() == 26;
    }
};
```

```cpp
class Solution {
  public:
    bool checkIfPangram (string sentence) {
      bool have[26] = {false};
      
      for (char c: sentence)
        have[c - 'a'] = true;
      
      return std::all_of(have, have + 26, [] (auto x) { return x; });
    }
};
```

<br>

### Statistics

- total accepted: 112833
- total submissions: 138921
- acceptance rate: 81.2%
- likes: 1090
- dislikes: 26

<br>

### Similar Problems

None
