# [1552] Magnetic Force Between Two Balls

**[array, binary-search, sorting]**

### Statement

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the `ith` basket is at `position[i]`, Morty has `m` balls and needs to distribute the balls into the baskets such that the **minimum magnetic force** between any two balls is **maximum**.

Rick stated that magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`. Return *the required force*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/11/q3v1.jpg)

```

**Input:** position = [1,2,3,4,7], m = 3
**Output:** 3
**Explanation:** Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

```

**Example 2:**

```

**Input:** position = [5,4,3,2,1,1000000000], m = 2
**Output:** 999999999
**Explanation:** We can use baskets 1 and 1000000000.

```

**Constraints:**
* `n == position.length`
* `2 <= n <= 105`
* `1 <= position[i] <= 109`
* All integers in `position` are **distinct**.
* `2 <= m <= position.length`


<br>

### Hints

- If you can place balls such that the answer is x then you can do it for y where y < x.
- Similarly if you cannot place balls such that the answer is x then you can do it for y where y > x.
- Binary search on the answer and greedily see if it is possible.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxDistance (vector <int>& position, int m) {
      int n = position.size();
      int low = 0, high = 1e9 + 42;
      
      std::sort(position.begin(), position.end());
      
      auto cost = [&] (int x) {
        int prev = position[0];
        int count = 1;
        
        for (int i = 1; i < n; ++i) {
          if (position[i] - prev >= x) {
            prev = position[i];
            ++count;
          }
        }
        
        return count >= m;
      };
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }
      
      int prev = position[0];
      int ans = 1 << 30;
      
      for (int i = 1; i < n; ++i) {
        if (position[i] - prev >= low - 1) {
          ans = std::min(ans, position[i] - prev);
          prev = position[i];
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 31403
- total submissions: 55868
- acceptance rate: 56.2%
- likes: 1329
- dislikes: 86

<br>

### Similar Problems

- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
