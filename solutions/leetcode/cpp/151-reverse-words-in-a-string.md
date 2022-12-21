# [151] Reverse Words in a String

**[two-pointers, string]**

### Statement

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return *a string of the words in reverse order concatenated by a single space.*
**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


**Example 1:**

```

**Input:** s = "the sky is blue"
**Output:** "blue is sky the"

```

**Example 2:**

```

**Input:** s = "  hello world  "
**Output:** "world hello"
**Explanation:** Your reversed string should not contain leading or trailing spaces.

```

**Example 3:**

```

**Input:** s = "a good   example"
**Output:** "example good a"
**Explanation:** You need to reduce multiple spaces between two words to a single space in the reversed string.

```

**Constraints:**
* `1 <= s.length <= 104`
* `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
* There is **at least one** word in `s`.


**Follow-up:**If the string data type is mutable in your language, canyou solve it**in-place**with`O(1)`extra space?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string reverseWords (string s) {
      int n = s.length();
      std::string current;
      std::vector <std::string> words;
      int i = 0;
      
      while (i < n) {
        if (s[i] == ' ') {
          if (current.empty()) {
            ++i;
            continue;
          }
          words.emplace_back(std::move(current));
        }
        else
          current += s[i];
        ++i;
      }
      
      if (not current.empty())
        words.emplace_back(std::move(current));
      
      int k = words.size();
      std::string ans;
      
      for (int i = k - 1; i >= 0; --i) {
        ans += std::move(words[i]);
        if (i > 0)
          ans += ' ';
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 797550
- total submissions: 2618156
- acceptance rate: 30.5%
- likes: 4332
- dislikes: 4241

<br>

### Similar Problems

- [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii) (Medium)
