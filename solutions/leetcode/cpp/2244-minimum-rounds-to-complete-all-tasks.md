# [2244] Minimum Rounds to Complete All Tasks

**[array, hash-table, greedy, counting]**

### Statement

You are given a **0-indexed** integer array `tasks`, where `tasks[i]` represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the **same difficulty level**.

Return *the **minimum** rounds required to complete all the tasks, or* `-1` *if it is not possible to complete all the tasks.*
**Example 1:**

```

**Input:** tasks = [2,2,3,3,2,4,4,4,4,4]
**Output:** 4
**Explanation:** To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

```

**Example 2:**

```

**Input:** tasks = [2,3,3]
**Output:** -1
**Explanation:** There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.

```

**Constraints:**
* `1 <= tasks.length <= 105`
* `1 <= tasks[i] <= 109`


<br>

### Hints

- Which data structure can you use to store the number of tasks of each difficulty level?
- For any particular difficulty level, what can be the optimal strategy to complete the tasks using minimum rounds?
- When can we not complete all tasks of a difficulty level?

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumRounds (vector <int>& tasks) {
      std::map <int, int> freq;
      int count = 0;
      
      for (int i: tasks)
        ++freq[i];
      
      for (auto &[p, q]: freq) {
        if (q == 1)
          return -1;
        else if (q % 3 == 0)
          count += q / 3;
        else if (q % 3 == 1)
          count += (q - 4) / 3 + 2;
        else
          count += (q - 2) / 3 + 1;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 66168
- total submissions: 105769
- acceptance rate: 62.6%
- likes: 1312
- dislikes: 34

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)
- [Odd String Difference](https://leetcode.com/problems/odd-string-difference) (Easy)
