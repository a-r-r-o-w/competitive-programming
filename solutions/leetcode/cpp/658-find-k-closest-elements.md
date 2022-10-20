# [658] Find K Closest Elements

**[array, two-pointers, binary-search, sorting, heap-priority-queue]**

### Statement

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

* `|a - x| < |b - x|`, or
* `|a - x| == |b - x|` and `a < b`


**Example 1:**

```
**Input:** arr = [1,2,3,4,5], k = 4, x = 3
**Output:** [1,2,3,4]

```
**Example 2:**

```
**Input:** arr = [1,2,3,4,5], k = 4, x = -1
**Output:** [1,2,3,4]

```

**Constraints:**
* `1 <= k <= arr.length`
* `1 <= arr.length <= 10^4`
* `arr` is sorted in **ascending** order.
* `-10^4 <= arr[i], x <= 10^4`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> findClosestElements (vector <int>& arr, int k, int x) {
      arr.push_back(x);
      std::sort(arr.begin(), arr.end());
      
      int n = arr.size();
      std::vector <int> ans;
      int position = std::find(arr.begin(), arr.end(), x) - arr.begin();
      int l = position - 1, r = position + 1;
      
      ans.reserve(k);
      
      while (l >= 0 and r < n and k--) {
        if (arr[position] - arr[l] <= arr[r] - arr[position]) {
          ans.push_back(arr[l]);
          --l;
        }
        else {
          ans.push_back(arr[r]);
          ++r;
        }
      }
      
      while (k-- > 0) {
        if (l >= 0) {
          ans.push_back(arr[l]);
          --l;
        }
        else {
          ans.push_back(arr[r]);
          ++r;
        }
      }
      
      std::sort(ans.begin(), ans.end());
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 331894
- total submissions: 732737
- acceptance rate: 45.3%
- likes: 5196
- dislikes: 466

<br>

### Similar Problems

- [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower) (Easy)
- [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii) (Medium)
- [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance) (Hard)
- [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero) (Easy)
