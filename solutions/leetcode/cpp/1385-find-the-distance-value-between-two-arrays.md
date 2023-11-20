# [1385] Find the Distance Value Between Two Arrays

**[array, two-pointers, binary-search, sorting]**

### Statement

Given two integer arrays `arr1` and `arr2`, and the integer `d`, *return the distance value between the two arrays*.

The distance value is defined as the number of elements `arr1[i]` such that there is not any element `arr2[j]` where `|arr1[i]-arr2[j]| <= d`.


**Example 1:**

```

**Input:** arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
**Output:** 2
**Explanation:** 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
**|8-10|=2 <= d=2**
**|8-9|=1 <= d=2**
|8-1|=7 > d=2
**|8-8|=0 <= d=2**

```

**Example 2:**

```

**Input:** arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
**Output:** 2

```

**Example 3:**

```

**Input:** arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
**Output:** 1

```

**Constraints:**
* `1 <= arr1.length, arr2.length <= 500`
* `-1000 <= arr1[i], arr2[j] <= 1000`
* `0 <= d <= 100`


<br>

### Hints

- Sort 'arr2' and use binary search to get the closest element for each 'arr1[i]', it gives a time complexity of O(nlogn).

<br>

### Solution

```cpp
class Solution {
  public:
    int findTheDistanceValue (vector <int>& arr1, vector <int>& arr2, int d) {
      std::sort(arr2.begin(), arr2.end());
      
      int count = 0;
      
      for (int i: arr1) {
        auto lb = std::lower_bound(arr2.begin(), arr2.end(), i);
        int min = 1 << 30;
        
        if (lb != arr2.end())
          min = std::min(min, *lb - i);
        
        if (lb != arr2.begin())
          min = std::min(min, i - *std::prev(lb));
        
        if (min > d)
          ++count;
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 62689
- total submissions: 96000
- acceptance rate: 65.3%
- likes: 549
- dislikes: 2090

<br>

### Similar Problems

None
