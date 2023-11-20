# [2126] Destroying Asteroids

**[array, greedy, sorting]**

### Statement

You are given an integer `mass`, which represents the original mass of a planet. You are further given an integer array `asteroids`, where `asteroids[i]` is the mass of the `i^th` asteroid.

You can arrange for the planet to collide with the asteroids in **any arbitrary order**. If the mass of the planet is **greater than or equal to** the mass of the asteroid, the asteroid is **destroyed** and the planet **gains** the mass of the asteroid. Otherwise, the planet is destroyed.

Return `true` *if **all** asteroids can be destroyed. Otherwise, return* `false`*.*
**Example 1:**

```

**Input:** mass = 10, asteroids = [3,9,19,5,21]
**Output:** true
**Explanation:** One way to order the asteroids is [9,19,5,3,21]:
- The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
- The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
- The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
- The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
- The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
All asteroids are destroyed.

```

**Example 2:**

```

**Input:** mass = 5, asteroids = [4,9,23,4]
**Output:** false
**Explanation:** 
The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
This is less than 23, so a collision would not destroy the last asteroid.
```

**Constraints:**
* `1 <= mass <= 10^5`
* `1 <= asteroids.length <= 10^5`
* `1 <= asteroids[i] <= 10^5`


<br />

### Hints

- Choosing the asteroid to collide with can be done greedily.
- If an asteroid will destroy the planet, then every bigger asteroid will also destroy the planet.
- You only need to check the smallest asteroid at each collision. If it will destroy the planet, then every other asteroid will also destroy the planet.
- Sort the asteroids in non-decreasing order by mass, then greedily try to collide with the asteroids in that order.

<br />

### Solution

```cpp
class Solution {
  public:
    bool asteroidsDestroyed (int mass, vector <int>& asteroids) {
      int64_t have = mass;
      int n = asteroids.size();

      std::sort(asteroids.begin(), asteroids.end());

      for (int i = 0; i < n; ++i) {
        if (have < asteroids[i])
          return false;
        have += asteroids[i];
      }

      return true;
    }
};
```

<br />

### Statistics

- total accepted: 26616
- total submissions: 53339
- acceptance rate: 49.9%
- likes: 347
- dislikes: 150

<br />

### Similar Problems

- [Asteroid Collision](https://leetcode.com/problems/asteroid-collision) (Medium)
