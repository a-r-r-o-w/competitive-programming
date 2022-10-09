# [792] Number of Matching Subsequences

**[hash-table, string, trie, sorting]**

### Statement

Given a string `s` and an array of strings `words`, return *the number of* `words[i]` *that is a subsequence of* `s`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.


**Example 1:**

```

**Input:** s = "abcde", words = ["a","bb","acd","ace"]
**Output:** 3
**Explanation:** There are three strings in words that are a subsequence of s: "a", "acd", "ace".

```

**Example 2:**

```

**Input:** s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
**Output:** 2

```

**Constraints:**
* `1 <= s.length <= 5 * 104`
* `1 <= words.length <= 5000`
* `1 <= words[i].length <= 50`
* `s` and `words[i]` consist of only lowercase English letters.


<br>

### Hints

None

<br>

### Solution

**O(s.length + words.length * max_word_length)**

Linear search for next valid index

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numMatchingSubseq (string s, vector <string>& words) {
      std::vector <std::vector <int>> have (26);
      
      for (int index = 0; char c: s)
        have[c - 'a'].push_back(index++);
      
      std::vector <int> indices (26);
      int ans = 0;
      
      for (auto& word: words) {
        bool bad = false;
        int index = -1;

        for (char c: word) {
          c -= 'a';
          
          while (indices[c] < (int)have[c].size() and have[c][indices[c]] <= index)
            ++indices[c];
          if (indices[c] >= (int)have[c].size()) {
            bad = true;
            break;
          }
          index = have[c][indices[c]];
        }
        
        if (!bad)
          ++ans;
        
        std::fill(indices.begin(), indices.end(), 0);
      }
      
      return ans;
    }
};
```

Same as above but search for next valid index using binary search

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numMatchingSubseq (string s, vector <string>& words) {
      std::vector <std::vector <int>> have (26);
      
      for (int index = 0; char c: s)
        have[c - 'a'].push_back(index++);
      
      int ans = 0;
      
      for (auto& word: words) {
        bool bad = false;
        int index = -1;
        
        for (char c: word) {
          c -= 'a';
          
          auto lb = std::upper_bound(have[c].begin(), have[c].end(), index);
          if (lb == have[c].end()) {
            bad = true;
            break;
          }
          index = *lb;
        }
        
        if (!bad)
          ++ans;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 158524
- total submissions: 309853
- acceptance rate: 51.2%
- likes: 3780
- dislikes: 169

<br>

### Similar Problems

- [Is Subsequence](https://leetcode.com/problems/is-subsequence) (Easy)
- [Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string) (Medium)
- [Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string) (Easy)
