# [557] Reverse Words in a String III

**[two-pointers, string]**

### Statement

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


**Example 1:**

```
**Input:** s = "Let's take LeetCode contest"
**Output:** "s'teL ekat edoCteeL tsetnoc"

```
**Example 2:**

```
**Input:** s = "God Ding"
**Output:** "doG gniD"

```

**Constraints:**
* `1 <= s.length <= 5 * 104`
* `s` contains printable **ASCII** characters.
* `s` does not contain any leading or trailing spaces.
* There is **at least one** word in `s`.
* All the words in `s` are separated by a single space.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string reverseWords (string s) {
      int n = s.length();
      int left = 0;
      int right = 0;
      
      while (left < n) {
        while (right < n and s[right] != ' ')
          ++right;
        std::reverse(s.begin() + left, s.begin() + right);
        ++right;
        left = right;
      }
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 499322
- total submissions: 626071
- acceptance rate: 79.8%
- likes: 3139
- dislikes: 186

<br>

### Similar Problems

- [Reverse String II](https://leetcode.com/problems/reverse-string-ii) (Easy)
