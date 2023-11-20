# [2028] Find Missing Observations

**[array, math, simulation]**

### Statement

You have observations of `n + m` **6-sided** dice rolls with each face numbered from `1` to `6`. `n` of the observations went missing, and you only have the observations of `m` rolls. Fortunately, you have also calculated the **average value** of the `n + m` rolls.

You are given an integer array `rolls` of length `m` where `rolls[i]` is the value of the `ith` observation. You are also given the two integers `mean` and `n`.

Return *an array of length* `n` *containing the missing observations such that the **average value** of the* `n + m` *rolls is **exactly*** `mean`. If there are multiple valid answers, return *any of them*. If no such array exists, return *an empty array*.

The **average value** of a set of `k` numbers is the sum of the numbers divided by `k`.

Note that `mean` is an integer, so the sum of the `n + m` rolls should be divisible by `n + m`.


**Example 1:**

```

**Input:** rolls = [3,2,4,3], mean = 4, n = 2
**Output:** [6,6]
**Explanation:** The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

```

**Example 2:**

```

**Input:** rolls = [1,5,6], mean = 3, n = 4
**Output:** [2,3,2,2]
**Explanation:** The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

```

**Example 3:**

```

**Input:** rolls = [1,2,3,4], mean = 6, n = 4
**Output:** []
**Explanation:** It is impossible for the mean to be 6 no matter what the 4 missing rolls are.

```

**Constraints:**
* `m == rolls.length`
* `1 <= n, m <= 105`
* `1 <= rolls[i], mean <= 6`


<br>

### Hints

- What should the sum of the n rolls be?
- Could you generate an array of size n such that each element is between 1 and 6?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    vector <int> missingRolls (vector <int>& rolls, int mean, int n) {
      int sum = std::accumulate(rolls.begin(), rolls.end(), 0), m = rolls.size();
      int required = mean * (n + m) - sum;

      if (required < n or required > 6 * n)
        return {};
      
      std::vector <int> x (n, 1);
      required -= n;

      for (int i = 0; i < n and required > 0; ++i) {
        int m = std::min(6 - x[i], required);
        x[i] += m;
        required -= m;
      }

      return x;
    }
};
```

<br>

### Statistics

- total accepted: 18433
- total submissions: 41735
- acceptance rate: 44.2%
- likes: 340
- dislikes: 19

<br>

### Similar Problems

- [Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum) (Medium)
- [Dice Roll Simulation](https://leetcode.com/problems/dice-roll-simulation) (Hard)
