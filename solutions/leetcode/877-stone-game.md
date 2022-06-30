# [877] Stone Game

**[array, math, dynamic-programming, game-theory]**

### Statement

Alice and Bob play a game with piles of stones. There are an **even** number of piles arranged in a row, and each pile has a **positive** integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The **total** number of stones across all the piles is **odd**, so there are no ties.

Alice and Bob take turns, with **Alice starting first**. Each turn, a player takes the entire pile of stones either from the **beginning** or from the **end** of the row. This continues until there are no more piles left, at which point the person with the **most stones wins**.

Assuming Alice and Bob play optimally, return `true` *if Alice wins the game, or* `false` *if Bob wins*.


**Example 1:**

```

**Input:** piles = [5,3,4,5]
**Output:** true
**Explanation:** 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

```

**Example 2:**

```

**Input:** piles = [3,7,2,3]
**Output:** true

```

**Constraints:**
* `2 <= piles.length <= 500`
* `piles.length` is **even**.
* `1 <= piles[i] <= 500`
* `sum(piles[i])` is **odd**.


<br>

### Hints

None

<br>

### Solution

**Top-Down Recursion DP**

```cpp
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      // dp[i][j]: max score of alice by only using piles[i...j]
      // len = j - i + 1
      // dp[i][j] = max(dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]) if len is even
      // dp[i][j] = max(dp[i + 1][j] - piles[i], dp[i][j - 1] - piles[j]) if len is odd
      
      int n = piles.size();
      const int inf32 = 1 << 30;
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (n + 1, -inf32));
      
      auto solve = [&] (auto self, int i, int j) -> int {
        if (i > j)
          return 0;
        else if (i == j) {
          dp[i][j] = piles[i - 1];
          return dp[i][j];
        }
        else if (dp[i][j] == -inf32) {
          int len = j - i + 1;
          int sign = len % 2 == 0 ? 1 : -1;
          int x = 0, y = 0;

          if (i + 1 <= j)
            x = self(self, i + 1, j) + piles[i - 1] * sign;
          if (i <= j - 1)
            y = self(self, i, j - 1) + piles[j - 1] * sign;

          dp[i][j] = x + y;
        }
        
        return dp[i][j];
      };
      
      int ans = solve(solve, n, n);
      return ans > 0;
    }
};
```

**Top-Down Recursion DP but not computing states that don't lead to optimal solution. Saves memory**

```cpp
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      // dp[i][j]: max score of alice by only using piles[i...j]
      // len = j - i + 1
      // dp[i][j] = max(dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]) if len is even
      // dp[i][j] = max(dp[i + 1][j] - piles[i], dp[i][j - 1] - piles[j]) if len is odd
      
      int n = piles.size();
      const int inf32 = 1 << 30;
      std::map <std::pair <int, int>, int> cache;
      
      auto solve = [&] (auto self, int i, int j) -> int {
        if (i > j)
          return 0;
        else if (i == j)
          cache[{i, j}] = piles[i - 1];
        else if (not cache.count({i, j})) {
          int len = j - i + 1;
          int sign = len % 2 == 0 ? 1 : -1;
          int x = 0, y = 0;

          if (i + 1 <= j)
            x = self(self, i + 1, j) + piles[i - 1] * sign;
          if (i <= j - 1)
            y = self(self, i, j - 1) + piles[j - 1] * sign;

          cache[{i, j}] = x + y;
        }
        
        return cache[{i, j}];
      };
      
      int ans = solve(solve, n, n);
      return ans > 0;
    }
};
```

**Bottom-Up DP**

```
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      // dp[len][i]: consider subarray piles[i...i+len-1], max score alice can get
      // dp[len][i] = max(dp[len - 1][i] + piles[i + len - 1], dp[len - 1][i + 1] + piles[i])
      
      const int inf32 = 1 << 30;
      int n = piles.size();
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (n, -inf32));
      
      for (int i = 0; i < n; ++i)
        dp[1][i] = piles[i];
      
      int sign = -1;
      for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
          dp[len][i] = std::max(
            dp[len - 1][i] + piles[i + len - 1] * sign,
            dp[len - 1][i + 1] + piles[i] * sign
          );
          sign = -sign;
        }
      }
      
      return dp[n][0] > 0;
    }
};
```

**Bottom-Up DP but noticing that only previous row is required to calculate states of current. Saves memory**

```cpp
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      // dp[len][i]: consider subarray piles[i...i+len-1], max score alice can get
      // dp[len][i] = max(dp[len - 1][i] + piles[i + len - 1], dp[len - 1][i + 1] + piles[i])
      
      const int inf32 = 1 << 30;
      int n = piles.size();
      std::vector <std::vector <int>> dp (2, std::vector <int> (n, -inf32));
      
      for (int i = 0; i < n; ++i)
        dp[1][i] = piles[i];
      
      int sign = -1;
      for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
          dp[i % 2][i] = std::max(
            dp[(i + 1) % 2][i] + piles[i + len - 1] * sign,
            dp[(i + 1) % 2][i + 1] + piles[i] * sign
          );
          sign = -sign;
        }
      }
      
      return dp[n % 2][0] > 0;
    }
};
```

**Bottom-Up DP but noticing that we can simply use a single vector instead of two**

```cpp
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      // dp[len][i]: consider subarray piles[i...i+len-1], max score alice can get
      // dp[len][i] = max(dp[len - 1][i] + piles[i + len - 1], dp[len - 1][i + 1] + piles[i])
      
      int n = piles.size();
      std::vector <int> dp = piles;
      
      int sign = -1;
      for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
          dp[i] = std::max(
            dp[i] + piles[i + len - 1] * sign,
            dp[i + 1] + piles[i] * sign
          );
          sign = -sign;
        }
      }
      
      return dp[0] > 0;
    }
};
```

**Noticing that this is a trick question and that Alice can win regardless of the values in piles. She can always manage to pick all odd indices or all even indices and since one of them has greater sum, she will choose either all odd indices or all even indices**

```cpp
class Solution {
  public:
    bool stoneGame(vector <int>& piles) {
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 158997
- total submissions: 229455
- acceptance rate: 69.3%
- likes: 2068
- dislikes: 2083

<br>

### Similar Problems

- [Stone Game V](https://leetcode.com/problems/stone-game-v) (Hard)
- [Stone Game VI](https://leetcode.com/problems/stone-game-vi) (Medium)
- [Stone Game VII](https://leetcode.com/problems/stone-game-vii) (Medium)
- [Stone Game VIII](https://leetcode.com/problems/stone-game-viii) (Hard)
- [Stone Game IX](https://leetcode.com/problems/stone-game-ix) (Medium)
