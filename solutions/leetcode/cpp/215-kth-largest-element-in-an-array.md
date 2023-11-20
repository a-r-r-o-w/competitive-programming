# [215] Kth Largest Element in an Array

**[array, divide-and-conquer, sorting, heap-priority-queue, quickselect]**

### Statement

Given an integer array `nums` and an integer `k`, return *the* `k^th` *largest element in the array*.

Note that it is the `k^th` largest element in the sorted order, not the `k^th` distinct element.

Can you solve it without sorting?


**Example 1:**

```
**Input:** nums = [3,2,1,5,6,4], k = 2
**Output:** 5

```
**Example 2:**

```
**Input:** nums = [3,2,3,1,2,4,5,5,6], k = 4
**Output:** 4

```

**Constraints:**
* `1 <= k <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int findKthLargest (vector <int>& nums, int k) {
      int n = nums.size();
      std::priority_queue <int, std::vector <int>, std::greater<>> pq;

      for (int i: nums) {
        pq.push(i);
        if ((int)pq.size() > k)
          pq.pop();
      }

      return pq.top();
    }
};
```

<br />

### Statistics

- total accepted: 1876058
- total submissions: 2798303
- acceptance rate: 67.0%
- likes: 15214
- dislikes: 723

<br />

### Similar Problems

- [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii) (Medium)
- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [Third Maximum Number](https://leetcode.com/problems/third-maximum-number) (Easy)
- [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) (Easy)
- [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) (Medium)
- [Find the Kth Largest Integer in the Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array) (Medium)
- [Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum) (Easy)
- [K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range) (Medium)
