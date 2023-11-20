# [1561] Maximum Number of Coins You Can Get

**[array, math, greedy, sorting, game-theory]**

### Statement

There are `3n` piles of coins of varying size, you and your friends will take piles of coins as follows:

* In each step, you will choose **any** `3` piles of coins (not necessarily consecutive).
* Of your choice, Alice will pick the pile with the maximum number of coins.
* You will pick the next pile with the maximum number of coins.
* Your friend Bob will pick the last pile.
* Repeat until there are no more piles of coins.



Given an array of integers `piles` where `piles[i]` is the number of coins in the `ith` pile.

Return the maximum number of coins that you can have.


**Example 1:**

```

**Input:** piles = [2,4,1,2,7,8]
**Output:** 9
**Explanation:** Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with **7** coins and Bob the last one.
Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with **2** coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, **2**, 8), (2, **4**, 7) you only get 2 + 4 = 6 coins which is not optimal.

```

**Example 2:**

```

**Input:** piles = [2,4,5]
**Output:** 4

```

**Example 3:**

```

**Input:** piles = [9,8,7,6,5,1,2,3,4]
**Output:** 18

```

**Constraints:**
* `3 <= piles.length <= 105`
* `piles.length % 3 == 0`
* `1 <= piles[i] <= 104`


<br>

### Hints

- Which pile of coins will you never be able to pick up?
- Bob is forced to take the last pile of coins, no matter what it is. Which pile should you give to him?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxCoins (vector <int>& piles) {
      std::sort(piles.begin(), piles.end());
      
      int n = piles.size();
      int l = 0, r = n - 1, me = 0;
      
      while (l < r) {
        --r;
        me += piles[r];
        --r;
        ++l;
      }
      
      return me;
    }
};
```

<br>

### Statistics

- total accepted: 55353
- total submissions: 70530
- acceptance rate: 78.5%
- likes: 810
- dislikes: 104

<br>

### Similar Problems

None
