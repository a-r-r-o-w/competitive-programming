# [2410] Maximum Matching of Players With Trainers

**[array, two-pointers, greedy, sorting]**

### Statement

You are given a **0-indexed** integer array `players`, where `players[i]` represents the **ability** of the `ith` player. You are also given a **0-indexed** integer array `trainers`, where `trainers[j]` represents the **training capacity** of the `jth` trainer.

The `ith` player can **match** with the `jth` trainer if the player's ability is **less than or equal to** the trainer's training capacity. Additionally, the `ith` player can be matched with at most one trainer, and the `jth` trainer can be matched with at most one player.

Return *the **maximum** number of matchings between* `players` *and* `trainers` *that satisfy these conditions.*
**Example 1:**

```

**Input:** players = [4,7,9], trainers = [8,2,5,8]
**Output:** 2
**Explanation:**
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.

```

**Example 2:**

```

**Input:** players = [1,1,1], trainers = [10]
**Output:** 1
**Explanation:**
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.

```

**Constraints:**
* `1 <= players.length, trainers.length <= 105`
* `1 <= players[i], trainers[j] <= 109`


<br>

### Hints

- Sort both the arrays.
- Construct the matching greedily.

<br>

### Solution

```cpp
class Solution {
  public:
    int matchPlayersAndTrainers (vector <int>& players, vector <int>& trainers) {
      int n = players.size(), m = trainers.size();
      int i = 0, j = 0;

      std::sort(players.begin(), players.end());
      std::sort(trainers.begin(), trainers.end());

      while (i < n and j < m) {
        if (players[i] <= trainers[j])
          ++i;
        ++j;
      }

      return i;
    }
};
```

<br>

### Statistics

- total accepted: 20256
- total submissions: 33789
- acceptance rate: 59.9%
- likes: 243
- dislikes: 9

<br>

### Similar Problems

- [Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work) (Medium)
- [Long Pressed Name](https://leetcode.com/problems/long-pressed-name) (Easy)
- [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections) (Medium)
- [Largest Merge Of Two Strings](https://leetcode.com/problems/largest-merge-of-two-strings) (Medium)
- [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign) (Hard)
- [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions) (Medium)
- [The Latest Time to Catch a Bus](https://leetcode.com/problems/the-latest-time-to-catch-a-bus) (Medium)
