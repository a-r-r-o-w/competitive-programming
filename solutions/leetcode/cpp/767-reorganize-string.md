# [767] Reorganize String

**[hash-table, string, greedy, sorting, heap-priority-queue, counting]**

### Statement

Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return *any possible rearrangement of* `s` *or return* `""` *if not possible*.


**Example 1:**

```
**Input:** s = "aab"
**Output:** "aba"

```
**Example 2:**

```
**Input:** s = "aaab"
**Output:** ""

```

**Constraints:**
* `1 <= s.length <= 500`
* `s` consists of lowercase English letters.


<br />

### Hints

- Alternate placing the most common letters.

<br />

### Solution

```cpp
class Solution {
  public:
    string reorganizeString(string s) {
      int n = s.size(), max = 0, which = -1;
      std::vector <int> freq(26);

      for (char c: s) {
        ++freq[c - 'a'];
        if (max < freq[c - 'a']) {
          max = freq[c - 'a'];
          which = c - 'a';
        }
      }

      if (max > (n + 1) / 2)
        return "";
      
      std::string ans(n, ' ');
      int index = 0;

      while (freq[which] > 0) {
        ans[index] = which + 'a';
        --freq[which];
        index += 2;
      }

      for (int i = 0; i < 26; ++i) {
        while (freq[i] > 0) {
          if (index >= n)
            index = 1;
          ans[index] = i + 'a';
          index += 2;
          --freq[i];
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 295159
- total submissions: 551642
- acceptance rate: 53.5%
- likes: 7029
- dislikes: 215

<br />

### Similar Problems

- [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart) (Hard)
- [Task Scheduler](https://leetcode.com/problems/task-scheduler) (Medium)
- [Longest Happy String](https://leetcode.com/problems/longest-happy-string) (Medium)
