# [2610] Convert an Array Into a 2D Array With Conditions



### Statement

You are given an integer array `nums`. You need to create a 2D array from `nums` satisfying the following conditions:

* The 2D array should contain **only** the elements of the array `nums`.
* Each row in the 2D array contains **distinct** integers.
* The number of rows in the 2D array should be **minimal**.



Return *the resulting array*. If there are multiple answers, return any of them.

**Note** that the 2D array can have a different number of elements on each row.


**Example 1:**

```

**Input:** nums = [1,3,4,1,2,3,1]
**Output:** [[1,3,4,2],[1,3],[1]]
**Explanation:** We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** [[4,3,2,1]]
**Explanation:** All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.

```

**Constraints:**
* `1 <= nums.length <= 200`
* `1 <= nums[i] <= nums.length`


<br />

### Hints

- Process the elements in the array one by one in any order and only create a new row in the matrix when we cannot put it into the existing rows
- We can simply iterate over the existing rows of the matrix to see if we can place each element.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> findMatrix (vector <int>& nums) {
      int n = nums.size();
      std::vector <std::vector <int>> buckets;
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and nums[i] == nums[j])
          ++j;
        int count = j - i;
        if (count > (int)buckets.size())
          buckets.resize(count);
        for (int k = 0; k < count; ++k)
          buckets[k].push_back(nums[i]);
        i = j - 1;
      }
      
      return buckets;
    }
};
```

<br />

### Statistics

- total accepted: 14871
- total submissions: 17259
- acceptance rate: 86.2%
- likes: 116
- dislikes: 3

<br />

### Similar Problems

None
