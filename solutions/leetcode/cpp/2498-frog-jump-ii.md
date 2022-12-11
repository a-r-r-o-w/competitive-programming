# [2498] Frog Jump II



### Statement

You are given a **0-indexed** integer array `stones` sorted in **strictly increasing order** representing the positions of stones in a river.

A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone **at most once**.

The **length** of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.

* More formally, if the frog is at `stones[i]` and is jumping to `stones[j]`, the length of the jump is `|stones[i] - stones[j]|`.



The **cost** of a path is the **maximum length of a jump** among all jumps in the path.

Return *the **minimum** cost of a path for the frog*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/11/14/example-1.png)

```

**Input:** stones = [0,2,5,6,7]
**Output:** 5
**Explanation:** The above figure represents one of the optimal paths the frog can take.
The cost of this path is 5, which is the maximum length of a jump.
Since it is not possible to achieve a cost of less than 5, we return it.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/14/example-2.png)

```

**Input:** stones = [0,3,9]
**Output:** 9
**Explanation:** 
The frog can jump directly to the last stone and come back to the first stone. 
In this case, the length of each jump will be 9. The cost for the path will be max(9, 9) = 9.
It can be shown that this is the minimum achievable cost.

```

**Constraints:**
* `2 <= stones.length <= 105`
* `0 <= stones[i] <= 109`
* `stones[0] == 0`
* `stones` is sorted in a strictly increasing order.


<br>

### Hints

- One of the optimal strategies will be to jump to every stone.
- Skipping just one stone in every forward jump and jumping to those skipped stones in backward jump can minimize the maximum jump.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxJump (vector <int>& stones) {
      int n = stones.size();
      int low = 1, high = 1e9 + 42;
      std::vector <bool> visited (n);
      
      auto cost = [&] (int x) {
        visited.assign(n, false);
        int index = 1, last = 0, prev_index = 0;
        bool any = false;
        
        while (index < n) {
          if (stones[index] - stones[prev_index] <= x) {
            last = index;
            ++index;
            any = true;
          }
          else {
            if (not any)
              return false;
            prev_index = last;
            visited[last] = true;
            any = false;
          }
        }
        
        index = n - 2, prev_index = n - 1, any = false;
        
        while (index >= 0) {
          if (visited[index])
            --index;
          else if (stones[prev_index] - stones[index] <= x) {
            last = index;
            --index;
            any = true;
          }
          else {
            if (not any)
              return false;
            prev_index = last;
            visited[last] = true;
            any = false;
          }
        }
        
        return any;
      };
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 4903
- total submissions: 8734
- acceptance rate: 56.1%
- likes: 66
- dislikes: 31

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas) (Medium)
