# [2287] Rearrange Characters to Make Target String

**[hash-table, string, counting]**

### Statement

You are given two **0-indexed** strings `s` and `target`. You can take some letters from `s` and rearrange them to form new strings.

Return *the **maximum** number of copies of* `target` *that can be formed by taking letters from* `s` *and rearranging them.*
**Example 1:**

```

**Input:** s = "ilovecodingonleetcode", target = "code"
**Output:** 2
**Explanation:**
For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
We can make at most two copies of "code", so we return 2.

```

**Example 2:**

```

**Input:** s = "abcba", target = "abc"
**Output:** 1
**Explanation:**
We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
We can make at most one copy of "abc", so we return 1.
Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, so we cannot make a second copy of "abc".

```

**Example 3:**

```

**Input:** s = "abbaccaddaeea", target = "aaaaa"
**Output:** 1
**Explanation:**
We can make one copy of "aaaaa" by taking the letters at indices 0, 3, 6, 9, and 12.
We can make at most one copy of "aaaaa", so we return 1.

```

**Constraints:**
* `1 <= s.length <= 100`
* `1 <= target.length <= 10`
* `s` and `target` consist of lowercase English letters.


<br>

### Hints

- Count the frequency of each character in s and target.
- Consider each letter one at a time. If there are x occurrences of a letter in s and y occurrences of the same letter in target, how many copies of this letter can we make?
- We can make floor(x / y) copies of the letter.

<br>

### Solution

```cpp
class Solution {
  public:
    int rearrangeCharacters (string s, string target) {
      std::vector <int> freq_s (26), freq_target (26);
      int min = 1 << 30;

      for (char c: s)
        ++freq_s[c - 'a'];
      
      for (char c: target)
        ++freq_target[c - 'a'];
      
      for (int i = 0; i < 26; ++i)
        if (freq_target[i] > 0)
          min = std::min(min, freq_s[i] / freq_target[i]);
      
      if (min == (1 << 30))
        min = 0;
      
      return min;
    }
};
```

<br>

### Statistics

- total accepted: 27693
- total submissions: 47827
- acceptance rate: 57.9%
- likes: 311
- dislikes: 23

<br>

### Similar Problems

- [Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters) (Easy)
- [Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring) (Medium)
