# [953] Verifying an Alien Dictionary

**[array, hash-table, string]**

### Statement

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographically in this alien language.


**Example 1:**

```

**Input:** words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
**Output:** true
**Explanation:** As 'h' comes before 'l' in this language, then the sequence is sorted.

```

**Example 2:**

```

**Input:** words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
**Output:** false
**Explanation:** As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

```

**Example 3:**

```

**Input:** words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
**Output:** false
**Explanation:** The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character ([More info](https://en.wikipedia.org/wiki/Lexicographical_order)).

```

**Constraints:**
* `1 <= words.length <= 100`
* `1 <= words[i].length <= 20`
* `order.length == 26`
* All characters in `words[i]` and `order` are English lowercase letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
public:
    bool isAlienSorted (vector <string>& words, string order) {
      std::vector <int> index (26);
      int n = words.size();
      
      for (int i = 0; i < 26; ++i)
        index[order[i] - 'a'] = i;
      
      for (int i = 0; i < n - 1; ++i) {
        auto &x = words[i];
        auto &y = words[i + 1];
        int p = x.length();
        int q = y.length();
        int j = 0;
        bool bad = true;
        
        while (j < p and j < q) {
          if (index[x[j] - 'a'] > index[y[j] - 'a'])
            return false;
          else if (index[x[j] - 'a'] < index[y[j] - 'a']) {
            bad = false;
            break;
          }
          ++j;
        }
        
        if (bad and p > q)
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 368234
- total submissions: 699577
- acceptance rate: 52.6%
- likes: 3067
- dislikes: 983

<br>

### Similar Problems

None
