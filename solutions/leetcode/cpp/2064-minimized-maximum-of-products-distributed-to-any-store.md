# [2064] Minimized Maximum of Products Distributed to Any Store

**[array, binary-search]**

### Statement

You are given an integer `n` indicating there are `n` specialty retail stores. There are `m` product types of varying amounts, which are given as a **0-indexed** integer array `quantities`, where `quantities[i]` represents the number of products of the `ith` product type.

You need to distribute **all products** to the retail stores following these rules:

* A store can only be given **at most one product type** but can be given **any** amount of it.
* After distribution, each store will have been given some number of products (possibly `0`). Let `x` represent the maximum number of products given to any store. You want `x` to be as small as possible, i.e., you want to **minimize** the **maximum** number of products that are given to any store.



Return *the minimum possible* `x`.


**Example 1:**

```

**Input:** n = 6, quantities = [11,6]
**Output:** 3
**Explanation:** One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

```

**Example 2:**

```

**Input:** n = 7, quantities = [15,10,10]
**Output:** 5
**Explanation:** One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

```

**Example 3:**

```

**Input:** n = 1, quantities = [100000]
**Output:** 100000
**Explanation:** The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.

```

**Constraints:**
* `m == quantities.length`
* `1 <= m <= n <= 105`
* `1 <= quantities[i] <= 105`


<br>

### Hints

- There exists a monotonic nature such that when x is smaller than some number, there will be no way to distribute, and when x is not smaller than that number, there will always be a way to distribute.
- If you are given a number k, where the number of products given to any store does not exceed k, could you determine if all products can be distributed?
- Implement a function canDistribute(k), which returns true if you can distribute all products such that any store will not be given more than k products, and returns false if you cannot. Use this function to binary search for the smallest possible k.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimizedMaximum (int n, vector <int>& quantities) {
      int q = quantities.size();
      int low = 1, high = 1e9;

      auto cost = [&] (int x) {
        int have = 0;
        for (int i = 0; i < q; ++i)
          have += (quantities[i] + x - 1) / x;
        return have > n;
      };

      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }

      return low;
    }
};
```

<br>

### Statistics

- total accepted: 17497
- total submissions: 34934
- acceptance rate: 50.1%
- likes: 666
- dislikes: 25

<br>

### Similar Problems

- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas) (Medium)
- [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days) (Medium)
- [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children) (Medium)
- [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold) (Medium)
- [Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls) (Medium)
- [Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag) (Medium)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)
- [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget) (Hard)
