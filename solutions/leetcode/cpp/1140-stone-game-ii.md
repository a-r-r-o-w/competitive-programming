# [1140] Stone Game II

**[array, math, dynamic-programming, game-theory]**

### Statement

Alice and Bob continue theirgames with piles of stones. There are a number ofpiles**arranged in a row**, and each pile has a positive integer number of stones`piles[i]`. The objective of the game is to end with the moststones.

Aliceand Bob take turns, with Alice starting first. Initially, `M = 1`.

On each player's turn, that playercan take **all the stones** in the **first** `X` remaining piles, where `1 <= X <= 2M`. Then, we set`M = max(M, X)`.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alicecan get.


**Example 1:**

```

**Input:** piles = [2,7,9,4,4]
**Output:** 10
**Explanation:**  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

```

**Example 2:**

```

**Input:** piles = [1,2,3,4,5,100]
**Output:** 104

```

**Constraints:**
* `1 <= piles.length <= 100`
* `1 <= piles[i]<= 10^4`


<br />

### Hints

- Use dynamic programming: the states are (i, m) for the answer of piles[i:] and that given m.

<br />

### Solution

```cpp
template <typename T>
using v = std::vector <T>;

class Solution {
  public:
    int stoneGameII (vector <int>& piles) {
      int n = piles.size();
      v <v <v <int>>> dp (2, v <v <int>> (n, v <int> (1 << 7, -1)));

      auto dfs = [&] (auto self, int turn, int index, int m) -> int {
        if (index >= n)
          return 0;
        if (dp[turn][index][m] != -1)
          return dp[turn][index][m];
        int ans = (turn ? 0 : 1 << 30), k = 0;
        for (int x = 1; index + x - 1 < n and x <= 2 * m; ++x) {
          if (turn) {
            k += piles[index + x - 1];
            ans = std::max(ans, k + self(self, turn ^ 1, index + x, std::max(m, x)));
          }
          else
            ans = std::min(ans, self(self, turn ^ 1, index + x, std::max(m, x)));
        }
        return dp[turn][index][m] = ans;
      };

      return dfs(dfs, 1, 0, 1);
    }
};
```

<br />

### Statistics

- total accepted: 63010
- total submissions: 93740
- acceptance rate: 67.2%
- likes: 2144
- dislikes: 476

<br />

### Similar Problems

- [Stone Game V](https://leetcode.com/problems/stone-game-v) (Hard)
- [Stone Game VI](https://leetcode.com/problems/stone-game-vi) (Medium)
- [Stone Game VII](https://leetcode.com/problems/stone-game-vii) (Medium)
- [Stone Game VIII](https://leetcode.com/problems/stone-game-viii) (Hard)
- [Stone Game IX](https://leetcode.com/problems/stone-game-ix) (Medium)
