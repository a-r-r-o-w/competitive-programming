# [1834] Single-Threaded CPU

**[array, sorting, heap-priority-queue]**

### Statement

You are given `n`​​​​​​ tasks labeled from `0` to `n - 1` represented by a 2D integer array `tasks`, where `tasks[i] = [enqueueTimei, processingTimei]` means that the `i​​​​​​th`​​​​ task will be available to process at `enqueueTimei` and will take `processingTimei`to finish processing.

You have a single-threaded CPU that can process **at most one** task at a time and will act in the following way:

* If the CPU is idle and there are no available tasks to process, the CPU remains idle.
* If the CPU is idle and there are available tasks, the CPU will choose the one with the **shortest processing time**. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
* Once a task is started, the CPU will **process the entire task** without stopping.
* The CPU can finish a task then start a new one instantly.



Return *the order in which the CPU will process the tasks.*
**Example 1:**

```

**Input:** tasks = [[1,2],[2,4],[3,2],[4,1]]
**Output:** [0,2,3,1]
**Explanation:** The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

```

**Example 2:**

```

**Input:** tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
**Output:** [4,3,2,0,1]
**Explanation****:** The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.

```

**Constraints:**
* `tasks.length == n`
* `1 <= n <= 105`
* `1 <= enqueueTimei, processingTimei <= 109`


<br>

### Hints

- To simulate the problem we first need to note that if at any point in time there are no enqueued tasks we need to wait to the smallest enqueue time of a non-processed element
- We need a data structure like a min-heap to support choosing the task with the smallest processing time from all the enqueued tasks

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> getOrder (vector <vector <int>>& tasks) {
      int n = tasks.size();
      std::vector <int> order (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        if (tasks[l][0] < tasks[r][0])
          return true;
        if (tasks[l][0] > tasks[r][0])
          return false;
        return tasks[l][1] < tasks[r][1];
      });

      std::priority_queue <std::tuple <int, int, int>> have;
      std::vector <int> ans;
      int64_t time = 0;
      int r = 0;

      while (r < n) {
        have.push({-tasks[order[r]][1], -order[r], tasks[order[r]][0]});
        ++r;

        while (!have.empty()) {
          auto [duration, index, start] = have.top();
          have.pop();

          if (time < start)
            time = start;
          time += -duration;
          ans.push_back(-index);

          while (r < n and tasks[order[r]][0] <= time) {
            have.push({-tasks[order[r]][1], -order[r], tasks[order[r]][0]});
            ++r;
          }
        }
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 51223
- total submissions: 118221
- acceptance rate: 43.3%
- likes: 1460
- dislikes: 145

<br>

### Similar Problems

- [Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii) (Hard)
