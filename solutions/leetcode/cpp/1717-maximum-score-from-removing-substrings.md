# [1717] Maximum Score From Removing Substrings

**[string, stack, greedy]**

### Statement

You are given a string `s` and two integers `x` and `y`. You can perform two types of operations any number of times.

* Remove substring `"ab"` and gain `x` points.
	+ For example, when removing `"ab"` from `"cabxbae"` it becomes `"cxbae"`.
* Remove substring `"ba"` and gain `y` points.
	+ For example, when removing `"ba"` from `"cabxbae"` it becomes `"cabxe"`.



Return *the maximum points you can gain after applying the above operations on* `s`.


**Example 1:**

```

**Input:** s = "cdbcbbaaabab", x = 4, y = 5
**Output:** 19
**Explanation:**
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
```

**Example 2:**

```

**Input:** s = "aabbaaxybbaabb", x = 5, y = 4
**Output:** 20

```

**Constraints:**
* `1 <= s.length <= 105`
* `1 <= x, y <= 104`
* `s` consists of lowercase English letters.


<br>

### Hints

- Note that it is always more optimal to take one type of substring before another
- You can use a stack to handle erasures

<br>

### Solution

```cpp
class Solution {
  public:
    int maximumGain (string s, int x, int y) {
      std::stack <char> st;
      int ans = 0;
      char p = 'a', q = 'b';
      
      if (x < y) {
        std::swap(p, q);
        std::swap(x, y);
      }
      
      for (char c: s) {
        if (c == q and !st.empty() and st.top() == p)
          ans += x, st.pop();
        else
          st.push(c);
      }
      s.clear();
      while (!st.empty()) {
        s += st.top();
        st.pop();
      }
      for (char c: s) {
        if (c == q and !st.empty() and st.top() == p)
          ans += y, st.pop();
        else
          st.push(c);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 11458
- total submissions: 24873
- acceptance rate: 46.1%
- likes: 507
- dislikes: 28

<br>

### Similar Problems

- [Count Words Obtained After Adding a Letter](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter) (Medium)
