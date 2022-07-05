# [128] Longest Consecutive Sequence

**[array, hash-table, union-find]**

### Statement

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in`O(n)`time.


**Example 1:**

```

**Input:** nums = [100,4,200,1,3,2]
**Output:** 4
**Explanation:** The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

```

**Example 2:**

```

**Input:** nums = [0,3,7,2,5,8,4,6,0,1]
**Output:** 9

```

**Constraints:**
* `0 <= nums.length <= 105`
* `-109 <= nums[i] <= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int longestConsecutive (vector <int>& nums) {
      int n = nums.size();
      
      if (n == 0)
        return 0;
      
      std::vector <int> parent (n), size (n, 1);
      std::unordered_map <int, int> have;
      
      std::iota(parent.begin(), parent.end(), 0);
      
      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };
      
      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);
        
        if (parent[u] == parent[v])
          return;
        if (size[u] < size[v])
          std::swap(u, v);
        parent[v] = parent[u];
        size[u] += size[v];
      };
      
      for (int i = 0; i < n; ++i) {
        if (have.count(nums[i]))
          continue;
        
        have[nums[i]] = i;
        
        if (have.count(nums[i] - 1))
          unite(have[nums[i] - 1], have[nums[i]]);
        if (have.count(nums[i] + 1))
          unite(have[nums[i] + 1], have[nums[i]]);
      }
      
      return *std::max_element(size.begin(), size.end());
    }
};
```

<br>

### Statistics

- total accepted: 746940
- total submissions: 1527974
- acceptance rate: 48.9%
- likes: 10761
- dislikes: 467

<br>

### Similar Problems

- [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence) (Medium)
- [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number) (Medium)
- [Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors) (Medium)
