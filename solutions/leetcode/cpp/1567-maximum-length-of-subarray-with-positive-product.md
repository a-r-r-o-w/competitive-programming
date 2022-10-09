# [1567] Maximum Length of Subarray With Positive Product

**[array, dynamic-programming, greedy]**

### Statement

Given an array of integers `nums`, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return *the maximum length of a subarray with positive product*.


**Example 1:**

```

**Input:** nums = [1,-2,-3,4]
**Output:** 4
**Explanation:** The array nums already has a positive product of 24.

```

**Example 2:**

```

**Input:** nums = [0,1,-2,-3,-4]
**Output:** 3
**Explanation:** The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
```

**Example 3:**

```

**Input:** nums = [-1,-2,-3,0,1]
**Output:** 2
**Explanation:** The longest subarray with positive product is [-1,-2] or [-2,-3].

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-109 <= nums[i] <= 109`


<br>

### Hints

- Split the whole array into subarrays by zeroes since a subarray with positive product cannot contain any zero.
- If the subarray has even number of negative numbers, the whole subarray has positive product.
- Otherwise, we have two choices, either - remove the prefix till the first negative element in this subarray, or remove the suffix starting from the last negative element in this subarray.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int getMaxLen (vector <int>& nums) {
      int n = nums.size();
      int pos = 0, neg = 0, best = 0;
      
      if (nums.front() > 0)
        pos = 1;
      if (nums.front() < 0)
        neg = 1;
      
      best = std::max(best, pos);
      
      for (int i = 1; i < n; ++i) {
        if (nums[i] > 0) {
          ++pos;
          neg = neg > 0 ? neg + 1 : 0;
        }
        else if (nums[i] < 0) {
          int t = neg;
          neg = pos + 1;
          pos = t > 0 ? t + 1 : 0;
        }
        else {
          pos = 0;
          neg = 0;
        }
        
        best = std::max(best, pos);
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 68906
- total submissions: 158207
- acceptance rate: 43.6%
- likes: 1792
- dislikes: 43

<br>

### Similar Problems

None
