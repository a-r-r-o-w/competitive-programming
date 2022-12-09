# [409] Longest Palindrome

**[hash-table, string, greedy]**

### Statement

Given a string `s` which consists of lowercase or uppercase letters, return *the length of the **longest palindrome***that can be built with those letters.

Letters are **case sensitive**, for example,`"Aa"` is not considered a palindrome here.


**Example 1:**

```

**Input:** s = "abccccdd"
**Output:** 7
**Explanation:** One longest palindrome that can be built is "dccaccd", whose length is 7.

```

**Example 2:**

```

**Input:** s = "a"
**Output:** 1
**Explanation:** The longest palindrome that can be built is "a", whose length is 1.

```

**Constraints:**
* `1 <= s.length <= 2000`
* `s` consists of lowercase **and/or** uppercase Englishletters only.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int longestPalindrome (string s) {
      int ans = 0;
      std::unordered_map <char, int> freq;
      bool extra = false;
      
      for (char c: s)
        ++freq[c];
      
      for (auto &[x, y]: freq) {
        ans += y / 2 * 2;
        if (y % 2 == 1)
          extra = true;
      }
      
      return ans + extra;
    }
};
```

<br>

### Statistics

- total accepted: 363386
- total submissions: 667504
- acceptance rate: 54.4%
- likes: 3483
- dislikes: 203

<br>

### Similar Problems

- [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation) (Easy)
- [Longest Palindrome by Concatenating Two Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words) (Medium)
- [Largest Palindromic Number](https://leetcode.com/problems/largest-palindromic-number) (Medium)
