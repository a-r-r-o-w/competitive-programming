# [2454] Next Greater Element IV



### Statement

You are given a **0-indexed** array of non-negative integers `nums`. For each integer in `nums`, you must find its respective **second greater** integer.

The **second greater** integer of `nums[i]` is `nums[j]` such that:

* `j > i`
* `nums[j] > nums[i]`
* There exists **exactly one** index `k` such that `nums[k] > nums[i]` and `i < k < j`.



If there is no such `nums[j]`, the second greater integer is considered to be `-1`.

* For example, in the array `[1, 2, 4, 3]`, the second greater integer of `1` is `4`, `2` is `3`,and that of `3` and `4` is `-1`.



Return *an integer array* `answer`*, where* `answer[i]` *is the second greater integer of* `nums[i]`*.*
**Example 1:**

```

**Input:** nums = [2,4,0,9,6]
**Output:** [9,6,6,-1,-1]
**Explanation:**
0th index: 4 is the first integer greater than 2, and 9 is the second integer greater than 2, to the right of 2.
1st index: 9 is the first, and 6 is the second integer greater than 4, to the right of 4.
2nd index: 9 is the first, and 6 is the second integer greater than 0, to the right of 0.
3rd index: There is no integer greater than 9 to its right, so the second greater integer is considered to be -1.
4th index: There is no integer greater than 6 to its right, so the second greater integer is considered to be -1.
Thus, we return [9,6,6,-1,-1].

```

**Example 2:**

```

**Input:** nums = [3,3]
**Output:** [-1,-1]
**Explanation:**
We return [-1,-1] since neither integer has any integer greater than it.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`


<br>

### Hints

- Move forward in nums and store the value in a non-increasing stack for the first greater value.
- Move the value in the stack to an ordered data structure for the second greater value.
- Move value from the ordered data structure for the answer.

<br>

### Solution

```cpp
const std::pair <int, int> NONE = {-1, -1};

class increasing_stack_t {
  public:
    std::vector <std::pair <int, int>> s;

    void update_stack (int value, int index) {
      while (!s.empty() && value <= s.back().first)
        s.pop_back();
      s.push_back({value, index});
    }

    std::pair <int, int> last_lower (int value) {
      if (s.empty())
        return NONE;
      auto it = lower_bound(s.begin(), s.end(), std::make_pair(value, 0)) - 1;
      if (it >= s.begin())
        return *it;
      return NONE;
    }
};

class Solution {
  public:
    vector <int> secondGreaterElement (vector <int>& nums) {
      const int inf32 = 1 << 30;
      int n = nums.size();
      std::vector <int> ans (n, -1);
      increasing_stack_t next;
      
      for (int &i: nums)
        i = -i;
      std::reverse(nums.begin(), nums.end());
    
      std::pair <int, int> p;
      std::vector <std::vector <std::pair <int, int>>> queries (n);

      for (int i = 0; i < n; i++) {
        if (NONE != (p = next.last_lower(nums[i])))
          queries[p.second].push_back({nums[i], i});
        next.update_stack(nums[i], i);
      }

      next.s.clear();
      
      for (int i = 0; i < n; i++) {
        for (auto &[u, v]: queries[i])
          if (NONE != (p = next.last_lower(u)))
            ans[n - v - 1] = -p.first;
        next.update_stack(nums[i], i);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 3351
- total submissions: 9016
- acceptance rate: 37.2%
- likes: 204
- dislikes: 2

<br>

### Similar Problems

- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) (Easy)
- [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) (Easy)
