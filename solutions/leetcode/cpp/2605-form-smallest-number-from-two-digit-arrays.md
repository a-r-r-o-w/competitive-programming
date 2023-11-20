# [2605] Form Smallest Number From Two Digit Arrays

**[array, hash-table, enumeration]**

### Statement

Given two arrays of **unique** digits `nums1` and `nums2`, return *the **smallest** number that contains **at least** one digit from each array*.

**Example 1:**

```

**Input:** nums1 = [4,1,3], nums2 = [5,7]
**Output:** 15
**Explanation:** The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

```

**Example 2:**

```

**Input:** nums1 = [3,5,2,6], nums2 = [3,1,7]
**Output:** 3
**Explanation:** The number 3 contains the digit 3 which exists in both arrays.

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 9`
* `1 <= nums1[i], nums2[i] <= 9`
* All digits in each array are **unique**.


<br />

### Hints

- How many digits will the resulting number have at most?
- The resulting number will have either one or two digits. Try to find when each case is possible.

<br />

### Solution

```cpp
class Solution {
  public:
    int minNumber (vector <int>& nums1, vector <int>& nums2) {
      std::sort(nums1.begin(), nums1.end());
      std::sort(nums2.begin(), nums2.end());
      for (int i: nums1) {
        for (int j: nums2) {
          if (i == j)
            return i;
        }
      }
      return std::min(10 * nums1.front() + nums2.front(), 10 * nums2.front() + nums1.front());
    }
};
```

<br />

### Statistics

- total accepted: 19382
- total submissions: 36530
- acceptance rate: 53.1%
- likes: 129
- dislikes: 7

<br />

### Similar Problems

None
