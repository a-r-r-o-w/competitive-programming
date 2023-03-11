# [2530] Maximal Score After Applying K Operations



### Statement

You are given a **0-indexed** integer array `nums` and an integer `k`. You have a **starting score** of `0`.

In one **operation**:

1. choose an index `i` such that `0 <= i < nums.length`,
2. increase your **score** by `nums[i]`, and
3. replace `nums[i]` with `ceil(nums[i] / 3)`.



Return *the maximum possible **score** you can attain after applying **exactly*** `k` *operations*.

The ceiling function `ceil(val)` is the least integer greater than or equal to `val`.


**Example 1:**

```

**Input:** nums = [10,10,10,10,10], k = 5
**Output:** 50
**Explanation:** Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

```

**Example 2:**

```

**Input:** nums = [1,10,3,3,3], k = 3
**Output:** 17
**Explanation:** You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,**4**,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,**2**,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,**1**,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.

```

**Constraints:**
* `1 <= nums.length, k <= 105`
* `1 <= nums[i] <= 109`


<br>

### Hints

- It is always optimal to select the greatest element in the array.
- Use a heap to query for the maximum in O(log n) time.

<br>

### Solution

```cpp
class Solution {
  public:
    long long maxKelements (vector <int>& nums, int k) {
      int64_t score = 0;
      std::priority_queue <int> pq;
      
      for (int i: nums)
        pq.push(i);
      
      while (k--) {
        int t = pq.top();
        pq.pop();
        score += t;
        pq.push((t + 2) / 3);
      }
      
      return score;
    }
};
```

<br>

### Statistics

- total accepted: 11724
- total submissions: 29867
- acceptance rate: 39.3%
- likes: 102
- dislikes: 1

<br>

### Similar Problems

- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) (Hard)
- [Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total) (Medium)
