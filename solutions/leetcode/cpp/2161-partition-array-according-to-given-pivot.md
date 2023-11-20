# [2161] Partition Array According to Given Pivot

**[array, two-pointers, simulation]**

### Statement

You are given a **0-indexed** integer array `nums` and an integer `pivot`. Rearrange `nums` such that the following conditions are satisfied:

* Every element less than `pivot` appears **before** every element greater than `pivot`.
* Every element equal to `pivot` appears **in between** the elements less than and greater than `pivot`.
* The **relative order** of the elements less than `pivot` and the elements greater than `pivot` is maintained.
	+ More formally, consider every `pi`, `pj` where `pi` is the new position of the `ith` element and `pj` is the new position of the `jth` element. For elements less than `pivot`, if `i < j` and `nums[i] < pivot` and `nums[j] < pivot`, then `pi < pj`. Similarly for elements greater than `pivot`, if `i < j` and `nums[i] > pivot` and `nums[j] > pivot`, then `pi < pj`.



Return `nums` *after the rearrangement.*
**Example 1:**

```

**Input:** nums = [9,12,5,10,14,3,10], pivot = 10
**Output:** [9,5,3,10,10,12,14]
**Explanation:** 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.

```

**Example 2:**

```

**Input:** nums = [-3,4,3,2], pivot = 2
**Output:** [-3,2,4,3]
**Explanation:** 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `-106 <= nums[i] <= 106`
* `pivot` equals to an element of `nums`.


<br>

### Hints

- Could you put the elements smaller than the pivot and greater than the pivot in a separate list as in the sequence that they occur?
- With the separate lists generated, could you then generate the result?

<br>

### Solution

Using 3 passes

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> pivotArray (vector <int>& nums, int pivot) {
      int n = nums.size();
      std::vector <int> ans (n);
      int index = 0;
      
      for (int i = 0; i < n; ++i)
        if (nums[i] < pivot)
          ans[index++] = nums[i];
      for (int i = 0; i < n; ++i)
        if (nums[i] == pivot)
          ans[index++] = nums[i];
      for (int i = 0; i < n; ++i)
        if (nums[i] > pivot)
          ans[index++] = nums[i];
      
      return ans;
    }
};
```

Uinsg 2 passes

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> pivotArray (vector <int>& nums, int pivot) {
      int n = nums.size();
      std::vector <int> ans (n);
      int lower = 0, equal = 0, higher = 0;
      
      for (int i: nums) {
        if (i < pivot)
          ++equal;
        else if (i == pivot)
          ++higher;
      }
      
      higher += equal;
      
      for (int i: nums) {
        if (i < pivot)
          ans[lower++] = i;
        else if (i == pivot)
          ans[equal++] = i;
        else
          ans[higher++] = i;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 29712
- total submissions: 35385
- acceptance rate: 84.0%
- likes: 438
- dislikes: 40

<br>

### Similar Problems

- [Partition List](https://leetcode.com/problems/partition-list) (Medium)
- [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign) (Medium)
