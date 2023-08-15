# [595] Big Countries

**[database]**

### Statement

Table: `World`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+
name is the primary key (column with unique values) for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.

```




A country is **big** if:

* it has an area of at leastthree million (i.e., `3000000 km^2`), or
* it has a population of at leasttwenty-five million (i.e., `25000000`).



Write a solution to find the name, population, and area of the **big countries**.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
**Output:** 
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
  return world.loc[(world['area'] >= 3000000) | (world['population'] >= 25000000), ['name', 'population', 'area']]
```

<br />

### Statistics

- total accepted: 714203
- total submissions: 1034128
- acceptance rate: 69.1%
- likes: 2035
- dislikes: 1200

<br />

### Similar Problems

None
