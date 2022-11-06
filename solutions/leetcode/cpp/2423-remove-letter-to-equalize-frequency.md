# [2423] Remove Letter To Equalize Frequency

**[hash-table, string, counting]**

### Statement

You are given a **0-indexed** string `word`, consisting of lowercase English letters. You need to select **one** index and **remove** the letter at that index from `word` so that the **frequency** of every letter present in `word` is equal.

Return`true` *if it is possible to remove one letter so that the frequency of all letters in* `word` *are equal, and* `false` *otherwise*.

**Note:**
* The **frequency** of a letter `x` is the number of times it occurs in the string.
* You **must** remove exactly one letter and cannot chose to do nothing.


**Example 1:**

```

**Input:** word = "abcc"
**Output:** true
**Explanation:** Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.

```

**Example 2:**

```

**Input:** word = "aazz"
**Output:** false
**Explanation:** We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.

```

**Constraints:**
* `2 <= word.length <= 100`
* `word` consists of lowercase English letters only.


<br>

### Hints

- Brute force all letters that could be removed.
- Use a frequency array of size 26.

<br>

### Solution

```cpp
class Solution {
  public:
    bool equalFrequency (string word) {
      std::vector <int> freq (26);
      
      for (char c: word)
        ++freq[c - 'a'];
      
      std::map <int, int> have;
      
      for (int i: freq)
        if (i > 0)
          ++have[i];
      
      if ((int)have.size() == 1)
        return have.begin()->first == 1 or have.begin()->second == 1;
      
      if ((int)have.size() == 2) {
        auto [u, v] = *have.begin();
        auto [p, q] = *have.rbegin();
        int min = std::min(u, p), max = std::max(u, p);
        return (min + 1 == max and have[max] == 1) or (min == 1 and have[min] == 1);
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 17412
- total submissions: 89934
- acceptance rate: 19.4%
- likes: 218
- dislikes: 532

<br>

### Similar Problems

- [Maximum Equal Frequency](https://leetcode.com/problems/maximum-equal-frequency) (Hard)
- [Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique) (Medium)
