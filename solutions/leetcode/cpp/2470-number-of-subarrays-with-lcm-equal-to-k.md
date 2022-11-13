# [2470] Number of Subarrays With LCM Equal to K



### Statement

Given an integer array `nums` and an integer `k`, return *the number of **subarrays** of* `nums` *where the least common multiple of the subarray's elements is* `k`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

The **least common multiple of an array** is the smallest positive integer that is divisible by all the array elements.


**Example 1:**

```

**Input:** nums = [3,6,2,7,1], k = 6
**Output:** 4
**Explanation:** The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [**3**,**6**,2,7,1]
- [**3**,**6**,**2**,7,1]
- [3,**6**,2,7,1]
- [3,**6**,**2**,7,1]

```

**Example 2:**

```

**Input:** nums = [3], k = 2
**Output:** 0
**Explanation:** There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i], k <= 1000`


<br>

### Hints

- The constraints on nums.length are small. It is possible to check every subarray.
- To calculate LCM, you can use a built-in function or the formula lcm(a, b) = a * b / gcd(a, b).
- As you calculate the LCM of more numbers, it can only become greater. Once it becomes greater than k, you know that any larger subarrays containing all the current elements will not work.

<br>

### Solution

```cpp
class Solution {
  public:
    int subarrayLCM (vector <int>& nums, int k) {
      int n = nums.size();
      int count = 0;
      
      for (int i = 0; i < n; ++i) {
        int64_t lcm = 1;
        
        for (int j = i; j < n; ++j) {
          lcm = std::lcm(lcm, nums[j]);
          
          if (lcm > k)
            break;
          
          if (lcm == k)
            ++count;
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 11693
- total submissions: 31319
- acceptance rate: 37.3%
- likes: 131
- dislikes: 10

<br>

### Similar Problems

- [Number of Subarrays With GCD Equal to K](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k) (Medium)
