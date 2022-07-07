# [97] Interleaving String

**[string, dynamic-programming]**

### Statement

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:

* `s = s1 + s2 + ... + sn`
* `t = t1 + t2 + ... + tm`
* `|n - m| <= 1`
* The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`


**Note:** `a + b` is the concatenation of strings `a` and `b`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

```

**Input:** s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
**Output:** true

```

**Example 2:**

```

**Input:** s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
**Output:** false

```

**Example 3:**

```

**Input:** s1 = "", s2 = "", s3 = ""
**Output:** true

```

**Constraints:**
* `0 <= s1.length, s2.length <= 100`
* `0 <= s3.length <= 200`
* `s1`, `s2`, and `s3` consist of lowercase English letters.


**Follow up:** Could you solve it using only `O(s2.length)` additional memory space?

<br>

### Hints

None

<br>

### Solution

**2D DP**

```cpp
class Solution {
  public:
    bool isInterleave (string s1, string s2, string s3) {
      int n = s1.length();
      int m = s2.length();
      int k = s3.length();
      
      if (n + m != k)
        return false;
      
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (m + 1));
      
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
          int max = 0;
          
          if (i and dp[i - 1][j] < k)
            max = std::max(max, dp[i - 1][j] + (s3[dp[i - 1][j]] == s1[i - 1]));
          if (j and dp[i][j - 1] < k)
            max = std::max(max, dp[i][j - 1] + (s3[dp[i][j - 1]] == s2[j - 1]));
          
          dp[i][j] = max;
        }
      }
      
      return dp[n][m] == k;
    }
}; 
```

**1D DP**

```cpp
class Solution {
  public:
    bool isInterleave (string s1, string s2, string s3) {
      int n = s1.length();
      int m = s2.length();
      int k = s3.length();
      
      if (n + m != k)
        return false;
      
      std::vector <int> dp (m + 1);
      
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
          int max = 0;
          
          if (i and dp[j] < k)
            max = std::max(max, dp[j] + (s3[dp[j]] == s1[i - 1]));
          if (j and dp[j - 1] < k)
            max = std::max(max, dp[j - 1] + (s3[dp[j - 1]] == s2[j - 1]));
          
          dp[j] = max;
        }
      }
      
      return dp[m] == k;
    }
};
```

**1D DP using boolean**

```cpp
class Solution {
  public:
    bool isInterleave (string s1, string s2, string s3) {
      int n = s1.length();
      int m = s2.length();
      int k = s3.length();
      
      if (n + m != k)
        return false;
      
      std::vector <bool> dp (m + 1);
      dp[0] = true;
      
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
          if (i == 0 and j == 0)
            continue;
          bool result = false;
          if (i)
            result |= dp[j] && s3[i + j - 1] == s1[i - 1];
          if (j)
            result |= dp[j - 1] && s3[i + j - 1] == s2[j - 1];
          dp[j] = result;
        }
      }
      
      return dp[m];
    }
};
```

<br>

### Statistics

- total accepted: 301003
- total submissions: 838790
- acceptance rate: 35.9%
- likes: 4886
- dislikes: 281

<br>

### Similar Problems

None
