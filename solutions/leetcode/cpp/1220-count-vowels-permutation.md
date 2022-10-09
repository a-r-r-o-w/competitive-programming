# [1220] Count Vowels Permutation

**[dynamic-programming]**

### Statement

Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

* Each character is a lower case vowel(`'a'`, `'e'`, `'i'`, `'o'`, `'u'`)
* Each vowel`'a'` may only be followed by an `'e'`.
* Each vowel`'e'` may only be followed by an `'a'`or an `'i'`.
* Each vowel`'i'` **may not** be followed by another `'i'`.
* Each vowel`'o'` may only be followed by an `'i'` or a`'u'`.
* Each vowel`'u'` may only be followed by an `'a'.`



Since the answermay be too large,return it modulo `10^9 + 7.`
**Example 1:**

```

**Input:** n = 1
**Output:** 5
**Explanation:** All possible strings are: "a", "e", "i" , "o" and "u".

```

**Example 2:**

```

**Input:** n = 2
**Output:** 10
**Explanation:** All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

```

**Example 3:**

```

**Input:** n = 5
**Output:** 68
```

**Constraints:**
* `1 <= n <= 2 * 10^4`


<br>

### Hints

- Use dynamic programming.
- Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.
- Deduce the recurrence from the given relations between vowels.

<br>

### Solution

```cpp
class Solution {
  public:
    int countVowelPermutation (int n) {
      const int64_t mod = 1000000007;
      std::vector <int64_t> dp (5, 1), dp_copy (5, 1);
      std::vector <std::vector <int>> transitions = {
        {1, 2, 4},
        {0, 2},
        {1, 3},
        {2},
        {2, 3}
      };
      
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 5; ++j)
          dp_copy[j] = dp[j];
        for (int j = 0; j < 5; ++j) {
          dp[j] = 0;
          for (int k: transitions[j]) {
            dp[j] += dp_copy[k];
            if (dp[j] >= mod)
              dp[j] -= mod;
          }
        }
      }
      
      return std::accumulate(dp.begin(), dp.end(), int64_t(0)) % mod;
    }
};
```

<br>

### Statistics

- total accepted: 69399
- total submissions: 117527
- acceptance rate: 59.0%
- likes: 1670
- dislikes: 125

<br>

### Similar Problems

None
