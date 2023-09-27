# [1207] Unique Number of Occurrences

**[array, hash-table]**

### Statement

Given an array of integers `arr`, return `true` if the number of occurrences of each value in the array is **unique**, or `false` otherwise.


**Example 1:**

```

**Input:** arr = [1,2,2,1,1,3]
**Output:** true
**Explanation:**The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

**Example 2:**

```

**Input:** arr = [1,2]
**Output:** false

```

**Example 3:**

```

**Input:** arr = [-3,0,1,-3,1,1,1,-3,10,0]
**Output:** true

```

**Constraints:**
* `1 <= arr.length<= 1000`
* `-1000 <= arr[i] <= 1000`


<br>

### Hints

- Find the number of occurrences of each element in the array using a hash map.
- Iterate through the hash map and check if there is a repeated value.

<br>

### Solution

```cpp
class Solution {
  public:
    bool uniqueOccurrences (vector <int>& arr) {
      std::vector <int> freq (2001);
      std::vector <bool> freq_freq (1001);
      
      for (int i: arr)
        ++freq[i + 1000];
      
      for (int i: freq) {
        if (i > 0) {
          if (freq_freq[i] > 0)
            return false;
          freq_freq[i] = true;
        }
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 218503
- total submissions: 298333
- acceptance rate: 73.2%
- likes: 2792
- dislikes: 61

<br>

### Similar Problems

None
