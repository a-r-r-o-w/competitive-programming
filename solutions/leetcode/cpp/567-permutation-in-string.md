# [567] Permutation in String

**[hash-table, two-pointers, string, sliding-window]**

### Statement

Given two strings `s1` and `s2`, return `true` *if* `s2` *contains a permutation of* `s1`*, or* `false` *otherwise*.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.


**Example 1:**

```

**Input:** s1 = "ab", s2 = "eidbaooo"
**Output:** true
**Explanation:** s2 contains one permutation of s1 ("ba").

```

**Example 2:**

```

**Input:** s1 = "ab", s2 = "eidboaoo"
**Output:** false

```

**Constraints:**
* `1 <= s1.length, s2.length <= 10^4`
* `s1` and `s2` consist of lowercase English letters.


<br>

### Hints

- Obviously, brute force will result in TLE. Think of something else.
- How will you check whether one string is a permutation of another string?
- One way is to sort the string and then compare. But, Is there a better way?
- If one string is a permutation of another string then they must one common metric. What is that?
- Both strings must have same character frequencies, if  one is permutation of another. Which data structure should be used to store frequencies?
- What about hash table?  An array of size 26?

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkInclusion (string s1, string s2) {
      int n = s1.length();
      int m = s2.length();
      
      std::vector <int> freq1 (26), freq2 (26);
      
      for (char c: s1)
        ++freq1[c - 'a'];
      
      for (int i = 0; i < m; ++i) {
        if (i >= n) {
          --freq2[s2[i - n] - 'a'];
          ++freq2[s2[i] - 'a'];
        }
        else
          ++freq2[s2[i] - 'a'];
        
        if (freq1 == freq2)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 471348
- total submissions: 1071619
- acceptance rate: 44.0%
- likes: 7070
- dislikes: 232

<br>

### Similar Problems

- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) (Hard)
- [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string) (Medium)
