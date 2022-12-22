# [179] Largest Number

**[string, greedy, sorting]**

### Statement

Given a list of non-negative integers `nums`, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.


**Example 1:**

```

**Input:** nums = [10,2]
**Output:** "210"

```

**Example 2:**

```

**Input:** nums = [3,30,34,5,9]
**Output:** "9534330"

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string largestNumber (vector <int>& nums) {
      int n = nums.size();
      std::vector <std::string> s (n);
      
      std::transform(nums.begin(), nums.end(), s.begin(), [&] (int x) { return std::to_string(x); });
      std::sort(s.begin(), s.end(), [&] (auto &l, auto &r) {
        return l + r > r + l;
      });
      
      auto result = std::accumulate(s.begin(), s.end(), std::string());
      
      if (result.front() == '0')
        result = "0";
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 351414
- total submissions: 1038900
- acceptance rate: 33.8%
- likes: 5785
- dislikes: 482

<br>

### Similar Problems

- [Smallest Value of the Rearranged Number](https://leetcode.com/problems/smallest-value-of-the-rearranged-number) (Medium)
