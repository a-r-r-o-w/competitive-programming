# [2404] Most Frequent Even Element



### Statement

Given an integer array `nums`, return *the most frequent even element*.

If there is a tie, return the **smallest** one. If there is no such element, return `-1`.


**Example 1:**

```

**Input:** nums = [0,1,2,2,4,4,1]
**Output:** 2
**Explanation:**
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
```

**Example 2:**

```

**Input:** nums = [4,4,4,9,2,4]
**Output:** 4
**Explanation:** 4 is the even element appears the most.

```

**Example 3:**

```

**Input:** nums = [29,47,21,41,13,37,25,7]
**Output:** -1
**Explanation:** There is no even element.

```

**Constraints:**
* `1 <= nums.length <= 2000`
* `0 <= nums[i] <= 105`


<br>

### Hints

- Could you count the frequency of each even element in the array?
- Would a hashmap help?

<br>

### Solution

```cpp
class Solution {
  public:
    int mostFrequentEven (vector <int>& nums) {
      std::map <int, int> freq;
      
      for (int i: nums)
        if (i % 2 == 0)
          ++freq[i];
      
      if (freq.empty())
        return -1;
      
      std::map <int, std::vector <int>> rev;
      
      for (auto &[x, y]: freq)
        rev[y].push_back(x);
      
      std::sort(rev.rbegin()->second.begin(), rev.rbegin()->second.end());
      return rev.rbegin()->second.front();
    }
};
```

<br>

### Statistics

- total accepted: 17647
- total submissions: 34273
- acceptance rate: 51.5%
- likes: 117
- dislikes: 3

<br>

### Similar Problems

- [Majority Element](https://leetcode.com/problems/majority-element) (Easy)
- [Majority Element II](https://leetcode.com/problems/majority-element-ii) (Medium)
- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) (Medium)
