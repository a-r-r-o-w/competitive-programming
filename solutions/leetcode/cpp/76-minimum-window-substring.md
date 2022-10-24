# [76] Minimum Window Substring

**[hash-table, string, sliding-window]**

### Statement

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the **minimum window substring** of* `s` *such that every character in* `t` *(**including duplicates**) is included in the window. If there is no such substring**, return the empty string* `""`*.*

The testcases will be generated such that the answer is **unique**.

A **substring** is a contiguous sequence of characters within the string.


**Example 1:**

```

**Input:** s = "ADOBECODEBANC", t = "ABC"
**Output:** "BANC"
**Explanation:** The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

```

**Example 2:**

```

**Input:** s = "a", t = "a"
**Output:** "a"
**Explanation:** The entire string s is the minimum window.

```

**Example 3:**

```

**Input:** s = "a", t = "aa"
**Output:** ""
**Explanation:** Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

```

**Constraints:**
* `m == s.length`
* `n == t.length`
* `1 <= m, n<= 105`
* `s` and `t` consist of uppercase and lowercase English letters.


**Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

<br>

### Hints

- Use two pointers to create a window of letters in s, which would have all the characters from t.
- Expand the right pointer until all the characters of t are covered.
- Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.
- Continue expanding the right and left pointers until you reach the end of s.

<br>

### Solution

```cpp
class Solution {
  public:
    string minWindow (string s, string t) {
      const int inf32 = 1 << 30;
      
      if (s.empty() or t.empty())
        return "";
      
      std::vector <int> lookup (128);
      int n = t.size(), m = s.size();
      
      for (int i = 0; i < n; ++i)
        ++lookup[t[i]];
      
      int min = inf32, l = 0, r = 0, index = 0;
      
      while (r <= m and l < m) {
        if (n) {
          if (r == m)
            break;

          --lookup[s[r]];

          if (lookup[s[r]] >= 0)
            --n;

          ++r;
        }
        else {
          if (r - l < min) {
            min = r - l;
            index = l;
          }

          ++lookup[s[l]];

          if (lookup[s[l]] > 0)
            ++n;
          
          ++l;
        }
      }
      
      if (min == inf32)
        return "";
      
      return s.substr(index, min);
    }
};
```

<br>

### Statistics

- total accepted: 905677
- total submissions: 2235719
- acceptance rate: 40.5%
- likes: 13276
- dislikes: 583

<br>

### Similar Problems

- [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words) (Hard)
- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) (Medium)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) (Hard)
- [Permutation in String](https://leetcode.com/problems/permutation-in-string) (Medium)
- [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists) (Hard)
- [Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence) (Hard)
