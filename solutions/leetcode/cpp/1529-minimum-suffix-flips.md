# [1529] Minimum Suffix Flips

**[string, greedy]**

### Statement

You are given a **0-indexed** binary string `target` of length `n`. You have another binary string `s` of length `n` that is initially set to all zeros. You want to make `s` equal to `target`.

In one operation, you can pick an index `i` where `0 <= i < n` and flip all bits in the **inclusive** range `[i, n - 1]`. Flip means changing `'0'` to `'1'` and `'1'` to `'0'`.

Return *the minimum number of operations needed to make* `s` *equal to* `target`.


**Example 1:**

```

**Input:** target = "10111"
**Output:** 3
**Explanation:** Initially, s = "00000".
Choose index i = 2: "00000" -> "00111"
Choose index i = 0: "00111" -> "11000"
Choose index i = 1: "11000" -> "10111"
We need at least 3 flip operations to form target.

```

**Example 2:**

```

**Input:** target = "101"
**Output:** 3
**Explanation:** Initially, s = "000".
Choose index i = 0: "000" -> "111"
Choose index i = 1: "111" -> "100"
Choose index i = 2: "100" -> "101"
We need at least 3 flip operations to form target.

```

**Example 3:**

```

**Input:** target = "00000"
**Output:** 0
**Explanation:** We do not need any operations since the initial s already equals target.

```

**Constraints:**
* `n == target.length`
* `1 <= n <= 105`
* `target[i]` is either `'0'` or `'1'`.


<br>

### Hints

- Consider a strategy where the choice of bulb with number i is increasing. In such a strategy, you no longer need to worry about bulbs that have been set to the left.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int minFlips (string target) {
      int ans = 0;
      int cur = '0';
      
      for (char c: target) {
        if (cur != c) {
          cur = c;
          ++ans;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 34314
- total submissions: 47377
- acceptance rate: 72.4%
- likes: 703
- dislikes: 33

<br>

### Similar Problems

None
