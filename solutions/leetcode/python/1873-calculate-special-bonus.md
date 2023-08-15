# [1873] Calculate Special Bonus

**[database]**

### Statement

Table: `Employees`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
In SQL, employee_id is the primary key for this table.
Each row of this table indicates the employee ID, employee name, and salary.

```




Calculate the bonus of each employee. The bonus of an employee is `100%` of their salary if the ID of the employee is **an odd number** and **the employee name does not start with the character** `'M'`. The bonus of an employee is `0` otherwise.

Return the result table ordered by `employee_id`.

Theresult format is in the following example.


**Example 1:**

```

**Input:** 
Employees table:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3800   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7700   |
+-------------+---------+--------+
**Output:** 
+-------------+-------+
| employee_id | bonus |
+-------------+-------+
| 2           | 0     |
| 3           | 0     |
| 7           | 7400  |
| 8           | 0     |
| 9           | 7700  |
+-------------+-------+
**Explanation:** 
The employees with IDs 2 and 8 get 0 bonus because they have an even employee_id.
The employee with ID 3 gets 0 bonus because their name starts with 'M'.
The rest of the employees get a 100% bonus.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
  cond = lambda x: x['salary'] if ((x['employee_id'] % 2 == 1) and (not x['name'].startswith('M'))) else 0
  employees['bonus'] = employees.apply(cond, axis=1)
  return employees[['employee_id', 'bonus']].sort_values('employee_id')
```

<br />

### Statistics

- total accepted: 187835
- total submissions: 320516
- acceptance rate: 58.6%
- likes: 941
- dislikes: 63

<br />

### Similar Problems

None
