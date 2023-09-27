# [1282] Group the People Given the Group Size They Belong To

**[array, hash-table]**

### Statement

There are `n` peoplethat are split into some unknown number of groups. Each person is labeled with a**unique ID**from`0`to`n - 1`.

You are given an integer array`groupSizes`, where `groupSizes[i]`is the size of the group that person`i`is in. For example, if`groupSizes[1] = 3`, thenperson`1`must be in agroup of size`3`.

Return*a list of groupssuch thateach person`i`is in a group of size`groupSizes[i]`*.

Each person shouldappear in**exactly one group**,and every person must be in a group. If there aremultiple answers, **return any of them**. It is **guaranteed** that there will be **at least one** valid solution for the given input.


**Example 1:**

```

**Input:** groupSizes = [3,3,3,3,3,1,3]
**Output:** [[5],[0,1,2],[3,4,6]]
**Explanation:** 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

```

**Example 2:**

```

**Input:** groupSizes = [2,1,3,3,3,2]
**Output:** [[1],[0,5],[2,3,4]]

```

**Constraints:**
* `groupSizes.length == n`
* `1 <= n<= 500`
* `1 <=groupSizes[i] <= n`


<br>

### Hints

- Put people's IDs with same groupSize into buckets, then split each bucket into groups.
- Greedy fill until you need a new group.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> groupThePeople (vector <int>& groupSizes) {
      int n = groupSizes.size();
      std::vector <std::vector <int>> ans;
      std::unordered_map <int, std::vector <int>> buckets;
      
      for (int i = 0; i < n; ++i)
        buckets[groupSizes[i]].push_back(i);
      
      for (auto &[x, y]: buckets) {
        std::vector <int> group;
        
        while (!y.empty()) {
          for (int i = 0; i < x; ++i) {
            group.push_back(y.back());
            y.pop_back();
          }
          ans.push_back(std::move(group));
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 85494
- total submissions: 99965
- acceptance rate: 85.5%
- likes: 1163
- dislikes: 489

<br>

### Similar Problems

None
