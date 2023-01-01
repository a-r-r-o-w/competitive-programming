# [2523] Closest Prime Numbers in Range



### Statement

Given two positive integers `left` and `right`, find the two integers `num1` and `num2` such that:

* `left <= nums1 < nums2 <= right` .
* `nums1` and `nums2` are both **prime** numbers.
* `nums2 - nums1` is the **minimum** amongst all other pairs satisfying the above conditions.



Return *the positive integer array* `ans = [nums1, nums2]`. *If there are multiple pairs satisfying these conditions, return the one with the minimum* `nums1` *value or* `[-1, -1]` *if such numbers do not exist.*

A number greater than `1` is called **prime** if it is only divisible by `1` and itself.


**Example 1:**

```

**Input:** left = 10, right = 19
**Output:** [11,13]
**Explanation:** The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

```

**Example 2:**

```

**Input:** left = 4, right = 6
**Output:** [-1,-1]
**Explanation:** There exists only one prime number in the given range, so the conditions cannot be satisfied.

```

**Constraints:**
* `1 <= left <= right <= 106`


.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}


<br>

### Hints

- Use Sieve of Eratosthenes to mark numbers that are primes.
- Iterate from right to left and find pair with the minimum distance between marked numbers.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> closestPrimes (int left, int right) {
      constexpr int max = 1000000 + 420;
      
      std::vector <int> primes;
      std::vector <bool> sieve (max, true);
      
      sieve[0] = false;
      sieve[1] = false;
      
      for (int i = 2; i < max; ++i) {
        if (sieve[i]) {
          primes.push_back(i);
          for (int j = 2 * i; j < max; j += i)
            sieve[j] = false;
        }
      }
      
      int l = std::lower_bound(primes.begin(), primes.end(), left) - primes.begin();
      int r = std::upper_bound(primes.begin(), primes.end(), right) - primes.begin() - 1;
      int a = -max, b = max;
      
      for (int i = l; i < r; ++i) {
        if (primes[i + 1] - primes[i] < b - a) {
          a = primes[i];
          b = primes[i + 1];
        }
      }
      
      if (a == -max) {
        a = -1;
        b = -1;
      }
      
      return {a, b};
    }
};
```

<br>

### Statistics

- total accepted: 7045
- total submissions: 20472
- acceptance rate: 34.4%
- likes: 88
- dislikes: 8

<br>

### Similar Problems

- [Count Ways to Make Array With Product](https://leetcode.com/problems/count-ways-to-make-array-with-product) (Hard)
