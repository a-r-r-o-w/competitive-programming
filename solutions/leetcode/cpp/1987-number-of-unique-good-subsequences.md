# [1987] Number of Unique Good Subsequences

**[string, dynamic-programming]**

### Statement

You are given a binary string `binary`. A **subsequence** of `binary` is considered **good** if it is **not empty** and has **no leading zeros** (with the exception of `"0"`).

Find the number of **unique good subsequences** of `binary`.

* For example, if `binary = "001"`, then all the **good** subsequences are `["0", "0", "1"]`, so the **unique** good subsequences are `"0"` and `"1"`. Note that subsequences `"00"`, `"01"`, and `"001"` are not good because they have leading zeros.



Return *the number of **unique good subsequences** of* `binary`. Since the answer may be very large, return it **modulo** `109 + 7`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** binary = "001"
**Output:** 2
**Explanation:** The good subsequences of binary are ["0", "0", "1"].
The unique good subsequences are "0" and "1".

```

**Example 2:**

```

**Input:** binary = "11"
**Output:** 2
**Explanation:** The good subsequences of binary are ["1", "1", "11"].
The unique good subsequences are "1" and "11".
```

**Example 3:**

```

**Input:** binary = "101"
**Output:** 5
**Explanation:** The good subsequences of binary are ["1", "0", "1", "10", "11", "101"]. 
The unique good subsequences are "0", "1", "10", "11", and "101".

```

**Constraints:**
* `1 <= binary.length <= 105`
* `binary` consists of only `'0'`s and `'1'`s.


<br>

### Hints

- The number of unique good subsequences is equal to the number of unique decimal values there are for all possible subsequences.
- Find the answer at each index based on the previous indexes' answers.

<br>

### Solution

```cpp
class Solution {
  public:
    int numberOfUniqueGoodSubsequences (string binary) {
      constexpr int mod = 1000000007;
      int64_t dp[2][2] = {[0 ... 1][0 ... 1] = 0};

      for (char c: binary) {
        c -= '0';
        if (c == 0) {
          dp[0][0] = 1;
          dp[1][0] = (dp[1][0] + dp[1][1]) % mod;
        }
        else
          dp[1][1] = (dp[1][0] + dp[1][1] + 1) % mod;
      }

      return (dp[0][0] + dp[1][0] + dp[1][1]) % mod;
    }
};
```

Combining states

```cpp
class Solution {
  public:
    int numberOfUniqueGoodSubsequences (string binary) {
      constexpr int mod = 1000000007;
      int64_t zero = 0, one = 0;
      bool zero_exist = false;

      for (char c: binary) {
        if (c == '0') {
          zero = (one + zero) % mod;
          zero_exist = true;
        }
        else
          one = (one + zero + 1) % mod;
      }

      return (one + zero + zero_exist) % mod;
    }
};
```

<br>

### Statistics

- total accepted: 8850
- total submissions: 16934
- acceptance rate: 52.3%
- likes: 533
- dislikes: 11

<br>

### Similar Problems

- [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences) (Hard)
- [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii) (Hard)
