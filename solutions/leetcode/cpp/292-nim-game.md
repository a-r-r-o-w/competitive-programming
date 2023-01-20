# [292] Nim Game

**[math, brainteaser, game-theory]**

### Statement

You are playing the following Nim Game with your friend:

* Initially, there is a heap of stones on the table.
* You and your friend will alternate taking turns, and **you go first**.
* On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
* The one who removes the last stone is the winner.



Given `n`, the number of stones in the heap, return `true` *if you can win the game assuming both you and your friend play optimally, otherwise return* `false`.


**Example 1:**

```

**Input:** n = 4
**Output:** false
**Explanation:** These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.

```

**Example 2:**

```

**Input:** n = 1
**Output:** true

```

**Example 3:**

```

**Input:** n = 2
**Output:** true

```

**Constraints:**
* `1 <= n <= 231 - 1`


<br>

### Hints

- If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?

<br>

### Solution

```cpp
class Solution {
  public:
    bool canWinNim (int n) {
      return n % 4;
    }
};
```

<br>

### Statistics

- total accepted: 308609
- total submissions: 551145
- acceptance rate: 56.0%
- likes: 1312
- dislikes: 2452

<br>

### Similar Problems

- [Flip Game II](https://leetcode.com/problems/flip-game-ii) (Medium)
