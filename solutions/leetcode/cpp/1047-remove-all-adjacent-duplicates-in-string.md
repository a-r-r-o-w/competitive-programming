# [1047] Remove All Adjacent Duplicates In String

**[string, stack]**

### Statement

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return *the final string after all such duplicate removals have been made*. It can be proven that the answer is **unique**.


**Example 1:**

```

**Input:** s = "abbaca"
**Output:** "ca"
**Explanation:** 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

```

**Example 2:**

```

**Input:** s = "azxxzy"
**Output:** "ay"

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of lowercase English letters.


<br>

### Hints

- Use a stack to process everything greedily.

<br>

### Solution

**Time complexity: O(n)**

**Space complexity: O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string removeDuplicates (string s) {
      std::stack <char> have;
      
      for (char c: s) {
        if (have.empty() or have.top() != c)
          have.push(c);
        else
          have.pop();
      }
      
      std::string ans;
      ans.reserve(have.size());
      
      while (!have.empty()) {
        ans += have.top();
        have.pop();
      }
      
      std::reverse(ans.begin(), ans.end());
      
      return ans;
    }
};
```

**Time complexity: O(n)**

**Space complexity: O(1)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string removeDuplicates (string s) {
      int l = -1;
      
      for (char c: s) {
        if (l == -1 or c != s[l]) {
          ++l;
          s[l] = c;
        }
        else
          --l;
      }
      
      return s.substr(0, l + 1);
    }
};
```

<br>

### Statistics

- total accepted: 341302
- total submissions: 484003
- acceptance rate: 70.5%
- likes: 4208
- dislikes: 180

<br>

### Similar Problems

- [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii) (Medium)
- [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) (Medium)
