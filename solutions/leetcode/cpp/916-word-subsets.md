# [916] Word Subsets

**[array, hash-table, string]**

### Statement

You are given two string arrays `words1` and `words2`.

A string `b` is a **subset** of string `a` if every letter in `b` occurs in `a` including multiplicity.

* For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.



A string `a` from `words1` is **universal** if for every string `b` in `words2`, `b` is a subset of `a`.

Return an array of all the **universal** strings in `words1`. You may return the answer in **any order**.


**Example 1:**

```

**Input:** words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
**Output:** ["facebook","google","leetcode"]

```

**Example 2:**

```

**Input:** words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
**Output:** ["apple","google","leetcode"]

```

**Constraints:**
* `1 <= words1.length, words2.length <= 104`
* `1 <= words1[i].length, words2[i].length <= 10`
* `words1[i]` and `words2[i]` consist only of lowercase English letters.
* All the strings of `words1` are **unique**.


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
  
    vector <string> wordSubsets (vector <string>& words1, vector <string>& words2) {
      std::vector <int> max_freq (26), freq (26);
      std::vector <std::string> ans;
      
      for (auto &word: words2) {
        for (auto &c: word)
          ++freq[c - 'a'];
        for (int i = 0; i < 26; ++i) {
          max_freq[i] = std::max(max_freq[i], freq[i]);
          freq[i] = 0;
        }
      }
      
      for (auto &word: words1) {
        for (auto &c: word)
          ++freq[c - 'a'];
        
        bool bad = false;
        
        for (int i = 0; i < 26; ++i) {
          if (max_freq[i] > freq[i])
            bad = true;
          freq[i] = 0;
        }
        
        if (!bad)
          ans.push_back(word);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 59082
- total submissions: 111788
- acceptance rate: 52.9%
- likes: 1250
- dislikes: 144

<br>

### Similar Problems

None
