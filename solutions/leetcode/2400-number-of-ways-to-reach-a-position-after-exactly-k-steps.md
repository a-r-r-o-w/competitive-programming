# [2400] Number of Ways to Reach a Position After Exactly k Steps



### Statement

You are given two **positive** integers `startPos` and `endPos`. Initially, you are standing at position `startPos` on an **infinite** number line. With one step, you can move either one position to the left, or one position to the right.

Given a positive integer `k`, return *the number of **different** ways to reach the position* `endPos` *starting from* `startPos`*, such that you perform **exactly*** `k` *steps*. Since the answer may be very large, return it **modulo** `109 + 7`.

Two ways are considered different if the order of the steps made is not exactly the same.

**Note** that the number line includes negative integers.


**Example 1:**

```

**Input:** startPos = 1, endPos = 2, k = 3
**Output:** 3
**Explanation:** We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.
```

**Example 2:**

```

**Input:** startPos = 2, endPos = 5, k = 10
**Output:** 0
**Explanation:** It is impossible to reach position 5 from position 2 in exactly 10 steps.

```

**Constraints:**
* `1 <= startPos, endPos, k <= 1000`


<br>

### Hints

- How many steps to the left and to the right do you need to make exactly?
- Does the order of the steps matter?
- Use combinatorics to find the number of ways to order the steps.

<br>

### Solution

**Top-Down**

```cpp
class Solution {
  public:
    int numberOfWays (int startPos, int endPos, int k) {
      const int mod = 1000000007;
      const int new_max = 3000 + 42;
      const int max = 1000;
      
      startPos += max;
      endPos += max;
      
      std::vector <std::vector <int>> dp (new_max, std::vector <int> (k + 1, -1));
      
      auto dfs = [&] (auto self, int x, int y) -> int {
        if (y < 0)
          return 0;
        else if (y == 0) {
          if (x == startPos)
            dp[x][y] = 1;
          else
            dp[x][y] = 0;
          return dp[x][y];
        }
        if (dp[x][y] == -1)
          dp[x][y] = self(self, x - 1, y - 1) + self(self, x + 1, y - 1);
        
        if (dp[x][y] >= mod)
          dp[x][y] -= mod;
        
        return dp[x][y];
      };
      
      return dfs(dfs, endPos, k);
    }
};
```

**Bottom Up**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numberOfWays (int startPos, int endPos, int k) {
      const int mod = 1000000007;
      const int new_max = 3000 + 42;
      const int max = 1000;
      
      startPos += max;
      endPos += max;
      
      std::vector <std::vector <int>> dp (k + 1, std::vector <int> (new_max));
      
      dp[0][startPos] = 1;
      
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j + 1 < new_max; ++j) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
          if (dp[i][j] >= mod)
            dp[i][j] -= mod;
        }
      }
      
      return dp[k][endPos];
    }
};
```

Memory optimised Bottom-Up

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numberOfWays (int startPos, int endPos, int k) {
      const int mod = 1000000007;
      const int new_max = 3000 + 42;
      const int max = 1000;
      
      startPos += max;
      endPos += max;
      
      std::vector <std::vector <int>> dp (2, std::vector <int> (new_max));
      
      dp[0][startPos] = 1;
      
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j + 1 < new_max; ++j) {
          int p = i % 2;
          int q = (i + 1) % 2;
          
          dp[p][j] = dp[q][j - 1] + dp[q][j + 1];
          if (dp[p][j] >= mod)
            dp[p][j] -= mod;
        }
      }
      
      return dp[k % 2][endPos];
    }
};
```

<br>

### Statistics

- total accepted: 8743
- total submissions: 32835
- acceptance rate: 26.6%
- likes: 146
- dislikes: 37

<br>

### Similar Problems

- [Unique Paths](https://leetcode.com/problems/unique-paths) (Medium)
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [Reach a Number](https://leetcode.com/problems/reach-a-number) (Medium)
- [Reaching Points](https://leetcode.com/problems/reaching-points) (Hard)
- [Number of Ways to Stay in the Same Place After Some Steps](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps) (Hard)
