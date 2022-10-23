# [2447] Number of Subarrays With GCD Equal to K



### Statement

Given an integer array `nums` and an integer `k`, return *the number of **subarrays** of* `nums` *where the greatest common divisor of the subarray's elements is* `k`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

The **greatest common divisor of an array** is the largest integer that evenly divides all the array elements.


**Example 1:**

```

**Input:** nums = [9,3,1,2,6,3], k = 3
**Output:** 4
**Explanation:** The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
- [9,**3**,1,2,6,3]
- [9,3,1,2,6,**3**]
- [**9,3**,1,2,6,3]
- [9,3,1,2,**6,3**]

```

**Example 2:**

```

**Input:** nums = [4], k = 7
**Output:** 0
**Explanation:** There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i], k <= 109`


<br>

### Hints

- The constraints on nums.length are small. It is possible to check every subarray.
- To calculate GCD, you can use a built-in function or the Euclidean Algorithm.

<br>

### Solution

```cpp
class Solution {
  public:
    int subarrayGCD (vector <int>& nums, int k) {
      int count = 0;
      int n = nums.size();
      
      for (int l = 0; l < n; ++l) {
        int gcd = 0;
        
        for (int r = l; r < n; ++r) {
          gcd = std::gcd(gcd, nums[r]);
          
          if (gcd < k)
            break;
          if (gcd == k)
            ++count;
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 11095
- total submissions: 25319
- acceptance rate: 43.8%
- likes: 105
- dislikes: 36

<br>

### Similar Problems

- [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array) (Easy)
