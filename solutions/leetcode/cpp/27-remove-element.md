# [27] Remove Element

**[array, two-pointers]**

### Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm). The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` *after placing the final result in the first* `k` *slots of* `nums`.

Do **not** allocate extra space for another array. You must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Custom Judge:**

The judge will test your solution with the following code:


```

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}

```


If all assertions pass, then your solution will be **accepted**.


**Example 1:**

```

**Input:** nums = [3,2,2,3], val = 3
**Output:** 2, nums = [2,2,\_,\_]
**Explanation:** Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

```

**Example 2:**

```

**Input:** nums = [0,1,2,2,3,0,4,2], val = 2
**Output:** 5, nums = [0,1,4,0,3,\_,\_,\_]
**Explanation:** Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

```

**Constraints:**
* `0 <= nums.length <= 100`
* `0 <= nums[i] <= 50`
* `0 <= val <= 100`


<br>

### Hints

- The problem statement clearly asks us to modify the array in-place and it also says that the element beyond the new length of the array can be anything. Given an element, we need to remove all the occurrences of it from the array. We don't technically need to <b>remove</b> that element per-say, right?
- We can move all the occurrences of this element to the end of the array. Use two pointers!
<br><img src="https://assets.leetcode.com/uploads/2019/10/20/hint_remove_element.png" width="500"/>
- Yet another direction of thought is to consider the elements to be removed as non-existent. In a single pass, if we keep copying the visible elements in-place, that should also solve this problem for us.

<br>

### Solution

**Using STL**

```cpp
class Solution {
  public:
    int removeElement (vector <int>& nums, int val) {
      auto position = std::partition(nums.begin(), nums.end(), [&] (auto& x) {
        return x != val;
      }) - nums.begin();
      
      return position;
    }
};
```

**Swapping with last element**

```cpp
class Solution {
  public:
    int removeElement (vector <int>& nums, int val) {
      int n = nums.size(), i = 0;
      
      while (i < n) {
        if (nums[i] == val) {
          std::swap(nums[i], nums[n - 1]);
          --n;
        }
        else
          ++i;
      }
      
      return i;
    }
};
```

<br>

### Statistics

- total accepted: 1386470
- total submissions: 2683830
- acceptance rate: 51.7%
- likes: 4008
- dislikes: 5761

<br>

### Similar Problems

- [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array) (Easy)
- [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) (Easy)
- [Move Zeroes](https://leetcode.com/problems/move-zeroes) (Easy)
