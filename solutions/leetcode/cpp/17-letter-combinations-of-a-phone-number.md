# [17] Letter Combinations of a Phone Number

**[hash-table, string, backtracking]**

### Statement

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
![](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png)
**Example 1:**

```

**Input:** digits = "23"
**Output:** ["ad","ae","af","bd","be","bf","cd","ce","cf"]

```

**Example 2:**

```

**Input:** digits = ""
**Output:** []

```

**Example 3:**

```

**Input:** digits = "2"
**Output:** ["a","b","c"]

```

**Constraints:**
* `0 <= digits.length <= 4`
* `digits[i]` is a digit in the range `['2', '9']`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    std::map <int, std::string> mapping;
  
    Solution () {
      char c = 'a';
      for (int i = 2; i <= 7; ++i) {
        mapping[i] += c++;
        mapping[i] += c++;
        mapping[i] += c++;
      }
      mapping[7] += c++;
      for (int i = 8; i <= 9; ++i) {
        mapping[i] += c++;
        mapping[i] += c++;
        mapping[i] += c++;
      }
      mapping[9] += c;
    }
  
    vector <string> letterCombinations (string digits) {
      int n = digits.length();
      
      if (n == 0)
        return {};
      
      std::vector <std::string> ans;
      
      auto dfs = [&] (auto self, int index, std::string& s) {
        if (index == n) {
          ans.push_back(s);
          return;
        }
        
        int digit = digits[index] - '0';
        
        for (char c: mapping[digit]) {
          s.push_back(c);
          self(self, index + 1, s);
          s.pop_back();
        }
      };
      
      std::string s;
      dfs(dfs, 0, s);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1266845
- total submissions: 2317175
- acceptance rate: 54.7%
- likes: 11293
- dislikes: 715

<br>

### Similar Problems

- [Generate Parentheses](https://leetcode.com/problems/generate-parentheses) (Medium)
- [Combination Sum](https://leetcode.com/problems/combination-sum) (Medium)
- [Binary Watch](https://leetcode.com/problems/binary-watch) (Easy)
- [Count Number of Texts](https://leetcode.com/problems/count-number-of-texts) (Medium)
