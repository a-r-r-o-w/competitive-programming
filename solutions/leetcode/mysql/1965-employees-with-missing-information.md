# [1965] Employees With Missing Information

**[database]**

### Statement

Table: `Employees`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the name of the employee whose ID is employee_id.

```




Table: `Salaries`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| salary      | int     |
+-------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates the salary of the employee whose ID is employee_id.

```




Write an SQL query to report the IDs of all the employees with **missing information**. The information of an employee is missing if:

* The employee's **name** is missing, or
* The employee's **salary** is missing.



Return the result table ordered by `employee_id` **in ascending order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Employees table:
+-------------+----------+
| employee_id | name     |
+-------------+----------+
| 2           | Crew     |
| 4           | Haven    |
| 5           | Kristian |
+-------------+----------+
Salaries table:
+-------------+--------+
| employee_id | salary |
+-------------+--------+
| 5           | 76071  |
| 1           | 22517  |
| 4           | 63539  |
+-------------+--------+
**Output:** 
+-------------+
| employee_id |
+-------------+
| 1           |
| 2           |
+-------------+
**Explanation:** 
Employees 1, 2, 4, and 5 are working at this company.
The name of employee 1 is missing.
The salary of employee 2 is missing.

```


<br>

### Hints

None

<br>

### Solution

```sql
select
  E.employee_id as employee_id
from
  Employees as E
where E.employee_id not in (
  select
    S.employee_id
  from
    Salaries as S
)

union

select
  S.employee_id as employee_id
from
  Salaries as S
where S.employee_id not in (
  select
    E.employee_id
  from
    Employees as E
)

order by employee_id;
```

<br>

### Statistics

- total accepted: 68926
- total submissions: 87925
- acceptance rate: 78.4%
- likes: 459
- dislikes: 26

<br>

### Similar Problems

None
