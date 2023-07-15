# [1025] Divisor Game

**[math, dynamic-programming, brainteaser, game-theory]**

### Statement

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:

* Choosing any `x` with `0 < x < n` and `n % x == 0`.
* Replacing the number `n` on the chalkboard with `n - x`.



Also, if a player cannot make a move, they lose the game.

Return `true` *if and only if Alice wins the game, assuming both players play optimally*.


**Example 1:**

```

**Input:** n = 2
**Output:** true
**Explanation:** Alice chooses 1, and Bob has no more moves.

```

**Example 2:**

```

**Input:** n = 3
**Output:** false
**Explanation:** Alice chooses 1, Bob chooses 1, and Alice has no more moves.

```

**Constraints:**
* `1 <= n <= 1000`


<br>

### Hints

- If the current number is even, we can always subtract a 1 to make it odd.  If the current number is odd, we must subtract an odd number to make it even.

<br>

### Solution

```cpp
class Solution {
  public:
    bool divisorGame (int n) {
      return n % 2 == 0;
    }
};
```

<br>

### Statistics

- total accepted: 190580
- total submissions: 282877
- acceptance rate: 67.4%
- likes: 1728
- dislikes: 3637

<br>

### Similar Problems

None
