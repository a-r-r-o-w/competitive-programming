# [659] Split Array into Consecutive Subsequences

**[array, hash-table, greedy, heap-priority-queue]**

### Statement

You are given an integer array `nums` that is **sorted in non-decreasing order**.

Determine if it is possible to split `nums` into **one or more subsequences** such that **both** of the following conditions are true:

* Each subsequence is a **consecutive increasing sequence** (i.e. each integer is **exactly one** more than the previous integer).
* All subsequences have a length of `3` **or more**.



Return `true` *if you can split* `nums` *according to the above conditions, or* `false` *otherwise*.

A **subsequence** of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., `[1,3,5]` is a subsequence of `[1,2,3,4,5]` while `[1,3,2]` is not).


**Example 1:**

```

**Input:** nums = [1,2,3,3,4,5]
**Output:** true
**Explanation:** nums can be split into the following subsequences:
[**1**,**2**,**3**,3,4,5] --> 1, 2, 3
[1,2,3,**3**,**4**,**5**] --> 3, 4, 5

```

**Example 2:**

```

**Input:** nums = [1,2,3,3,4,4,5,5]
**Output:** true
**Explanation:** nums can be split into the following subsequences:
[**1**,**2**,**3**,3,**4**,4,**5**,5] --> 1, 2, 3, 4, 5
[1,2,3,**3**,4,**4**,5,**5**] --> 3, 4, 5

```

**Example 3:**

```

**Input:** nums = [1,2,3,4,4,5]
**Output:** false
**Explanation:** It is impossible to split nums into consecutive increasing subsequences of length 3 or more.

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-1000 <= nums[i] <= 1000`
* `nums` is sorted in **non-decreasing** order.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool isPossible (vector <int>& nums) {
      int n = nums.size();
      std::unordered_map <int, int> endings, count;
      
      for (int i: nums)
        ++count[i];
      
      for (int i: nums) {
        if (not count[i])
          continue;
        --count[i];
        if (endings[i - 1] > 0) {
          --endings[i - 1];
          ++endings[i];
        }
        else if (count[i + 1] > 0 and count[i + 2] > 0) {
          --count[i + 1];
          --count[i + 2];
          ++endings[i + 2];
        }
        else
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 100698
- total submissions: 204152
- acceptance rate: 49.3%
- likes: 3502
- dislikes: 695

<br>

### Similar Problems

- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [Divide Array in Sets of K Consecutive Numbers](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers) (Medium)
