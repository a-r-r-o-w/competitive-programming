# [2027] Minimum Moves to Convert String

**[string, greedy]**

### Statement

You are given a string `s` consisting of `n` characters which are either `'X'` or `'O'`.

A **move** is defined as selecting **three** **consecutive characters** of `s` and converting them to `'O'`. Note that if a move is applied to the character `'O'`, it will stay the **same**.

Return *the **minimum** number of moves required so that all the characters of* `s` *are converted to* `'O'`.


**Example 1:**

```

**Input:** s = "XXX"
**Output:** 1
**Explanation:** XXX -> OOO
We select all the 3 characters and convert them in one move.

```

**Example 2:**

```

**Input:** s = "XXOX"
**Output:** 2
**Explanation:** XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
```

**Example 3:**

```

**Input:** s = "OOOO"
**Output:** 0
**Explanation:** There are no 'X's in s to convert.

```

**Constraints:**
* `3 <= s.length <= 1000`
* `s[i]` is either `'X'` or `'O'`.


<br>

### Hints

- Find the smallest substring you need to consider at a time.
- Try delaying a move as long as possible.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumMoves (string s) {
      int n = s.length(), count = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
          i += 2;
          ++count;
        }
      }
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 25006
- total submissions: 46398
- acceptance rate: 53.9%
- likes: 340
- dislikes: 58

<br>

### Similar Problems

None
