# [1480] Running Sum of 1d Array

**[array, prefix-sum]**

### Statement

Given an array `nums`. We define a running sum of an array as`runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.


**Example 1:**

```

**Input:** nums = [1,2,3,4]
**Output:** [1,3,6,10]
**Explanation:** Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```

**Input:** nums = [1,1,1,1,1]
**Output:** [1,2,3,4,5]
**Explanation:** Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```

**Input:** nums = [3,1,2,10,1]
**Output:** [3,4,6,16,17]

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `-10^6<= nums[i] <=10^6`


<br>

### Hints

- Think about how we can calculate the i-th number in the running sum from the (i-1)-th number.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> runningSum (vector <int>& nums) {
      int n = nums.size();
      int sum = 0;
      std::vector <int> ans (n);
      
      for (int i = 0; i < n; ++i) {
        sum += nums[i];
        ans[i] = sum;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 760745
- total submissions: 842222
- acceptance rate: 90.3%
- likes: 4047
- dislikes: 236

<br>

### Similar Problems

None
