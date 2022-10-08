# [852] Peak Index in a Mountain Array

**[array, binary-search]**

### Statement

An array `arr` a **mountain** if the following properties hold:

* `arr.length >= 3`
* There exists some `i` with `0 < i < arr.length - 1` such that:
	+ `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
	+ `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`



Given a mountain array `arr`, return the index `i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in `O(log(arr.length))` time complexity.


**Example 1:**

```

**Input:** arr = [0,1,0]
**Output:** 1

```

**Example 2:**

```

**Input:** arr = [0,2,1,0]
**Output:** 1

```

**Example 3:**

```

**Input:** arr = [0,10,5,2]
**Output:** 1

```

**Constraints:**
* `3 <= arr.length <= 105`
* `0 <= arr[i] <= 106`
* `arr` is **guaranteed** to be a mountain array.


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
  
    int peakIndexInMountainArray (vector <int>& arr) {
      int n = arr.size();
      int low = 0, high = n;
      
      while (low < high) {
        int mid = (low + high) / 2;
        bool good = true;
        
        for (int i = 0; i < mid; ++i)
          if (arr[i] >= arr[i + 1]) {
            good = false;
            break;
          }
        
        if (good)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

or

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int peakIndexInMountainArray (vector <int>& arr) {
      int n = arr.size();
      int low = 0, high = n, prev = arr[0];
      
      arr[0] = true;
      
      for (int i = 1; i < n; ++i) {
        int t = arr[i];
        arr[i] = arr[i - 1];
        if (t <= prev)
          arr[i] = false;
        prev = t;
      }
      
      while (low < high) {
        int mid = (low + high) / 2;
        
        if (arr[mid])
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

<br>

### Statistics

- total accepted: 446967
- total submissions: 642069
- acceptance rate: 69.6%
- likes: 3591
- dislikes: 1719

<br>

### Similar Problems

- [Find Peak Element](https://leetcode.com/problems/find-peak-element) (Medium)
- [Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array) (Hard)
- [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array) (Hard)
