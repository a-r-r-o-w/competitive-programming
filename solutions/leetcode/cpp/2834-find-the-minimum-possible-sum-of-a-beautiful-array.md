# [2834] Find the Minimum Possible Sum of a Beautiful Array



### Statement

You are given positive integers `n` and `target`.

An array `nums` is **beautiful** if it meets the following conditions:

* `nums.length == n`.
* `nums` consists of pairwise **distinct** **positive** integers.
* There doesn't exist two **distinct** indices, `i` and `j`, in the range `[0, n - 1]`, such that `nums[i] + nums[j] == target`.



Return *the **minimum** possible sum that a beautiful array could have*.


**Example 1:**

```

**Input:** n = 2, target = 3
**Output:** 4
**Explanation:** We can see that nums = [1,3] is beautiful.
- The array nums has length n = 2.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 4 is the minimum possible sum that a beautiful array could have.

```

**Example 2:**

```

**Input:** n = 3, target = 3
**Output:** 8
**Explanation:** We can see that nums = [1,3,4] is beautiful.
- The array nums has length n = 3.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 8 is the minimum possible sum that a beautiful array could have.

```

**Example 3:**

```

**Input:** n = 1, target = 1
**Output:** 1
**Explanation:** We can see, that nums = [1] is beautiful.

```

**Constraints:**
* `1 <= n <= 10^5`
* `1 <= target <= 10^5`


<br />

### Hints

- <div class="_1l1MA">Greedily try to add the smallest possible number in the array <code>nums</code>, such that <code>nums</code> contains distinct positive integers, and there are no two indices <code>i</code> and <code>j</code> with <code>nums[i] + nums[j] == target</code>.</div>

<br />

### Solution

```cpp
class Solution {
  public:
    long long minimumPossibleSum(int n, int target) {
      int64_t ans = 0, value = 0;
      std::unordered_set <int64_t> have;
      
      while (n > 0) {
        ++value;
        if (have.count(target - value))
          continue;
        ans += value;
        have.insert(value);
        --n;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 22439
- total submissions: 48052
- acceptance rate: 46.7%
- likes: 169
- dislikes: 7

<br />

### Similar Problems

None
