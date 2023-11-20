# [1647] Minimum Deletions to Make Character Frequencies Unique

**[hash-table, string, greedy, sorting]**

### Statement

A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.

Given a string `s`, return *the **minimum** number of characters you need to delete to make* `s` ***good**.*

The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.


**Example 1:**

```

**Input:** s = "aab"
**Output:** 0
**Explanation:** s is already good.

```

**Example 2:**

```

**Input:** s = "aaabbbcc"
**Output:** 2
**Explanation:** You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

**Example 3:**

```

**Input:** s = "ceabaacb"
**Output:** 2
**Explanation:** You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).

```

**Constraints:**
* `1 <= s.length <= 10^5`
* `s`contains only lowercase English letters.


<br />

### Hints

- As we can only delete characters, if we have multiple characters having the same frequency, we must decrease all the frequencies of them, except one.
- Sort the alphabet characters by their frequencies non-increasingly.
- Iterate on the alphabet characters, keep decreasing the frequency of the current character until it reaches a value that has not appeared before.

<br />

### Solution

```cpp
class Solution {
  public:
    int minDeletions(string s) {
      std::vector <int> freq(26);
      
      for (char c: s)
        ++freq[c - 'a'];
      std::sort(freq.rbegin(), freq.rend());

      int ans = 0;
      for (int i = 1; i < 26; ++i) {
        while (freq[i] > 0 and freq[i] >= freq[i - 1]) {
          ++ans;
          --freq[i];
        }
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 182687
- total submissions: 309128
- acceptance rate: 59.1%
- likes: 3608
- dislikes: 52

<br />

### Similar Problems

- [Minimum Deletions to Make Array Beautiful](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful) (Medium)
- [Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array) (Medium)
- [Remove Letter To Equalize Frequency](https://leetcode.com/problems/remove-letter-to-equalize-frequency) (Easy)
