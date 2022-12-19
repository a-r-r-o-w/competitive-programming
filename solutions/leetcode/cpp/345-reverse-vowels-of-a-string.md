# [345] Reverse Vowels of a String

**[two-pointers, string]**

### Statement

Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.


**Example 1:**

```
**Input:** s = "hello"
**Output:** "holle"

```
**Example 2:**

```
**Input:** s = "leetcode"
**Output:** "leotcede"

```

**Constraints:**
* `1 <= s.length <= 3 * 105`
* `s` consist of **printable ASCII** characters.


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
  
    string reverseVowels (string s) {
      std::vector <int> pos;
      int n = s.length();
      
      for (int i = 0; i < n; ++i) {
        char c = s[i];
        
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
            c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
          pos.push_back(i);
      }
      
      for (int i = 0; i < (int)pos.size() / 2; ++i)
        std::swap(s[pos[i]], s[pos[pos.size() - i - 1]]);
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 391140
- total submissions: 819595
- acceptance rate: 47.7%
- likes: 2007
- dislikes: 2031

<br>

### Similar Problems

- [Reverse String](https://leetcode.com/problems/reverse-string) (Easy)
- [Remove Vowels from a String](https://leetcode.com/problems/remove-vowels-from-a-string) (Easy)
