# [2186] Minimum Number of Steps to Make Two Strings Anagram II

**[hash-table, string, counting]**

### Statement

You are given two strings `s` and `t`. In one step, you can append **any character** to either `s` or `t`.

Return *the minimum number of steps to make* `s` *and* `t` ***anagrams** of each other.*

An **anagram** of a string is a string that contains the same characters with a different (or the same) ordering.


**Example 1:**

```

**Input:** s = "**lee**tco**de**", t = "co**a**t**s**"
**Output:** 7
**Explanation:** 
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcode**as**".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coats**leede**".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.

```

**Example 2:**

```

**Input:** s = "night", t = "thing"
**Output:** 0
**Explanation:** The given strings are already anagrams of each other. Thus, we do not need any further steps.

```

**Constraints:**
* `1 <= s.length, t.length <= 2 * 105`
* `s` and `t` consist of lowercase English letters.


<br>

### Hints

- Notice that for anagrams, the order of the letters is irrelevant.
- For each letter, we can count its frequency in s and t.
- For each letter, its contribution to the answer is the absolute difference between its frequency in s and t.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int minSteps (string s, string t) {
      std::vector <int> freq (26);
      int ans = 0;
      
      for (char c: s)
        ++freq[c - 'a'];
      for (char c: t)
        --freq[c - 'a'];
      
      for (int i = 0; i < 26; ++i)
        ans += std::abs(freq[i]);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 24926
- total submissions: 34871
- acceptance rate: 71.5%
- likes: 292
- dislikes: 5

<br>

### Similar Problems

- [Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram) (Medium)
