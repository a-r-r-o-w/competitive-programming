# [2644] Find the Maximum Divisibility Score

**[array]**

### Statement

You are given two **0-indexed** integer arrays `nums` and `divisors`.

The **divisibility score** of `divisors[i]` is the number of indices `j` such that `nums[j]` is divisible by `divisors[i]`.

Return *the integer* `divisors[i]` *with the maximum divisibility score*. If there is more than one integer with the maximum score, return the minimum of them.


**Example 1:**

```

**Input:** nums = [4,7,9,3,9], divisors = [5,2,3]
**Output:** 3
**Explanation:** The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 0 since no number in nums is divisible by 5.
The divisibility score of divisors[1] is 1 since nums[0] is divisible by 2.
The divisibility score of divisors[2] is 3 since nums[2], nums[3], and nums[4] are divisible by 3.
Since divisors[2] has the maximum divisibility score, we return it.

```

**Example 2:**

```

**Input:** nums = [20,14,21,10], divisors = [5,7,5]
**Output:** 5
**Explanation:** The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 2 since nums[0] and nums[3] are divisible by 5.
The divisibility score of divisors[1] is 2 since nums[1] and nums[2] are divisible by 7.
The divisibility score of divisors[2] is 2 since nums[0] and nums[3] are divisible by 5.
Since divisors[0], divisors[1], and divisors[2] all have the maximum divisibility score, we return the minimum of them (i.e., divisors[2]).

```

**Example 3:**

```

**Input:** nums = [12], divisors = [10,16]
**Output:** 10
**Explanation:** The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 0 since no number in nums is divisible by 10.
The divisibility score of divisors[1] is 0 since no number in nums is divisible by 16.
Since divisors[0] and divisors[1] both have the maximum divisibility score, we return the minimum of them (i.e., divisors[0]).

```

**Constraints:**
* `1 <= nums.length, divisors.length <= 1000`
* `1 <= nums[i], divisors[i] <= 10^9`


<br />

### Hints

- Consider counting for each element in divisors the count of elements in nums divisible by it using bruteforce.
- After counting for each divisor, take the one with the maximum count. In case of a tie, take the minimum one of them.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxDivScore (vector <int>& nums, vector <int>& divisors) {
      int max = -1, which = 1 << 30;
      for (int i: divisors) {
        int count = 0;
        for (int j: nums) {
          if (j % i == 0)
            ++count;
        }
        if (count > max) {
          max = count;
          which = i;
        }
        else if (count == max)
          which = std::min(which, i);
      }

      return which;
    }
};
```

<br />

### Statistics

- total accepted: 20960
- total submissions: 43185
- acceptance rate: 48.5%
- likes: 106
- dislikes: 31

<br />

### Similar Problems

- [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5) (Easy)
