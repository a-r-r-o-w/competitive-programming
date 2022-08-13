# [30] Substring with Concatenation of All Words

**[hash-table, string, sliding-window]**

### Statement

You are given a string `s` and an array of strings `words` of **the same length**. Returnall starting indices of substring(s) in `s`that is a concatenation of each word in `words` **exactly once**, **in any order**,and **without any intervening characters**.

You can return the answer in **any order**.


**Example 1:**

```

**Input:** s = "barfoothefoobarman", words = ["foo","bar"]
**Output:** [0,9]
**Explanation:** Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

```

**Example 2:**

```

**Input:** s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
**Output:** []

```

**Example 3:**

```

**Input:** s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
**Output:** [6,9,12]

```

**Constraints:**
* `1 <= s.length <= 104`
* `1 <= words.length <= 5000`
* `1 <= words[i].length <= 30`
* `s` and `words[i]` consist of lowercase English letters.


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
  
    vector <int> findSubstring (string s, vector <string>& words) {
      std::vector <int> ans;
      std::unordered_map <std::string, int> count;
      int n = words.size(), m = s.length(), k = words.front().length();
      
      for (auto &word: words)
        ++count[word];
      
      for (int i = 0; i + n * k - 1 < m; ++i) {
        std::unordered_map <std::string, int> seen;
        bool bad = false;
        
        for (int j = 0; j < n; ++j) {
          std::string current_word = s.substr(i + j * k, k);
          
          ++seen[current_word];

          if (seen[current_word] > count[current_word]) {
            bad = true;
            break;
          }
        }
        
        if (not bad)
          ans.push_back(i);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 302353
- total submissions: 995803
- acceptance rate: 30.4%
- likes: 3018
- dislikes: 2150

<br>

### Similar Problems

- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) (Hard)
