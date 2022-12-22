# [274] H-Index

**[array, sorting, counting-sort]**

### Statement

Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their `ith` paper, return compute the researcher's `h`**-index**.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): A scientist has an index `h` if `h` of their `n` papers have at least `h` citations each, and the other `n − h` papers have no more than `h` citations each.

If there are several possible values for `h`, the maximum one is taken as the `h`**-index**.


**Example 1:**

```

**Input:** citations = [3,0,6,1,5]
**Output:** 3
**Explanation:** [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

```

**Example 2:**

```

**Input:** citations = [1,3,1]
**Output:** 1

```

**Constraints:**
* `n == citations.length`
* `1 <= n <= 5000`
* `0 <= citations[i] <= 1000`


<br>

### Hints

- An easy approach is to sort the array first.
- What are the possible values of h-index?
- A faster approach is to use extra space.

<br>

### Solution

```cpp
class Solution {
  public:
    int hIndex (vector <int>& citations) {
      int n = citations.size();
      
      std::sort(citations.begin(), citations.end());

      for (int i = 0; i < n; ++i) {
        if (citations[n - i - 1] <= i)
          return i;
      }

      return n;
    }
};
```

<br>

### Statistics

- total accepted: 252816
- total submissions: 661780
- acceptance rate: 38.2%
- likes: 1415
- dislikes: 2042

<br>

### Similar Problems

- [H-Index II](https://leetcode.com/problems/h-index-ii) (Medium)
