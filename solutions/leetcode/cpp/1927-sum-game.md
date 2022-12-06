# [1927] Sum Game

**[math, greedy, game-theory]**

### Statement

Alice and Bob take turns playing a game, with **Alice****starting first**.

You are given a string `num` of **even length** consisting of digits and `'?'` characters. On each turn, a player will do the following if there is still at least one `'?'` in `num`:

1. Choose an index `i` where `num[i] == '?'`.
2. Replace `num[i]` with any digit between `'0'` and `'9'`.



The game ends when there are no more `'?'` characters in `num`.

For Bobto win, the sum of the digits in the first half of `num` must be **equal** to the sum of the digits in the second half. For Aliceto win, the sums must **not be equal**.

* For example, if the game ended with `num = "243801"`, then Bobwins because `2+4+3 = 8+0+1`. If the game ended with `num = "243803"`, then Alicewins because `2+4+3 != 8+0+3`.



Assuming Alice and Bob play **optimally**, return `true` *if Alice will win and* `false` *if Bob will win*.


**Example 1:**

```

**Input:** num = "5023"
**Output:** false
**Explanation:** There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.

```

**Example 2:**

```

**Input:** num = "25??"
**Output:** true
**Explanation:** Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.

```

**Example 3:**

```

**Input:** num = "?3295???"
**Output:** false
**Explanation:** It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.

```

**Constraints:**
* `2 <= num.length <= 105`
* `num.length` is **even**.
* `num` consists of only digits and `'?'`.


<br>

### Hints

- Bob can always make the total sum of both sides equal in mod 9.
- Why does the difference between the number of question marks on the left and right side matter?

<br>

### Solution

```cpp
class Solution {
  public:
    bool sumGame (string num) {
      int n = num.length();
      double lsum = 0, rsum = 0;

      for (int i = 0; i < n; ++i) {
        if (i < n / 2)
          lsum += (num[i] == '?' ? 4.5 : num[i] - '0');
        else
          rsum += (num[i] == '?' ? 4.5 : num[i] - '0');
      }

      return lsum != rsum;
    }
};
```

<br>

### Statistics

- total accepted: 7982
- total submissions: 17037
- acceptance rate: 46.9%
- likes: 393
- dislikes: 57

<br>

### Similar Problems

None
