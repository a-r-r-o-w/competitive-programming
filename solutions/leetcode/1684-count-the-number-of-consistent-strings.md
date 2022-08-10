# [1684] Count the Number of Consistent Strings

**[array, hash-table, string, bit-manipulation]**

### Statement

You are given a string `allowed` consisting of **distinct** characters and an array of strings `words`. A string is **consistent** if all characters in the string appear in the string `allowed`.

Return *the number of **consistent** strings in the array* `words`.


**Example 1:**

```

**Input:** allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
**Output:** 2
**Explanation:** Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

```

**Example 2:**

```

**Input:** allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
**Output:** 7
**Explanation:** All strings are consistent.

```

**Example 3:**

```

**Input:** allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
**Output:** 4
**Explanation:** Strings "cc", "acd", "ac", and "d" are consistent.

```

**Constraints:**
* `1 <= words.length <= 104`
* `1 <= allowed.length <=26`
* `1 <= words[i].length <= 10`
* The characters in `allowed` are **distinct**.
* `words[i]` and `allowed` contain only lowercase English letters.


<br>

### Hints

- A string is incorrect if it contains a character that is not allowed
- Constraints are small enough for brute force

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countConsistentStrings (string allowed, vector <string>& words) {
      int mask = 0;
      
      for (char c: allowed)
        mask |= 1 << (c - 'a');
      
      int ans = 0;
      
      for (auto &word: words) {
        int word_mask = 0;
        for (char c: word)
          word_mask |= 1 << (c - 'a');
        if ((mask | word_mask) == mask)
          ++ans;
      }
      
      return ans;
    }
};
```

or

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countConsistentStrings (string allowed, vector <string>& words) {
      int mask = 0;
      
      for (char c: allowed)
        mask |= 1 << (c - 'a');
      
      int ans = 0;
      
      for (auto &word: words) {
        bool bad = false;
        for (char c: word) {
          if ((mask & (1 << (c - 'a'))) == 0) {
            bad = true;
            break;
          }
        }
        if (not bad)
          ++ans;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 98710
- total submissions: 120650
- acceptance rate: 81.8%
- likes: 1050
- dislikes: 48

<br>

### Similar Problems

None
