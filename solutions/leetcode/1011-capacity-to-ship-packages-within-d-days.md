# [1011] Capacity To Ship Packages Within D Days

**[array, binary-search]**

### Statement

A conveyor belt has packages that must be shipped from one port to another within `days` days.

The `ith` package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages on the conveyor belt (in the order given by `weights`). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within `days` days.


**Example 1:**

```

**Input:** weights = [1,2,3,4,5,6,7,8,9,10], days = 5
**Output:** 15
**Explanation:** A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

```

**Example 2:**

```

**Input:** weights = [3,2,2,4,1,4], days = 3
**Output:** 6
**Explanation:** A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

```

**Example 3:**

```

**Input:** weights = [1,2,3,1,1], days = 4
**Output:** 3
**Explanation:**
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

```

**Constraints:**
* `1 <= days <= weights.length <= 5 * 104`
* `1 <= weights[i] <= 500`


<br>

### Hints

- Binary search on the answer.  We need a function possible(capacity) which returns true if and only if we can do the task in D days.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int shipWithinDays (vector <int>& weights, int days) {
      auto cost = [&] (int x) {
        int sum = 0;
        int count = 1;
        
        for (auto &w: weights) {
          if (w > x)
            return true;
          else if (sum + w > x) {
            sum = w;
            ++count;
          }
          else
            sum += w;
        }
        
        return count > days;
      };
      
      int low = 0, high = 1e9;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }
      
      return low;
    }
};
```

<br>

### Statistics

- total accepted: 163361
- total submissions: 255161
- acceptance rate: 64.0%
- likes: 4774
- dislikes: 109

<br>

### Similar Problems

- [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) (Hard)
- [Divide Chocolate](https://leetcode.com/problems/divide-chocolate) (Hard)
- [Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons) (Medium)
- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
- [Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks) (Medium)
