# [496] Next Greater Element I

**[array, hash-table, stack, monotonic-stack]**

### Statement

The **next greater element** of some element `x` in an array is the **first greater** element that is **to the right** of `x` in the same array.

You are given two **distinct 0-indexed** integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return *an array* `ans` *of length* `nums1.length` *such that* `ans[i]` *is the **next greater element** as described above.*
**Example 1:**

```

**Input:** nums1 = [4,1,2], nums2 = [1,3,4,2]
**Output:** [-1,3,-1]
**Explanation:** The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

```

**Example 2:**

```

**Input:** nums1 = [2,4], nums2 = [1,2,3,4]
**Output:** [3,-1]
**Explanation:** The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

```

**Constraints:**
* `1 <= nums1.length <= nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 104`
* All integers in `nums1` and `nums2` are **unique**.
* All the integers of `nums1` also appear in `nums2`.


**Follow up:** Could you find an `O(nums1.length + nums2.length)` solution?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> nextGreaterElement (vector <int>& nums1, vector <int>& nums2) {
      int n = nums2.size();
      std::unordered_map <int, int> ans;
      std::deque <int> q;
      
      for (int i = 0; i < n; ++i) {
        while (!q.empty() and q.back() < nums2[i]) {
          ans[q.back()] = nums2[i];
          q.pop_back();
        }
        q.push_back(nums2[i]);
      }
      
      while (!q.empty()) {
        ans[q.back()] = -1;
        q.pop_back();
      }
      
      std::transform(nums1.begin(), nums1.end(), nums1.begin(), [&] (int x) {
        return ans[x];
      });
      
      return nums1;
    }
};
```

<br>

### Statistics

- total accepted: 423366
- total submissions: 595301
- acceptance rate: 71.1%
- likes: 4201
- dislikes: 258

<br>

### Similar Problems

- [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) (Medium)
- [Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii) (Medium)
- [Daily Temperatures](https://leetcode.com/problems/daily-temperatures) (Medium)
- [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges) (Medium)
- [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards) (Hard)
