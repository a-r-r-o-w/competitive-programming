# [596] Classes More Than 5 Students

**[database]**

### Statement

Table: `Courses`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the name of a student and the class in which they are enrolled.

```




Write a solution to find all the classes that have **at least five students**.

Return the result table in **any order**.

Theresult format is in the following example.


**Example 1:**

```

**Input:** 
Courses table:
+---------+----------+
| student | class    |
+---------+----------+
| A       | Math     |
| B       | English  |
| C       | Math     |
| D       | Biology  |
| E       | Math     |
| F       | Computer |
| G       | Math     |
| H       | Math     |
| I       | Math     |
+---------+----------+
**Output:** 
+---------+
| class   |
+---------+
| Math    |
+---------+
**Explanation:** 
- Math has 6 students, so we include it.
- English has 1 student, so we do not include it.
- Biology has 1 student, so we do not include it.
- Computer has 1 student, so we do not include it.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
  grouped = courses.groupby("class")["student"].count().reset_index()
  return grouped[grouped["student"] >= 5][["class"]]
```

<br />

### Statistics

- total accepted: 280988
- total submissions: 560339
- acceptance rate: 50.1%
- likes: 823
- dislikes: 1036

<br />

### Similar Problems

None
