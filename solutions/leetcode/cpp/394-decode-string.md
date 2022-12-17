# [394] Decode String

**[string, stack, recursion]**

### Statement

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `105`.


**Example 1:**

```

**Input:** s = "3[a]2[bc]"
**Output:** "aaabcbc"

```

**Example 2:**

```

**Input:** s = "3[a2[c]]"
**Output:** "accaccacc"

```

**Example 3:**

```

**Input:** s = "2[abc]3[cd]ef"
**Output:** "abcabccdcdcdef"

```

**Constraints:**
* `1 <= s.length <= 30`
* `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
* `s` is guaranteed to be **a valid** input.
* All the integers in `s` are in the range `[1, 300]`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string decodeString (string s) {
      int n = s.length();
      
      auto dfs = [&] (auto self, int index) -> std::pair <std::string, int> {
        if (index >= n)
          return {"", 0};
        
        std::string prefix;
        int repeats = 0, end = -1;
        
        for (int i = index; i < n; ++i) {
          if (s[i] == ']') {
            end = i;
            break;
          }
          else if (s[i] == '[') {
            auto [r, index] = self(self, i + 1);
            
            while (repeats > 0) {
              prefix += r;
              --repeats;
            }
            
            i = index;
          }
          else if (std::isdigit(s[i]))
            repeats = repeats * 10 + s[i] - '0';
          else
            prefix += s[i];
        }
        
        return {prefix, end};
      };
      
      return dfs(dfs, 0).first;
    }
};
```

<br>

### Statistics

- total accepted: 555682
- total submissions: 971098
- acceptance rate: 57.2%
- likes: 9331
- dislikes: 410

<br>

### Similar Problems

- [Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length) (Hard)
- [Number of Atoms](https://leetcode.com/problems/number-of-atoms) (Hard)
- [Brace Expansion](https://leetcode.com/problems/brace-expansion) (Medium)
