# [837] New 21 Game

**[math, dynamic-programming, sliding-window, probability-and-statistics]**

### Statement

Alice plays the following game, loosely based on the card game **"21"**.

Alice starts with `0` points and draws numbers while she has less than `k` points. During each draw, she gains an integer number of points randomly from the range `[1, maxPts]`, where `maxPts` is an integer. Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets `k` **or more points**.

Return the probability that Alice has `n` or fewer points.

Answers within `10^-5` of the actual answer are considered accepted.


**Example 1:**

```

**Input:** n = 10, k = 1, maxPts = 10
**Output:** 1.00000
**Explanation:** Alice gets a single card, then stops.

```

**Example 2:**

```

**Input:** n = 6, k = 1, maxPts = 10
**Output:** 0.60000
**Explanation:** Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.

```

**Example 3:**

```

**Input:** n = 21, k = 17, maxPts = 10
**Output:** 0.73278

```

**Constraints:**
* `0 <= k <= n <= 10^4`
* `1 <= maxPts <= 10^4`


<br />

### Hints

None

<br />

### Solution

Segment Tree

```cpp
class Solution {
  public:
    double new21Game (int n, int k, int maxPts) {
      struct node {
        double value = 0;
        double lazy = 0;
        bool prop = false;
      };

      const double eps = 1e-6;
      std::vector <node> dp (4 * (n + 1));

      auto push = [&] (int v, int tl, int tr, int tm) {
        if (not dp[v].prop)
          return;
        dp[2 * v + 1].value += (tm - tl + 1) * dp[v].lazy;
        dp[2 * v + 2].value += (tr - tm) * dp[v].lazy;
        dp[2 * v + 1].lazy += dp[v].lazy;
        dp[2 * v + 2].lazy += dp[v].lazy;
        dp[2 * v + 1].prop = true;
        dp[2 * v + 2].prop = true;
        dp[v].lazy = 0;
        dp[v].prop = false;
      };

      auto update = [&] (auto self, int v, int tl, int tr, int l, int r, double val) -> void {
        if (l > r)
          return;
        if (tl == l and tr == r) {
          dp[v].value += (tr - tl + 1) * val;
          dp[v].lazy += val;
          dp[v].prop = true;
          return;
        }
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        self(self, 2 * v + 1, tl, tm, l, std::min(r, tm), val);
        self(self, 2 * v + 2, tm + 1, tr, std::max(l, tm + 1), r, val);
        dp[v].value = dp[2 * v + 1].value + dp[2 * v + 2].value;
      };

      auto query = [&] (auto self, int v, int tl, int tr, int l, int r) -> double {
        if (l > r)
          return 0;
        if (tl == l and tr == r)
          return dp[v].value;
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        double lchild = self(self, 2 * v + 1, tl, tm, l, std::min(r, tm));
        double rchild = self(self, 2 * v + 2, tm + 1, tr, std::max(l, tm + 1), r);
        return lchild + rchild;
      };

      update(update, 0, 0, n, 0, 0, 1);

      for (int i = 0; i < k; ++i) {
        double val = query(query, 0, 0, n, i, i);
        update(update, 0, 0, n, i + 1, std::min(i + maxPts, n), val / maxPts);
      }

      return query(query, 0, 0, n, k, n);
    }
};
```

DP

```cpp
class Solution {
  public:
    double new21Game (int n, int k, int maxPts) {
      std::vector <double> dp (n + 1);
      double sum = 0;

      dp[0] = 1;
      if (k > 0)
        sum = 1;
      
      for (int i = 1; i <= n; ++i) {
        dp[i] = sum / maxPts;
        if (i < k)
          sum += dp[i];
        if (i - maxPts >= 0 and i - maxPts < k)
          sum -= dp[i - maxPts];
      }

      double ans = 0;
      for (int i = k; i <= n; ++i)
        ans += dp[i];
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 44731
- total submissions: 112880
- acceptance rate: 39.6%
- likes: 1389
- dislikes: 1032

<br />

### Similar Problems

None
