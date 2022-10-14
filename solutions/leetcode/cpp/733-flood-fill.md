# [733] Flood Fill

**[array, depth-first-search, breadth-first-search, matrix]**

### Statement

An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `color`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**, consider the starting pixel, plus any pixels connected **4-directionally** to the starting pixel of the same color as the starting pixel, plus any pixels connected **4-directionally** to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with `color`.

Return *the modified image after performing the flood fill*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg)

```

**Input:** image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
**Output:** [[2,2,2],[2,2,0],[2,0,1]]
**Explanation:** From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

```

**Example 2:**

```

**Input:** image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
**Output:** [[0,0,0],[0,0,0]]
**Explanation:** The starting pixel is already colored 0, so no changes are made to the image.

```

**Constraints:**
* `m == image.length`
* `n == image[i].length`
* `1 <= m, n <= 50`
* `0 <= image[i][j], color < 216`
* `0 <= sr < m`
* `0 <= sc < n`


<br>

### Hints

- Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> floodFill (vector <vector <int>>& image, int sr, int sc, int color) {
      int m = image.size();
      int n = image.front().size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      std::vector <std::vector <bool>> visited (m, std::vector <bool> (n));
      
      auto dfs = [&] (auto self, int i, int j) -> void {
        visited[i][j] = true;
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (ni < 0 or nj < 0 or ni >= m or nj >= n or visited[ni][nj] or image[ni][nj] != image[sr][sc])
            continue;
          
          self(self, ni, nj);
        }
        
        image[i][j] = color;
      };
      
      dfs(dfs, sr, sc);
      
      return image;
    }
};
```

<br>

### Statistics

- total accepted: 539356
- total submissions: 900248
- acceptance rate: 59.9%
- likes: 5376
- dislikes: 523

<br>

### Similar Problems

- [Island Perimeter](https://leetcode.com/problems/island-perimeter) (Easy)
