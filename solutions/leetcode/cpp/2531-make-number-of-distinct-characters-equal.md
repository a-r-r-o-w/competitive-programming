# [2531] Make Number of Distinct Characters Equal



### Statement

You are given two **0-indexed** strings `word1` and `word2`.

A **move** consists of choosing two indices `i` and `j` such that `0 <= i < word1.length` and `0 <= j < word2.length` and swapping `word1[i]` with `word2[j]`.

Return `true` *if it is possible to get the number of distinct characters in* `word1` *and* `word2` *to be equal with **exactly one** move.* Return `false` *otherwise*.


**Example 1:**

```

**Input:** word1 = "ac", word2 = "b"
**Output:** false
**Explanation:** Any pair of swaps would yield two distinct characters in the first string, and one in the second string.

```

**Example 2:**

```

**Input:** word1 = "abcc", word2 = "aab"
**Output:** true
**Explanation:** We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.

```

**Example 3:**

```

**Input:** word1 = "abcde", word2 = "fghij"
**Output:** true
**Explanation:** Both resulting strings will have 5 distinct characters, regardless of which indices we swap.

```

**Constraints:**
* `1 <= word1.length, word2.length <= 105`
* `word1` and `word2` consist of only lowercase English letters.


<br>

### Hints

- Create a frequency array of the letters of each string.
- There are 26*26 possible pairs of letters to swap. Can we try them all?
- Iterate over all possible pairs of letters and check if swapping them will yield two strings that have the same number of distinct characters. Use the frequency array for the check.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isItPossible (string word1, string word2) {
      int n = word1.size(), m = word2.size();
      std::vector <int> freq1 (26), freq2 (26);
      
      for (char c: word1)
        ++freq1[c - 'a'];
      for (char c: word2)
        ++freq2[c - 'a'];
      
      for (int i = 0; i < 26; ++i) {
        if (freq1[i] == 0)
          continue;
        
        for (int j = 0; j < 26; ++j) {
          if (freq2[j] == 0)
            continue;
          
          --freq1[i];
          --freq2[j];
          ++freq1[j];
          ++freq2[i];

          if (std::count(freq1.begin(), freq1.end(), 0) == std::count(freq2.begin(), freq2.end(), 0))
            return true;
          
          ++freq1[i];
          ++freq2[j];
          --freq1[j];
          --freq2[i];
        }
      }

      return false;
    }
};
```

<br>

### Statistics

- total accepted: 6680
- total submissions: 32150
- acceptance rate: 20.8%
- likes: 141
- dislikes: 72

<br>

### Similar Problems

- [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows) (Medium)
- [Buddy Strings](https://leetcode.com/problems/buddy-strings) (Easy)
- [Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal) (Medium)
- [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal) (Easy)
- [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) (Easy)
