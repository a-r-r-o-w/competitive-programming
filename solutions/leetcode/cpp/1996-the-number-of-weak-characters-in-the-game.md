# [1996] The Number of Weak Characters in the Game

**[array, stack, greedy, sorting, monotonic-stack]**

### Statement

You are playing a game that contains multiple characters, and each of the characters has **two** main properties: **attack** and **defense**. You are given a 2D integer array `properties` where `properties[i] = [attacki, defensei]` represents the properties of the `ith` character in the game.

A character is said to be **weak** if any other character has **both** attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be **weak** if there exists another character `j` where `attackj > attacki` and `defensej > defensei`.

Return *the number of **weak** characters*.


**Example 1:**

```

**Input:** properties = [[5,5],[6,3],[3,6]]
**Output:** 0
**Explanation:** No character has strictly greater attack and defense than the other.

```

**Example 2:**

```

**Input:** properties = [[2,2],[3,3]]
**Output:** 1
**Explanation:** The first character is weak because the second character has a strictly greater attack and defense.

```

**Example 3:**

```

**Input:** properties = [[1,5],[10,4],[4,3]]
**Output:** 1
**Explanation:** The third character is weak because the second character has a strictly greater attack and defense.

```

**Constraints:**
* `2 <= properties.length <= 10^5`
* `properties[i].length == 2`
* `1 <= attacki, defensei <= 10^5`


<br>

### Hints

- Sort the array on the basis of the attack values and group characters with the same attack together. How can you use these groups?
- Characters in one group will always have a lesser attack value than the characters of the next group. Hence, we will only need to check if there is a higher defense value present in the next groups.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numberOfWeakCharacters (vector <vector <int>>& properties) {
      std::sort(properties.begin(), properties.end(), [] (auto &l, auto &r) {
        if (l[0] < r[0])
          return true;
        if (l[0] > r[0])
          return false;
        return l[1] > r[1];
      });
      
      int count = 0, max = -(1 << 30), n = properties.size();
      
      for (int i = n - 1; i >= 0; --i) {
        if (properties[i][1] < max)
          ++count;
        max = std::max(max, properties[i][1]);
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 37831
- total submissions: 93721
- acceptance rate: 40.4%
- likes: 1288
- dislikes: 45

<br>

### Similar Problems

- [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes) (Hard)
- [Maximum Height by Stacking Cuboids ](https://leetcode.com/problems/maximum-height-by-stacking-cuboids) (Hard)
