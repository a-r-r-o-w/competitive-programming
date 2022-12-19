# [739] Daily Temperatures

**[array, stack, monotonic-stack]**

### Statement

Given an array of integers `temperatures` represents the daily temperatures, return *an array* `answer` *such that* `answer[i]` *is the number of days you have to wait after the* `ith` *day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.


**Example 1:**

```
**Input:** temperatures = [73,74,75,71,69,72,76,73]
**Output:** [1,1,4,2,1,1,0,0]

```
**Example 2:**

```
**Input:** temperatures = [30,40,50,60]
**Output:** [1,1,1,0]

```
**Example 3:**

```
**Input:** temperatures = [30,60,90]
**Output:** [1,1,0]

```

**Constraints:**
* `1 <=temperatures.length <= 105`
* `30 <=temperatures[i] <= 100`


<br>

### Hints

- If the temperature is say, 70 today, then in the future a warmer temperature must be either 71, 72, 73, ..., 99, or 100.  We could remember when all of them occur next.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }

    vector <int> dailyTemperatures (vector <int>& temperatures) {
      const int max = 100 + 1;
      int n = temperatures.size();
      std::vector <int> next (max, -1), ans (n);

      for (int i = n - 1; i >= 0; --i) {
        int min = 1 << 30;

        for (int j = temperatures[i] + 1; j < max; ++j) {
          if (next[j] == -1)
            continue;
          min = std::min(min, next[j] - i);
        }

        if (min != 1 << 30)
          ans[i] = min;
        
        next[temperatures[i]] = i;
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 502829
- total submissions: 755090
- acceptance rate: 66.6%
- likes: 8780
- dislikes: 203

<br>

### Similar Problems

- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) (Easy)
- [Online Stock Span](https://leetcode.com/problems/online-stock-span) (Medium)
