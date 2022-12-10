# [907] Sum of Subarray Minimums

**[array, dynamic-programming, stack, monotonic-stack]**

### Statement

Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `109 + 7`.


**Example 1:**

```

**Input:** arr = [3,1,2,4]
**Output:** 17
**Explanation:** 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

```

**Example 2:**

```

**Input:** arr = [11,81,94,43,3]
**Output:** 444

```

**Constraints:**
* `1 <= arr.length <= 3 * 104`
* `1 <= arr[i] <= 3 * 104`


<br>

### Hints

None

<br>

### Solution

Sorting + Binary search

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int sumSubarrayMins (vector <int>& arr) {
      const int mod = 1000000007;
      int n = arr.size();
      int64_t sum = 0;
      std::vector <int> order (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return arr[l] < arr[r];
      });
      
      std::set <int> usedleft, usedright;
      
      usedleft.insert(1);
      usedleft.insert(-n);
      usedright.insert(-1);
      usedright.insert(n);
      
      for (int i = 0; i < n; ++i) {
        int j = order[i];
        int l = -*usedleft.upper_bound(-j);
        int r = *usedright.upper_bound(j);
        
        sum = (sum + int64_t(arr[j]) * (r - j) * (j - l)) % mod;
        usedleft.insert(-j);
        usedright.insert(j);
      }
      
      return sum;
    }
};
```

Monotonic Stack

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int sumSubarrayMins (vector <int>& arr) {
      const int mod = 1000000007;
      int n = arr.size();
      int64_t sum = 0;
      std::stack <int> have;
      
      for (int i = 0; i < n; ++i) {
        while (!have.empty() and arr[have.top()] >= arr[i]) {
          int t = have.top();
          have.pop();
          
          int l = have.empty() ? -1 : have.top();
          int r = i;
          
          sum = (sum + int64_t(arr[t]) * (r - t) * (t - l)) % mod;
        }
        
        have.push(i);
      }
      
      while (!have.empty()) {
        int t = have.top();
        have.pop();
        
        int l = have.empty() ? -1 : have.top();
        int r = n;
        
        sum = (sum + int64_t(arr[t]) * (r - t) * (t - l)) % mod;
      }
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 107026
- total submissions: 310004
- acceptance rate: 34.5%
- likes: 4573
- dislikes: 308

<br>

### Similar Problems

- [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges) (Medium)
- [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards) (Hard)
