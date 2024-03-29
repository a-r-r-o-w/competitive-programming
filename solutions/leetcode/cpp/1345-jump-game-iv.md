# [1345] Jump Game IV

**[array, hash-table, breadth-first-search]**

### Statement

Given an array ofintegers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:

* `i + 1` where:`i + 1 < arr.length`.
* `i - 1` where:`i - 1 >= 0`.
* `j` where: `arr[i] == arr[j]` and `i != j`.



Return *the minimum number of steps* to reach the **last index** of the array.

Notice that you can not jump outside of the array at any time.


**Example 1:**

```

**Input:** arr = [100,-23,-23,404,100,23,23,23,3,404]
**Output:** 3
**Explanation:** You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

```

**Example 2:**

```

**Input:** arr = [7]
**Output:** 0
**Explanation:** Start index is the last index. You do not need to jump.

```

**Example 3:**

```

**Input:** arr = [7,6,9,6,9,6,9,7]
**Output:** 1
**Explanation:** You can jump directly from index 0 to index 7 which is last index of the array.

```

**Constraints:**
* `1 <= arr.length <= 5 * 10^4`
* `-10^8 <= arr[i] <= 10^8`


<br />

### Hints

- Build a graph of n nodes where nodes are the indices of the array and edges for node i are nodes i+1, i-1, j where arr[i] == arr[j].
- Start bfs from node 0 and keep distance. The answer is the distance when you reach node n-1.

<br />

### Solution

```cpp
class Solution {
  public:
    int minJumps (vector <int>& arr) {
      int n = arr.size();
      std::map <int, std::vector <int>> groups;
      std::set <int> visited_value;
      std::vector <bool> visited_index (n);
      std::queue <int> q;
      int depth = 0;

      for (int i = 0; i < n; ++i)
        groups[arr[i]].push_back(i);

      q.push(0);
      visited_index[0] = true;

      while (!q.empty()) {
        int s = q.size();

        for (int i = 0; i < s; ++i) {
          int u = q.front();
          q.pop();
          if (u == n - 1)
            return depth;
          if (u - 1 >= 0 and !visited_index[u - 1]) {
            q.push(u - 1);
            visited_index[u - 1] = true;
          }
          if (u + 1 < n and !visited_index[u + 1]) {
            q.push(u + 1);
            visited_index[u + 1] = true;
          }
          if (!visited_value.count(arr[u])) {
            visited_value.insert(arr[u]);
            for (int x: groups[arr[u]]) {
              if (u != x)
                q.push(x);
            }
          }
        }

        ++depth;
      }

      return -1;
    }
};
```

<br />

### Statistics

- total accepted: 114598
- total submissions: 247038
- acceptance rate: 46.4%
- likes: 3123
- dislikes: 108

<br />

### Similar Problems

- [Jump Game VII](https://leetcode.com/problems/jump-game-vii) (Medium)
- [Jump Game VIII](https://leetcode.com/problems/jump-game-viii) (Medium)
