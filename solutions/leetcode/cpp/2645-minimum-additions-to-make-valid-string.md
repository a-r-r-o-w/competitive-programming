# [2645] Minimum Additions to Make Valid String

**[string, dynamic-programming, stack, greedy]**

### Statement

Given a string `word` to which you can insert letters "a", "b" or "c" anywhere and any number of times, return *the minimum number of letters that must be inserted so that `word` becomes **valid**.*

A string is called **valid** if it can be formed by concatenating the string "abc" several times.


**Example 1:**

```

**Input:** word = "b"
**Output:** 2
**Explanation:** Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "**a**b**c**".

```

**Example 2:**

```

**Input:** word = "aaa"
**Output:** 6
**Explanation:** Insert letters "b" and "c" next to each "a" to obtain the valid string "a**bc**a**bc**a**bc**".

```

**Example 3:**

```

**Input:** word = "abc"
**Output:** 0
**Explanation:** word is already valid. No modifications are needed. 

```

**Constraints:**
* `1 <= word.length <= 50`
* `word` consists of letters "a", "b"and "c" only.


<br />

### Hints

- Maintain a pointer on word and another pointer on string “abc”.
- If the two characters that are being pointed to differ, Increment the answer and the pointer to the string “abc” by one.

<br />

### Solution

```cpp
class Solution {
  public:
    int addMinimum (string word) {
      int ans = 0, index = 0;
      std::string need = "abc";

      for (char c: word) {
        while (c != need[index % 3])
          ++ans, ++index;
        ++index;
      }
      if (index % 3)
        ans += 3 - (index % 3);

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 18568
- total submissions: 37543
- acceptance rate: 49.5%
- likes: 370
- dislikes: 15

<br />

### Similar Problems

- [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately) (Easy)
