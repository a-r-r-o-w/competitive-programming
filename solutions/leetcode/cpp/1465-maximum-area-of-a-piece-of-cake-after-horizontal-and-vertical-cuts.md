# [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

**[array, greedy, sorting]**

### Statement

You are given a rectangular cake of size `h x w` and two arrays of integers `horizontalCuts` and `verticalCuts` where:

* `horizontalCuts[i]` is the distance from the top of the rectangular cake to the `ith` horizontal cut and similarly, and
* `verticalCuts[j]` is the distance from the left of the rectangular cake to the `jth` vertical cut.



Return *the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays* `horizontalCuts` *and* `verticalCuts`. Since the answer can be a large number, return this **modulo** `109 + 7`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_2.png)

```

**Input:** h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
**Output:** 4 
**Explanation:** The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_3.png)

```

**Input:** h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
**Output:** 6
**Explanation:** The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

```

**Example 3:**

```

**Input:** h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
**Output:** 9

```

**Constraints:**
* `2 <= h, w <= 109`
* `1 <= horizontalCuts.length <= min(h - 1, 105)`
* `1 <= verticalCuts.length <= min(w - 1, 105)`
* `1 <= horizontalCuts[i] < h`
* `1 <= verticalCuts[i] < w`
* All the elements in `horizontalCuts` are distinct.
* All the elements in `verticalCuts` are distinct.


<br>

### Hints

- Sort the arrays, then compute the maximum difference between two consecutive elements for horizontal cuts and vertical cuts.
- The answer is the product of these maximum values in horizontal cuts and vertical cuts.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxArea (int h, int w, vector <int>& horizontalCuts, vector <int>& verticalCuts) {
      horizontalCuts.push_back(0);
      horizontalCuts.push_back(h);
      verticalCuts.push_back(0);
      verticalCuts.push_back(w);
      
      std::sort(horizontalCuts.begin(), horizontalCuts.end());
      std::sort(verticalCuts.begin(), verticalCuts.end());
      
      const int mod = 1000000007;
      int H = horizontalCuts.size();
      int W = verticalCuts.size();
      int64_t maxH = 0;
      int64_t maxW = 0;
      
      for (int i = 0; i < H - 1; ++i)
        maxH = std::max(maxH, (int64_t)horizontalCuts[i + 1] - horizontalCuts[i]);
      for (int i = 0; i < W - 1; ++i)
        maxW = std::max(maxW, (int64_t)verticalCuts[i + 1] - verticalCuts[i]);
      
      int64_t ans = 0;
      for (int i = 0; i < W - 1; ++i)
        ans = std::max(ans, maxH * int64_t(verticalCuts[i + 1] - verticalCuts[i]));
      for (int i = 0; i < H - 1; ++i)
        ans = std::max(ans, maxW * int64_t(horizontalCuts[i + 1] - horizontalCuts[i]));
      
      return ans % mod;
    }
};
```

<br>

### Statistics

- total accepted: 122569
- total submissions: 310769
- acceptance rate: 39.4%
- likes: 1796
- dislikes: 287

<br>

### Similar Problems

None
