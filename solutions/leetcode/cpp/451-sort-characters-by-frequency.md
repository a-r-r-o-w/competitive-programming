# [451] Sort Characters By Frequency

**[hash-table, string, sorting, heap-priority-queue, bucket-sort, counting]**

### Statement

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return *the sorted string*. If there are multiple answers, return *any of them*.


**Example 1:**

```

**Input:** s = "tree"
**Output:** "eert"
**Explanation:** 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

```

**Example 2:**

```

**Input:** s = "cccaaa"
**Output:** "aaaccc"
**Explanation:** Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

```

**Example 3:**

```

**Input:** s = "Aabb"
**Output:** "bbAa"
**Explanation:** "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

```

**Constraints:**
* `1 <= s.length <= 5 * 105`
* `s` consists of uppercase and lowercase English letters and digits.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string frequencySort (string s) {
      std::unordered_map <char, int> freq;
      
      for (char c: s)
        ++freq[c];
      
      std::vector <std::pair <char, int>> v (freq.begin(), freq.end());
      std::string ans;
      
      std::sort(v.begin(), v.end(), [] (auto &l, auto &r) {
        return l.second > r.second;
      });
      for (auto [c, i]: v)
        ans += std::string(i, c);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 435583
- total submissions: 629688
- acceptance rate: 69.2%
- likes: 5549
- dislikes: 209

<br>

### Similar Problems

- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) (Easy)
- [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) (Easy)
- [Percentage of Letter in String](https://leetcode.com/problems/percentage-of-letter-in-string) (Easy)
- [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array) (Easy)
- [Node With Highest Edge Score](https://leetcode.com/problems/node-with-highest-edge-score) (Medium)
- [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) (Easy)
