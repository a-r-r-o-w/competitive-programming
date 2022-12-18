# [2506] Count Pairs Of Similar Strings



### Statement

You are given a **0-indexed** string array `words`.

Two strings are **similar** if they consist of the same characters.

* For example, `"abca"` and `"cba"` are similar since both consist of characters `'a'`, `'b'`, and `'c'`.
* However, `"abacba"` and `"bcfd"` are not similar since they do not consist of the same characters.



Return *the number of pairs* `(i, j)` *such that* `0 <= i < j <= word.length - 1` *and the two strings* `words[i]` *and* `words[j]` *are similar*.


**Example 1:**

```

**Input:** words = ["aba","aabb","abcd","bac","aabc"]
**Output:** 2
**Explanation:** There are 2 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 

```

**Example 2:**

```

**Input:** words = ["aabb","ab","ba"]
**Output:** 3
**Explanation:** There are 3 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
- i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.

```

**Example 3:**

```

**Input:** words = ["nba","cba","dba"]
**Output:** 0
**Explanation:** Since there does not exist any pair that satisfies the conditions, we return 0.
```

**Constraints:**
* `1 <= words.length <= 100`
* `1 <= words[i].length <= 100`
* `words[i]` consist of only lowercase English letters.


<br>

### Hints

- How can you check if two strings are similar?
- Use a hashSet to store the character of each string.

<br>

### Solution

```cpp
class Solution {
  public:
    int similarPairs (vector <string>& words) {
      int n = words.size(), count = 0;
      std::vector <std::set <char>> have;
      have.reserve(n);

      for (auto &w: words)
        have.push_back(std::set <char> (w.begin(), w.end()));
      
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
          if (have[i] == have[j])
            ++count;
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 10065
- total submissions: 15341
- acceptance rate: 65.6%
- likes: 40
- dislikes: 5

<br>

### Similar Problems

- [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) (Medium)
- [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings) (Easy)
- [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) (Hard)
