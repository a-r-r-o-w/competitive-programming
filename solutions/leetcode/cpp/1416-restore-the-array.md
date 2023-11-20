# [1416] Restore The Array

**[string, dynamic-programming]**

### Statement

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits `s` and all we know is that all integers in the array were in the range `[1, k]` and there are no leading zeros in the array.

Given the string `s` and the integer `k`, return *the number of the possible arrays that can be printed as* `s` *using the mentioned program*. Since the answer may be very large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** s = "1000", k = 10000
**Output:** 1
**Explanation:** The only possible array is [1000]

```

**Example 2:**

```

**Input:** s = "1000", k = 10
**Output:** 0
**Explanation:** There cannot be an array that was printed this way and has all integer >= 1 and <= 10.

```

**Example 3:**

```

**Input:** s = "1317", k = 2000
**Output:** 8
**Explanation:** Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]

```

**Constraints:**
* `1 <= s.length <= 10^5`
* `s` consists of only digits and does not contain leading zeros.
* `1 <= k <= 10^9`


<br />

### Hints

- Use dynamic programming. Build an array dp where dp[i] is the number of ways you can divide the string starting from index i to the end.
- Keep in mind that the answer is modulo 10^9 + 7 and take the mod for each operation.

<br />

### Solution

```cpp
class Solution {
  public:
    int numberOfArrays (string s, int k) {
      const int64_t mod = 1000000007;
      int n = s.length();
      std::vector <int64_t> dp (n, -1);

      auto dfs = [&] (auto self, int index) -> int64_t {
        if (index >= n)
          return 1;
        if (dp[index] != -1)
          return dp[index];
        
        int64_t value = s[index] - '0', ways = 0;
        int orig_index = index;

        ++index;
        if (value < 1)
          return 0;
        while (value <= k and index < n) {
          ways = (ways + self(self, index)) % mod;
          value = value * 10 + s[index] - '0';
          ++index;
        }
        if (value <= k)
          ways += self(self, index);

        return dp[orig_index] = ways;
      };

      return dfs(dfs, 0);
    }
};
```

<br />

### Statistics

- total accepted: 46437
- total submissions: 95085
- acceptance rate: 48.8%
- likes: 1313
- dislikes: 44

<br />

### Similar Problems

- [Number of Ways to Separate Numbers](https://leetcode.com/problems/number-of-ways-to-separate-numbers) (Hard)
- [Number of Beautiful Partitions](https://leetcode.com/problems/number-of-beautiful-partitions) (Hard)
