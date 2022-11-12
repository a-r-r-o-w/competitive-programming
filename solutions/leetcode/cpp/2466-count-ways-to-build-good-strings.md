# [2466] Count Ways To Build Good Strings



### Statement

Given the integers `zero`, `one`, `low`, and `high`, we can construct a string by starting with an empty string, and then at each step perform either of the following:

* Append the character `'0'` `zero` times.
* Append the character `'1'` `one` times.



This can be performed any number of times.

A **good** string is a string constructed by the above process having a **length** between `low` and `high` (**inclusive**).

Return *the number of **different** good strings that can be constructed satisfying these properties.* Since the answer can be large, return it **modulo** `109 + 7`.


**Example 1:**

```

**Input:** low = 3, high = 3, zero = 1, one = 1
**Output:** 8
**Explanation:** 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.

```

**Example 2:**

```

**Input:** low = 2, high = 3, zero = 1, one = 2
**Output:** 5
**Explanation:** The good strings are "00", "11", "000", "110", and "011".

```

**Constraints:**
* `1 <= low<= high<= 105`
* `1 <= zero, one <= low`


<br>

### Hints

- Calculate the number of good strings with length less or equal to some constant x.
- Apply dynamic programming using the group size of consecutive zeros and ones.

<br>

### Solution

```cpp
class Solution {
  public:
    int countGoodStrings (int low, int high, int zero, int one) {
      // length l
      // l = p * zero + q * one
      
      const int mod = 1000000007;
      
      std::vector <int64_t> dp (high + 1);
      dp[0] = 1;
      
      for (int l = 1; l <= high; ++l) {
        if (l - zero >= 0)
          dp[l] += dp[l - zero];
        if (l - one >= 0)
          dp[l] += dp[l - one];
        dp[l] %= mod;
      }
      
      int64_t sum = 0;
      
      for (int i = low; i <= high; ++i)
        sum = (sum + dp[i]) % mod;
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 5589
- total submissions: 15066
- acceptance rate: 37.1%
- likes: 95
- dislikes: 13

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
