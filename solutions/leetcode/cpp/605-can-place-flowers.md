# [605] Can Place Flowers

**[array, greedy]**

### Statement

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if* `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.


**Example 1:**

```
**Input:** flowerbed = [1,0,0,0,1], n = 1
**Output:** true

```
**Example 2:**

```
**Input:** flowerbed = [1,0,0,0,1], n = 2
**Output:** false

```

**Constraints:**
* `1 <= flowerbed.length <= 2 * 10^4`
* `flowerbed[i]` is `0` or `1`.
* There are no two adjacent flowers in `flowerbed`.
* `0 <= n <= flowerbed.length`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    bool canPlaceFlowers (vector <int>& flowerbed, int n) {
        int k = flowerbed.size(), count = 0;

        if ((k == 1 and flowerbed[0] == 0) or (k >= 2 and flowerbed[0] == 0 and flowerbed[1] == 0))
          flowerbed[0] = 1, ++count;

        for (int i = 1; i < k; ++i) {
          if (flowerbed[i] == 0 and flowerbed[i - 1] != 1 and (i + 1 >= k or flowerbed[i + 1] != 1)) {
            ++count;
            flowerbed[i] = 1;
          }
        }

        return count >= n;
    }
};
```

<br />

### Statistics

- total accepted: 348723
- total submissions: 1074896
- acceptance rate: 32.4%
- likes: 3611
- dislikes: 727

<br />

### Similar Problems

- [Teemo Attacking](https://leetcode.com/problems/teemo-attacking) (Easy)
- [Asteroid Collision](https://leetcode.com/problems/asteroid-collision) (Medium)
