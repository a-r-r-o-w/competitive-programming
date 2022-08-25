# [383] Ransom Note

**[hash-table, string, counting]**

### Statement

Given two strings `ransomNote` and `magazine`, return `true` *if* `ransomNote` *can be constructed by using the letters from* `magazine` *and* `false` *otherwise*.

Each letter in `magazine` can only be used once in `ransomNote`.


**Example 1:**

```
**Input:** ransomNote = "a", magazine = "b"
**Output:** false

```
**Example 2:**

```
**Input:** ransomNote = "aa", magazine = "ab"
**Output:** false

```
**Example 3:**

```
**Input:** ransomNote = "aa", magazine = "aab"
**Output:** true

```

**Constraints:**
* `1 <= ransomNote.length, magazine.length <= 105`
* `ransomNote` and `magazine` consist of lowercase English letters.


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
  
    bool canConstruct (string ransomNote, string magazine) {
      std::vector <int> freq (26);
      
      for (char c: magazine)
        ++freq[c - 'a'];
      
      for (char c: ransomNote) {
        if (freq[c - 'a'] <= 0)
          return false;
        --freq[c - 'a'];
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 487200
- total submissions: 863910
- acceptance rate: 56.4%
- likes: 2222
- dislikes: 343

<br>

### Similar Problems

- [Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word) (Hard)
