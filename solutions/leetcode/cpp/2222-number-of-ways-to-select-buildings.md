# [2222] Number of Ways to Select Buildings

**[string, dynamic-programming, prefix-sum]**

### Statement

You are given a **0-indexed** binary string `s` which represents the types of buildings along a street where:

* `s[i] = '0'` denotes that the `i^th` building is an office and
* `s[i] = '1'` denotes that the `i^th` building is a restaurant.



As a city official, you would like to **select** 3 buildings for random inspection. However, to ensure variety, **no two consecutive** buildings out of the **selected** buildings can be of the same type.

* For example, given `s = "0**0**1**1**0**1**"`, we cannot select the `1^st`, `3^rd`, and `5^th` buildings as that would form `"0**11**"` which is **not** allowed due to having two consecutive buildings of the same type.



Return *the **number of valid ways** to select 3 buildings.*
**Example 1:**

```

**Input:** s = "001101"
**Output:** 6
**Explanation:** 
The following sets of indices selected are valid:
- [0,2,4] from "**0**0**1**1**0**1" forms "010"
- [0,3,4] from "**0**01**10**1" forms "010"
- [1,2,4] from "0**01**1**0**1" forms "010"
- [1,3,4] from "0**0**1**10**1" forms "010"
- [2,4,5] from "00**1**1**01**" forms "101"
- [3,4,5] from "001**101**" forms "101"
No other selection is valid. Thus, there are 6 total ways.

```

**Example 2:**

```

**Input:** s = "11100"
**Output:** 0
**Explanation:** It can be shown that there are no valid selections.

```

**Constraints:**
* `3 <= s.length <= 10^5`
* `s[i]` is either `'0'` or `'1'`.


<br />

### Hints

- There are only 2 valid patterns: ‘101’ and ‘010’. Think about how we can construct these 2 patterns from smaller patterns.
- Count the number of subsequences of the form ‘01’ or ‘10’ first. Let n01[i] be the number of ‘01’ subsequences that exist in the prefix of s up to the ith building. How can you compute n01[i]?
- Let n0[i] and n1[i] be the number of ‘0’s and ‘1’s that exists in the prefix of s up to i respectively. Then n01[i] = n01[i – 1] if s[i] == ‘0’, otherwise n01[i] = n01[i – 1] + n0[i – 1].
- The same logic applies to building the n10 array and subsequently the n101 and n010 arrays for the number of ‘101’ and ‘010‘ subsequences.

<br />

### Solution

```cpp
class Solution {
  public:
    long long numberOfWays (string s) {
      int64_t ans = 0, n = s.length();
      int64_t sones = 0, szeroes = 0;
      int64_t pones = 0, pzeroes = 0;

      for (int i = 0; i < n; ++i)
        ++(s[i] == '0' ? szeroes : sones);
      
      for (int i = 0; i < n; ++i) {
        ++(s[i] == '0' ? pzeroes : pones);
        --(s[i] == '0' ? szeroes : sones);
        if (s[i] == '0')
          ans += pones * sones;
        else
          ans += pzeroes * szeroes;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 26658
- total submissions: 52172
- acceptance rate: 51.1%
- likes: 803
- dislikes: 34

<br />

### Similar Problems

None
