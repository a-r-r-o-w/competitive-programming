# [2483] Minimum Penalty for a Shop



### Statement

You are given the customer visit log of a shop represented by a **0-indexed** string `customers` consisting only of characters `'N'` and `'Y'`:

* if the `ith` character is `'Y'`, it means that customers come at the `ith` hour
* whereas `'N'` indicates that no customers come at the `ith` hour.



If the shop closes at the `jth` hour (`0 <= j <= n`), the **penalty** is calculated as follows:

* For every hour when the shop is open and no customers come, the penalty increases by `1`.
* For every hour when the shop is closed and customers come, the penalty increases by `1`.



Return *the **earliest** hour at which the shop must be closed to incur a **minimum** penalty.*
**Note** that if a shop closes at the `jth` hour, it means the shop is closed at the hour `j`.


**Example 1:**

```

**Input:** customers = "YYNY"
**Output:** 2
**Explanation:** 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

```

**Example 2:**

```

**Input:** customers = "NNNNN"
**Output:** 0
**Explanation:** It is best to close the shop at the 0th hour as no customers arrive.
```

**Example 3:**

```

**Input:** customers = "YYYY"
**Output:** 4
**Explanation:** It is best to close the shop at the 4th hour as customers arrive at each hour.

```

**Constraints:**
* `1 <= customers.length <= 105`
* `customers` consists only of characters `'Y'` and `'N'`.


<br>

### Hints

- At any index, the penalty is the sum of prefix count of ‘N’ and suffix count of ‘Y’.
- Enumerate all indices and find the minimum such value.

<br>

### Solution

```cpp
class Solution {
  public:
    int bestClosingTime (string customers) {
      int n = customers.length();
      std::vector <int> pref (n + 1), suff (n + 1);
      
      for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + (customers[i] == 'N');
      for (int i = n - 1; i >= 0; --i)
        suff[i] = suff[i + 1] + (customers[i] == 'Y');
      
      int ans = 1 << 30, index = -1;
      
      for (int i = 0; i <= n; ++i) {
        int penalty = pref[i] + suff[i];
        if (penalty < ans) {
          ans = penalty;
          index = i;
        }
      }
      
      return index;
    }
};
```

<br>

### Statistics

- total accepted: 7817
- total submissions: 15016
- acceptance rate: 52.1%
- likes: 120
- dislikes: 1

<br>

### Similar Problems

- [Grid Game](https://leetcode.com/problems/grid-game) (Medium)
