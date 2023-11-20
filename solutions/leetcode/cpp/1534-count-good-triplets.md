# [1534] Count Good Triplets

**[array, enumeration]**

### Statement

Given an array of integers `arr`, and three integers`a`,`b`and`c`. You need to find the number of good triplets.

A triplet `(arr[i], arr[j], arr[k])`is **good** if the following conditions are true:

* `0 <= i < j < k <arr.length`
* `|arr[i] - arr[j]| <= a`
* `|arr[j] - arr[k]| <= b`
* `|arr[i] - arr[k]| <= c`



Where `|x|` denotes the absolute value of `x`.

Return *the number of good triplets*.


**Example 1:**

```

**Input:** arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
**Output:** 4
**Explanation:**There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].

```

**Example 2:**

```

**Input:** arr = [1,1,2,2,3], a = 0, b = 0, c = 1
**Output:** 0
**Explanation:** No triplet satisfies all conditions.

```

**Constraints:**
* `3 <= arr.length <= 100`
* `0 <= arr[i] <= 1000`
* `0 <= a, b, c <= 1000`


<br>

### Hints

- Notice that the constraints are small enough for a brute force solution to pass.
- Loop through all triplets, and count the ones that are good.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countGoodTriplets (vector <int>& v, int a, int b, int c) {
      int n = v.size();
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (std::abs(v[i] - v[j]) <= a) {
            for (int k = j + 1; k < n; ++k) {
              if (std::abs(v[j] - v[k]) <= b and std::abs(v[k] - v[i]) <= c)
                ++ans;
            }
          }
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 81464
- total submissions: 100942
- acceptance rate: 80.7%
- likes: 474
- dislikes: 956

<br>

### Similar Problems

- [Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets) (Easy)
