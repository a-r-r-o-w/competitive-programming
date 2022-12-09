# [433] Minimum Genetic Mutation

**[hash-table, string, breadth-first-search]**

### Statement

A gene string can be represented by an 8-character long string, with choices from `'A'`, `'C'`, `'G'`, and `'T'`.

Suppose we need to investigate a mutation from a gene string `start` to a gene string `end` where one mutation is defined as one single character changed in the gene string.

* For example, `"AACCGGTT" --> "AACCGGTA"` is one mutation.



There is also a gene bank `bank` that records all the valid gene mutations. A gene must be in `bank` to make it a valid gene string.

Given the two gene strings `start` and `end` and the gene bank `bank`, return *the minimum number of mutations needed to mutate from* `start` *to* `end`. If there is no such a mutation, return `-1`.

Note that the starting point is assumed to be valid, so it might not be included in the bank.


**Example 1:**

```

**Input:** start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
**Output:** 1

```

**Example 2:**

```

**Input:** start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
**Output:** 2

```

**Example 3:**

```

**Input:** start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
**Output:** 3

```

**Constraints:**
* `start.length == 8`
* `end.length == 8`
* `0 <= bank.length <= 10`
* `bank[i].length == 8`
* `start`, `end`, and `bank[i]` consist of only the characters `['A', 'C', 'G', 'T']`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minMutation (string start, string end, vector <string>& bank) {
      int n = bank.size(), m = 8, depth = 0;
      std::queue <std::string> q;
      std::unordered_set <std::string> have;
      
      q.push(start);
      have.insert(start);
      
      while (!q.empty()) {
        int k = q.size();
        
        for (int i = 0; i < k; ++i) {
          auto gene = q.front();
          q.pop();
          
          if (gene == end)
            return depth;
          
          for (int i = 0; i < m; ++i) {
            for (char c: "ATCG") {
              std::string mutation = gene;
              bool contains = false;
              
              mutation[i] = c;
              
              if (have.count(mutation))
                continue;
              
              for (int j = 0; j < n; ++j)
                if (bank[j] == mutation) {
                  contains = true;
                  break;
                }
              
              if (contains) {
                q.push(mutation);
                have.insert(mutation);
              }
            }
          }
        }
        
        ++depth;
      }
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 67700
- total submissions: 138093
- acceptance rate: 49.0%
- likes: 1247
- dislikes: 131

<br>

### Similar Problems

- [Word Ladder](https://leetcode.com/problems/word-ladder) (Hard)
