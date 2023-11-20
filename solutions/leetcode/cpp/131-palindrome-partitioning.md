# [131] Palindrome Partitioning

**[string, dynamic-programming, backtracking]**

### Statement

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return *all possible palindrome partitioning of* `s`.


**Example 1:**

```
**Input:** s = "aab"
**Output:** [["a","a","b"],["aa","b"]]

```
**Example 2:**

```
**Input:** s = "a"
**Output:** [["a"]]

```

**Constraints:**
* `1 <= s.length <= 16`
* `s` contains only lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <string>> partition (string s) {
      int n = s.length();
      std::vector <std::vector <std::string>> ans;
      std::vector <std::string> v;

      auto is_palindrome = [] (const std::string &s) -> bool {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
          if (s[i] != s[n - i - 1])
            return false;
        }
        return true;
      };

      auto dfs = [&] (auto self, int index) -> void {
        if (index == n) {
          ans.push_back(v);
          return;
        }
        
        std::string have;
        
        for (int i = index; i < n; ++i) {
          have += s[i];
          if (is_palindrome(have)) {
            v.push_back(have);
            self(self, i + 1);
            v.pop_back();
          }
        }
      };

      dfs(dfs, 0);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 568330
- total submissions: 898135
- acceptance rate: 63.3%
- likes: 9293
- dislikes: 300

<br>

### Similar Problems

- [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) (Hard)
- [Palindrome Partitioning IV](https://leetcode.com/problems/palindrome-partitioning-iv) (Hard)
- [Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings) (Hard)
