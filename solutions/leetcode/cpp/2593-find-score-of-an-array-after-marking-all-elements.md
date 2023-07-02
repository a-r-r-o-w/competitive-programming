# [2593] Find Score of an Array After Marking All Elements



### Statement

You are given an array `nums` consisting of positive integers.

Starting with `score = 0`, apply the following algorithm:

* Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
* Add the value of the chosen integer to `score`.
* Mark **the chosen element and its two adjacent elements if they exist**.
* Repeat until all the array elements are marked.



Return *the score you get after applying the above algorithm*.


**Example 1:**

```

**Input:** nums = [2,1,3,4,5,2]
**Output:** 7
**Explanation:** We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

```

**Example 2:**

```

**Input:** nums = [2,3,5,1,3,2]
**Output:** 5
**Explanation:** We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^6`


<br />

### Hints

- Try simulating the process of marking the elements and their adjacent.
- If there is an element that was already marked, then you skip it.

<br />

### Solution

```cpp
class Solution {
  public:
    long long findScore (vector <int>& nums) {
      int n = nums.size();
      int64_t score = 0;
      std::map <int, std::set <int>> have;
      
      for (int i = 0; i < n; ++i)
        have[nums[i]].insert(i);
      
      while (!have.empty()) {
        int smallest = have.begin()->first;
        int index = *have[smallest].begin();
        score += smallest;
        have[smallest].erase(index);
        if (have[smallest].empty())
          have.erase(smallest);
        if (index - 1 >= 0) {
          have[nums[index - 1]].erase(index - 1);
          if (have[nums[index - 1]].empty())
            have.erase(nums[index - 1]);
        }
        if (index + 1 < n) {
          have[nums[index + 1]].erase(index + 1);
          if (have[nums[index + 1]].empty())
            have.erase(nums[index + 1]);
        }
      }
      
      return score;
    }
};
```

<br />

### Statistics

- total accepted: 9230
- total submissions: 18000
- acceptance rate: 51.3%
- likes: 157
- dislikes: 2

<br />

### Similar Problems

- [Sort Integers by The Power Value](https://leetcode.com/problems/sort-integers-by-the-power-value) (Medium)
