# [2327] Number of People Aware of a Secret

**[dynamic-programming, queue, simulation]**

### Statement

On day `1`, one person discovers a secret.

You are given an integer `delay`, which means that each person will **share** the secret with a new person **every day**, starting from `delay` days after discovering the secret. You are also given an integer `forget`, which means that each person will **forget** the secret `forget` days after discovering it. A person **cannot** share the secret on the same day they forgot it, or on any day afterwards.

Given an integer `n`, return *the number of people who know the secret at the end of day* `n`. Since the answer may be very large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** n = 6, delay = 2, forget = 4
**Output:** 5
**Explanation:**
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)

```

**Example 2:**

```

**Input:** n = 4, delay = 1, forget = 3
**Output:** 6
**Explanation:**
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)

```

**Constraints:**
* `2 <= n <= 1000`
* `1 <= delay < forget <= n`


<br />

### Hints

- Let dp[i][j] be the number of people who have known the secret for exactly j + 1 days, at day i.
- If j > 0, dp[i][j] = dp[i – 1][j – 1].
- dp[i][0] = sum(dp[i – 1][j]) for j in [delay – 1, forget – 2].

<br />

### Solution

O(N^2)

```cpp
class Solution {
  public:
    int peopleAwareOfSecret (int n, int delay, int forget) {
      constexpr int mod = 1000000007;
      std::vector <int64_t> dp (n + 1);
      dp[1] = 1;

      for (int i = 2; i <= n; ++i) {
        for (int j = i - delay; j >= std::max(1, i - forget + 1); --j)
          dp[i] += dp[j];
        dp[i] %= mod;
      }

      int64_t sum = 0;
      for (int j = n; j >= std::max(1, n - forget + 1); --j) {
        sum += dp[j];
        sum %= mod;
      }

      return sum;
    }
};
```

O(N)

```cpp
class Solution {
  public:
    int peopleAwareOfSecret (int n, int delay, int forget) {
      constexpr int mod = 1000000007;
      std::vector <int64_t> dp (n + 1);
      int64_t window = 0;
      
      dp[1] = 1;

      for (int i = 2; i <= n; ++i) {
        if (i - delay >= 0)
          window += dp[i - delay];
        if (i - forget >= 0)
          window -= dp[i - forget];
        window = (window + mod) % mod;
        dp[i] = window;
      }

      int64_t sum = 0;
      for (int j = n; j >= n - forget + 1; --j) {
        sum += dp[j];
        sum %= mod;
      }

      return sum;
    }
};
```

<br />

### Statistics

- total accepted: 16270
- total submissions: 36199
- acceptance rate: 44.9%
- likes: 619
- dislikes: 100

<br />

### Similar Problems

None
