# [1683] Invalid Tweets

**[database]**

### Statement

Table: `Tweets`

```

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
In SQL, tweet_id is the primary key for this table.
This table contains all the tweets in a social media app.

```




Find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is **strictly greater** than `15`.

Return the result table in **any order**.

The result format is in the following example.


**Example 1:**

```

**Input:** 
Tweets table:
+----------+----------------------------------+
| tweet_id | content                          |
+----------+----------------------------------+
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |
+----------+----------------------------------+
**Output:** 
+----------+
| tweet_id |
+----------+
| 2        |
+----------+
**Explanation:** 
Tweet 1 has length = 14. It is a valid tweet.
Tweet 2 has length = 32. It is an invalid tweet.

```


<br />

### Hints

None

<br />

### Solution

```py
import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
  return tweets.loc[tweets['content'].str.len() > 15, ['tweet_id']]
```

<br />

### Statistics

- total accepted: 93303
- total submissions: 108150
- acceptance rate: 86.3%
- likes: 395
- dislikes: 156

<br />

### Similar Problems

None
