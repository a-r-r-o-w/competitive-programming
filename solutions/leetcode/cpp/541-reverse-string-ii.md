# [541] Reverse String II

**[two-pointers, string]**

### Statement

Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the start of the string.

If there are fewer than `k` characters left, reverse all of them. If there are less than `2k` but greater than or equal to `k` characters, then reverse the first `k` characters and leave the other as original.


**Example 1:**

```
**Input:** s = "abcdefg", k = 2
**Output:** "bacdfeg"

```
**Example 2:**

```
**Input:** s = "abcd", k = 2
**Output:** "bacd"

```

**Constraints:**
* `1 <= s.length <= 104`
* `s` consists of only lowercase English letters.
* `1 <= k <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string reverseStr (string s, int k) {
      int n = s.length(), i = 0;
      
      while (i < n) {
        std::reverse(s.begin() + i, s.begin() + std::min(i + k, n));
        i += 2 * k;
      }
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 177250
- total submissions: 350899
- acceptance rate: 50.5%
- likes: 1332
- dislikes: 2847

<br>

### Similar Problems

- [Reverse String](https://leetcode.com/problems/reverse-string) (Easy)
- [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii) (Easy)
