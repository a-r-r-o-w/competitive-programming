# [332] Reconstruct Itinerary

**[depth-first-search, graph, eulerian-circuit]**

### Statement

You are given a list of airline `tickets` where `tickets[i] = [fromi, toi]` represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from `"JFK"`, thus, the itinerary must begin with `"JFK"`. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

* For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.



You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)

```

**Input:** tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
**Output:** ["JFK","MUC","LHR","SFO","SJC"]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg)

```

**Input:** tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
**Output:** ["JFK","ATL","JFK","SFO","ATL","SFO"]
**Explanation:** Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

```

**Constraints:**
* `1 <= tickets.length <= 300`
* `tickets[i].length == 2`
* `fromi.length == 3`
* `toi.length == 3`
* `fromi` and `toi` consist of uppercase English letters.
* `fromi != toi`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <string> findItinerary(vector <vector <string>>& tickets) {
      int m = tickets.size();
      std::map <std::string, int> encode;
      std::map <int, std::string> decode;

      for (auto &v: tickets) {
        encode[v[0]];
        encode[v[1]];
      }
      int n = 0;
      for (auto &[x, y]: encode) {
        y = n++;
        decode[y] = x;
      }
      
      std::vector <std::vector <int>> graph(n);
      for (auto &v: tickets)
        graph[encode[v[0]]].push_back(encode[v[1]]);
      for (int i = 0; i < n; ++i)
        std::sort(graph[i].begin(), graph[i].end(), [&] (auto &l, auto &r) {
          return decode[l] > decode[r];
        });
      
      std::vector <int> order;

      auto dfs = [&] (auto self, int u) -> void {
        while (!graph[u].empty()) {
          int v = graph[u].back();
          graph[u].pop_back();
          self(self, v);
        }
        order.push_back(u);
      };

      dfs(dfs, encode["JFK"]);
      
      std::vector <std::string> ans(order.size());
      std::transform(order.begin(), order.end(), ans.rbegin(), [&] (auto &x) {
        return decode[x];
      });

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 367111
- total submissions: 863060
- acceptance rate: 42.5%
- likes: 5285
- dislikes: 1753

<br />

### Similar Problems

- [Longest Common Subpath](https://leetcode.com/problems/longest-common-subpath) (Hard)
- [Valid Arrangement of Pairs](https://leetcode.com/problems/valid-arrangement-of-pairs) (Hard)
