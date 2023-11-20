# [1768] Merge Strings Alternately

**[two-pointers, string]**

### Statement

You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return *the merged string.*
**Example 1:**

```

**Input:** word1 = "abc", word2 = "pqr"
**Output:** "apbqcr"
**Explanation:**The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

```

**Example 2:**

```

**Input:** word1 = "ab", word2 = "pqrs"
**Output:** "apbqrs"
**Explanation:**Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

```

**Example 3:**

```

**Input:** word1 = "abcd", word2 = "pq"
**Output:** "apbqcd"
**Explanation:**Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

```

**Constraints:**
* `1 <= word1.length, word2.length <= 100`
* `word1` and `word2` consist of lowercase English letters.


<br>

### Hints

- Use two pointers, one pointer for each string. Alternately choose the character from each pointer, and move the pointer upwards.

<br>

### Solution

```cpp
class Solution {
  public:
    string mergeAlternately (string word1, string word2) {
      std::string result;
      int i = 0;
      int n = word1.length(), m = word2.length();
      
      while (i < n and i < m) {
        result += word1[i];
        result += word2[i];
        ++i;
      }
      
      while (i < n)
        result += word1[i++];
      while (i < m)
        result += word2[i++];
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 73284
- total submissions: 96579
- acceptance rate: 75.9%
- likes: 725
- dislikes: 14

<br>

### Similar Problems

- [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator) (Medium)
