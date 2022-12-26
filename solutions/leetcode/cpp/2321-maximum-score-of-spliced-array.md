# [2321] Maximum Score Of Spliced Array

**[array, dynamic-programming]**

### Statement

You are given two **0-indexed** integer arrays `nums1` and `nums2`, both of length `n`.

You can choose two integers `left` and `right` where `0 <= left <= right < n` and **swap** the subarray `nums1[left...right]` with the subarray `nums2[left...right]`.

* For example, if `nums1 = [1,2,3,4,5]` and `nums2 = [11,12,13,14,15]` and you choose `left = 1` and `right = 2`, `nums1` becomes `[1,**12,13**,4,5]` and `nums2` becomes `[11,**2,3**,14,15]`.



You may choose to apply the mentioned operation **once** or not do anything.

The **score** of the arrays is the **maximum** of `sum(nums1)` and `sum(nums2)`, where `sum(arr)` is the sum of all the elements in the array `arr`.

Return *the **maximum possible score***.

A **subarray** is a contiguous sequence of elements within an array. `arr[left...right]` denotes the subarray that contains the elements of `nums` between indices `left` and `right` (**inclusive**).


**Example 1:**

```

**Input:** nums1 = [60,60,60], nums2 = [10,90,10]
**Output:** 210
**Explanation:** Choosing left = 1 and right = 1, we have nums1 = [60,**90**,60] and nums2 = [10,**60**,10].
The score is max(sum(nums1), sum(nums2)) = max(210, 80) = 210.
```

**Example 2:**

```

**Input:** nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
**Output:** 220
**Explanation:** Choosing left = 3, right = 4, we have nums1 = [20,40,20,**40,20**] and nums2 = [50,20,50,**70,30**].
The score is max(sum(nums1), sum(nums2)) = max(140, 220) = 220.

```

**Example 3:**

```

**Input:** nums1 = [7,11,13], nums2 = [1,1,1]
**Output:** 31
**Explanation:** We choose not to swap any subarray.
The score is max(sum(nums1), sum(nums2)) = max(31, 3) = 31.

```

**Constraints:**
* `n == nums1.length == nums2.length`
* `1 <= n <= 105`
* `1 <= nums1[i], nums2[i] <= 104`


<br>

### Hints

- Think on Dynamic Programming.
- First assume you will be taking the array a and choose some subarray from b
- Suppose the DP is DP(pos, state). pos is the current position you are in. state is one of {0,1,2}, where 0 means taking the array a, 1 means we are taking the subarray b, and 2 means we are again taking the array a. We need to handle the transitions carefully.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }

    int maximumsSplicedArray (vector <int>& nums1, vector <int>& nums2) {
      int n = nums1.size(), max = 0;
      int pref1 = 0, pref2 = 0;
      std::vector <int> d (n + 1);

      for (int i = 0; i < n; ++i) {
        pref1 += nums1[i];
        pref2 += nums2[i];
        d[i + 1] = pref1 - pref2;
      }

      constexpr int inf32 = 1 << 30;
      std::vector <int> maxpref (n + 1, 0), maxsuff(n + 1, d.back());
      std::vector <int> minpref (n + 1, 0), minsuff(n + 1, d.back());

      for (int i = 1; i <= n; ++i) {
        maxpref[i] = std::max(maxpref[i - 1], d[i]);
        minpref[i] = std::min(minpref[i - 1], d[i]);
      }

      for (int i = n - 1; i >= 0; --i) {
        maxsuff[i] = std::max(maxsuff[i + 1], d[i]);
        minsuff[i] = std::min(minsuff[i + 1], d[i]);
      }

      for (int i = 0; i <= n; ++i) {
        max = std::max(max, pref1 + maxpref[i] - minsuff[i]);
        max = std::max(max, pref2 + maxsuff[i] - minpref[i]);
      }

      return max;
    }
};
```

<br>

### Statistics

- total accepted: 14851
- total submissions: 26705
- acceptance rate: 55.6%
- likes: 614
- dislikes: 9

<br>

### Similar Problems

- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) (Medium)
