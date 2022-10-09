# [2007] Find Original Array From Doubled Array

**[array, hash-table, greedy, sorting]**

### Statement

An integer array `original` is transformed into a **doubled** array `changed` by appending **twice the value** of every element in `original`, and then randomly **shuffling** the resulting array.

Given an array `changed`, return `original` *if* `changed` *is a **doubled** array. If* `changed` *is not a **doubled** array, return an empty array. The elements in* `original` *may be returned in **any** order*.


**Example 1:**

```

**Input:** changed = [1,3,4,2,6,8]
**Output:** [1,3,4]
**Explanation:** One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].

```

**Example 2:**

```

**Input:** changed = [6,3,0,1]
**Output:** []
**Explanation:** changed is not a doubled array.

```

**Example 3:**

```

**Input:** changed = [1]
**Output:** []
**Explanation:** changed is not a doubled array.

```

**Constraints:**
* `1 <= changed.length <= 105`
* `0 <= changed[i] <= 105`


<br>

### Hints

- If changed is a doubled array, you should be able to delete elements and their doubled values until the array is empty.
- Which element is guaranteed to not be a doubled value? It is the smallest element.
- After removing the smallest element and its double from changed, is there another number that is guaranteed to not be a doubled value?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> findOriginalArray (vector <int>& changed) {
      int n = changed.size();
      
      if (n & 1)
        return {};
      
      std::sort(changed.begin(), changed.end());
      
      int i = 0, j = 0;
      std::vector <int> ans;
      
      while (j < n) {
        while (i < n and changed[i] == -1)
          ++i;
        
        j = std::max(j, i + 1);
        
        while (j < n and 2 * changed[i] > changed[j])
          ++j;
        
        if (j < n and 2 * changed[i] == changed[j]) {
          ans.push_back(changed[i]);
          changed[i] = -1;
          changed[j] = -1;
          ++i;
          ++j;
        }
        else
          return {};
      }
      
      return (int)ans.size() == n / 2 ? ans : std::vector <int> {};
    }
};
```

<br>

### Statistics

- total accepted: 69340
- total submissions: 172418
- acceptance rate: 40.2%
- likes: 1157
- dislikes: 77

<br>

### Similar Problems

- [Array of Doubled Pairs](https://leetcode.com/problems/array-of-doubled-pairs) (Medium)
- [Recover the Original Array](https://leetcode.com/problems/recover-the-original-array) (Hard)
