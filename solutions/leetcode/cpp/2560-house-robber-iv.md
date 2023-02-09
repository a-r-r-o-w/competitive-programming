# [2560] House Robber IV



### Statement

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he **refuses to steal from adjacent homes**.

The **capability** of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array `nums` representing how much money is stashed in each house. More formally, the `i^th` house from the left has `nums[i]` dollars.

You are also given an integer `k`, representing the **minimum** number of houses the robber will steal from.It is always possible to steal at least `k` houses.

Return *the **minimum*** capability of the robber out of all the possible ways to steal at least `k` houses.


**Example 1:**

```

**Input:** nums = [2,3,5,9], k = 2
**Output:** 5
**Explanation:** 
There are three ways to rob at least 2 houses:
- Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
- Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
- Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
Therefore, we return min(5, 9, 9) = 5.

```

**Example 2:**

```

**Input:** nums = [2,7,9,3,1], k = 2
**Output:** 2
**Explanation:** There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^9`
* `1 <= k <= (nums.length + 1)/2`


<br />

### Hints

- Can we use binary search to find the minimum value of a non-contiguous subsequence of a given size k?
- Initialize the search range with the minimum and maximum elements of the input array.
- Use a check function to determine if it is possible to select k non-consecutive elements that are less than or equal to the current "guess" value.
- Adjust the search range based on the outcome of the check function, until the range converges and the minimum value is found.

<br />

### Solution

```cpp
class Solution {
  public:
    int minCapability (vector <int>& nums, int k) {
      int n = nums.size();
      int low = 0, high = 1e9 + 1;
      
      auto cost = [&] (int x) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
          if (nums[i] <= x) {
            ++count;
            ++i;
          }
        }
        return count >= k;
      };
      
      while (low < high) {
        int mid = (low + high) / 2;
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

- total accepted: 3665
- total submissions: 13756
- acceptance rate: 26.6%
- likes: 168
- dislikes: 7

<br />

### Similar Problems

- [Container With Most Water](https://leetcode.com/problems/container-with-most-water) (Medium)
- [House Robber](https://leetcode.com/problems/house-robber) (Medium)
