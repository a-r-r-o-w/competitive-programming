# [2525] Categorize Box According to Criteria



### Statement

Given four integers `length`, `width`, `height`, and `mass`, representing the dimensions and mass of a box, respectively, return *a string representing the **category** of the box*.

* The box is `"Bulky"` if:
	+ **Any** of the dimensions of the box is greater or equal to `104`.
	+ Or, the **volume** of the box is greater or equal to `109`.
* If the mass of the box is greater or equal to `100`, it is `"Heavy".`
* If the box is both `"Bulky"` and `"Heavy"`, then its category is `"Both"`.
* If the box is neither `"Bulky"` nor `"Heavy"`, then its category is `"Neither"`.
* If the box is `"Bulky"` but not `"Heavy"`, then its category is `"Bulky"`.
* If the box is `"Heavy"` but not `"Bulky"`, then its category is `"Heavy"`.


**Note** that the volume of the box is the product of its length, width and height.


**Example 1:**

```

**Input:** length = 1000, width = 35, height = 700, mass = 300
**Output:** "Heavy"
**Explanation:** 
None of the dimensions of the box is greater or equal to 104. 
Its volume = 24500000 <= 109. So it cannot be categorized as "Bulky".
However mass >= 100, so the box is "Heavy".
Since the box is not "Bulky" but "Heavy", we return "Heavy".
```

**Example 2:**

```

**Input:** length = 200, width = 50, height = 800, mass = 50
**Output:** "Neither"
**Explanation:** 
None of the dimensions of the box is greater or equal to 104.
Its volume = 8 * 106 <= 109. So it cannot be categorized as "Bulky".
Its mass is also less than 100, so it cannot be categorized as "Heavy" either. 
Since its neither of the two above categories, we return "Neither".
```

**Constraints:**
* `1 <= length, width, height <= 105`
* `1 <= mass <= 103`


<br>

### Hints

- Use conditional statements to find the right category of the box.

<br>

### Solution

```cpp
class Solution {
  public:
    string categorizeBox (int length, int width, int height, int mass) {
      bool bulky = false, heavy = false;
      
      if (length >= 10000 or width >= 10000 or height >= 10000)
        bulky = true;
      if (int64_t(length) * width * height >= 1000000000)
        bulky = true;
      if (mass >= 100)
        heavy = true;
      
      if (bulky and heavy)
        return "Both";
      else if (bulky)
        return "Bulky";
      else if (heavy)
        return "Heavy";
      return "Neither";
    }
};
```

<br>

### Statistics

- total accepted: 12313
- total submissions: 42065
- acceptance rate: 29.3%
- likes: 11
- dislikes: 0

<br>

### Similar Problems

- [Fizz Buzz](https://leetcode.com/problems/fizz-buzz) (Easy)
- [Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game) (Easy)
- [Best Poker Hand](https://leetcode.com/problems/best-poker-hand) (Easy)
