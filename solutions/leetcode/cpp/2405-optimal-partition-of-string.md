# [2405] Optimal Partition of String



### Statement

Given a string `s`, partition the string into one or more **substrings** such that the characters in each substring are **unique**. That is, no letter appears in a single substring more than **once**.

Return *the **minimum** number of substrings in such a partition.*

Note that each character should belong to exactly one substring in a partition.


**Example 1:**

```

**Input:** s = "abacaba"
**Output:** 4
**Explanation:**
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

```

**Example 2:**

```

**Input:** s = "ssssss"
**Output:** 6
**Explanation:**The only valid partition is ("s","s","s","s","s","s").

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of only English lowercase letters.


<br>

### Hints

- Try to come up with a greedy approach.
- From left to right, extend every substring in the partition as much as possible.

<br>

### Solution

```cpp
class Solution {
  public:
    int partitionString (string s) {
      std::vector <bool> have (26);
      int count = 1;
      
      for (char c: s) {
        c -= 'a';
        
        if (have[c]) {
          for (int i = 0; i < 26; ++i)
            have[i] = false;
          ++count;
        }
        
        have[c] = true;
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 15253
- total submissions: 21260
- acceptance rate: 71.7%
- likes: 134
- dislikes: 6

<br>

### Similar Problems

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) (Medium)
- [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters) (Medium)
- [Partition Labels](https://leetcode.com/problems/partition-labels) (Medium)
- [Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals) (Medium)
