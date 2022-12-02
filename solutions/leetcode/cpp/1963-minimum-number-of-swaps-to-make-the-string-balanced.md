# [1963] Minimum Number of Swaps to Make the String Balanced

**[two-pointers, string, stack, greedy]**

### Statement

You are given a **0-indexed** string `s` of **even** length `n`. The string consists of **exactly** `n / 2` opening brackets `'['` and `n / 2` closing brackets `']'`.

A string is called **balanced** if and only if:

* It is the empty string, or
* It can be written as `AB`, where both `A` and `B` are **balanced** strings, or
* It can be written as `[C]`, where `C` is a **balanced** string.



You may swap the brackets at **any** two indices **any** number of times.

Return *the **minimum** number of swaps to make* `s` ***balanced***.


**Example 1:**

```

**Input:** s = "][]["
**Output:** 1
**Explanation:** You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

```

**Example 2:**

```

**Input:** s = "]]][[["
**Output:** 2
**Explanation:** You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

```

**Example 3:**

```

**Input:** s = "[]"
**Output:** 0
**Explanation:** The string is already balanced.

```

**Constraints:**
* `n == s.length`
* `2 <= n <= 106`
* `n` is even.
* `s[i]` is either `'['` or `']'`.
* The number of opening brackets `'['` equals `n / 2`, and the number of closing brackets `']'` equals `n / 2`.


<br>

### Hints

- Iterate over the string and keep track of the number of opening and closing brackets on each step.
- If the number of closing brackets is ever larger, you need to make a swap.
- Swap it with the opening bracket closest to the end of s.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int minSwaps (string s) {
      int ans = 0, n = s.length();
      int l = 0, r = n - 1, d = 0;
      
      while (l < r) {
        if (s[l] == '[') {
          ++d;
          ++l;
        }
        else {
          --d;
          
          if (d < 0) {
            while (s[r] != '[')
              --r;
            std::swap(s[l], s[r]);
            ++l;
            --r;
            ++ans;
            d += 2;
          }
          else
            ++l;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 38158
- total submissions: 55754
- acceptance rate: 68.4%
- likes: 1172
- dislikes: 42

<br>

### Similar Problems

- [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses) (Hard)
- [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid) (Medium)
- [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses) (Medium)
- [Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string) (Medium)
