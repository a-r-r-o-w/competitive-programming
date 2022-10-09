# [1760] Minimum Limit of Balls in a Bag

**[array, binary-search]**

### Statement

You are given an integer array `nums` where the `ith` bag contains `nums[i]` balls. You are also given an integer `maxOperations`.

You can perform the following operation at most `maxOperations` times:

* Take any bag of balls and divide it into two new bags with a **positive** number of balls.
	+ For example, a bag of `5` balls can become two new bags of `1` and `4` balls, or two new bags of `2` and `3` balls.



Your penalty is the **maximum** number of balls in a bag. You want to **minimize** your penalty after the operations.

Return *the minimum possible penaltyafter performing the operations*.


**Example 1:**

```

**Input:** nums = [9], maxOperations = 2
**Output:** 3
**Explanation:** 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [**9**] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [**6**,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.

```

**Example 2:**

```

**Input:** nums = [2,4,8,2], maxOperations = 4
**Output:** 2
**Explanation:**
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,**8**,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,**4**,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,**4**,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,**4**,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2 an you should return 2.

```

**Example 3:**

```

**Input:** nums = [7,17], maxOperations = 2
**Output:** 7

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= maxOperations, nums[i] <= 109`


<br>

### Hints

- Let's change the question if we know the maximum size of a bag what is the minimum number of bags you can make
- note that as the maximum size increases the minimum number of bags decreases so we can binary search the maximum size

<br>

### Solution

```cpp
namespace arrow {
  template <typename T, typename Predicate>
  std::enable_if_t <std::is_integral_v <T>, T> binary_search (T low, T high, Predicate&& predicate) {
    while (low < high) {
      T mid = (low + high) / 2;
      if (predicate(mid))
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }
  
  template <typename T, typename Predicate>
  std::enable_if_t <std::is_floating_point_v <T>, T> binary_search (T low, T high, Predicate&& predicate) {
    for (int i = 0; i < 100; ++i) {
      long double mid = (low + high) / 2;
      if (predicate(mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
}

class Solution {
  public:
    int minimumSize (vector <int>& nums, int maxOperations) {
      return arrow::binary_search <int> (1, 1e9 + 42, [&] (int x) {
        int need = 0;
        for (int n: nums)
          need += (n + x - 1) / x - 1;
        return need > maxOperations;
      });
    }
};
```

<br>

### Statistics

- total accepted: 21890
- total submissions: 36792
- acceptance rate: 59.5%
- likes: 1225
- dislikes: 38

<br>

### Similar Problems

- [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children) (Medium)
- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
