# [936] Stamping The Sequence

**[string, stack, greedy, queue]**

### Statement

You are given two strings `stamp` and `target`. Initially, there is a string `s` of length `target.length` with all `s[i] == '?'`.

In one turn, you can place `stamp` over `s` and replace every letter in the `s` with the corresponding letter from `stamp`.

* For example, if `stamp = "abc"` and `target = "abcba"`, then `s` is `"?????"` initially. In one turn you can:
	+ place `stamp` at index `0` of `s` to obtain `"abc??"`,
	+ place `stamp` at index `1` of `s` to obtain `"?abc?"`, or
	+ place `stamp` at index `2` of `s` to obtain `"??abc"`.
 Note that `stamp` must be fully contained in the boundaries of `s` in order to stamp (i.e., you cannot place `stamp` at index `3` of `s`).



We want to convert `s` to `target` using **at most** `10 * target.length` turns.

Return *an array of the index of the left-most letter being stamped at each turn*. If we cannot obtain `target` from `s` within `10 * target.length` turns, return an empty array.


**Example 1:**

```

**Input:** stamp = "abc", target = "ababc"
**Output:** [0,2]
**Explanation:** Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.

```

**Example 2:**

```

**Input:** stamp = "abca", target = "aabcaca"
**Output:** [3,0,1]
**Explanation:** Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".

```

**Constraints:**
* `1 <= stamp.length <= target.length <= 1000`
* `stamp` and `target` consist of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

Referred from [here](https://leetcode.com/problems/stamping-the-sequence/discuss/189576/C%2B%2B-simple-greedy).

```cpp
class Solution {
  public:
    vector <int> movesToStamp (string stamp, string target) {
      std::vector <int> ans;
      int m = stamp.size();
      int n = target.size();
      int total = 0, count = 0;
      
      do {
        count = 0;
        
        for (int size = m; size > 0; --size) {
          for (int i = 0; i < m - size + 1; ++i) {
            auto new_stamp = std::string(i, '*') + stamp.substr(i, size) + std::string(m - size - i, '*');
            auto pos = target.find(new_stamp);
            
            while (pos != std::string::npos) {
              ans.push_back(pos);
              count += size;
              std::fill(target.begin() + pos, target.begin() + pos + m, '*');
              pos = target.find(new_stamp);
            }
          }
        }
        
        total += count;
      }
      while (count > 0);
      
      std::reverse(ans.begin(), ans.end());
      
      if (total != n)
        return {};
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 47859
- total submissions: 75864
- acceptance rate: 63.1%
- likes: 1240
- dislikes: 195

<br>

### Similar Problems

None
