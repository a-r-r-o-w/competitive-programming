# [2446] Determine if Two Events Have Conflict



### Statement

You are given two arrays of strings that represent two inclusive events that happened **on the same day**, `event1` and `event2`, where:

* `event1 = [startTime1, endTime1]` and
* `event2 = [startTime2, endTime2]`.



Event times are valid 24 hours format in the form of `HH:MM`.

A **conflict** happens when two events have some non-empty intersection (i.e., some moment is common to both events).

Return `true` *if there is a conflict between two events. Otherwise, return* `false`.


**Example 1:**

```

**Input:** event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
**Output:** true
**Explanation:** The two events intersect at time 2:00.

```

**Example 2:**

```

**Input:** event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
**Output:** true
**Explanation:** The two events intersect starting from 01:20 to 02:00.

```

**Example 3:**

```

**Input:** event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
**Output:** false
**Explanation:** The two events do not intersect.

```

**Constraints:**
* `evnet1.length == event2.length == 2.`
* `event1[i].length == event2[i].length == 5`
* `startTime1 <= endTime1`
* `startTime2 <= endTime2`
* All the event times follow the `HH:MM` format.


<br>

### Hints

- Parse time format to some integer interval first
- How would you determine if two intervals overlap?

<br>

### Solution

```cpp
class Solution {
  public:
    bool haveConflict (vector <string>& event1, vector <string>& event2) {
      int a = std::stoi(event1[0].substr(0, 2)) * 60 + std::stoi(event1[0].substr(3, 2));
      int b = std::stoi(event1[1].substr(0, 2)) * 60 + std::stoi(event1[1].substr(3, 2));
      int c = std::stoi(event2[0].substr(0, 2)) * 60 + std::stoi(event2[0].substr(3, 2));
      int d = std::stoi(event2[1].substr(0, 2)) * 60 + std::stoi(event2[1].substr(3, 2));
      
      if (!(b < c or a > d))
        return true;
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 14405
- total submissions: 30210
- acceptance rate: 47.7%
- likes: 97
- dislikes: 26

<br>

### Similar Problems

- [Merge Intervals](https://leetcode.com/problems/merge-intervals) (Medium)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals) (Medium)
- [My Calendar I](https://leetcode.com/problems/my-calendar-i) (Medium)
