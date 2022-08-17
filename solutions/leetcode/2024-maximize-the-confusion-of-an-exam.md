# [2024] Maximize the Confusion of an Exam

**[string, binary-search, sliding-window, prefix-sum]**

### Statement

A teacher is writing a test with `n` true/false questions, with `'T'` denoting true and `'F'` denoting false. He wants to confuse the students by **maximizing** the number of **consecutive** questions with the **same** answer (multiple trues or multiple falses in a row).

You are given a string `answerKey`, where `answerKey[i]` is the original answer to the `ith` question. In addition, you are given an integer `k`, the maximum number of times you may perform the following operation:

* Change the answer key for any question to `'T'` or `'F'` (i.e., set `answerKey[i]` to `'T'` or `'F'`).



Return *the **maximum** number of consecutive* `'T'`s or `'F'`s *in the answer key after performing the operation at most* `k` *times*.


**Example 1:**

```

**Input:** answerKey = "TTFF", k = 2
**Output:** 4
**Explanation:** We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

```

**Example 2:**

```

**Input:** answerKey = "TFFT", k = 1
**Output:** 3
**Explanation:** We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

```

**Example 3:**

```

**Input:** answerKey = "TTFTTFTT", k = 1
**Output:** 5
**Explanation:** We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.

```

**Constraints:**
* `n == answerKey.length`
* `1 <= n <= 5 * 104`
* `answerKey[i]` is either `'T'` or `'F'`
* `1 <= k <= n`


<br>

### Hints

- Can we use the maximum length at the previous position to help us find the answer for the current position?
- Can we use binary search to find the maximum consecutive same answer at every position?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxConsecutiveAnswers (string answerKey, int k) {
      int n = answerKey.length();
      int ans = 0, used = 0, have = 0, last = 0;
      
      for (int i = 0; i < n; ++i) {
        if (answerKey[i] == 'T')
          ++have;
        else {
          if (used < k)
            ++used, ++have;
          else {
            while (used >= k) {
              if (answerKey[last] == 'F')
                --used;
              --have;
              ++last;
            }
            ++used;
            ++have;
          }
        }
        ans = std::max(ans, have);
      }
      
      used = 0, have = 0, last = 0;
      
      for (int i = 0; i < n; ++i) {
        if (answerKey[i] == 'F')
          ++have;
        else {
          if (used < k)
            ++used, ++have;
          else {
            while (used >= k) {
              if (answerKey[last] == 'T')
                --used;
              --have;
              ++last;
            }
            ++used;
            ++have;
          }
        }
        ans = std::max(ans, have);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 17141
- total submissions: 29236
- acceptance rate: 58.6%
- likes: 619
- dislikes: 13

<br>

### Similar Problems

- [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters) (Medium)
- [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) (Medium)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) (Medium)
- [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets) (Medium)
