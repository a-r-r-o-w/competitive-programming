# [2124] Check if All A's Appears Before All B's

**[string]**

### Statement

Given a string `s` consisting of **only** the characters `'a'` and `'b'`, return `true` *if **every*** `'a'` *appears before **every*** `'b'` *in the string*. Otherwise, return `false`.


**Example 1:**

```

**Input:** s = "aaabbb"
**Output:** true
**Explanation:**
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.

```

**Example 2:**

```

**Input:** s = "abab"
**Output:** false
**Explanation:**
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.

```

**Example 3:**

```

**Input:** s = "bbb"
**Output:** true
**Explanation:**
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.

```

**Constraints:**
* `1 <= s.length <= 100`
* `s[i]` is either `'a'` or `'b'`.


<br>

### Hints

- You can check the opposite: check if there is a ‘b’ before an ‘a’. Then, negate and return that answer.
- s should not have any occurrences of “ba” as a substring.

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkString (string s) {
      const int inf32 = 1 << 30;
      int n = s.length();
      int lastA = -1, firstB = inf32;
      
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'a')
          lastA = i;
        else if (firstB == inf32)
          firstB = i;
      }
      
      return lastA < firstB;
    }
};
```

<br>

### Statistics

- total accepted: 36165
- total submissions: 50191
- acceptance rate: 72.1%
- likes: 373
- dislikes: 5

<br>

### Similar Problems

- [Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced) (Medium)
- [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated) (Easy)
- [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) (Easy)
