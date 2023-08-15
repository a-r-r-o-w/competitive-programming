# [1667] Fix Names in a Table

**[database]**

### Statement

Table: `Users`

```

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
In SQL, user_id is the primary key for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.

```




Fix the names so that only the first character is uppercase and the rest are lowercase.

Return the result table ordered by `user_id`.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
**Output:** 
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
  return users.assign(name = users['name'].str.capitalize()).sort_values('user_id')
```

<br />

### Statistics

- total accepted: 129100
- total submissions: 200212
- acceptance rate: 64.5%
- likes: 665
- dislikes: 83

<br />

### Similar Problems

None
