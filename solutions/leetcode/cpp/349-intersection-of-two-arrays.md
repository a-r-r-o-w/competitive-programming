# [349] Intersection of Two Arrays

**[array, hash-table, two-pointers, binary-search, sorting]**

### Statement

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.


**Example 1:**

```

**Input:** nums1 = [1,2,2,1], nums2 = [2,2]
**Output:** [2]

```

**Example 2:**

```

**Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
**Output:** [9,4]
**Explanation:** [4,9] is also accepted.

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> intersection(vector <int>& nums1, vector <int>& nums2) {
      std::unordered_set <int> have1 (nums1.begin(), nums1.end());
      std::unordered_set <int> have2 (nums2.begin(), nums2.end());
      std::vector <int> ans;

      for (int i: have1) {
        if (have2.count(i))
          ans.push_back(i);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 872881
- total submissions: 1225322
- acceptance rate: 71.2%
- likes: 4859
- dislikes: 2138

<br />

### Similar Problems

- [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii) (Easy)
- [Intersection of Three Sorted Arrays](https://leetcode.com/problems/intersection-of-three-sorted-arrays) (Easy)
- [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays) (Easy)
- [Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence) (Easy)
- [Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range) (Hard)
- [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays) (Easy)
- [Minimum Common Value](https://leetcode.com/problems/minimum-common-value) (Easy)
