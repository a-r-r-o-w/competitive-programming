# [2660] Determine the Winner of a Bowling Game



### Statement

You are given two **0-indexed** integer arrays `player1` and `player2`, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of `n` turns, and the number of pins in each turn is exactly `10`.

Assume a player hit `xi` pins in the `i^th` turn. The value of the `i^th` turn for the player is:

* `2xi` if the player hit `10` pins in any of the previous two turns.
* Otherwise, It is `xi`.



The score of the player is the sum of the values of their `n` turns.

Return

* `1` *if the score of player 1 is more than the score of player 2,*
* `2` *if the score of player 2 is more than the score of player 1, and*
* `0` *in case of a draw.*


**Example 1:**

```

**Input:** player1 = [4,10,7,9], player2 = [6,5,2,3]
**Output:** 1
**Explanation:** The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
The score of player2 is 6 + 5 + 2 + 3 = 16.
Score of player1 is more than the score of player2, so, player1 is the winner, and the answer is 1.

```

**Example 2:**

```

**Input:** player1 = [3,5,7,6], player2 = [8,10,10,2]
**Output:** 2
**Explanation:** The score of player1 is 3 + 5 + 7 + 6 = 21.
The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
Score of player2 is more than the score of player1, so, player2 is the winner, and the answer is 2.

```

**Example 3:**

```

**Input:** player1 = [2,3], player2 = [4,1]
**Output:** 0
**Explanation:** The score of player1 is 2 + 3 = 5
The score of player2 is 4 + 1 = 5
The score of player1 equals to the score of player2, so, there is a draw, and the answer is 0.


```

**Constraints:**
* `n == player1.length == player2.length`
* `1 <= n <= 1000`
* `0 <= player1[i], player2[i] <= 10`


<br />

### Hints

- Think about simulating the process to calculate the answer.
- Iterate over each element and check the previous two elements. See if one of them is 10 and can affect the score.

<br />

### Solution

```cpp
class Solution {
  public:
    int isWinner (vector <int>& player1, vector <int>& player2) {
      int n = player1.size();
      int score1 = 0, score2 = 0;
      
      for (int i = 0; i < n; ++i) {
        bool has = false;
        if (i - 1 >= 0 and player1[i - 1] == 10)
          has = true;
        else if (i - 2 >= 0 and player1[i - 2] == 10)
          has = true;
        if (has)
          score1 += 2 * player1[i];
        else
          score1 += player1[i];
      }
      for (int i = 0; i < n; ++i) {
        bool has = false;
        if (i - 1 >= 0 and player2[i - 1] == 10)
          has = true;
        else if (i - 2 >= 0 and player2[i - 2] == 10)
          has = true;
        if (has)
          score2 += 2 * player2[i];
        else
          score2 += player2[i];
      }
      
      return score1 > score2 ? 1 : score1 < score2 ? 2 : 0;
    }
};
```

<br />

### Statistics

- total accepted: 10257
- total submissions: 34062
- acceptance rate: 30.1%
- likes: 18
- dislikes: 20

<br />

### Similar Problems

- [High Five](https://leetcode.com/problems/high-five) (Easy)
