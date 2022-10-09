# [1539] Kth Missing Positive Number

**[array, binary-search]**

### Statement

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

Return *the* `kth` ***positive** integer that is **missing** from this array.*
**Example 1:**

```

**Input:** arr = [2,3,4,7,11], k = 5
**Output:** 9
**Explanation:** The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5thmissing positive integer is 9.

```

**Example 2:**

```

**Input:** arr = [1,2,3,4], k = 2
**Output:** 6
**Explanation:** The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

```

**Constraints:**
* `1 <= arr.length <= 1000`
* `1 <= arr[i] <= 1000`
* `1 <= k <= 1000`
* `arr[i] < arr[j]` for `1 <= i < j <= arr.length`


**Follow up:**

Could you solve this problem in less than O(n) complexity?

<br>

### Hints

- Keep track of how many positive numbers are missing as you scan the array.

<br>

### Solution

**O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findKthPositive (vector <int>& arr, int k) {
      int prev = 0, missing = 0, n = arr.size();
      
      for (int i = 0; i < n; ++i) {
        int x = arr[i] - prev - 1;
        if (missing + x >= k)
          return prev + k - missing;
        prev = arr[i];
        missing += x;
      }
      
      return arr.back() + k - missing;
    }
};
```

**O(log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findKthPositive (vector <int>& arr, int k) {
      int n = arr.size();
      int low = 0, high = n;
      
      while (low < high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - mid - 1;
        
        if (missing < k)
          low = mid + 1;
        else
          high = mid;
      }
      
      return k + low;
    }
};
```

<br>

### Statistics

- total accepted: 181635
- total submissions: 325982
- acceptance rate: 55.7%
- likes: 2842
- dislikes: 205

<br>

### Similar Problems

- [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum) (Medium)
