# [2206] Divide Array Into Equal Pairs

**[array, hash-table, bit-manipulation, counting]**

### Statement

You are given an integer array `nums` consisting of `2 * n` integers.

You need to divide `nums` into `n` pairs such that:

* Each element belongs to **exactly one** pair.
* The elements present in a pair are **equal**.



Return `true` *if nums can be divided into* `n` *pairs, otherwise return* `false`.


**Example 1:**

```

**Input:** nums = [3,2,3,2,2,2]
**Output:** true
**Explanation:** 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.

```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** false
**Explanation:** 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.

```

**Constraints:**
* `nums.length == 2 * n`
* `1 <= n <= 500`
* `1 <= nums[i] <= 500`


<br>

### Hints

- For any number x in the range [1, 500], count the number of elements in nums whose values are equal to x.
- The elements with equal value can be divided completely into pairs if and only if their count is even.

<br>

### Solution

```cpp
class Solution {
  public:
    bool divideArray (vector <int>& nums) {
      const int max = 501;
      std::vector <int> freq (max);
      
      for (int i: nums)
        ++freq[i];
      
      for (int i = 0; i < max; ++i)
        if (freq[i] & 1)
          return false;
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 40973
- total submissions: 54840
- acceptance rate: 74.7%
- likes: 389
- dislikes: 14

<br>

### Similar Problems

- [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) (Easy)
