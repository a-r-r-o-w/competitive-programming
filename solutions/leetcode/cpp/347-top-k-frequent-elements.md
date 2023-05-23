# [347] Top K Frequent Elements

**[array, hash-table, divide-and-conquer, sorting, heap-priority-queue, bucket-sort, counting, quickselect]**

### Statement

Given an integer array `nums` and an integer `k`, return *the* `k` *most frequent elements*. You may return the answer in **any order**.


**Example 1:**

```
**Input:** nums = [1,1,1,2,2,3], k = 2
**Output:** [1,2]

```
**Example 2:**

```
**Input:** nums = [1], k = 1
**Output:** [1]

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`
* `k` is in the range `[1, the number of unique elements in the array]`.
* It is **guaranteed** that the answer is **unique**.


**Follow up:** Your algorithm's time complexity must be better than `O(n log n)`, where n is the array's size.

<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> topKFrequent (vector <int>& nums, int k) {
      std::unordered_map <int, int> freq;
      std::vector <std::pair <int, int>> v;

      for (int i: nums)
        ++freq[i];
      for (auto &x: freq)
        v.push_back(x);
      std::sort(v.begin(), v.end(), [&] (auto &l, auto &r) {
        return l.second > r.second;
      });

      std::vector <int> ans;
      ans.reserve(k);
      for (int i = 0; i < k; ++i)
        ans.push_back(v[i].first);
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 1430587
- total submissions: 2233069
- acceptance rate: 64.1%
- likes: 13761
- dislikes: 497

<br />

### Similar Problems

- [Word Frequency](https://leetcode.com/problems/word-frequency) (Medium)
- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) (Medium)
- [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) (Medium)
- [Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences) (Medium)
- [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) (Medium)
- [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) (Medium)
- [Sort Features by Popularity](https://leetcode.com/problems/sort-features-by-popularity) (Medium)
- [Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count) (Medium)
- [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) (Easy)
