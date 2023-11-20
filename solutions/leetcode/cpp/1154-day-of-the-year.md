# [1154] Day of the Year

**[math, string]**

### Statement

Given a string `date` representing a [Gregorian calendar](https://en.wikipedia.org/wiki/Gregorian_calendar) date formatted as `YYYY-MM-DD`, return *the day number of the year*.


**Example 1:**

```

**Input:** date = "2019-01-09"
**Output:** 9
**Explanation:** Given date is the 9th day of the year in 2019.

```

**Example 2:**

```

**Input:** date = "2019-02-10"
**Output:** 41

```

**Constraints:**
* `date.length == 10`
* `date[4] == date[7] == '-'`, and all other `date[i]`'s are digits
* `date` represents a calendar date between Jan 1^st, 1900 and Dec 31^th, 2019.


<br />

### Hints

- Have a integer array of how many days there are per month.  February gets one extra day if its a leap year.  Then, we can manually count the ordinal as day + (number of days in months before this one).

<br />

### Solution

```cpp
class Solution {
  public:
    int dayOfYear (string date) {
      std::replace(date.begin(), date.end(), '-', ' ');

      std::stringstream stream (date);
      int y, m, d;
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      stream >> y >> m >> d;
      if (y % 4 == 0) {
        if (y % 100 == 0) {
          if (y % 400 == 0)
            ++days[1];
        }
        else
          ++days[1];
      }
      
      int ans = 0;
      for (int i = 0; i < m - 1; ++i)
        ans += days[i];
      ans += d;

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 41413
- total submissions: 82993
- acceptance rate: 49.9%
- likes: 320
- dislikes: 385

<br />

### Similar Problems

None
