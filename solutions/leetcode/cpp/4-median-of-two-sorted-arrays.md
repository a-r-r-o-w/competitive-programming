# [4] Median of Two Sorted Arrays

**[array, binary-search, divide-and-conquer]**

### Statement

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.


**Example 1:**

```

**Input:** nums1 = [1,3], nums2 = [2]
**Output:** 2.00000
**Explanation:** merged array = [1,2,3] and median is 2.

```

**Example 2:**

```

**Input:** nums1 = [1,2], nums2 = [3,4]
**Output:** 2.50000
**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

**Constraints:**
* `nums1.length == m`
* `nums2.length == n`
* `0 <= m <= 1000`
* `0 <= n <= 1000`
* `1 <= m + n <= 2000`
* `-106 <= nums1[i], nums2[i] <= 106`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    double findMedianSortedArrays (vector <int>& nums1, vector <int>& nums2) {
      int m = nums1.size(), n = nums2.size();
      
      if (m > n) {
        std::swap(m, n);
        nums1.swap(nums2);
      }
      
      int k = (m + n - 1) / 2, l = 0, r = m;
      
      while (l < r) {
        int m1 = (l + r) / 2;
        int m2 = k - m1;
        
        if (nums1[m1] < nums2[m2])
          l = m1 + 1;
        else
          r = m1;
      }
      
      int x = 0;
      
      if (l > 0 and k - l >= 0)
        x = std::max(nums1[l - 1], nums2[k - l]);
      else if (l > 0)
        x = nums1[l - 1];
      else
        x = nums2[k - l];
      
      if ((m + n) & 1)
        return x;
      
      int y = 0;
      
      if (l < m and k - l + 1 < n)
        y = std::min(nums1[l], nums2[k - l + 1]);
      else if (l < m)
        y = nums1[l];
      else
        y = nums2[k - l + 1];
      
      return (x + y) / 2.0;
    }
};
```

<br>

### Statistics

- total accepted: 1674102
- total submissions: 4742831
- acceptance rate: 35.3%
- likes: 20697
- dislikes: 2340

<br>

### Similar Problems

- [Median of a Row Wise Sorted Matrix](https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix) (Medium)
