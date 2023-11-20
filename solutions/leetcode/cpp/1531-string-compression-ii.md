# [1531] String Compression II

**[string, dynamic-programming]**

### Statement

[Run-length encoding](http://en.wikipedia.org/wiki/Run-length_encoding) is a string compression method that works byreplacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string`"aabccc"`we replace `"aa"`by`"a2"`and replace `"ccc"`by`"c3"`. Thus the compressed string becomes `"a2bc3"`.

Notice that in this problem, we are not adding`'1'`after single characters.

Given astring `s`and an integer `k`. You need to delete **at most**`k` characters from`s`such that the run-length encoded version of `s`has minimum length.

Find the *minimum length of the run-length encodedversion of* `s` *after deleting at most* `k` *characters*.


**Example 1:**

```

**Input:** s = "aaabcccd", k = 2
**Output:** 4
**Explanation:** Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
```

**Example 2:**

```

**Input:** s = "aabbaa", k = 2
**Output:** 2
**Explanation:** If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.

```

**Example 3:**

```

**Input:** s = "aaaaaaaaaaa", k = 0
**Output:** 3
**Explanation:** Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.

```

**Constraints:**
* `1 <= s.length <= 100`
* `0 <= k <= s.length`
* `s` contains only lowercase English letters.


<br>

### Hints

- Use dynamic programming.
- The state of the DP can be the current index and the remaining characters to delete.
- Having a prefix sum for each character can help you determine for a certain character c in some specific range, how many characters you need to delete to merge all occurrences of c in that range.

<br>

### Solution

```cpp
class Solution {
  public:
    int getLengthOfOptimalCompression (string s, int k) {
      const int inf32 = 1 << 30;
      
      int n = s.length();
      std::vector <std::vector <int>> dp (n, std::vector <int> (k + 1, -1));
      
      auto dfs = [&] (auto self, int index, int steps) -> int {
        // if you can remove entire string, then cost is 0
        if ((int)s.size() - index <= steps)
          return 0;
        
        if (dp[index][steps] != -1)
          return dp[index][steps];
        
        int ans = steps <= 0 ? inf32 : self(self, index + 1, steps - 1);
        int count = 1;
        
        for (int i = index + 1, available = steps; i <= (int)s.size() and available >= 0; ++i) {
          int digit_count = 0;
          
          if (count >= 100)
            digit_count = 3;
          else if (count >= 10)
            digit_count = 2;
          else if (count > 1)
            digit_count = 1;
          
          ans = std::min(ans, self(self, i, available) + 1 + digit_count);
          
          if (i != (int)s.size()) {
            if (s[i] == s[index])
              ++count;
            else
              --available;
          }
        }
        
        dp[index][steps] = ans;
        return ans;
      };
      
      return dfs(dfs, 0, k);
    }
};
```

<br>

### Statistics

- total accepted: 37268
- total submissions: 73858
- acceptance rate: 50.5%
- likes: 1430
- dislikes: 108

<br>

### Similar Problems

None
