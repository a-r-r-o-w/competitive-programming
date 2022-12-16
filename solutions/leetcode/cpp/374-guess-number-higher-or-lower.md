# [374] Guess Number Higher or Lower

**[binary-search, interactive]**

### Statement

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns three possible results:

* `-1`: Your guess is higher than the number I picked (i.e. `num > pick`).
* `1`: Your guess is lower than the number I picked (i.e. `num < pick`).
* `0`: your guess is equal to the number I picked (i.e. `num == pick`).



Return *the number that I picked*.


**Example 1:**

```

**Input:** n = 10, pick = 6
**Output:** 6

```

**Example 2:**

```

**Input:** n = 1, pick = 1
**Output:** 1

```

**Example 3:**

```

**Input:** n = 2, pick = 1
**Output:** 1

```

**Constraints:**
* `1 <= n <= 2^31 - 1`
* `1 <= pick <= n`


<br>

### Hints

None

<br>

### Solution

```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
    int guessNumber (int n) {
      int64_t low = 1, high = (int64_t)n + 1;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        int g = guess(mid);
        
        if (g == 1)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 353449
- total submissions: 707820
- acceptance rate: 49.9%
- likes: 1330
- dislikes: 212

<br>

### Similar Problems

- [First Bad Version](https://leetcode.com/problems/first-bad-version) (Easy)
- [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii) (Medium)
- [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements) (Medium)
