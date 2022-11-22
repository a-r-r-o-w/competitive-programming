# [189] Rotate Array

**[array, math, two-pointers]**

### Statement

Given an array, rotate the array to the right by `k` steps, where `k` is non-negative.


**Example 1:**

```

**Input:** nums = [1,2,3,4,5,6,7], k = 3
**Output:** [5,6,7,1,2,3,4]
**Explanation:**
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

```

**Example 2:**

```

**Input:** nums = [-1,-100,3,99], k = 2
**Output:** [3,99,-1,-100]
**Explanation:** 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-231 <= nums[i] <= 231 - 1`
* `0 <= k <= 105`


**Follow up:**
* Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
* Could you do it in-place with `O(1)` extra space?


<br>

### Hints

- The easiest solution would use additional memory and that is perfectly fine.
- The actual trick comes when trying to solve this problem without using any additional memory. This means you need to use the original array somehow to move the elements around. Now, we can place each element in its original location and shift all the elements around it to adjust as that would be too costly and most likely will time out on larger input arrays.
- One line of thought is based on reversing the array (or parts of it) to obtain the desired result. Think about how reversal might potentially help us out by using an example.
- The other line of thought is a tad bit complicated but essentially it builds on the idea of placing each element in its original position while keeping track of the element originally in that position. Basically, at every step, we place an element in its rightful position and keep track of the element already there or the one being overwritten in an additional variable. We can't do this in one linear pass and the idea here is based on <b>cyclic-dependencies</b> between elements.

<br>

### Solution

Using extra space

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    void rotate (vector <int>& nums, int k) {
      int n = nums.size();
      std::vector <int> rotated (n);
      
      k %= n;
      
      for (int i = 0; i < n; ++i)
        rotated[i] = nums[(n - k + i) % n];
      
      nums = rotated;
    }
};
```

STL

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    void rotate (vector <int>& nums, int k) {
      int n = nums.size();
      k %= n;
      std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
    }
};
```

Reversing subarrays

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    void rotate (vector <int>& nums, int k) {
      int n = nums.size(), x = nums[0];
      
      k %= n;
      
      std::reverse(nums.begin(), nums.begin() + n);
      std::reverse(nums.begin(), nums.begin() + k);
      std::reverse(nums.begin() + k, nums.begin() + n);
    }
};
```

<br>

### Statistics

- total accepted: 1244575
- total submissions: 3189689
- acceptance rate: 39.0%
- likes: 11034
- dislikes: 1396

<br>

### Similar Problems

- [Rotate List](https://leetcode.com/problems/rotate-list) (Medium)
- [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii) (Medium)
