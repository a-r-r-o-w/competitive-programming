# [177] Nth Highest Salary

**[database]**

### Statement

Table: `Employee`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an employee.

```




Write a solution to find the `n^th` highest salary from the `Employee` table. If there is no `n^th` highest salary, return`null`.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
n = 2
**Output:** 
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+

```

**Example 2:**

```

**Input:** 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
n = 2
**Output:** 
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| null                   |
+------------------------+

```


<br />

### Hints

None

<br />

### Solution

```cpp
import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
  return employee.drop_duplicates(subset=['salary']).sort_values(by = 'salary', ascending = False).iloc[N - 1 : N][['salary']
```

<br />

### Statistics

- total accepted: 327575
- total submissions: 862214
- acceptance rate: 38.0%
- likes: 1720
- dislikes: 885

<br />

### Similar Problems

- [The Number of Users That Are Eligible for Discount](https://leetcode.com/problems/the-number-of-users-that-are-eligible-for-discount) (Easy)
