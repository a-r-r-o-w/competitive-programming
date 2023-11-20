# [2215] Find the Difference of Two Arrays

**[array, hash-table]**

### Statement

Given two **0-indexed** integer arrays `nums1` and `nums2`, return *a list* `answer` *of size* `2` *where:*
* `answer[0]` *is a list of all **distinct** integers in* `nums1` *which are **not** present in* `nums2`*.*
* `answer[1]` *is a list of all **distinct** integers in* `nums2` *which are **not** present in* `nums1`.


**Note** that the integers in the lists may be returned in **any** order.


**Example 1:**

```

**Input:** nums1 = [1,2,3], nums2 = [2,4,6]
**Output:** [[1,3],[4,6]]
**Explanation:**For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
```

**Example 2:**

```

**Input:** nums1 = [1,2,3,3], nums2 = [1,1,2,2]
**Output:** [[3],[]]
**Explanation:**For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 1000`
* `-1000 <= nums1[i], nums2[i] <= 1000`


<br />

### Hints

- For each integer in nums1, check if it exists in nums2.
- Do the same for each integer in nums2.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> findDifference (vector <int>& nums1, vector <int>& nums2) {
      std::unordered_set <int> have1 (nums1.begin(), nums1.end());
      std::unordered_set <int> have2 (nums2.begin(), nums2.end());
      std::vector <std::vector <int>> ans;
      std::vector <int> t;
      int n = nums1.size(), m = nums2.size();

      for (int i: have1) {
        if (have2.count(i))
          continue;
        t.emplace_back(i);
      }
      ans.emplace_back(std::move(t));
      for (int i: have2) {
        if (have1.count(i))
          continue;
        t.emplace_back(i);
      }
      ans.emplace_back(std::move(t));

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 112820
- total submissions: 145697
- acceptance rate: 77.4%
- likes: 1417
- dislikes: 56

<br />

### Similar Problems

- [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays) (Easy)
- [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii) (Easy)
- [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays) (Easy)
