# [2085] Count Common Words With One Occurrence

**[array, hash-table, string, counting]**

### Statement

Given two string arrays `words1` and `words2`, return *the number of strings that appear **exactly once** in **each**of the two arrays.*
**Example 1:**

```

**Input:** words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
**Output:** 2
**Explanation:**
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.

```

**Example 2:**

```

**Input:** words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
**Output:** 0
**Explanation:** There are no strings that appear in each of the two arrays.

```

**Example 3:**

```

**Input:** words1 = ["a","ab"], words2 = ["a","a","a","ab"]
**Output:** 1
**Explanation:** The only string that appears exactly once in each of the two arrays is "ab".

```

**Constraints:**
* `1 <= words1.length, words2.length <= 1000`
* `1 <= words1[i].length, words2[j].length <= 30`
* `words1[i]` and `words2[j]` consists only of lowercase English letters.


<br>

### Hints

- Could you try every word?
- Could you use a hash map to achieve a good complexity?

<br>

### Solution

```cpp
class Solution {
  public:
    int countWords (vector <string>& words1, vector <string>& words2) {
      std::unordered_map <std::string, int> freq1, freq2;
      std::unordered_set <std::string> unique;
      
      for (auto &s: words1) {
        ++freq1[s];
        unique.insert(s);
      }
      for (auto &s: words2) {
        ++freq2[s];
        unique.insert(s);
      }
      
      int count = 0;
      for (auto &s: unique) {
        if (freq1[s] == 1 and freq2[s] == 1)
          ++count;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 39675
- total submissions: 56813
- acceptance rate: 69.8%
- likes: 540
- dislikes: 12

<br>

### Similar Problems

- [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays) (Easy)
- [Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences) (Easy)
- [Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array) (Easy)
