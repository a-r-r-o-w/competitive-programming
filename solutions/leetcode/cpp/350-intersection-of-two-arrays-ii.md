# [350] Intersection of Two Arrays II

**[array, hash-table, two-pointers, binary-search, sorting]**

### Statement

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.


**Example 1:**

```

**Input:** nums1 = [1,2,2,1], nums2 = [2,2]
**Output:** [2,2]

```

**Example 2:**

```

**Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
**Output:** [4,9]
**Explanation:** [9,4] is also accepted.

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`


**Follow up:**
* What if the given array is already sorted? How would you optimize your algorithm?
* What if `nums1`'s size is small compared to `nums2`'s size? Which algorithm is better?
* What if elements of `nums2` are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


<br>

### Hints

None

<br>

### Solution

Multiset

```cpp
class Solution {
  public:
    vector <int> intersect (vector <int>& nums1, vector <int>& nums2) {
      std::multiset <int> have (nums1.begin(), nums1.end());
      std::vector <int> ans;
      
      for (int i: nums2) {
        auto f = have.find(i);
        if (f != have.end()) {
          ans.push_back(i);
          have.erase(f);
        }
      }
      
      return ans;
    }
};
```

Sorting

```cpp
class Solution {
  public:
    vector <int> intersect (vector <int>& nums1, vector <int>& nums2) {
      std::vector <int> ans;
      int n = nums1.size(), m = nums2.size();
      int l1 = 0, l2 = 0;
      
      std::sort(nums1.begin(), nums1.end());
      std::sort(nums2.begin(), nums2.end());
      
      while (l1 < n and l2 < m) {
        if (nums1[l1] == nums2[l2]) {
          ans.push_back(nums1[l1]);
          ++l1;
          ++l2;
        }
        else if (nums1[l1] < nums2[l2])
          ++l1;
        else
          ++l2;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 897678
- total submissions: 1620004
- acceptance rate: 55.4%
- likes: 5222
- dislikes: 767

<br>

### Similar Problems

- [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays) (Easy)
- [Find Common Characters](https://leetcode.com/problems/find-common-characters) (Easy)
- [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays) (Easy)
- [Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range) (Hard)
- [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays) (Easy)
