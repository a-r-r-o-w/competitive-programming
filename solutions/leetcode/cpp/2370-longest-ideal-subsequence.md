# [2370] Longest Ideal Subsequence



### Statement

You are given a string `s` consisting of lowercase letters and an integer `k`. We call a string `t` **ideal** if the following conditions are satisfied:

* `t` is a **subsequence** of the string `s`.
* The absolute difference in the alphabet order of every two **adjacent** letters in `t` is less than or equal to `k`.



Return *the length of the **longest** ideal string*.

A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

**Note** that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of `'a'` and `'z'` is `25`, not `1`.


**Example 1:**

```

**Input:** s = "acfgbd", k = 2
**Output:** 4
**Explanation:** The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
```

**Example 2:**

```

**Input:** s = "abcd", k = 3
**Output:** 4
**Explanation:** The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.

```

**Constraints:**
* `1 <= s.length <= 105`
* `0 <= k <= 25`
* `s` consists of lowercase English letters.


<br>

### Hints

- How can you calculate the longest ideal subsequence that ends at a specific index i?
- Can you calculate it for all positions i? How can you use previously calculated answers to calculate the answer for the next position?

<br>

### Solution

Top-Down recursion with memoization

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestIdealString (string s, int k) {
      int n = s.length();
      std::vector <std::vector <int>> dp (26, std::vector <int> (n, -1));
      
      auto dfs = [&] (auto self, int index, char prev) -> int {
        if (index < 0)
          return 0;
        if (dp[prev][index] != -1)
          return dp[prev][index];
        
        int current = s[index] - 'a';
        
        dp[prev][index] = std::max(dp[prev][index], self(self, index - 1, prev));
        if (std::abs(prev - current) <= k)
          dp[prev][index] = std::max(dp[prev][index], self(self, index - 1, current) + 1);
        
        return dp[prev][index];
      };
      
      int ans = 0;
      
      for (char i = 'a'; i <= 'z'; ++i)
        ans = std::max(ans, dfs(dfs, n - 1, i - 'a'));
      
      return ans;
    }
};
```

Bottom-Up DP

```cp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestIdealString (string s, int k) {
      int n = s.length();
      std::vector <std::vector <int>> dp (26, std::vector <int> (n + 1));
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
          int x = s[i - 1] - 'a';
          if (std::abs(j - x) <= k)
            dp[x][i] = std::max(dp[x][i], dp[j][i - 1] + 1);
        }
        for (int j = 0; j < 26; ++j)
          dp[j][i] = std::max(dp[j][i], dp[j][i - 1]);
      }
      
      int ans = 0;
      
      for (int i = 0; i < 26; ++i) {
        ans = std::max(ans, dp[i][n]);
      }
      
      return ans;
    }
};
```

Getting rid of inner dimension by noticing that we only require 26 states

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestIdealString (string s, int k) {
      int n = s.length();
      std::vector <int> dp (26), copy (26);
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
          int x = s[i - 1] - 'a';
          if (std::abs(j - x) <= k)
            dp[x] = std::max(dp[x], copy[j] + 1);
        }
        for (int j = 0; j < 26; ++j)
          dp[j] = copy[j] = std::max(dp[j], copy[j]);
      }
      
      return *std::max_element(dp.begin(), dp.end());
    }
};
```

...further optimisation noticing that we don't really require all 26 states to perform update

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestIdealString (string s, int k) {
      int n = s.length();
      int ans = 0;
      std::vector <int> dp (26);
      
      for (int i = 1; i <= n; ++i) {
        int x = s[i - 1] - 'a';
        dp[x] += 1;
        
        for (int j = std::max(0, x - k); j < std::min(26, x + k + 1); ++j) {
          if (j != x)
            dp[x] = std::max(dp[x], dp[j] + 1);
        }
        
        ans = std::max(ans, dp[x]);
      }
      
      return ans;
    }
};
```

Syntax sugar with STL

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestIdealString (string s, int k) {
      int n = s.length();
      std::vector <int> dp (26);
      
      for (int i = 1; i <= n; ++i) {
        int x = s[i - 1] - 'a';
        int low = std::max(0, x - k);
        int high = std::min(26, x + k + 1);
        
        dp[x] = std::max(dp[x], *std::max_element(dp.begin() + low, dp.begin() + high)) + 1;
      }
      
      return *std::max_element(dp.begin(), dp.end());
    }
};
```

<br>

### Statistics

- total accepted: 9714
- total submissions: 27375
- acceptance rate: 35.5%
- likes: 294
- dislikes: 11

<br>

### Similar Problems

- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
