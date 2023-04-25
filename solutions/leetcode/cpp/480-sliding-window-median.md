# [480] Sliding Window Median

**[array, hash-table, sliding-window, heap-priority-queue]**

### Statement

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

* For examples, if `arr = [2,3,4]`, the median is `3`.
* For examples, if `arr = [1,2,3,4]`, the median is `(2 + 3) / 2 = 2.5`.



You are given an integer array `nums` and an integer `k`. There is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the median array for each window in the original array*. Answers within `10^-5` of the actual value will be accepted.


**Example 1:**

```

**Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3
**Output:** [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
**Explanation:** 
Window position                Median
---------------                -----
[**1 3 -1**] -3  5  3  6  7        1
 1 [**3 -1 -3**] 5  3  6  7       -1
 1  3 [**-1 -3 5**] 3  6  7       -1
 1  3  -1 [**-3 5 3**] 6  7        3
 1  3  -1  -3 [**5 3 6**] 7        5
 1  3  -1  -3  5 [**3 6 7**]       6

```

**Example 2:**

```

**Input:** nums = [1,2,3,4,2,3,1,4,2], k = 3
**Output:** [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

```

**Constraints:**
* `1 <= k <= nums.length <= 10^5`
* `-2^31 <= nums[i] <= 2^31 - 1`


<br />

### Hints

- The simplest of solutions comes from the basic idea of finding the median given a set of numbers. We know that by definition, a median is the center element (or an average of the two center elements). Given an unsorted list of numbers, how do we find the median element? If you know the answer to this question, can we extend this idea to every sliding window that we come across in the array?
- Is there a better way to do what we are doing in the above hint? Don't you think there is duplication of calculation being done there? Is there some sort of optimization that we can do to achieve the same result? This approach is merely a modification of the basic approach except that it simply reduces duplication of calculations once done.
- The third line of thought is also based on this same idea but achieving the result in a different way. We obviously need the window to be sorted for us to be able to find the median. Is there a data-structure out there that we can use (in one or more quantities) to obtain the median element extremely fast, say O(1) time while having the ability to perform the other operations fairly efficiently as well?

<br />

### Solution

```cpp
class Solution {
  public:
    vector <double> medianSlidingWindow (vector <int>& nums, int k) {
      int n = nums.size();
      std::vector <double> ans;
      std::multiset <int> low, high;

      if (k == 1) {
        for (int i = 0; i < n; ++i)
          ans.push_back(nums[i]);
        return ans;
      }

      auto insert = [&] (int u) {
        int median = *low.rbegin();
  
        if (median >= u) {
          low.insert(u);
          if (int(low.size()) > (k + 1) / 2) {
            auto last = low.end();
            --last;
            high.insert(*last);
            low.erase(last);
          }
        }
        else {
          high.insert(u);
          if (int(high.size()) > k / 2) {
            auto first = high.begin();
            low.insert(*first);
            high.erase(first);
          }
        }
      };
  
      auto erase = [&] (int u) {
        if (high.find(u) != high.end())
          high.erase(high.find(u));
        else
          low.erase(low.find(u));
        if (low.empty()) {
          low.insert(*high.begin());
          high.erase(high.begin());
        }
      };

      low.insert(nums[0]);
      for (int i = 1; i < k; ++i)
        insert(nums[i]);
      if (k & 1)
        ans.push_back(*low.rbegin());
      else
        ans.push_back((double(*low.rbegin()) + *high.begin()) / 2);

      for (int i = k; i < n; ++i) {
        erase(nums[i - k]);
        insert(nums[i]);
        if (k & 1)
          ans.push_back(*low.rbegin());
        else
          ans.push_back((double(*low.rbegin()) + *high.begin()) / 2);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 126261
- total submissions: 307622
- acceptance rate: 41.0%
- likes: 2785
- dislikes: 160

<br />

### Similar Problems

- [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream) (Hard)
