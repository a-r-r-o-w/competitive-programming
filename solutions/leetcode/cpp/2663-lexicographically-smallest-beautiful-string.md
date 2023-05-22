# [2663] Lexicographically Smallest Beautiful String



### Statement

A string is **beautiful** if:

* It consists of the first `k` letters of the English lowercase alphabet.
* It does not contain any substring of length `2` or more which is a palindrome.



You are given a beautiful string `s` of length `n` and a positive integer `k`.

Return *the lexicographically smallest string of length* `n`*, which is larger than* `s` *and is **beautiful***. If there is no such string, return an empty string.

A string `a` is lexicographically larger than a string `b` (of the same length) if in the first position where `a` and `b` differ, `a` has a character strictly larger than the corresponding character in `b`.

* For example, `"abcd"` is lexicographically larger than `"abcc"` because the first position they differ is at the fourth character, and `d` is greater than `c`.


**Example 1:**

```

**Input:** s = "abcz", k = 26
**Output:** "abda"
**Explanation:** The string "abda" is beautiful and lexicographically larger than the string "abcz".
It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".

```

**Example 2:**

```

**Input:** s = "dc", k = 4
**Output:** ""
**Explanation:** It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.

```

**Constraints:**
* `1 <= n == s.length <= 10^5`
* `4 <= k <= 26`
* `s` is a beautiful string.


<br />

### Hints

- If the string does not contain any palindromic substrings of lengths 2 and 3, then the string does not contain any palindromic substrings at all.
- Iterate from right to left and if it is possible to increase character at index i without creating any palindromic substrings of lengths 2 and 3, then increase it.
- After increasing the character at index i, set every character after index i equal to character a. With this, we will ensure that we have created a lexicographically larger string than s, which does not contain any palindromes before index i and is lexicographically the smallest.
- Finally, we are just left with a case to fix palindromic substrings, which come after index i. This can be done with a similar method mentioned in the second hint.

<br />

### Solution

```cpp
class Solution {
  public:
    string smallestBeautifulString (string s, int k) {
      auto dfs = [&] (auto self, int index) -> bool {
        if (index < 0)
          return false;
        
        s[index] += 1;
        
        if (s[index] - 'a' == k) {
          if (self(self, index - 1)) {
            s[index] = 'a' - 1;
            return self(self, index);
          }
          return false;
        }
        else {
          if (
            (index - 1 >= 0 and s[index] == s[index - 1]) or
            (index - 2 >= 0 and s[index] == s[index - 2])
          )
            return self(self, index);
        }
        return true;
      };
      
      if (dfs(dfs, s.length() - 1))
        return s;
      return "";
    }
};
```

<br />

### Statistics

- total accepted: 715
- total submissions: 3038
- acceptance rate: 23.5%
- likes: 14
- dislikes: 6

<br />

### Similar Problems

- [Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps) (Medium)
- [Find Palindrome With Fixed Length](https://leetcode.com/problems/find-palindrome-with-fixed-length) (Medium)
