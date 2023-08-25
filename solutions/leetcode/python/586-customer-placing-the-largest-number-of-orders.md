# [586] Customer Placing the Largest Number of Orders

**[database]**

### Statement

Table: `Orders`

```

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key (column with unique values) for this table.
This table contains information about the order ID and the customer ID.

```




Write a solution to find the `customer_number` for the customer who has placed **the largest number of orders**.

The test cases are generated so that **exactly one customer** will have placed more orders than any other customer.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
**Output:** 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
**Explanation:** 
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order. 
So the result is customer_number 3.

```

**Follow up:** What if more than one customer has the largest number of orders, can you find all the `customer_number` in this case?

<br />

### Hints

- MySQL uses a different expression to get the first records other than MSSQL's TOP expression.

<br />

### Solution

```py
import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
  grouped = orders.groupby("customer_number")["order_number"].count().reset_index()
  mx = grouped["order_number"].max()
  return grouped[grouped["order_number"] == mx][["customer_number"]]

```

<br />

### Statistics

- total accepted: 196574
- total submissions: 295662
- acceptance rate: 66.5%
- likes: 834
- dislikes: 60

<br />

### Similar Problems

None
