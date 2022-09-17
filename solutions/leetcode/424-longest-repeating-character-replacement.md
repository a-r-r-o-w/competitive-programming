# [424] Longest Repeating Character Replacement

**[hash-table, string, sliding-window]**

### Statement

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return *the length of the longest substring containing the same letter you can get after performing the above operations*.


**Example 1:**

```

**Input:** s = "ABAB", k = 2
**Output:** 4
**Explanation:** Replace the two 'A's with two 'B's or vice versa.

```

**Example 2:**

```

**Input:** s = "AABABBA", k = 1
**Output:** 4
**Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of only uppercase English letters.
* `0 <= k <= s.length`


<br>

### Hints

None

<br>

### Solution

Time: O(n.k)
Space: O(k)

k is alphabet size

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int characterReplacement (string s, int k) {
      std::vector <int> left (26);
      int n = s.length(), max = 0;
      
      for (int i = 0; i < 26; ++i) {
        char c = i + 'A';
        int same = 0, diff = 0;
        
        for (int j = 0; j < n; ++j) {
          if (s[j] == c)
            ++same;
          else {
            ++diff;
            if (diff > k) {
              while (s[left[i]] == c) {
                --same;
                ++left[i];
              }
              --diff;
              ++left[i];
            }
          }
          
          max = std::max(max, same + diff);
        }
      }
      
      return max;
    }
};
```

Time: O(n)
Space: O(k)

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int characterReplacement (string s, int k) {
      std::vector <int> freq (26);
      int n = s.length(), left = 0, max_freq = 0, max = 0;
      
      for (int i = 0; i < n; ++i) {
        ++freq[s[i] - 'A'];
        max_freq = std::max(max_freq, freq[s[i] - 'A']);
        
        if (i - left + 1 > max_freq + k) {
          --freq[s[left] - 'A'];
          ++left;
        }
        
        max = std::max(max, i - left + 1);
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 323621
- total submissions: 630991
- acceptance rate: 51.3%
- likes: 6096
- dislikes: 241

<br>

### Similar Problems

- [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters) (Medium)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) (Medium)
- [Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous) (Hard)
- [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam) (Medium)
- [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character) (Hard)
