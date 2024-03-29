# [1464] Maximum Product of Two Elements in an Array

**[array, sorting, heap-priority-queue]**

### Statement

Given the array of integers `nums`, you will choose two different indices `i` and `j` of that array. *Return the maximum value of* `(nums[i]-1)*(nums[j]-1)`.

**Example 1:**

```

**Input:** nums = [3,4,5,2]
**Output:** 12 
**Explanation:** If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)\*(nums[2]-1) = (4-1)\*(5-1) = 3\*4 = 12. 

```

**Example 2:**

```

**Input:** nums = [1,5,4,5]
**Output:** 16
**Explanation:** Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)\*(5-1) = 16.

```

**Example 3:**

```

**Input:** nums = [3,7]
**Output:** 12

```

**Constraints:**
* `2 <= nums.length <= 500`
* `1 <= nums[i] <= 10^3`


<br>

### Hints

- Use brute force: two loops to select i and j, then select the maximum value of (nums[i]-1)*(nums[j]-1).

<br>

### Solution

```cpp
class Solution {
  public:
    int maxProduct (vector <int>& nums) {
      const int inf32 = 1 << 30;
      int max1 = -inf32;
      int max2 = -inf32;
      
      for (int n: nums) {
        if (n > max1) {
          max2 = max1;
          max1 = n;
        }
        else if (n > max2)
          max2 = n;
      }
      
      return (max1 - 1) * (max2 - 1);
    }
};
```

<br>

### Statistics

- total accepted: 151464
- total submissions: 191409
- acceptance rate: 79.1%
- likes: 1167
- dislikes: 167

<br>

### Similar Problems

None
