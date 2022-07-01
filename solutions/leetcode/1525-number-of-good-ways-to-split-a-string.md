# [1525] Number of Good Ways to Split a String

**[string, dynamic-programming, bit-manipulation]**

### Statement

You are given a string `s`.

A split is called **good** if you can split `s` into two non-empty strings `sleft` and `sright` where their concatenation is equal to `s` (i.e., `sleft + sright = s`) and the number of distinct letters in `sleft` and `sright` is the same.

Return *the number of **good splits** you can make in `s`*.


**Example 1:**

```

**Input:** s = "aacaba"
**Output:** 2
**Explanation:** There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.

```

**Example 2:**

```

**Input:** s = "abcd"
**Output:** 1
**Explanation:** Split the string as follows ("ab", "cd").

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of only lowercase English letters.


<br>

### Hints

- Use two HashMap to store the counts of distinct letters in the left and right substring divided by the current index.

<br>

### Solution

**O(26 * n) time complexity**

```cpp
class Solution {
  public:
    int numSplits (string s) {
      std::vector <int> pref (26), suff (26);
      int ans = 0;
      
      for (char c: s)
        suff[c - 'a'] += 1;
      
      for (char c: s) {
        pref[c - 'a'] += 1;
        suff[c - 'a'] -= 1;
        
        int psum = 0, ssum = 0;
        for (int i = 0; i < 26; ++i) {
          psum += !!pref[i];
          ssum += !!suff[i];
        }
        
        if (psum == ssum)
          ++ans;
      }
      
      return ans;
    }
};
```

**O(n) time complexity**

```cpp
class Solution {
  public:
    int numSplits (string s) {
      int n = s.length();
      std::unordered_set <char> x, y;
      std::vector <int> pref (n), suff (n);
      
      for (int i = 0; i < n; ++i) {
        x.insert(s[i]);
        y.insert(s[n - i - 1]);
        pref[i] = x.size();
        suff[n - i - 1] = y.size();
      }
      
      int ans = 0;
      for (int i = 0; i < n - 1; ++i)
        if (pref[i] == suff[i + 1])
          ++ans;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 74169
- total submissions: 106176
- acceptance rate: 69.9%
- likes: 1423
- dislikes: 33

<br>

### Similar Problems

None
