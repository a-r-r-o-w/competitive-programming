# [2001] Number of Pairs of Interchangeable Rectangles

**[array, hash-table, math, counting, number-theory]**

### Statement

You are given `n` rectangles represented by a **0-indexed** 2D integer array `rectangles`, where `rectangles[i] = [widthi, heighti]` denotes the width and height of the `ith` rectangle.

Two rectangles `i` and `j` (`i < j`) are considered **interchangeable** if they have the **same** width-to-height ratio. More formally, two rectangles are **interchangeable** if `widthi/heighti == widthj/heightj` (using decimal division, not integer division).

Return *the **number** of pairs of **interchangeable** rectangles in* `rectangles`.


**Example 1:**

```

**Input:** rectangles = [[4,8],[3,6],[10,20],[15,30]]
**Output:** 6
**Explanation:** The following are the interchangeable pairs of rectangles by index (0-indexed):
- Rectangle 0 with rectangle 1: 4/8 == 3/6.
- Rectangle 0 with rectangle 2: 4/8 == 10/20.
- Rectangle 0 with rectangle 3: 4/8 == 15/30.
- Rectangle 1 with rectangle 2: 3/6 == 10/20.
- Rectangle 1 with rectangle 3: 3/6 == 15/30.
- Rectangle 2 with rectangle 3: 10/20 == 15/30.

```

**Example 2:**

```

**Input:** rectangles = [[4,5],[7,8]]
**Output:** 0
**Explanation:** There are no interchangeable pairs of rectangles.

```

**Constraints:**
* `n == rectangles.length`
* `1 <= n <= 105`
* `rectangles[i].length == 2`
* `1 <= widthi, heighti <= 105`


<br>

### Hints

- Store the rectangle height and width ratio in a hashmap.
- Traverse the ratios, and for each ratio, use the frequency of the ratio to add to the total pair count.

<br>

### Solution

```cpp
class Solution {
  public:
    long long interchangeableRectangles (vector <vector <int>>& rectangles) {
      int n = rectangles.size();
      std::map <std::pair <int, int>, int64_t> freq;

      for (auto &v: rectangles) {
        int g = std::gcd(v[0], v[1]);
        ++freq[{v[0] / g, v[1] / g}];
      }

      int64_t ans = 0;

      for (auto &[p, q]: freq)
        ans += q * (q - 1) / 2;
      
      return ans;
    }
}
```

<br>

### Statistics

- total accepted: 21881
- total submissions: 48105
- acceptance rate: 45.5%
- likes: 322
- dislikes: 27

<br>

### Similar Problems

- [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) (Easy)
- [Count Nice Pairs in an Array](https://leetcode.com/problems/count-nice-pairs-in-an-array) (Medium)
- [Replace Non-Coprime Numbers in Array](https://leetcode.com/problems/replace-non-coprime-numbers-in-array) (Hard)
