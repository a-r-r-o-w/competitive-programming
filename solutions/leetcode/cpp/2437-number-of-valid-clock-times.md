# [2437] Number of Valid Clock Times



### Statement

You are given a string of length `5` called `time`, representing the current time on a digital clock in the format `"hh:mm"`. The **earliest** possible time is `"00:00"` and the **latest** possible time is `"23:59"`.

In the string `time`, the digits represented by the `?`symbol are **unknown**, and must be **replaced** with a digit from `0` to `9`.

Return *an integer* `answer`*, the number of valid clock times that can be created by replacing every* `?`*with a digit from* `0` *to* `9`.


**Example 1:**

```

**Input:** time = "?5:00"
**Output:** 2
**Explanation:** We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.

```

**Example 2:**

```

**Input:** time = "0?:0?"
**Output:** 100
**Explanation:** Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.

```

**Example 3:**

```

**Input:** time = "??:??"
**Output:** 1440
**Explanation:** There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.

```

**Constraints:**
* `time` is a valid string of length `5` in the format `"hh:mm"`.
* `"00" <= hh <= "23"`
* `"00" <= mm <= "59"`
* Some of the digits might be replaced with `'?'` and need to be replaced with digits from `0` to `9`.


<br>

### Hints

- Brute force all possible clock times.
- Checking if a clock time is valid can be done with Regex.

<br>

### Solution

```cpp
class Solution {
  public:
    int countTime (string time) {
      int64_t ans = 1;
      
      if (time[0] == '?' and time[1] == '?')
        ans *= 24;
      else if (time[0] == '?')
        ans *= time[1] > '3' ? 2 : 3;
      else if (time[1] == '?')
        ans *= time[0] == '2' ? 4 : 10;
      
      if (time[3] == '?' and time[4] == '?')
        ans *= 60;
      else if (time[3] == '?')
        ans *= 6;
      else if (time[4] == '?')
        ans *= 10;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 10954
- total submissions: 28323
- acceptance rate: 38.7%
- likes: 67
- dislikes: 80

<br>

### Similar Problems

- [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits) (Medium)
- [Latest Time by Replacing Hidden Digits](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits) (Easy)
