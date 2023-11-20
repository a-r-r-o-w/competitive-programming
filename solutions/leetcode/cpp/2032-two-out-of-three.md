# [2032] Two Out of Three

**[array, hash-table]**

### Statement

Given three integer arrays `nums1`, `nums2`, and `nums3`, return *a **distinct** array containing all the values that are present in **at least two** out of the three arrays. You may return the values in **any** order*.

**Example 1:**

```

**Input:** nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
**Output:** [3,2]
**Explanation:** The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.

```

**Example 2:**

```

**Input:** nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
**Output:** [2,3,1]
**Explanation:** The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.

```

**Example 3:**

```

**Input:** nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
**Output:** []
**Explanation:** No value is present in at least two arrays.

```

**Constraints:**
* `1 <= nums1.length, nums2.length, nums3.length <= 100`
* `1 <= nums1[i], nums2[j], nums3[k] <= 100`


<br>

### Hints

- What data structure can we use to help us quickly find whether an element belongs in an array?
- Can we count the frequencies of the elements in each array?

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> twoOutOfThree (vector <int>& nums1, vector <int>& nums2, vector <int>& nums3) {
      constexpr int max = 100 + 1;
      std::bitset <max> a, b, c;

      for (int i: nums1)
        a[i] = 1;
      for (int i: nums2)
        b[i] = 1;
      for (int i: nums3)
        c[i] = 1;
      
      std::vector <int> ans;
      auto x = (a & b) | (b & c) | (c & a);
      
      for (int i = 0; i < max; ++i) {
        if (x[i])
          ans.push_back(i);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 41173
- total submissions: 56452
- acceptance rate: 72.9%
- likes: 503
- dislikes: 34

<br>

### Similar Problems

None
