# [318] Maximum Product of Word Lengths

**[array, string, bit-manipulation]**

### Statement

Given a string array `words`, return *the maximum value of* `length(word[i]) * length(word[j])` *where the two words do not share common letters*. If no such two words exist, return `0`.


**Example 1:**

```

**Input:** words = ["abcw","baz","foo","bar","xtfn","abcdef"]
**Output:** 16
**Explanation:** The two words can be "abcw", "xtfn".

```

**Example 2:**

```

**Input:** words = ["a","ab","abc","d","cd","bcd","abcd"]
**Output:** 4
**Explanation:** The two words can be "ab", "cd".

```

**Example 3:**

```

**Input:** words = ["a","aa","aaa","aaaa"]
**Output:** 0
**Explanation:** No such pair of words.

```

**Constraints:**
* `2 <= words.length <= 1000`
* `1 <= words[i].length <= 1000`
* `words[i]` consists only of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

Brute Force

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxProduct (vector <string>& words) {
      int max = 0;
      int n = words.size();
      std::vector <int> freq (26);
      
      for (int i = 0; i < n; ++i) {
        for (char c: words[i])
          ++freq[c - 'a'];
        
        for (int j = i + 1; j < n; ++j) {
          bool bad = false;
          
          for (char c: words[j]) {
            if (freq[c - 'a'] > 0) {
              bad = true;
              break;
            }
          }
          
          if (not bad)
            max = std::max <int> (max, words[i].size() * words[j].size());
        }
        
        std::fill(freq.begin(), freq.end(), 0);
      }
      
      return max;
    }
};
```

Optimising using bitmasks

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxProduct (vector <string>& words) {
      int max = 0;
      int n = words.size();
      std::vector <int> mask (n);
      
      for (int i = 0; i < n; ++i) {
        for (char &c: words[i])
          mask[i] |= 1 << (c - 'a');
      }
      
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (mask[i] & mask[j])
            continue;
          max = std::max <int> (max, words[i].size() * words[j].size());
        }
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 191790
- total submissions: 318541
- acceptance rate: 60.2%
- likes: 2967
- dislikes: 118

<br>

### Similar Problems

None
