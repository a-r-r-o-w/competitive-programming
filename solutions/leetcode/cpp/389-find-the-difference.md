# [389] Find the Difference

**[hash-table, string, bit-manipulation, sorting]**

### Statement

You are given two strings `s` and `t`.

String `t` is generated by random shuffling string `s` and then add one more letter at a random position.

Return the letter that was added to `t`.


**Example 1:**

```

**Input:** s = "abcd", t = "abcde"
**Output:** "e"
**Explanation:** 'e' is the letter that was added.

```

**Example 2:**

```

**Input:** s = "", t = "y"
**Output:** "y"

```

**Constraints:**
* `0 <= s.length <= 1000`
* `t.length == s.length + 1`
* `s` and `t` consist of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    char findTheDifference (string s, string t) {
      std::vector <int> freq (26);
      
      for (char c: s)
        ++freq[c - 'a'];
      for (char c: t)
        --freq[c - 'a'];
      
      for (int i = 0; i < 26; ++i)
        if (freq[i] == -1)
          return i + 'a';
      
      return -1; // cannot reach here as per question
    }
};
```

<br>

### Statistics

- total accepted: 431155
- total submissions: 713214
- acceptance rate: 60.5%
- likes: 3157
- dislikes: 397

<br>

### Similar Problems

- [Single Number](https://leetcode.com/problems/single-number) (Easy)