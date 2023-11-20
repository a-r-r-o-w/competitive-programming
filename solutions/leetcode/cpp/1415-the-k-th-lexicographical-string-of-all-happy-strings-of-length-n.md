# [1415] The k-th Lexicographical String of All Happy Strings of Length n

**[string, backtracking]**

### Statement

A **happy string** is a string that:

* consists only of letters of the set `['a', 'b', 'c']`.
* `s[i] != s[i + 1]` for all values of `i` from `1` to `s.length - 1` (string is 1-indexed).



For example, strings **"abc", "ac", "b"** and **"abcbabcbcb"** are all happy strings and strings **"aa", "baa"** and **"ababbc"** are not happy strings.

Given two integers `n` and `k`, consider a list of all happy strings of length `n` sorted in lexicographical order.

Return *the kth string* of this list or return an **empty string** if there are less than `k` happy strings of length `n`.


**Example 1:**

```

**Input:** n = 1, k = 3
**Output:** "c"
**Explanation:** The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

```

**Example 2:**

```

**Input:** n = 1, k = 4
**Output:** ""
**Explanation:** There are only 3 happy strings of length 1.

```

**Example 3:**

```

**Input:** n = 3, k = 9
**Output:** "cab"
**Explanation:** There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9^th string = "cab"

```

**Constraints:**
* `1 <= n <= 10`
* `1 <= k <= 100`


<br />

### Hints

- Generate recursively all the happy strings of length n.
- Sort them in lexicographical order and return the kth string if it exists.

<br />

### Solution

```cpp
class Solution {
  public:
    string getHappyString (int n, int k) {
      std::vector <char> chars = {'a', 'b', 'c'};
      std::vector <std::string> values;

      auto dfs = [&] (auto self, int index, std::string &current) -> void {
        if (index >= n) {
          values.push_back(current);
          return;
        }
        for (char c: chars) {
          if (not current.empty() and c == current.back())
            continue;
          current.push_back(c);
          self(self, index + 1, current);
          current.pop_back();
        }
      };

      std::string x;

      dfs(dfs, 0, x);
      std::sort(values.begin(), values.end());

      return k - 1 >= (int)values.size() ? "" : values[k - 1];
    }
};
```

<br />

### Statistics

- total accepted: 30589
- total submissions: 42278
- acceptance rate: 72.4%
- likes: 817
- dislikes: 21

<br />

### Similar Problems

None
