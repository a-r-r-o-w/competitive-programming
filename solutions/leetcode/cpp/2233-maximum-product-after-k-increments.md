# [2233] Maximum Product After K Increments

**[array, greedy, heap-priority-queue]**

### Statement

You are given an array of non-negative integers `nums` and an integer `k`. In one operation, you may choose **any** element from `nums` and **increment** it by `1`.

Return *the **maximum** **product** of* `nums` *after **at most*** `k` *operations.* Since the answer may be very large, return it **modulo** `10^9 + 7`. Note that you should maximize the product before taking the modulo.


**Example 1:**

```

**Input:** nums = [0,4], k = 5
**Output:** 20
**Explanation:** Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.

```

**Example 2:**

```

**Input:** nums = [6,3,3,2], k = 2
**Output:** 216
**Explanation:** Increment the second number 1 time and increment the fourth number 1 time.
Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
It can be shown that 216 is maximum product possible, so we return 216.
Note that there may be other ways to increment nums to have the maximum product.

```

**Constraints:**
* `1 <= nums.length, k <= 10^5`
* `0 <= nums[i] <= 10^6`


<br />

### Hints

- If you can increment only once, which number should you increment?
- We should always prioritize the smallest number. What kind of data structure could we use?
- Use a min heap to hold all the numbers. Each time we do an operation, replace the top of the heap x by x + 1.

<br />

### Solution

```cpp
class Solution {
  public:
    int maximumProduct (vector <int>& nums, int k) {
      int n = nums.size();
      std::priority_queue <int> pq;

      for (int i: nums)
        pq.push(-i);
      
      while (k > 0) {
        int a = -pq.top(); pq.pop();
        --k;
        ++a;
        pq.push(-a);
      }
      
      const int64_t mod = 1000000007;
      int64_t product = 1;

      while (!pq.empty()) {
        product = (product * -pq.top()) % mod;
        pq.pop();
      }
      
      return product;
    }
};
```

<br />

### Statistics

- total accepted: 23364
- total submissions: 56954
- acceptance rate: 41.0%
- likes: 552
- dislikes: 36

<br />

### Similar Problems

- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) (Medium)
- [Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique) (Medium)
- [Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing) (Easy)
