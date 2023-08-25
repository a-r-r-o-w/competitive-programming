# [570] Managers with at Least 5 Direct Reports

**[database]**

### Statement

Table: `Employee`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.

```




Write a solution to find managers with at least **five direct reports**.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | None      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
**Output:** 
+------+
| name |
+------+
| John |
+------+

```


<br />

### Hints

- Try to get all the mangerIDs that have count bigger than 5
- Use the last hint's result as a table and do join with origin table at id equals to managerId
- This is a very good example to show the performance of SQL code. Try to work out other solutions and you may be surprised by running time difference.
- If your solution uses 'IN' function and runs more than 5 seconds, try to optimize it by using 'JOIN' instead.

<br />

### Solution

```py
import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
  df = employee.merge(employee["managerId"].value_counts(), "left", left_on="id", right_on="managerId")
  return df[df["count"] >= 5][["name"]]
```

<br />

### Statistics

- total accepted: 133773
- total submissions: 227978
- acceptance rate: 58.7%
- likes: 626
- dislikes: 61

<br />

### Similar Problems

None
