# [2375] Construct Smallest Number From DI String

**[string, backtracking, stack, greedy]**

### Statement

You are given a **0-indexed** string `pattern` of length `n` consisting of the characters `'I'` meaning **increasing** and `'D'` meaning **decreasing**.

A **0-indexed** string `num` of length `n + 1` is created using the following conditions:

* `num` consists of the digits `'1'` to `'9'`, where each digit is used **at most** once.
* If `pattern[i] == 'I'`, then `num[i] < num[i + 1]`.
* If `pattern[i] == 'D'`, then `num[i] > num[i + 1]`.



Return *the lexicographically **smallest** possible string* `num` *that meets the conditions.*
**Example 1:**

```

**Input:** pattern = "IIIDIDDD"
**Output:** "123549876"
**Explanation:**At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
```

**Example 2:**

```

**Input:** pattern = "DDD"
**Output:** "4321"
**Explanation:**
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

```

**Constraints:**
* `1 <= pattern.length <= 8`
* `pattern` consists of only the letters `'I'` and `'D'`.


<br>

### Hints

- With the constraints, could we generate every possible string?
- Yes we can. Now we just need to check if the string meets all the conditions.

<br>

### Solution

```cpp
class Solution {
  public:
    string smallestNumber (string pattern) {
      std::string ans (9, '9');
      std::vector <bool> visited (9);

      auto dfs = [&] (auto self, std::string &s) -> void {
        if (s.length() == pattern.length() + 1) {
          ans = std::min(ans, s);
          return;
        }
        if (pattern[s.length() - 1] == 'I') {
          for (char c = s.back() + 1; c <= '9'; ++c) {
            if (visited[c - '1'])
              continue;
            s.push_back(c);
            visited[c - '1'] = true;
            self(self, s);
            visited[c - '1'] = false;
            s.pop_back();
          }
        }
        else {
          for (char c = s.back() - 1; c >= '1'; --c) {
            if (visited[c - '1'])
              continue;
            s.push_back(c);
            visited[c - '1'] = true;
            self(self, s);
            visited[c - '1'] = false;
            s.pop_back();
          }
        }
      };

      std::string x;

      for (char i = '1'; i <= '9'; ++i) {
        x.push_back(i);
        visited[i - '1'] = true;
        dfs(dfs, x);
        visited[i - '1'] = false;
        x.pop_back();
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 19809
- total submissions: 26758
- acceptance rate: 74.0%
- likes: 590
- dislikes: 21

<br>

### Similar Problems

- [DI String Match](https://leetcode.com/problems/di-string-match) (Easy)
