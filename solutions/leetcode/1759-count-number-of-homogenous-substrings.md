# [1759] Count Number of Homogenous Substrings

**[math, string]**

### Statement

Given a string `s`, return *the number of **homogenous** substrings of* `s`*.* Since the answer may be too large, return it **modulo** `109 + 7`.

A string is **homogenous** if all the characters of the string are the same.

A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** s = "abbcccaa"
**Output:** 13
**Explanation:** The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
```

**Example 2:**

```

**Input:** s = "xy"
**Output:** 2
**Explanation:** The homogenous substrings are "x" and "y".
```

**Example 3:**

```

**Input:** s = "zzzzz"
**Output:** 15

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of lowercase letters.


<br>

### Hints

- A string of only 'a's of length k contains k choose 2 homogenous substrings.
- Split the string into substrings where each substring contains only one letter, and apply the formula on each substring's length.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countHomogenous (string s) {
      const int64_t mod = 1000000007;
      int ans = 0;
      int n = s.length();
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and s[j] == s[i])
          ++j;
        int64_t count = j - i;
        ans = (ans + count * (count + 1) / 2) % mod;
        i = j - 1;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 20209
- total submissions: 42753
- acceptance rate: 47.3%
- likes: 439
- dislikes: 39

<br>

### Similar Problems

- [Consecutive Characters](https://leetcode.com/problems/consecutive-characters) (Easy)
- [Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s) (Medium)
- [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges) (Medium)
