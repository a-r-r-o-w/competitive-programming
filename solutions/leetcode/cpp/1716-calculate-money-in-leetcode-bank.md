# [1716] Calculate Money in Leetcode Bank

**[math]**

### Statement

Hercy wants to save money for his first car. He puts money in the Leetcodebank **every day**.

He starts by putting in `$1` on Monday, the first day. Every day from Tuesday to Sunday, he will put in `$1` more than the day before. On every subsequent Monday, he will put in `$1` more than the **previous Monday**. 

Given `n`, return *the total amount of money he will have in the Leetcode bank at the end of the* `nth` *day.*
**Example 1:**

```

**Input:** n = 4
**Output:** 10
**Explanation:**After the 4th day, the total is 1 + 2 + 3 + 4 = 10.

```

**Example 2:**

```

**Input:** n = 10
**Output:** 37
**Explanation:**After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.

```

**Example 3:**

```

**Input:** n = 20
**Output:** 96
**Explanation:**After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.

```

**Constraints:**
* `1 <= n <= 1000`


<br>

### Hints

- Simulate the process by keeping track of how much money John is putting in and which day of the week it is, and use this information to deduce how much money John will put in the next day.

<br>

### Solution

```cpp
class Solution {
  public:
    int totalMoney (int n) {
      int x = n / 7, y = n % 7;
      int ans = 28 * x + 7 * x * (x - 1) / 2;
      if (y)
        ans += y * (y + 1) / 2 + y * x;
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 35824
- total submissions: 54908
- acceptance rate: 65.2%
- likes: 510
- dislikes: 16

<br>

### Similar Problems

None
