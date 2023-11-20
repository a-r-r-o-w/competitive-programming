# [2409] Count Days Spent Together

**[math, string]**

### Statement

Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings `arriveAlice`, `leaveAlice`, `arriveBob`, and `leaveBob`. Alice will be in the city from the dates `arriveAlice` to `leaveAlice` (**inclusive**), while Bob will be in the city from the dates `arriveBob` to `leaveBob` (**inclusive**). Each will be a 5-character string in the format `"MM-DD"`, corresponding to the month and day of the date.

Return *the total number of days that Alice and Bob are in Rome together.*

You can assume that all dates occur in the **same** calendar year, which is **not** a leap year. Note that the number of days per month can be represented as: `[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]`.


**Example 1:**

```

**Input:** arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
**Output:** 3
**Explanation:** Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

```

**Example 2:**

```

**Input:** arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
**Output:** 0
**Explanation:** There is no day when Alice and Bob are in Rome together, so we return 0.

```

**Constraints:**
* All dates are provided in the format `"MM-DD"`.
* Alice and Bob's arrival dates are **earlier than or equal to** their leaving dates.
* The given dates are valid dates of a **non-leap** year.


<br>

### Hints

- For a given day, determine if Alice or Bob or both are in Rome.
- Brute force all 365 days for both Alice and Bob.

<br>

### Solution

```cpp
class Solution {
  public:
    int countDaysTogether (string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      int month_day_count[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      for (int i = 0; i < 12; ++i)
        month_day_count[i + 1] += month_day_count[i];

      auto to_day_count = [&] (const std::string& s) -> int {
        int dd = 10 * (s[3] - '0') + s[4] - '0';
        int mm = 10 * (s[0] - '0') + s[1] - '0' - 1;
        int day_count = 0;
        day_count += dd;
        day_count += month_day_count[mm];
        return day_count;
      };

      int aa = to_day_count(arriveAlice), la = to_day_count(leaveAlice);
      int ab = to_day_count(arriveBob), lb = to_day_count(leaveBob);
      int ans = 0;

      std::cout << "a: " << aa << ' ' << la << '\n';
      std::cout << "b: " << ab << ' ' << lb << '\n';
      std::cout << '\n';

      for (int i = aa; i <= la; ++i) {
        if (i >= ab and i <= lb)
          ++ans;
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 15391
- total submissions: 35765
- acceptance rate: 43.0%
- likes: 180
- dislikes: 505

<br>

### Similar Problems

- [Number of Days Between Two Dates](https://leetcode.com/problems/number-of-days-between-two-dates) (Easy)
- [Minimum Number of Operations to Convert Time](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time) (Easy)
