# [2582] Pass the Pillow



### Statement

There are `n` people standing in a line labeled from `1` to `n`. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

* For example, once the pillow reaches the `n^th` person they pass it to the `n - 1^th` person, then to the `n - 2^th` person and so on.



Given the two positive integers `n` and `time`, return *the index of the person holding the pillow after* `time` *seconds*.

**Example 1:**

```

**Input:** n = 4, time = 5
**Output:** 2
**Explanation:** People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Afer five seconds, the pillow is given to the 2^nd person.

```

**Example 2:**

```

**Input:** n = 3, time = 2
**Output:** 3
**Explanation:** People pass the pillow in the following way: 1 -> 2 -> 3.
Afer two seconds, the pillow is given to the 3^r^d person.

```

**Constraints:**
* `2 <= n <= 1000`
* `1 <= time <= 1000`


<br />

### Hints

- Maintain two integer variables, direction and i, where direction denotes the current direction in which the pillow should pass, and i denotes an index of the person holding the pillow.
- While time is positive, update the current index with the current direction. If the index reaches the end of the line, multiply direction by - 1.

<br />

### Solution

```cpp
class Solution {
  public:
    int passThePillow (int n, int time) {
      int rounds = time / (n - 1);
      time %= n - 1;
      return rounds % 2 == 0 ? 1 + time : n - time;
    }
};
```

<br />

### Statistics

- total accepted: 13110
- total submissions: 29351
- acceptance rate: 44.7%
- likes: 82
- dislikes: 4

<br />

### Similar Problems

- [Find the Student that Will Replace the Chalk](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk) (Medium)
