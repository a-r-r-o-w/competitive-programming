# [2594] Minimum Time to Repair Cars



### Statement

You are given an integer array `ranks` representing the **ranks** of some mechanics. ranksi is the rank of the i^th mechanic. A mechanic with a rank `r` can repair n cars in `r * n^2` minutes.

You are also given an integer `cars` representing the total number of cars waiting in the garage to be repaired.

Return *the **minimum** time taken to repair all the cars.*
**Note:** All the mechanics can repair the cars simultaneously.


**Example 1:**

```

**Input:** ranks = [4,2,3,1], cars = 10
**Output:** 16
**Explanation:** 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

```

**Example 2:**

```

**Input:** ranks = [5,1,8], cars = 6
**Output:** 16
**Explanation:** 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

```

**Constraints:**
* `1 <= ranks.length <= 10^5`
* `1 <= ranks[i] <= 100`
* `1 <= cars <= 10^6`


<br />

### Hints

- For a predefined fixed time, can all the cars be repaired?
- Try using binary search on the answer.

<br />

### Solution

```cpp
class Solution {
  public:
    long long repairCars (vector <int>& ranks, int cars) {
      int n = ranks.size();
      auto cost = [&] (int64_t time) {
        int64_t count = 0;
        for (int i = 0; i < n; ++i)
          count += std::sqrt(time / ranks[i]);
        return count >= cars;
      };
      int64_t low = 0, high = 1e18;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }
      
      return low;
    }
};
```

<br />

### Statistics

- total accepted: 6399
- total submissions: 14796
- acceptance rate: 43.2%
- likes: 234
- dislikes: 9

<br />

### Similar Problems

- [Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array) (Medium)
- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas) (Medium)
