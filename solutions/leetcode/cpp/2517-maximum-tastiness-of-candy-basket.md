# [2517] Maximum Tastiness of Candy Basket



### Statement

You are given an array of positive integers `price` where `price[i]` denotes the price of the `ith` candy and a positive integer `k`.

The store sells baskets of `k` **distinct** candies. The **tastiness** of a candy basket is the smallest absolute difference of the **prices** of any two candies in the basket.

Return *the **maximum** tastiness of a candy basket.*
**Example 1:**

```

**Input:** price = [13,5,1,8,21,2], k = 3
**Output:** 8
**Explanation:** Choose the candies with the prices [13,5,21].
The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8.
It can be proven that 8 is the maximum tastiness that can be achieved.

```

**Example 2:**

```

**Input:** price = [1,3,1], k = 2
**Output:** 2
**Explanation:** Choose the candies with the prices [1,3].
The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
It can be proven that 2 is the maximum tastiness that can be achieved.

```

**Example 3:**

```

**Input:** price = [7,7,7,7], k = 2
**Output:** 0
**Explanation:** Choosing any two distinct candies from the candies we have will result in a tastiness of 0.

```

**Constraints:**
* `1 <= price.length <= 105`
* `1 <= price[i] <= 109`
* `2 <= k <= price.length`


<br>

### Hints

- The answer is binary searchable.
- For some x, we can use a greedy strategy to check if it is possible to pick k distinct candies with tastiness being at least x.
- Sort prices and iterate from left to right. For some price[i] check if the price difference between the last taken candy and price[i] is at least x. If so, add the candy i to the basket.
- So, a candy basket with tastiness x can be achieved if the basket size is bigger than or equal to k.

<br>

### Solution

```cpp
class Solution {
  public:
    int maximumTastiness (vector <int>& price, int k) {
      int n = price.size();
      int64_t low = 0, high = 1e15;
      
      std::sort(price.begin(), price.end());
      
      auto cost = [&] (int64_t x) {
        int64_t current = 1e15, count = 0;
        
        for (int i = n - 1; i >= 0; --i) {
          if (price[i] <= current) {
            current = price[i] - x;
            count += 1;
          }
        }
        
        return count >= k;
      };
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        
        if (cost(mid))
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

- total accepted: 2789
- total submissions: 4936
- acceptance rate: 56.5%
- likes: 104
- dislikes: 4

<br>

### Similar Problems

- [Container With Most Water](https://leetcode.com/problems/container-with-most-water) (Medium)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) (Hard)
