# [1406] Stone Game III

**[array, math, dynamic-programming, game-theory]**

### Statement

Alice and Bob continue their games with piles of stones. There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take `1`, `2`, or `3` stones from the **first** remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is `0` initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob **play optimally**.

Return `"Alice"` *if Alice will win,* `"Bob"` *if Bob will win, or* `"Tie"` *if they will end the game with the same score*.


**Example 1:**

```

**Input:** values = [1,2,3,7]
**Output:** "Bob"
**Explanation:** Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

```

**Example 2:**

```

**Input:** values = [1,2,3,-9]
**Output:** "Alice"
**Explanation:** Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

```

**Example 3:**

```

**Input:** values = [1,2,3,6]
**Output:** "Tie"
**Explanation:** Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

```

**Constraints:**
* `1 <= stoneValue.length <= 5 * 10^4`
* `-1000 <= stoneValue[i] <= 1000`


<br />

### Hints

- The game can be mapped to minmax game. Alice tries to maximize the total score and Bob tries to minimize it.
- Use dynamic programming to simulate the game. If the total score was 0 the game is "Tie", and if it has positive value then "Alice" wins, otherwise "Bob" wins.

<br />

### Solution

```cpp
class Solution {
  public:
    string stoneGameIII (vector <int>& stoneValue) {
      int n = stoneValue.size();
      std::vector dp (2, std::vector <int> (n, std::numeric_limits <int>::min()));

      auto dfs = [&] (auto self, int turn, int index) -> int {
        if (index >= n)
          return 0;
        if (dp[turn][index] != std::numeric_limits <int>::min())
          return dp[turn][index];
        int ans = (turn ? -(1 << 30) : 1 << 30), k = 0;
        for (int x = 1; index + x - 1 < n and x <= 3; ++x) {
          if (turn) {
            k += stoneValue[index + x - 1];
            ans = std::max(ans, k + self(self, turn ^ 1, index + x));
          }
          else
            ans = std::min(ans, self(self, turn ^ 1, index + x));
        }
        return dp[turn][index] = ans;
      };

      int x = dfs(dfs, 1, 0), y = std::accumulate(stoneValue.begin(), stoneValue.end(), 0) - x;
      return x > y ? "Alice" : x < y ? "Bob" : "Tie";
    }
};
```

<br />

### Statistics

- total accepted: 59784
- total submissions: 95836
- acceptance rate: 62.4%
- likes: 1648
- dislikes: 44

<br />

### Similar Problems

- [Stone Game V](https://leetcode.com/problems/stone-game-v) (Hard)
- [Stone Game VI](https://leetcode.com/problems/stone-game-vi) (Medium)
- [Stone Game VII](https://leetcode.com/problems/stone-game-vii) (Medium)
- [Stone Game VIII](https://leetcode.com/problems/stone-game-viii) (Hard)
- [Stone Game IX](https://leetcode.com/problems/stone-game-ix) (Medium)
