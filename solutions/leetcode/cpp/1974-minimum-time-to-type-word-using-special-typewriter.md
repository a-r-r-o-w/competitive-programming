# [1974] Minimum Time to Type Word Using Special Typewriter

**[string, greedy]**

### Statement

There is a special typewriter with lowercase English letters `'a'` to `'z'` arranged in a **circle** with a **pointer**. A character can **only** be typed if the pointer is pointing to that character. The pointer is **initially** pointing to the character `'a'`.
![](https://assets.leetcode.com/uploads/2021/07/31/chart.jpg)
Each second, you may perform one of the following operations:

* Move the pointer one character **counterclockwise** or **clockwise**.
* Type the character the pointer is **currently** on.



Given a string `word`, return the **minimum** number of seconds to type out the characters in `word`.


**Example 1:**

```

**Input:** word = "abc"
**Output:** 5
**Explanation:**The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.

```

**Example 2:**

```

**Input:** word = "bza"
**Output:** 7
**Explanation:**The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.

```

**Example 3:**

```

**Input:** word = "zjpc"
**Output:** 34
**Explanation:**
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.

```

**Constraints:**
* `1 <= word.length <= 100`
* `word` consists of lowercase English letters.


<br>

### Hints

- There are only two possible directions you can go when you move to the next letter.
- When moving to the next letter, you will always go in the direction that takes the least amount of time.

<br>

### Solution

```cpp
class Solution {
  public:
    int minTimeToType (string word) {
      int x = 0;
      int time = 0;
      
      for (char c: word) {
        c -= 'a';
        time += std::min(std::abs(c - x), 26 - std::abs(c - x));
        x = c;
      }
      
      return time + word.length();
    }
};
```

<br>

### Statistics

- total accepted: 26360
- total submissions: 36893
- acceptance rate: 71.4%
- likes: 461
- dislikes: 18

<br>

### Similar Problems

- [Minimum Distance to Type a Word Using Two Fingers](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers) (Hard)
