# [791] Custom Sort String

**[hash-table, string, sorting]**

### Statement

You are given two strings order and s. All the characters of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return *any permutation of* `s` *that satisfies this property*.


**Example 1:**

```

**Input:** order = "cba", s = "abcd"
**Output:** "cbad"
**Explanation:** 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

```

**Example 2:**

```

**Input:** order = "cbafg", s = "abcd"
**Output:** "cbad"

```

**Constraints:**
* `1 <= order.length <= 26`
* `1 <= s.length <= 200`
* `order` and `s` consist of lowercase English letters.
* All the characters of `order` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string customSortString (string order, string s) {
      std::vector <int> freq (26);
      
      for (char c: s)
        ++freq[c - 'a'];
      
      s.clear();
      
      for (char c: order) {
        if (freq[c - 'a'] > 0) {
          s += std::string(freq[c - 'a'], c);
          freq[c - 'a'] = 0;
        }
      }
      
      for (int i = 0; i < 26; ++i)
        if (freq[i])
          s += std::string(freq[i], i + 'a');
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 191857
- total submissions: 276633
- acceptance rate: 69.4%
- likes: 2169
- dislikes: 299

<br>

### Similar Problems

None
