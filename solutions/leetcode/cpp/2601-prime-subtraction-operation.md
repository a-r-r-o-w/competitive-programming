# [2601] Prime Subtraction Operation

**[array, math, binary-search, greedy, number-theory]**

### Statement

You are given a **0-indexed** integer array `nums` of length `n`.

You can perform the following operation as many times as you want:

* Pick an index `i` that you haven’t picked before, and pick a prime `p` **strictly less than** `nums[i]`, then subtract `p` from `nums[i]`.



Return *true if you can make `nums` a strictly increasing array using the above operation and false otherwise.*

A **strictly increasing array** is an array whose each element is strictly greater than its preceding element.


**Example 1:**

```

**Input:** nums = [4,9,6,10]
**Output:** true
**Explanation:** In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.
```

**Example 2:**

```

**Input:** nums = [6,8,11,12]
**Output:** true
**Explanation:** Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
```

**Example 3:**

```

**Input:** nums = [5,8,3]
**Output:** false
**Explanation:** It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`
* `nums.length == n`


<br />

### Hints

- Think about if we have many primes to subtract from nums[i]. Which prime is more optimal?
- The most optimal prime to subtract from nums[i] is the one that makes nums[i] the smallest as possible and greater than nums[i-1].

<br />

### Solution

```cpp
class Solution {
  public:
    bool primeSubOperation (vector <int>& nums) {
      const int max = 1001;
      std::bitset <max> sieve;
      std::vector <int> primes;

      sieve.set();
      sieve[0] = 0;
      sieve[1] = 0;

      for (int i = 2; i < max; ++i) {
        if (!sieve[i])
          continue;
        primes.push_back(i);
        for (int j = i * i; j < max; j += i)
          sieve[j] = 0;
      }

      auto lb = std::lower_bound(primes.begin(), primes.end(), nums[0]);
      if (lb != primes.begin()) {
        --lb;
        nums[0] -= *lb;
      }

      int n = nums.size();

      for (int i = 1; i < n; ++i) {
        int diff = nums[i] - nums[i - 1];
        if (diff <= 0)
          return false;
        lb = std::lower_bound(primes.begin(), primes.end(), diff);
        if (lb == primes.begin())
          continue;
        --lb;
        nums[i] -= *lb;
      }

      return true;
    }
};
```

<br />

### Statistics

- total accepted: 12254
- total submissions: 33303
- acceptance rate: 36.8%
- likes: 296
- dislikes: 29

<br />

### Similar Problems

None
