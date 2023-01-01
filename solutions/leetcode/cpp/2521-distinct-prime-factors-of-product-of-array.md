# [2521] Distinct Prime Factors of Product of Array



### Statement

Given an array of positive integers `nums`, return *the number of **distinct prime factors** in the product of the elements of* `nums`.

**Note** that:

* A number greater than `1` is called **prime** if it is divisible by only `1` and itself.
* An integer `val1` is a factor of another integer `val2` if `val2 / val1` is an integer.


**Example 1:**

```

**Input:** nums = [2,4,3,7,10,6]
**Output:** 4
**Explanation:**
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.

```

**Example 2:**

```

**Input:** nums = [2,4,8,16]
**Output:** 1
**Explanation:**
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.

```

**Constraints:**
* `1 <= nums.length <= 104`
* `2 <= nums[i] <= 1000`


<br>

### Hints

- Do not multiply all the numbers together, as the product is too big to store.
- Think about how each individual number's prime factors contribute to the prime factors of the product of the entire array.
- Find the prime factors of each element in nums, and store all of them in a set to avoid duplicates.

<br>

### Solution

```cpp
class Solution {
  public:
    int distinctPrimeFactors (vector <int>& nums) {
      std::set <int> factors;
      
      for (int i: nums) {
        for (int j = 2; j * j <= i; ++j) {
          if (i % j == 0) {
            factors.insert(j);
            while (i % j == 0)
              i /= j;
          }
        }
        if (i != 1)
          factors.insert(i);
      }
      
      return factors.size();
    }
};
```

<br>

### Statistics

- total accepted: 9448
- total submissions: 20569
- acceptance rate: 45.9%
- likes: 81
- dislikes: 5

<br>

### Similar Problems

- [2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard) (Medium)
- [Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor) (Hard)
- [Closest Divisors](https://leetcode.com/problems/closest-divisors) (Medium)
- [Smallest Value After Replacing With Sum of Prime Factors](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors) (Medium)
