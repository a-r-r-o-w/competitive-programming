# [28] Implement strStr()

**[two-pointers, string, string-matching]**

### Statement

Implement [strStr()](http://www.cplusplus.com/reference/cstring/strstr/).

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Clarification:**

What should we return when `needle` is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's [strstr()](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)).


**Example 1:**

```

**Input:** haystack = "hello", needle = "ll"
**Output:** 2

```

**Example 2:**

```

**Input:** haystack = "aaaaa", needle = "bba"
**Output:** -1

```

**Constraints:**
* `1 <= haystack.length, needle.length <= 104`
* `haystack` and `needle` consist of only lowercase English characters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int strStr (string haystack, string needle) {
      int ans = -1;
      int m = haystack.length();
      int n = needle.length();
      
      for (int i = 0; i + n - 1 < m; ++i) {
        bool bad = false;
        
        for (int j = 0; j < n; ++j) {
          if (haystack[i + j] != needle[j]) {
            bad = true;
            break;
          }
        }
        
        if (!bad) {
          ans = i;
          break;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1352334
- total submissions: 3673883
- acceptance rate: 36.8%
- likes: 4675
- dislikes: 3843

<br>

### Similar Problems

- [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome) (Hard)
- [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) (Easy)
