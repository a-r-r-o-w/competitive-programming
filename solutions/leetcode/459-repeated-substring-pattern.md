# [459] Repeated Substring Pattern

**[string, string-matching]**

### Statement

Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.


**Example 1:**

```

**Input:** s = "abab"
**Output:** true
**Explanation:** It is the substring "ab" twice.

```

**Example 2:**

```

**Input:** s = "aba"
**Output:** false

```

**Example 3:**

```

**Input:** s = "abcabcabcabc"
**Output:** true
**Explanation:** It is the substring "abc" four times or the substring "abcabc" twice.

```

**Constraints:**
* `1 <= s.length <= 104`
* `s` consists of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool repeatedSubstringPattern (string s) {
      int n = s.size();
      std::vector <int> z (n);
      
      for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
          z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
          ++z[i];
        if (i + z[i] - 1 > r) {
          l = i;
          r = i + z[i] - 1;
        }
        if (n % i == 0 and i + z[i] == n)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 256864
- total submissions: 587867
- acceptance rate: 43.7%
- likes: 3631
- dislikes: 338

<br>

### Similar Problems

- [Implement strStr()](https://leetcode.com/problems/implement-strstr) (Easy)
- [Repeated String Match](https://leetcode.com/problems/repeated-string-match) (Medium)
