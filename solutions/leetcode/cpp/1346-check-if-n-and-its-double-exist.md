# [1346] Check If N and Its Double Exist

**[array, hash-table, two-pointers, binary-search, sorting]**

### Statement

Given an array `arr` of integers, check if there exists two integers `N` and `M` such that `N` is the double of `M` ( i.e. `N = 2 * M`).

More formally check if there existstwo indices `i` and `j` such that :

* `i != j`
* `0 <= i, j < arr.length`
* `arr[i] == 2 * arr[j]`


**Example 1:**

```

**Input:** arr = [10,2,5,3]
**Output:** true
**Explanation:** N = 10 is the double of M = 5,that is, 10 = 2 * 5.

```

**Example 2:**

```

**Input:** arr = [7,1,14,11]
**Output:** true
**Explanation:** N = 14 is the double of M = 7,that is, 14 = 2 * 7.

```

**Example 3:**

```

**Input:** arr = [3,1,7,11]
**Output:** false
**Explanation:** In this case does not exist N and M, such that N = 2 \* M.

```

**Constraints:**
* `2 <= arr.length <= 500`
* `-10^3 <= arr[i] <= 10^3`


<br>

### Hints

- Loop from i = 0 to arr.length, maintaining in a hashTable the array elements from [0, i - 1].
- On each step of the loop check if we have seen the element 2 * arr[i] so far or arr[i] / 2 was seen if arr[i] % 2 == 0.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool checkIfExist (vector <int>& arr) {
      int n = arr.size();
      std::unordered_set <int> values;
      
      for (int i = 0; i < n; ++i) {
        if (values.count(2 * arr[i]) or (arr[i] % 2 == 0 and values.count(arr[i] / 2)))
          return true;
        values.insert(arr[i]);
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 219850
- total submissions: 613387
- acceptance rate: 35.8%
- likes: 1107
- dislikes: 133

<br>

### Similar Problems

- [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) (Easy)
