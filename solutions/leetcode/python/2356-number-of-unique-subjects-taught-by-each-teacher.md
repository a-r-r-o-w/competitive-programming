# [2356] Number of Unique Subjects Taught by Each Teacher

**[database]**

### Statement

Table: `Teacher`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| teacher_id  | int  |
| subject_id  | int  |
| dept_id     | int  |
+-------------+------+
(subject_id, dept_id) is the primary key (combinations of columns with unique values) of this table.
Each row in this table indicates that the teacher with teacher_id teaches the subject subject_id in the department dept_id.

```




Write a solution to calculatethe number of unique subjects each teacher teaches in the university.

Return the result table in **any order**.

Theresult format is shown in the following example.


**Example 1:**

```

**Input:** 
Teacher table:
+------------+------------+---------+
| teacher_id | subject_id | dept_id |
+------------+------------+---------+
| 1          | 2          | 3       |
| 1          | 2          | 4       |
| 1          | 3          | 3       |
| 2          | 1          | 1       |
| 2          | 2          | 1       |
| 2          | 3          | 1       |
| 2          | 4          | 1       |
+------------+------------+---------+
**Output:**  
+------------+-----+
| teacher_id | cnt |
+------------+-----+
| 1          | 2   |
| 2          | 4   |
+------------+-----+
**Explanation:** 
Teacher 1:
  - They teach subject 2 in departments 3 and 4.
  - They teach subject 3 in department 3.
Teacher 2:
  - They teach subject 1 in department 1.
  - They teach subject 2 in department 1.
  - They teach subject 3 in department 1.
  - They teach subject 4 in department 1.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
  return teacher.groupby("teacher_id")["subject_id"].nunique().reset_index().rename(columns={
    "subject_id": "cnt"
  })
```

<br />

### Statistics

- total accepted: 37575
- total submissions: 42897
- acceptance rate: 87.6%
- likes: 210
- dislikes: 12

<br />

### Similar Problems

None
