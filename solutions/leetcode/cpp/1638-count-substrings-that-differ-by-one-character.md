# [1638] Count Substrings That Differ by One Character

**[hash-table, string, dynamic-programming]**

### Statement

Given two strings `s` and `t`, find the number of ways you can choose a non-empty substring of `s` and replace a **single character** by a different character such that the resulting substring is a substring of `t`. In other words, find the number of substrings in `s` that differ from some substring in `t` by **exactly** one character.

For example, the underlined substrings in `"computer"` and `"computation"` only differ by the `'e'`/`'a'`, so this is a valid way.

Return *the number of substrings that satisfy the condition above.*

A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** s = "aba", t = "baba"
**Output:** 6
**Explanation:** The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.

```

​​**Example 2:**

```

**Input:** s = "ab", t = "bb"
**Output:** 3
**Explanation:** The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
​​​​The underlined portions are the substrings that are chosen from s and t.

```

**Constraints:**
* `1 <= s.length, t.length <= 100`
* `s` and `t` consist of lowercase English letters only.


<br>

### Hints

- Take every substring of s, change a character, and see how many substrings of t match that substring.
- Use a Trie to store all substrings of t as a dictionary.

<br>

### Solution

O((n.m)^2)

```cpp
class Solution {
  public:
    int countSubstrings (string s, string t) {
      // brute force:
      //   iterate over every substring of s -> total n * (n + 1) / 2
      //   check if the substring occurs in t with a difference of 1 character -> m - n
      // TC: O(n.n.m)
      
      int n = s.length();
      int m = t.length();
      int ans = 0;
      std::string current;
      
      for (int i = 0; i < n; ++i) {
        int len = 0;
        
        for (int j = i; j < n; ++j) {
          current += s[j];
          ++len;
          
          for (int k = 0; k + len - 1 < m; ++k) {
            int diff = 0;
            
            for (int l = 0; l < len and diff <= 1; ++l) {
              if (t[k + l] != current[l])
                ++diff;
            }
            
            if (diff == 1)
              ++ans;
          }
        }
        
        current.clear();
      }
      
      return ans;
    }
};
```

O(n^2.m)

```cpp
class Solution {
  public:
    int countSubstrings (string s, string t) {
      int n = s.length();
      int m = t.length();
      int ans = 0;
    
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s[i] == t[j])
            continue;
          
          int left = 1, right = 1;
          
          while (i - left >= 0 and j - left >= 0 and s[i - left] == t[j - left])
            ++left;
          while (i + right < n and j + right < m and s[i + right] == t[j + right])
            ++right;
          
          ans += left * right;
        }
      }
      
      return ans;
    }
};
```

O(n.m)

```cpp
class Solution {
  public:
    int countSubstrings (string s, string t) {
      int n = s.length();
      int m = t.length();
      int ans = 0;
      std::vector <std::vector <int>> dpl (n + 1, std::vector <int> (m + 1));
      std::vector <std::vector <int>> dpr (n + 1, std::vector <int> (m + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (s[i - 1] == t[j - 1])
            dpl[i][j] = dpl[i - 1][j - 1] + 1;
        }
      }
      
      for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
          if (s[i - 1] == t[j - 1])
            dpr[i - 1][j - 1] = dpr[i][j] + 1;
        }
      }
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s[i] != t[j])
            ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 20503
- total submissions: 28605
- acceptance rate: 71.7%
- likes: 821
- dislikes: 278

<br>

### Similar Problems

- [Count Words Obtained After Adding a Letter](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter) (Medium)
