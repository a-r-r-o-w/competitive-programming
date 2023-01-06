# [1945] Sum of Digits of String After Convert

**[string, simulation]**

### Statement

You are given a string `s` consisting of lowercase English letters, and an integer `k`.

First, **convert** `s` into an integer by replacing each letter with its position in the alphabet (i.e., replace `'a'` with `1`, `'b'` with `2`, ..., `'z'` with `26`). Then, **transform** the integer by replacing it with the **sum of its digits**. Repeat the **transform** operation `k` **times** in total.

For example, if `s = "zbax"` and `k = 2`, then the resulting integer would be `8` by the following operations:

* **Convert**: `"zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124`
* **Transform #1**: `262124 ➝ 2 + 6 + 2 + 1 + 2 + 4➝ 17`
* **Transform #2**: `17 ➝ 1 + 7 ➝ 8`



Return *the resulting integer after performing the operations described above*.


**Example 1:**

```

**Input:** s = "iiii", k = 1
**Output:** 36
**Explanation:** The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.

```

**Example 2:**

```

**Input:** s = "leetcode", k = 2
**Output:** 6
**Explanation:** The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.

```

**Example 3:**

```

**Input:** s = "zbax", k = 2
**Output:** 8

```

**Constraints:**
* `1 <= s.length <= 100`
* `1 <= k <= 10`
* `s` consists of lowercase English letters.


<br>

### Hints

- First, let's note that after the first transform the value will be at most 100 * 9 which is not much
- After The first transform, we can just do the rest of the transforms by brute force

<br>

### Solution

```cpp
class Solution {
  public:
    int getLucky (string s, int k) {
      int sum = 0;

      for (char c: s) {
        c = c - 'a' + 1;
        while (c) {
          sum += c % 10;
          c /= 10;
        }
      }

      while (--k) {
        int x = sum;
        sum = 0;

        while (x) {
          sum += x % 10;
          x /= 10;
        }
      }

      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 35497
- total submissions: 57881
- acceptance rate: 61.3%
- likes: 429
- dislikes: 43

<br>

### Similar Problems

- [Happy Number](https://leetcode.com/problems/happy-number) (Easy)
- [Add Digits](https://leetcode.com/problems/add-digits) (Easy)
- [Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum) (Easy)
