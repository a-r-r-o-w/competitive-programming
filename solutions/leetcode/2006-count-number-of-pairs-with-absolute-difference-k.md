# [2006] Count Number of Pairs With Absolute Difference K

**[array, hash-table, counting]**

### Statement

Given an integer array `nums` and an integer `k`, return *the number of pairs* `(i, j)` *where* `i < j` *such that* `|nums[i] - nums[j]| == k`.

The value of `|x|` is defined as:

* `x` if `x >= 0`.
* `-x` if `x < 0`.


**Example 1:**

```

**Input:** nums = [1,2,2,1], k = 1
**Output:** 4
**Explanation:** The pairs with an absolute difference of 1 are:
- [**1**,**2**,2,1]
- [**1**,2,**2**,1]
- [1,**2**,2,**1**]
- [1,2,**2**,**1**]

```

**Example 2:**

```

**Input:** nums = [1,3], k = 3
**Output:** 0
**Explanation:** There are no pairs with an absolute difference of 3.

```

**Example 3:**

```

**Input:** nums = [3,2,1,5,4], k = 2
**Output:** 3
**Explanation:** The pairs with an absolute difference of 2 are:
- [**3**,2,**1**,5,4]
- [**3**,2,1,**5**,4]
- [3,**2**,1,5,**4**]

```

**Constraints:**
* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 100`
* `1 <= k <= 99`


<br>

### Hints

- Can we check every possible pair?
- Can we use a nested for loop to solve this problem?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countKDifference (vector <int>& nums, int k) {
      int n = nums.size();
      int ans = 0;
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n; ++i) {
        auto lb = std::lower_bound(nums.begin(), nums.end(), nums[i] + k);
        
        if (lb == nums.end())
          break;
        
        auto ub = std::upper_bound(nums.begin(), nums.end(), nums[i] + k);
        
        ans += ub - lb;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 63918
- total submissions: 77767
- acceptance rate: 82.2%
- likes: 834
- dislikes: 17

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array) (Medium)
- [Finding Pairs With a Certain Sum](https://leetcode.com/problems/finding-pairs-with-a-certain-sum) (Medium)
- [Count Equal and Divisible Pairs in an Array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array) (Easy)
- [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs) (Medium)
