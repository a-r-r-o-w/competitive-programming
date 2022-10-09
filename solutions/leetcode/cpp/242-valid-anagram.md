# [242] Valid Anagram

**[hash-table, string, sorting]**

### Statement

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


**Example 1:**

```
**Input:** s = "anagram", t = "nagaram"
**Output:** true

```
**Example 2:**

```
**Input:** s = "rat", t = "car"
**Output:** false

```

**Constraints:**
* `1 <= s.length, t.length <= 5 * 104`
* `s` and `t` consist of lowercase English letters.


**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

<br>

### Hints

None

<br>

### Solution

Sorting

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }

    bool isAnagram (string s, string t) {
      std::sort(s.begin(), s.end());
      std::sort(t.begin(), t.end());
      return s == t;
    }
};
```

Frequency counting

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool isAnagram (string s, string t) {
      std::vector <int> freq (26);
      
      for (char c: s)
        ++freq[c - 'a'];
      for (char c: t)
        --freq[c - 'a'];
      
      for (int i = 0; i < 26; ++i)
        if (freq[i] != 0)
          return false;
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 1470474
- total submissions: 2370155
- acceptance rate: 62.0%
- likes: 5884
- dislikes: 232

<br>

### Similar Problems

- [Group Anagrams](https://leetcode.com/problems/group-anagrams) (Medium)
- [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation) (Easy)
- [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string) (Medium)
- [Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams) (Easy)
