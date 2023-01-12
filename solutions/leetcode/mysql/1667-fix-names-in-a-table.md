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
user_id is the primary key for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.

```




Write an SQL query to fix the names so that only the first character is uppercase and the rest are lowercase.

Return the result table ordered by `user_id`.

The query result format is in the following example.


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


<br>

### Hints

None

<br>

### Solution

```cpp
select
  user_id, concat(
    upper(substr(name, 1, 1)),
    lower(substr(name, 2))
  ) as name
from
  users
order by
  user_id asc;
```

<br>

### Statistics

- total accepted: 82316
- total submissions: 124122
- acceptance rate: 66.3%
- likes: 469
- dislikes: 69

<br>

### Similar Problems

None
