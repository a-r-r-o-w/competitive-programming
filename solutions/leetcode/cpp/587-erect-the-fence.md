# [587] Erect the Fence

**[array, math, geometry]**

### Statement

You are given an array `trees` where `trees[i] = [xi, yi]` represents the location of a tree in the garden.

You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if **all the trees are enclosed**.

Return *the coordinates of trees that are exactly located on the fence perimeter*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/24/erect2-plane.jpg)

```

**Input:** points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
**Output:** [[1,1],[2,0],[3,3],[2,4],[4,2]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/04/24/erect1-plane.jpg)

```

**Input:** points = [[1,2],[2,2],[4,2]]
**Output:** [[4,2],[2,2],[1,2]]

```

**Constraints:**
* `1 <= points.length <= 3000`
* `points[i].length == 2`
* `0 <= xi, yi <= 100`
* All the given points are **unique**.


<br>

### Hints

None

<br>

### Solution

Graham Scan Algorithm

```cpp
struct point {
  int x;
  int y;
  
  point (int x = 0, int y = 0)
    : x (x), y (y)
  { }
};

int orientation (const point &a, const point &b, const point &c) {
  int value = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (value < 0)
    return -1; // clockwise
  else if (value > 0)
    return +1; // counter clockwise
  return 0; // collinear
}

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> outerTrees (vector <vector <int>>& trees) {
      int n = trees.size();
      std::vector <point> points;
      points.reserve(n);
      
      for (int i = 0; i < n; ++i)
        points.emplace_back(trees[i][0], trees[i][1]);
      
      auto p0 = *std::min_element(points.begin(), points.end(), [] (auto &l, auto &r) {
        if (l.y < r.y)
          return true;
        if (l.y > r.y)
          return false;
        return l.x < r.x;
      });
      
      std::sort(points.begin(), points.end(), [&] (auto &l, auto &r) {
        int o = orientation(p0, l, r);
        
        if (o == 0) {
          auto lhs = (p0.x - l.x) * (p0.x - l.x) + (p0.y - l.y) * (p0.y - l.y);
          auto rhs = (p0.x - r.x) * (p0.x - r.x) + (p0.y - r.y) * (p0.y - r.y);
          return lhs < rhs;
        }
        
        return o < 0;
      });
      
      {
        int i = n - 1;
        while (i >= 0 && orientation(p0, points[i], points.back()) == 0)
          --i;
        std::reverse(points.begin() + i + 1, points.end());
      }
      
      std::vector <point> stack;
      
      for (int i = 0; i < n; ++i) {
        int k = stack.size();
        
        while (k >= 2 and orientation(stack[k - 2], stack[k - 1], points[i]) > 0) {
          stack.pop_back();
          --k;
        }
        
        stack.emplace_back(points[i]);
      }
      
      int k = stack.size();
      
      for (int i = 0; i < k; ++i) {
        trees[i][0] = stack[i].x;
        trees[i][1] = stack[i].y;
      }
      
      trees.resize(k);
      
      return trees;
    }
};
```

<br>

### Statistics

- total accepted: 25611
- total submissions: 59177
- acceptance rate: 43.3%
- likes: 625
- dislikes: 378

<br>

### Similar Problems

- [Erect the Fence II](https://leetcode.com/problems/erect-the-fence-ii) (Hard)
