# [176] Second Highest Salary

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




Write a solution to findthe second highest salary from the `Employee` table. If there is no second highest salary,return`null (returnNone in Pandas)`.

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
**Output:** 
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

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
**Output:** 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+

```


<br />

### Hints

None

<br />

### Solution

```cpp
import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
  salaries = employee['salary'].drop_duplicates()
  if salaries.size < 2:
    return pd.DataFrame({'SecondHighestSalary': [None]})
  return pd.DataFrame(
    {'SecondHighestSalary': [salaries.sort_values().iloc[-2]]}
  )
```

<br />

### Statistics

- total accepted: 697821
- total submissions: 1810796
- acceptance rate: 38.5%
- likes: 3125
- dislikes: 877

<br />

### Similar Problems

None
