# [184] Department Highest Salary

**[database]**

### Statement

Table: `Employee`

```

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key (column with unique values) for this table.
departmentId is a foreign key (reference columns) of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.

```




Table: `Department`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table. It is guaranteed that department name is not NULL.
Each row of this table indicates the ID of a department and its name.

```




Write a solution to find employees who have the highest salary in each of the departments.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Employee table:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
Department table:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
**Output:** 
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
| IT         | Max      | 90000  |
+------------+----------+--------+
**Explanation:** Max and Jim both have the highest salary in the IT department and Henry has the highest salary in the Sales department.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
  return employee.merge(
    department, left_on="departmentId", right_on="id", suffixes=("_e", "_d")
  ).groupby("departmentId").apply(
    lambda x: x[x["salary"] == x["salary"].max()]
  ).reset_index(drop=True)[
    ["name_d", "name_e", "salary"]
  ].rename(columns = {
    "name_d": "Department",
    "name_e": "Employee",
    "salary": "Salary"
  })
```

<br />

### Statistics

- total accepted: 322351
- total submissions: 639185
- acceptance rate: 50.4%
- likes: 1818
- dislikes: 180

<br />

### Similar Problems

- [Highest Grade For Each Student](https://leetcode.com/problems/highest-grade-for-each-student) (Medium)
