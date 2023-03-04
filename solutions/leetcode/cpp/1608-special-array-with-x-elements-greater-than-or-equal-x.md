# [1608] Special Array With X Elements Greater Than or Equal X

**[array, binary-search, sorting]**

### Statement

You are given an array `nums` of non-negative integers. `nums` is considered **special** if there exists a number `x` such that there are **exactly** `x` numbers in `nums` that are **greater than or equal to** `x`.

Notice that `x` **does not** have to be an element in `nums`.

Return `x` *if the array is **special**, otherwise, return* `-1`. It can be proven that if `nums` is special, the value for `x` is **unique**.


**Example 1:**

```

**Input:** nums = [3,5]
**Output:** 2
**Explanation:** There are 2 values (3 and 5) that are greater than or equal to 2.

```

**Example 2:**

```

**Input:** nums = [0,0]
**Output:** -1
**Explanation:** No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

```

**Example 3:**

```

**Input:** nums = [0,4,3,0,4]
**Output:** 3
**Explanation:** There are 3 values that are greater than or equal to 3.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`


<br>

### Hints

- Count the number of elements greater than or equal to x for each x in the range [0, nums.length].
- If for any x, the condition satisfies, return that x. Otherwise, there is no answer.

<br>

### Solution

```cpp
class Solution {
  public:
    int specialArray (vector <int>& nums) {
      int n = nums.size();
      int low = 0, high = n + 1;
      
      while (low < high) {
        int mid = (low + high) / 2;
        int count = 0;
        
        for (int i = 0; i < n; ++i)
          if (nums[i] >= mid)
            ++count;
        
        if (count > mid)
          low = mid + 1;
        else
          high = mid;
      }
      
      int count = 0;
      
      for (int i = 0; i < n; ++i)
        if (nums[i] >= low)
          ++count;
      
      return count == low ? low : -1;
    }
};
```

<br>

### Statistics

- total accepted: 50833
- total submissions: 84527
- acceptance rate: 60.1%
- likes: 1032
- dislikes: 166

<br>

### Similar Problems

None
