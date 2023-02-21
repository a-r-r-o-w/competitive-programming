# [2568] Minimum Impossible OR



### Statement

You are given a **0-indexed**integer array `nums`.

We say that an integer x is **expressible** from `nums` if there exist some integers `0 <= index1 < index2 < ... < indexk < nums.length` for which `nums[index1] | nums[index2] | ... | nums[indexk] = x`. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of `nums`.

Return *the minimum **positive non-zero integer**that is not* *expressible from* `nums`.


**Example 1:**

```

**Input:** nums = [2,1]
**Output:** 4
**Explanation:** 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.

```

**Example 2:**

```

**Input:** nums = [5,3,2]
**Output:** 1
**Explanation:** We can show that 1 is the smallest number that is not expressible.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^9`


<br />

### Hints

- Think about forming numbers in the powers of 2 using their bit representation.
- The minimum power of 2 not present in the array will be the first number that could not be expressed using the given operation.

<br />

### Solution

```cpp
class Solution {
  public:
    int minImpossibleOR (vector <int>& nums) {
      int n = nums.size();
      std::vector <bool> have (31);
      
      for (int i = 0; i < n; ++i) {
        if ((nums[i] & (nums[i] - 1)) == 0)
          have[__builtin_ctz(nums[i])] = true;
      }
      
      for (int i = 0; i < 31; ++i) {
        if (!have[i])
          return 1 << i;
      }
      
      return -1;
    }
};
```

<br />

### Statistics

- total accepted: 7217
- total submissions: 13942
- acceptance rate: 51.8%
- likes: 107
- dislikes: 6

<br />

### Similar Problems

None
