# [1491] Average Salary Excluding the Minimum and Maximum Salary

**[array, sorting]**

### Statement

You are given an array of **unique** integers `salary` where `salary[i]` is the salary of the `ith` employee.

Return *the average salary of employees excluding the minimum and maximum salary*. Answers within `10-5` of the actual answer will be accepted.


**Example 1:**

```

**Input:** salary = [4000,3000,1000,2000]
**Output:** 2500.00000
**Explanation:** Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

```

**Example 2:**

```

**Input:** salary = [1000,2000,3000]
**Output:** 2000.00000
**Explanation:** Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

```

**Constraints:**
* `3 <= salary.length <= 100`
* `1000 <= salary[i] <= 106`
* All the integers of `salary` are **unique**.


<br>

### Hints

- Get the total sum and subtract the minimum and maximum value in the array.  Finally divide the result by n - 2.

<br>

### Solution

```cpp
class Solution {
  public:
    double average (vector <int>& salary) {
      int sum = 0;
      int min = 1 << 30, max = 0;
      int n = salary.size();
      
      for (int i: salary) {
        sum += i;
        min = std::min(min, i);
        max = std::max(max, i);
      }
      
      return double(sum - min - max) / (n - 2);
    }
};
```

<br>

### Statistics

- total accepted: 141775
- total submissions: 223166
- acceptance rate: 63.5%
- likes: 875
- dislikes: 104

<br>

### Similar Problems

None
