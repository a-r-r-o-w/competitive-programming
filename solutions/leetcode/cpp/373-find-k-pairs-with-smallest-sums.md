# [373] Find K Pairs with Smallest Sums

**[array, heap-priority-queue]**

### Statement

You are given two integer arrays `nums1` and `nums2` sorted in **ascending order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return *the* `k` *pairs* `(u1, v1), (u2, v2), ..., (uk, vk)` *with the smallest sums*.


**Example 1:**

```

**Input:** nums1 = [1,7,11], nums2 = [2,4,6], k = 3
**Output:** [[1,2],[1,4],[1,6]]
**Explanation:** The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

```

**Example 2:**

```

**Input:** nums1 = [1,1,2], nums2 = [1,2,3], k = 2
**Output:** [[1,1],[1,1]]
**Explanation:** The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

```

**Example 3:**

```

**Input:** nums1 = [1,2], nums2 = [3], k = 3
**Output:** [[1,3],[2,3]]
**Explanation:** All possible pairs are returned from the sequence: [1,3],[2,3]

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 10^5`
* `-10^9 <= nums1[i], nums2[i] <= 10^9`
* `nums1` and `nums2` both are sorted in **ascending order**.
* `1 <= k <= 10^4`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> kSmallestPairs (vector <int>& nums1, vector <int>& nums2, int k) {
      int m = nums1.size(), n = nums2.size();
      std::set <std::pair <int, int>> visited;
      std::priority_queue <std::pair <int, std::pair <int, int>>, std::vector <std::pair <int, std::pair <int, int>>>, std::greater <>> pq;
      std::vector <std::vector <int>> ans;

      pq.push({nums1[0] + nums2[0], {0, 0}});
      visited.insert({0, 0});

      while (!pq.empty() and k--) {
        auto [u, v] = pq.top();
        int i = v.first, j = v.second;;

        pq.pop();
        ans.push_back({nums1[i], nums2[j]});
        
        if (i + 1 < m and !visited.count({i + 1, j})) {
          pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
          visited.insert({i + 1, j});
        }
        if (j + 1 < n and !visited.count({i, j + 1})) {
          pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
          visited.insert({i, j + 1});
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 235942
- total submissions: 593199
- acceptance rate: 39.8%
- likes: 5248
- dislikes: 306

<br />

### Similar Problems

- [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) (Medium)
- [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance) (Hard)
- [Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays) (Hard)
