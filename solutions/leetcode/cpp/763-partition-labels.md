# [763] Partition Labels

**[hash-table, two-pointers, string, greedy]**

### Statement

You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.

Return *a list of integers representing the size of these parts*.


**Example 1:**

```

**Input:** s = "ababcbacadefegdehijhklij"
**Output:** [9,7,8]
**Explanation:**
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

```

**Example 2:**

```

**Input:** s = "eccbbbbdec"
**Output:** [10]

```

**Constraints:**
* `1 <= s.length <= 500`
* `s` consists of lowercase English letters.


<br>

### Hints

- Try to greedily choose the smallest partition that includes the first letter.  If you have something like "abaccbdeffed", then you might need to add b.  You can use an map like "last['b'] = 5" to help you expand the width of your partition.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> partitionLabels (string s) {
      int n = s.length();
      std::vector <int> ans, last (26);
      
      for (int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        last[x] = i;
      }
      
      int current = 0;
      
      while (current < n) {
        int max = current, start = current;
        
        while (current <= max) {
          max = std::max(max, last[s[current] - 'a']);
          ++current;
        }
        
        ans.push_back(current - start);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 410846
- total submissions: 515313
- acceptance rate: 79.7%
- likes: 8193
- dislikes: 314

<br>

### Similar Problems

- [Merge Intervals](https://leetcode.com/problems/merge-intervals) (Medium)
