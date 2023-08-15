# [183] Customers Who Never Order

**[database]**

### Statement

Table: `Customers`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID and name of a customer.

```




Table: `Orders`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
customerId is a foreign key (reference columns) of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.

```




Write a solution to find all customers who never order anything.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
**Output:** 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
  return customers.loc[~customers['id'].isin(orders['customerId']), ['name']].rename(columns = {'name': 'Customers'})
```

<br />

### Statistics

- total accepted: 671458
- total submissions: 977921
- acceptance rate: 68.7%
- likes: 2303
- dislikes: 117

<br />

### Similar Problems

None
