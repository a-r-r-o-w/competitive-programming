# [1636] Sort Array by Increasing Frequency

**[array, hash-table, sorting]**

### Statement

Given an array of integers `nums`, sort the array in **increasing** order based on the frequency of the values. If multiple values have the same frequency, sort them in **decreasing** order.

Return the *sorted array*.


**Example 1:**

```

**Input:** nums = [1,1,2,2,2,3]
**Output:** [3,1,1,2,2,2]
**Explanation:** '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

```

**Example 2:**

```

**Input:** nums = [2,3,1,3,2]
**Output:** [1,3,3,2,2]
**Explanation:** '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

```

**Example 3:**

```

**Input:** nums = [-1,1,-6,4,5,-6,1,4,1]
**Output:** [5,-1,4,4,-6,-6,1,1,1]
```

**Constraints:**
* `1 <= nums.length <= 100`
* `-100 <= nums[i] <= 100`


<br />

### Hints

- Count the frequency of each value.
- Use a custom comparator to compare values by their frequency. If two values have the same frequency, compare their values.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> frequencySort (vector <int>& nums) {
      constexpr int max = 200 + 1, offset = 100;
      int n = nums.size();
      std::vector <int> freq (max);
      std::vector <std::pair <int, int>> pairs;

      for (int i: nums)
        ++freq[i + offset];
      for (int i = 0; i < max; ++i) {
        if (freq[i] == 0)
          continue;
        pairs.emplace_back(freq[i], i);
      }

      std::sort(pairs.begin(), pairs.end(), [&] (auto &l, auto &r) {
        if (l.first < r.first)
          return true;
        if (l.first > r.first)
          return false;
        return l.second > r.second;
      });

      nums.clear();
      for (auto &[p, q]: pairs)
        for (int i = 0; i < p; ++i)
          nums.push_back(q - offset);
      return nums;
    }
};
```

<br />

### Statistics

- total accepted: 89919
- total submissions: 129639
- acceptance rate: 69.4%
- likes: 2207
- dislikes: 85

<br />

### Similar Problems

- [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) (Medium)
- [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) (Easy)
- [Most Frequent Number Following Key In an Array](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array) (Easy)
- [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array) (Easy)
- [Node With Highest Edge Score](https://leetcode.com/problems/node-with-highest-edge-score) (Medium)
- [Sort the People](https://leetcode.com/problems/sort-the-people) (Easy)
