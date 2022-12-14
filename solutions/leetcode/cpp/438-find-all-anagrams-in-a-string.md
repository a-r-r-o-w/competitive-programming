# [438] Find All Anagrams in a String

**[hash-table, string, sliding-window]**

### Statement

Given two strings `s` and `p`, return *an array of all the start indices of* `p`*'s anagrams in* `s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


**Example 1:**

```

**Input:** s = "cbaebabacd", p = "abc"
**Output:** [0,6]
**Explanation:**
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

```

**Example 2:**

```

**Input:** s = "abab", p = "ab"
**Output:** [0,1,2]
**Explanation:**
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

```

**Constraints:**
* `1 <= s.length, p.length <= 3 * 104`
* `s` and `p` consist of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> findAnagrams (string s, string p) {
      std::vector <int> have_s (26), have_p (26);
      int n = s.length(), m = p.length();
      std::vector <int> ans;
      
      if (n < m)
        return {};
      
      for (int i = 0; i < m; ++i) {
        ++have_s[s[i] - 'a'];
        ++have_p[p[i] - 'a'];
      }
      
      if (have_s == have_p)
        ans.push_back(0);
      
      for (int i = m; i < n; ++i) {
        have_s[s[i - m] - 'a'] -= 1;
        have_s[s[i] - 'a'] += 1;
        
        if (have_p == have_s)
          ans.push_back(i - m + 1);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 604509
- total submissions: 1237016
- acceptance rate: 48.9%
- likes: 8656
- dislikes: 270

<br>

### Similar Problems

- [Valid Anagram](https://leetcode.com/problems/valid-anagram) (Easy)
- [Permutation in String](https://leetcode.com/problems/permutation-in-string) (Medium)
