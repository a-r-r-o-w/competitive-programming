# [278] First Bad Version

**[binary-search, interactive]**

### Statement

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.


**Example 1:**

```

**Input:** n = 5, bad = 4
**Output:** 4
**Explanation:**
call isBadVersion(3) -> false
call isBadVersion(5)-> true
call isBadVersion(4)-> true
Then 4 is the first bad version.

```

**Example 2:**

```

**Input:** n = 1, bad = 1
**Output:** 1

```

**Constraints:**
* `1 <= bad <= n <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion (int64_t n) {
      int64_t low = 1, high = n + 1;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (isBadVersion(mid))
          high = mid;
        else
          low = mid + 1;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 1081606
- total submissions: 2562467
- acceptance rate: 42.2%
- likes: 5311
- dislikes: 1976

<br>

### Similar Problems

- [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) (Medium)
- [Search Insert Position](https://leetcode.com/problems/search-insert-position) (Easy)
- [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower) (Easy)
