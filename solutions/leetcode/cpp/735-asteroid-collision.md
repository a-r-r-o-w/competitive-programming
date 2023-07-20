# [735] Asteroid Collision

**[array, stack, simulation]**

### Statement

We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


**Example 1:**

```

**Input:** asteroids = [5,10,-5]
**Output:** [5,10]
**Explanation:** The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

```

**Example 2:**

```

**Input:** asteroids = [8,-8]
**Output:** []
**Explanation:** The 8 and -8 collide exploding each other.

```

**Example 3:**

```

**Input:** asteroids = [10,2,-5]
**Output:** [10]
**Explanation:** The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

```

**Constraints:**
* `2 <= asteroids.length <= 10^4`
* `-1000 <= asteroids[i] <= 1000`
* `asteroids[i] != 0`


<br />

### Hints

- Say a row of asteroids is stable.  What happens when a new asteroid is added on the right?

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> asteroidCollision (vector <int>& asteroids) {
      std::vector <int> ans;
      
      for (int i: asteroids) {
        bool have = true;

        while (!ans.empty() and ans.back() > 0 and i < 0) {
          if (std::abs(ans.back() < std::abs(i))) {
            ans.pop_back();
            continue;
          }
          else if (std::abs(ans.back()) == std::abs(i))
            ans.pop_back();
          have = false;
          break;
        }

        if (have)
          ans.push_back(i);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 339528
- total submissions: 747007
- acceptance rate: 45.5%
- likes: 6378
- dislikes: 641

<br />

### Similar Problems

- [Can Place Flowers](https://leetcode.com/problems/can-place-flowers) (Easy)
- [Destroying Asteroids](https://leetcode.com/problems/destroying-asteroids) (Medium)
- [Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road) (Medium)
- [Robot Collisions](https://leetcode.com/problems/robot-collisions) (Hard)
