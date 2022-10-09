# [3] Longest Substring Without Repeating Characters

**[hash-table, string, sliding-window]**

### Statement

Given a string `s`, find the length of the **longest substring** without repeating characters.


**Example 1:**

```

**Input:** s = "abcabcbb"
**Output:** 3
**Explanation:** The answer is "abc", with the length of 3.

```

**Example 2:**

```

**Input:** s = "bbbbb"
**Output:** 1
**Explanation:** The answer is "b", with the length of 1.

```

**Example 3:**

```

**Input:** s = "pwwkew"
**Output:** 3
**Explanation:** The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

**Constraints:**
* `0 <= s.length <= 5 * 104`
* `s` consists of English letters, digits, symbols and spaces.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int lengthOfLongestSubstring (string s) {
      const int inf32 = 1 << 30;
      
      int n = s.length();
      int min = inf32;
      int best = 0;
      std::unordered_map <char, int> prev;
      
      for (int i = 0; i < n; ++i)
        prev[s[i]] = -1;
      
      for (int i = 0; i < n; ++i) {
        if (prev[s[i]] == -1) {
          prev[s[i]] = i;
          min = std::min(min, i);
          best = std::max(best, i - min + 1);
        }
        else {
          best = std::max(best, i - min);
          min = std::max(min, prev[s[i]] + 1);
          prev[s[i]] = i;
        }
      }
      
      return std::max(best, n - min);
    }
};
```

<br>

### Statistics

- total accepted: 3331395
- total submissions: 10054036
- acceptance rate: 33.1%
- likes: 24042
- dislikes: 1067

<br>

### Similar Problems

- [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters) (Medium)
- [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters) (Medium)
- [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers) (Hard)
- [Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value) (Medium)
- [Number of Equal Count Substrings](https://leetcode.com/problems/number-of-equal-count-substrings) (Medium)
- [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up) (Medium)
