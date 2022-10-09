# [1338] Reduce Array Size to The Half

**[array, hash-table, greedy, sorting, heap-priority-queue]**

### Statement

You are given an integer array `arr`. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return *the minimum size of the set so that **at least** half of the integers of the array are removed*.


**Example 1:**

```

**Input:** arr = [3,3,3,3,5,5,5,2,2,7]
**Output:** 2
**Explanation:** Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

```

**Example 2:**

```

**Input:** arr = [7,7,7,7,7,7]
**Output:** 1
**Explanation:** The only possible set you can choose is {7}. This will make the new array empty.

```

**Constraints:**
* `2 <= arr.length <= 105`
* `arr.length` is even.
* `1 <= arr[i] <= 105`


<br>

### Hints

- Count the frequency of each integer in the array.
- Start with an empty set, add to the set the integer with the maximum frequency.
- Keep Adding the integer with the max frequency until you remove at least half of the integers.

<br>

### Solution

```cpp
class Solution {
  public:
    int minSetSize (vector <int>& arr) {
      int n = arr.size();
      std::unordered_map <int, int> freq;
      
      for (int x: arr)
        ++freq[x];
      
      std::vector <int> order;
      
      for (auto &[x, y]: freq)
        order.push_back(y);
      
      std::sort(order.rbegin(), order.rend());
      
      int m = 0, count = 0;
      
      for (int i = 0; i < (int)order.size() and 2 * m < n; ++i) {
        m += order[i];
        ++count;
      }
  
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 141607
- total submissions: 202252
- acceptance rate: 70.0%
- likes: 2483
- dislikes: 129

<br>

### Similar Problems

None
