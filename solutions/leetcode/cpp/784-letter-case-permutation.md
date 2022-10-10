# [784] Letter Case Permutation

**[string, backtracking, bit-manipulation]**

### Statement

Given a string `s`, youcan transform every letter individually to be lowercase or uppercase to create another string.

Return *a list of all possible strings we could create*. Return the output in **any order**.


**Example 1:**

```

**Input:** s = "a1b2"
**Output:** ["a1b2","a1B2","A1b2","A1B2"]

```

**Example 2:**

```

**Input:** s = "3z4"
**Output:** ["3z4","3Z4"]

```

**Constraints:**
* `1 <= s.length <= 12`
* `s` consists of lowercase English letters, uppercase English letters, and digits.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
public:
    vector <string> letterCasePermutation (string s) {
      std::vector <std::string> ans;
      int n = s.length();
      
      auto dfs = [&] (auto self, int index) -> void {
        if (index >= n) {
          ans.push_back(s);
          return;
        }
        
        if (std::isalpha(s[index])) {
          if (std::islower(s[index])) {
            self(self, index + 1);
            s[index] = std::toupper(s[index]);
            self(self, index + 1);
          }
          else {
            self(self, index + 1);
            s[index] = std::tolower(s[index]);
            self(self, index + 1);
          }
        }
        else
          self(self, index + 1);
      };
      
      dfs(dfs, 0);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 241986
- total submissions: 330131
- acceptance rate: 73.3%
- likes: 3762
- dislikes: 148

<br>

### Similar Problems

- [Subsets](https://leetcode.com/problems/subsets) (Medium)
- [Brace Expansion](https://leetcode.com/problems/brace-expansion) (Medium)
