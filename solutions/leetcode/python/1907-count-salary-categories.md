# [1907] Count Salary Categories

**[database]**

### Statement

Table: `Accounts`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key (column with unique values) for this table.
Each row contains information about the monthly income for one bank account.

```




Write a solutionto calculate the number of bank accounts for each salary category. The salary categories are:

* `"Low Salary"`: All the salaries **strictly less** than `$20000`.
* `"Average Salary"`: All the salaries in the **inclusive** range `[$20000, $50000]`.
* `"High Salary"`: All the salaries **strictly greater** than `$50000`.



The result table **must** contain all three categories. If there are no accounts in a category,return`0`.

Return the result table in **any order**.

Theresult format is in the following example.


**Example 1:**

```

**Input:** 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
**Output:** 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
**Explanation:** 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
  return pd.DataFrame({
    "category": ["Low Salary", "Average Salary", "High Salary"],
    "accounts_count": [
      accounts[accounts["income"] < 20000].shape[0],
      accounts[(accounts["income"] >= 20000) & (accounts["income"] <= 50000)].shape[0],
      accounts[accounts["income"] > 50000].shape[0]
    ]
  })
```

<br />

### Statistics

- total accepted: 25480
- total submissions: 45097
- acceptance rate: 56.5%
- likes: 203
- dislikes: 49

<br />

### Similar Problems

- [Create a Session Bar Chart](https://leetcode.com/problems/create-a-session-bar-chart) (Easy)
