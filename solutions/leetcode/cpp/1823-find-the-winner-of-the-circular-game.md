# [1823] Find the Winner of the Circular Game

**[array, math, recursion, queue, simulation]**

### Statement

There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

1. **Start** at the `1st` friend.
2. Count the next `k` friends in the clockwise direction **including** the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.



Given the number of friends, `n`, and an integer `k`, return *the winner of the game*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png)

```

**Input:** n = 5, k = 2
**Output:** 3
**Explanation:** Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```

**Example 2:**

```

**Input:** n = 6, k = 5
**Output:** 1
**Explanation:** The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.

```

**Constraints:**
* `1 <= k <= n <= 500`


**Follow up:**

Could you solve this problem in linear time with constant space?

<br>

### Hints

- Simulate the process.
- Maintain in a circular list the people who are still in the circle and the current person you are standing at.
- In each turn, count k people and remove the last person from the list.

<br>

### Solution

Brute force using linked lists

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findTheWinner (int n, int k) {
      if (k == 1)
        return n;
      
      std::vector <int> right (n);
      
      for (int i = 0; i < n; ++i)
        right[i] = (i + 1) % n;
      
      int current = 0, size = n;
      
      while (size > 1) {
        int prev = -1;
        
        for (int i = 0; i < k - 1; ++i) {
          prev = current;
          current = right[current];
        }
        
        right[prev] = right[current];
        current = right[current];
        
        --size;
      }
      
      return current + 1;
    }
};
```

Recursive linear implementation

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findTheWinner (int n, int k) {
      auto find = [&] (auto self, int x) -> int {
        if (x == 1)
          return 0;
        return (self(self, x - 1) + k) % x;
      };
      
      return find(find, n) + 1;
    }
};
```

Iterative linear implementation

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findTheWinner (int n, int k) {
      int ans = 0;
      
      for (int i = 1; i <= n; ++i)
        ans = (ans + k) % i;
      
      return ans + 1;
    }
};
```

<br>

### Statistics

- total accepted: 60136
- total submissions: 77952
- acceptance rate: 77.1%
- likes: 1616
- dislikes: 31

<br>

### Similar Problems

None
