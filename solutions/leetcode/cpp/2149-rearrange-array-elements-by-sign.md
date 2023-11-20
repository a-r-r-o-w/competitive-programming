# [2149] Rearrange Array Elements by Sign

**[array, two-pointers, simulation]**

### Statement

You are given a **0-indexed** integer array `nums` of **even** length consisting of an **equal** number of positive and negative integers.

You should **rearrange** the elements of `nums` such that the modified array follows the given conditions:

1. Every **consecutive pair** of integers have **opposite signs**.
2. For all integers with the same sign, the **order** in which they were present in `nums` is **preserved**.
3. The rearranged array begins with a positive integer.



Return *the modified array after rearranging the elements to satisfy the aforementioned conditions*.


**Example 1:**

```

**Input:** nums = [3,1,-2,-5,2,-4]
**Output:** [3,-2,1,-5,2,-4]
**Explanation:**
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

```

**Example 2:**

```

**Input:** nums = [-1,1]
**Output:** [1,-1]
**Explanation:**
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].

```

**Constraints:**
* `2 <= nums.length <= 2 * 105`
* `nums.length` is **even**
* `1 <= |nums[i]| <= 105`
* `nums` consists of **equal** number of positive and negative integers.


<br>

### Hints

- Divide the array into two parts- one comprising of only positive integers and the other of negative integers.
- Merge the two parts to get the resultant array.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> rearrangeArray (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> ans (n);
      int pos = 0, neg = 0;
      bool is_required = true;
      
      for (int i = 0; i < n; ++i) {
        if (is_required) {
          while (nums[pos] <= 0)
            ++pos;
          ans[i] = nums[pos];
          ++pos;
        }
        else {
          while (nums[neg] >= 0)
            ++neg;
          ans[i] = nums[neg];
          ++neg;
        }
        is_required = !is_required;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 41320
- total submissions: 50662
- acceptance rate: 81.6%
- likes: 644
- dislikes: 45

<br>

### Similar Problems

- [Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence) (Medium)
- [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii) (Easy)
- [Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot) (Medium)
- [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity) (Easy)
