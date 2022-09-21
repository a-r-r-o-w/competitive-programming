# [985] Sum of Even Numbers After Queries

**[array, simulation]**

### Statement

You are given an integer array `nums` and an array `queries` where `queries[i] = [vali, indexi]`.

For each query `i`, first, apply `nums[indexi] = nums[indexi] + vali`, then print the sum of the even values of `nums`.

Return *an integer array* `answer` *where* `answer[i]` *is the answer to the* `ith` *query*.


**Example 1:**

```

**Input:** nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
**Output:** [8,6,2,4]
**Explanation:** At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.

```

**Example 2:**

```

**Input:** nums = [1], queries = [[4,0]]
**Output:** [0]

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `1 <= queries.length <= 104`
* `-104 <= vali <= 104`
* `0 <= indexi < nums.length`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> sumEvenAfterQueries (vector <int>& nums, vector <vector <int>>& queries) {
      int n = nums.size();
      int sum = 0;
      std::vector <int> ans;
      ans.reserve(n);
      
      for (int i = 0; i < n; ++i)
        if (nums[i] % 2 == 0)
          sum += nums[i];
      
      for (auto &q: queries) {
        auto &val = q[0];
        auto &index = q[1];
        
        if (nums[index] % 2 == 0)
          sum -= nums[index];
        
        nums[index] += val;
        
        if (nums[index] % 2 == 0)
          sum += nums[index];
        
        ans.push_back(sum);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 101324
- total submissions: 152579
- acceptance rate: 66.4%
- likes: 1441
- dislikes: 284

<br>

### Similar Problems

None
