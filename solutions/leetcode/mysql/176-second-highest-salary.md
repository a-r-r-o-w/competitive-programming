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
id is the primary key column for this table.
Each row of this table contains information about the salary of an employee.

```




Write an SQL query to report the second highest salary from the `Employee` table. If there is no second highest salary, the query should report `null`.

The query result format is in the following example.


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


<br>

### Hints

None

<br>

### Solution

```cpp
select
  case
    when count(*) = 2 then min(salary)
    else null
  end as SecondHighestSalary
from (
  select
    distinct salary
  from
    Employee
  order by salary desc
  limit 2
) as HighestTwoSalaries;
```

<br>

### Statistics

- total accepted: 595574
- total submissions: 1609486
- acceptance rate: 37.0%
- likes: 2605
- dislikes: 808

<br>

### Similar Problems

None
