# [1312] Minimum Insertion Steps to Make a String Palindrome

**[string, dynamic-programming]**

### Statement

Given a string `s`. In one step you can insert any character at any index of the string.

Return *the minimum number of steps* to make `s`palindrome.

A**Palindrome String**is one that reads the same backward as well as forward.


**Example 1:**

```

**Input:** s = "zzazz"
**Output:** 0
**Explanation:** The string "zzazz" is already palindrome we do not need any insertions.

```

**Example 2:**

```

**Input:** s = "mbadm"
**Output:** 2
**Explanation:** String can be "mbdadbm" or "mdbabdm".

```

**Example 3:**

```

**Input:** s = "leetcode"
**Output:** 5
**Explanation:** Inserting 5 characters the string becomes "leetcodocteel".

```

**Constraints:**
* `1 <= s.length <= 500`
* `s` consists of lowercase English letters.


<br />

### Hints

- Is dynamic programming suitable for this problem ?
- If we know the longest palindromic sub-sequence is x and the length of the string is n then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.

<br />

### Solution

```cpp
class Solution {
  public:
    int minInsertions (string s) {
      int n = s.length();
      std::vector <std::vector <int>> dp (n, std::vector <int> (n, -1));

      auto dfs = [&] (auto self, int l, int r) -> int {
        if (l >= r)
          return 0;
        if (dp[l][r] != -1)
          return dp[l][r];
        if (s[l] == s[r])
          return dp[l][r] = self(self, l + 1, r - 1);
        int m = 1 << 30;
        m = std::min(m, self(self, l + 1, r));
        m = std::min(m, self(self, l, r - 1));
        return dp[l][r] = m + 1;
      };

      return dfs(dfs, 0, n - 1);
    }
};
```

<br />

### Statistics

- total accepted: 96742
- total submissions: 142783
- acceptance rate: 67.8%
- likes: 3596
- dislikes: 47

<br />

### Similar Problems

- [Minimum Number of Moves to Make Palindrome](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome) (Hard)
