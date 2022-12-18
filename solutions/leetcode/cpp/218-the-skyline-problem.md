# [218] The Skyline Problem

**[array, divide-and-conquer, binary-indexed-tree, segment-tree, line-sweep, heap-priority-queue, ordered-set]**

### Statement

A city's **skyline** is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return *the **skyline** formed by these buildings collectively*.

The geometric information of each building is given in the array `buildings` where `buildings[i] = [lefti, righti, heighti]`:

* `lefti` is the x coordinate of the left edge of the `ith` building.
* `righti` is the x coordinate of the right edge of the `ith` building.
* `heighti` is the height of the `ith` building.



You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The **skyline** should be represented as a list of "key points" **sorted by their x-coordinate** in the form `[[x1,y1],[x2,y2],...]`. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate `0` and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

**Note:** There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/12/01/merged.jpg)

```

**Input:** buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
**Output:** [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
**Explanation:**
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

```

**Example 2:**

```

**Input:** buildings = [[0,2,3],[2,5,3]]
**Output:** [[0,3],[5,0]]

```

**Constraints:**
* `1 <= buildings.length <= 10^4`
* `0 <= lefti < righti <= 2^31 - 1`
* `1 <= heighti <= 2^31 - 1`
* `buildings` is sorted by `lefti` innon-decreasing order.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> getSkyline (vector <vector <int>>& buildings) {
      int n = buildings.size();
      std::map <int, int> compress;
      
      for (auto &b: buildings) {
        compress[b[0]];
        compress[b[1]];
      }
      
      int unique = 0;

      for (auto &[x, y]: compress)
        y = unique++;
      
      std::vector <int> lookup (unique);
      
      for (auto &[x, y]: compress)
        lookup[y] = x;
      
      std::vector <int> tree (4 * unique, 0);
      std::vector <int> lazy (4 * unique, 0);
      
      auto push = [&] (int v) {
        if (lazy[v]) {
          tree[2 * v + 1] = std::max(tree[2 * v + 1], lazy[v]);
          tree[2 * v + 2] = std::max(tree[2 * v + 2], lazy[v]);
          lazy[2 * v + 1] = std::max(lazy[2 * v + 1], lazy[v]);
          lazy[2 * v + 2] = std::max(lazy[2 * v + 2], lazy[v]);
          lazy[v] = 0;
        }
      };
      
      auto update = [&] (auto self, int v, int tl, int tr, int l, int r, int value) -> void {
        if (l > r)
          return;
        
        if (tl == l and tr == r) {
          tree[v] = std::max(tree[v], value);
          lazy[v] = std::max(lazy[v], value);
          return;
        }
        
        push(v);
        
        int tm = (tl + tr) / 2;
        self(self, 2 * v + 1, tl, tm, l, std::min(r, tm), value);
        self(self, 2 * v + 2, tm + 1, tr, std::max(l, tm + 1), r, value);
        tree[v] = std::max(tree[2 * v + 1], tree[2 * v + 2]);
      };
      
      auto query = [&] (auto self, int v, int tl, int tr, int pos) -> int {
        if (tl == tr)
          return tree[v];
        
        push(v);
        
        int tm = (tl + tr) / 2;
        
        if (pos <= tm)
          return self(self, 2 * v + 1, tl, tm, pos);
        else
          return self(self, 2 * v + 2, tm + 1, tr, pos);
      };
      
      for (auto &b: buildings)
        update(update, 0, 0, unique - 1, compress[b[0]], compress[b[1]] - 1, b[2]);
      
      int last_height = -1;
      std::vector <std::vector <int>> ans;
      
      for (int i = 0; i < unique; ++i) {
        int current_height = query(query, 0, 0, unique - 1, i);
        
        if (current_height != last_height) {
          ans.push_back({lookup[i], current_height});
          last_height = current_height;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 245569
- total submissions: 594661
- acceptance rate: 41.3%
- likes: 4976
- dislikes: 233

<br>

### Similar Problems

- [Falling Squares](https://leetcode.com/problems/falling-squares) (Hard)
- [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii) (Medium)
