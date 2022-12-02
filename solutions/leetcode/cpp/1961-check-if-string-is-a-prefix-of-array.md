# [1961] Check If String Is a Prefix of Array

**[array, string]**

### Statement

Given a string `s` and an array of strings `words`, determine whether `s` is a **prefix string** of `words`.

A string `s` is a **prefix string** of `words` if `s` can be made by concatenating the first `k` strings in `words` for some **positive** `k` no larger than `words.length`.

Return `true` *if* `s` *is a **prefix string** of* `words`*, or* `false` *otherwise*.


**Example 1:**

```

**Input:** s = "iloveleetcode", words = ["i","love","leetcode","apples"]
**Output:** true
**Explanation:**
s can be made by concatenating "i", "love", and "leetcode" together.

```

**Example 2:**

```

**Input:** s = "iloveleetcode", words = ["apples","i","love","leetcode"]
**Output:** false
**Explanation:**
It is impossible to make s using a prefix of arr.
```

**Constraints:**
* `1 <= words.length <= 100`
* `1 <= words[i].length <= 20`
* `1 <= s.length <= 1000`
* `words[i]` and `s` consist of only lowercase English letters.


<br>

### Hints

- There are only words.length prefix strings.
- Create all of them and see if s is one of them.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPrefixString (string s, vector <string>& words) {
      int s_index = 0;
      int w_index = 0, index = 0;
      
      while (w_index < (int)words.size()) {
        if (s[s_index] == words[w_index][index]) {
          ++s_index;
          ++index;
        }
        else
          return false;
        
        if (s_index == (int)s.length() and index == (int)words[w_index].length())
          return true;
        
        if (index == (int)words[w_index].length()) {
          ++w_index;
          index = 0;
        }
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 33110
- total submissions: 61249
- acceptance rate: 54.1%
- likes: 318
- dislikes: 54

<br>

### Similar Problems

- [Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string) (Easy)
