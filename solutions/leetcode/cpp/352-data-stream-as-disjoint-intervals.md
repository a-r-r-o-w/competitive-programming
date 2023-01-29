# [352] Data Stream as Disjoint Intervals

**[binary-search, design, ordered-set]**

### Statement

Given a data stream input of non-negative integers `a1, a2, ..., an`, summarize the numbers seen so far as a list of disjoint intervals.

Implement the `SummaryRanges` class:

* `SummaryRanges()` Initializes the object with an empty stream.
* `void addNum(int value)` Adds the integer `value` to the stream.
* `int[][] getIntervals()` Returns a summary of the integers in the stream currently as a list of disjoint intervals `[starti, endi]`. The answer should be sorted by `starti`.


**Example 1:**

```

**Input**
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
**Output**
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

**Explanation**
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]

```

**Constraints:**
* `0 <= value <= 10^4`
* At most `3 * 10^4` calls will be made to `addNum` and `getIntervals`.


**Follow up:** What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?

<br />

### Hints

None

<br />

### Solution

```cpp
constexpr int maxA = 10000 + 1;
constexpr int inf32 = 1 << 30;

class SummaryRanges {
    std::vector <int> parent, rank;
    std::unordered_map <int, std::pair <int, int>> intervals;

  public:
    SummaryRanges () {
      parent.resize(maxA, -1);
      rank.resize(maxA);
    }

    int find (int u) {
      return parent[u] = u == parent[u] ? u : find(parent[u]);
    }

    void unite (int u, int v) {
      u = find(u);
      v = find(v);
      
      if (u == v)
        return;
      if (rank[u] < rank[v])
        std::swap(u, v);
      
      intervals[u] = {std::min(intervals[u].first, intervals[v].first), std::max(intervals[u].second, intervals[v].second)};
      intervals.erase(v);
      ++rank[u];
      parent[v] = u;
    }
    
    void addNum (int value) {
      if (parent[value] != -1)
        return;
      
      parent[value] = value;
      intervals[value] = {value, value};
      
      if (value - 1 >= 0 and parent[value - 1] != -1)
        unite(value - 1, value);
      if (value + 1 < maxA and parent[value + 1] != -1)
        unite(value, value + 1);
    }
    
    vector <vector <int>> getIntervals () {
      std::vector <std::vector <int>> ans;

      for (auto &[p, q]: intervals)
        ans.push_back({q.first, q.second});
      std::sort(ans.begin(), ans.end());

      return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```

<br />

### Statistics

- total accepted: 56555
- total submissions: 109188
- acceptance rate: 51.8%
- likes: 756
- dislikes: 170

<br />

### Similar Problems

- [Summary Ranges](https://leetcode.com/problems/summary-ranges) (Easy)
- [Find Right Interval](https://leetcode.com/problems/find-right-interval) (Medium)
- [Range Module](https://leetcode.com/problems/range-module) (Hard)
- [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals) (Hard)
