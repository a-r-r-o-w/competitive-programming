# [799] Champagne Tower

**[dynamic-programming]**

### Statement

We stack glasses in a pyramid, where the **first** row has `1` glass, the **second** row has `2` glasses, and so on until the 100^th row. Each glass holds one cupof champagne.

Then, some champagne is poured into the first glass at the top. When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it. When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on. (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full. After two cups of champagne are poured, the two glasses on the second row are half full. After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now. After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/09/tower.png)

Now after pouring some non-negative integer cups of champagne, return how full the `j^th` glass in the `i^th` row is (both `i` and `j` are 0-indexed.)


**Example 1:**

```

**Input:** poured = 1, query_row = 1, query_glass = 1
**Output:** 0.00000
**Explanation:** We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.

```

**Example 2:**

```

**Input:** poured = 2, query_row = 1, query_glass = 1
**Output:** 0.50000
**Explanation:** We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.

```

**Example 3:**

```

**Input:** poured = 100000009, query_row = 33, query_glass = 17
**Output:** 1.00000

```

**Constraints:**
* `0 <=poured <= 10^9`
* `0 <= query_glass <= query_row< 100`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
      std::vector dp(query_row + 1, std::vector<double>(query_row + 1, -1));

      auto dfs = [&] (auto self, int i, int j) -> double {
        std::cout << i << ' ' << j << '\n';
        if (j > i or i < 0 or j < 0)
          return 0;
        if (i == 0 and j == 0)
          return poured;
        if (dp[i][j] != -1)
          return dp[i][j];
        double ans = 0;
        ans += std::max<double>(0, self(self, i - 1, j - 1) - 1) / 2;
        ans += std::max<double>(0, self(self, i - 1, j) - 1) / 2;
        return dp[i][j] = ans;
      };

      return std::min<double>(1, dfs(dfs, query_row, query_glass));
    }
};
```

<br />

### Statistics

- total accepted: 108914
- total submissions: 199611
- acceptance rate: 54.6%
- likes: 3045
- dislikes: 174

<br />

### Similar Problems

- [Number of Ways to Build House of Cards](https://leetcode.com/problems/number-of-ways-to-build-house-of-cards) (Medium)
