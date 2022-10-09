# [1] Two Sum

**[array, hash-table]**

### Statement

Given an array of integers `nums`and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.


**Example 1:**

```

**Input:** nums = [2,7,11,15], target = 9
**Output:** [0,1]
**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

```

**Example 2:**

```

**Input:** nums = [3,2,4], target = 6
**Output:** [1,2]

```

**Example 3:**

```

**Input:** nums = [3,3], target = 6
**Output:** [0,1]

```

**Constraints:**
* `2 <= nums.length <= 104`
* `-109 <= nums[i] <= 109`
* `-109 <= target <= 109`
* **Only one valid answer exists.**


**Follow-up:**Can you come up with an algorithm that is less than`O(n2)`time complexity?

<br>

### Hints

- A really brute force way would be to search for all possible pairs of numbers but that would be too slow. Again, it's best to try out brute force solutions for just for completeness. It is from these brute force solutions that you can come up with optimizations.
- So, if we fix one of the numbers, say <pre>x</pre>, we have to scan the entire array to find the next number <pre>y</pre> which is <pre>value - x</pre> where value is the input parameter. Can we change our array somehow so that this search becomes faster?
- The second train of thought is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

<br>

### Solution

**Two Pointers**

```cpp
class Solution {
  public:
    vector <int> twoSum (vector <int>& nums, int target) {
      int n = nums.size();
      
      std::vector <int> indices (n);
      std::iota(indices.begin(), indices.end(), 0);
      std::sort(indices.begin(), indices.end(), [&] (int l, int r) {
        return nums[l] < nums[r];
      });
      
      int l = 0, r = n - 1;
      while (l < r) {
        int i = indices[l];
        int j = indices[r];
        
        if (nums[i] + nums[j] < target)
          ++l;
        else if (nums[i] + nums[j] > target)
          --r;
        else
          return {i, j};
      }
      
      return {}; // unreachable as answer is always guaranteed
    }
};
```

**Hash Map**

```cpp
class Solution {
  public:
    vector <int> twoSum (vector <int>& nums, int target) {
      int n = nums.size();
      std::unordered_map <int, int> map;
      
      for (int i = 0; i < n; ++i) {
        if (map.count(target - nums[i]))
          return {map[target - nums[i]], i};
        else
          map[nums[i]] = i;
      }
      
      return {}; // unreachable as answer is always guaranteed
    }
};
```

<br>

### Statistics

- total accepted: 6750732
- total submissions: 13874478
- acceptance rate: 48.7%
- likes: 32725
- dislikes: 1035

<br>

### Similar Problems

- [3Sum](https://leetcode.com/problems/3sum) (Medium)
- [4Sum](https://leetcode.com/problems/4sum) (Medium)
- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) (Medium)
- [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design) (Easy)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) (Medium)
- [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) (Easy)
- [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k) (Easy)
- [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs) (Medium)
- [Count Good Meals](https://leetcode.com/problems/count-good-meals) (Medium)
- [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k) (Easy)
- [Number of Pairs of Strings With Concatenation Equal to Target](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target) (Medium)
- [Find All K-Distant Indices in an Array](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array) (Easy)
