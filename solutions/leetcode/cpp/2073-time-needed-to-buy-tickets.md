# [2073] Time Needed to Buy Tickets

**[array, queue, simulation]**

### Statement

There are `n` people in a line queuing to buy tickets, where the `0th` person is at the **front** of the line and the `(n - 1)th` person is at the **back** of the line.

You are given a **0-indexed** integer array `tickets` of length `n` where the number of tickets that the `ith` person would like to buy is `tickets[i]`.

Each person takes **exactly 1 second** to buy a ticket. A person can only buy **1 ticket at a time** and has to go back to **the end** of the line (which happens **instantaneously**) in order to buy more tickets. If a person does not have any tickets left to buy, the person will **leave** the line.

Return *the **time taken** for the person at position* `k`***(0-indexed)****to finish buying tickets*.


**Example 1:**

```

**Input:** tickets = [2,3,2], k = 2
**Output:** 6
**Explanation:** 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person atposition 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.

```

**Example 2:**

```

**Input:** tickets = [5,1,1,1], k = 0
**Output:** 8
**Explanation:**
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person atposition 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.

```

**Constraints:**
* `n == tickets.length`
* `1 <= n <= 100`
* `1 <= tickets[i] <= 100`
* `0 <= k < n`


<br>

### Hints

- Loop through the line of people and decrement the number of tickets for each to buy one at a time as if simulating the line moving forward. Keep track of how many tickets have been sold up until person k has no more tickets to buy.
- Remember that those who have no more tickets to buy will leave the line.

<br>

### Solution

```cpp
class Solution {
  public:
    int timeRequiredToBuy (vector <int>& tickets, int k) {
      int n = tickets.size(), ans = -1, time = 1;
      std::queue <std::pair <int, int>> q;

      for (int i = 0; i < n; ++i)
        q.emplace(i, tickets[i]);
      
      while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        --b;

        if (a == k and b == 0) {
          ans = time;
          break;
        }
        if (b != 0)
          q.emplace(a, b);
        
        ++time;
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 35629
- total submissions: 57390
- acceptance rate: 62.1%
- likes: 591
- dislikes: 36

<br>

### Similar Problems

- [Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch) (Easy)
