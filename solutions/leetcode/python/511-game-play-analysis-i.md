# [511] Game Play Analysis I

**[database]**

### Statement

Table: `Activity`

```

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key (combination of columns with unique values) of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.

```




Write a solution to find the **first login date** for each player.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
**Output:** 
+-----------+-------------+
| player_id | first_login |
+-----------+-------------+
| 1         | 2016-03-01  |
| 2         | 2017-06-25  |
| 3         | 2016-03-02  |
+-----------+-------------+

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
  return activity.sort_values("event_date").drop_duplicates("player_id").rename(columns={
    "event_date": "first_login"
  })[["player_id", "first_login"]]
```

<br />

### Statistics

- total accepted: 204027
- total submissions: 272777
- acceptance rate: 74.8%
- likes: 700
- dislikes: 23

<br />

### Similar Problems

- [Game Play Analysis II](https://leetcode.com/problems/game-play-analysis-ii) (Easy)
