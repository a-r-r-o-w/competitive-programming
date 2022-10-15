# [729] My Calendar I

**[binary-search, design, segment-tree, ordered-set]**

### Statement

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a **double booking**.

A **double booking** happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers `start` and `end` that represents a booking on the half-open interval `[start, end)`, the range of real numbers `x` such that `start <= x < end`.

Implement the `MyCalendar` class:

* `MyCalendar()` Initializes the calendar object.
* `boolean book(int start, int end)` Returns `true` if the event can be added to the calendar successfully without causing a **double booking**. Otherwise, return `false` and do not add the event to the calendar.


**Example 1:**

```

**Input**
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
**Output**
[null, true, false, true]

**Explanation**
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
```

**Constraints:**
* `0 <= start < end <= 109`
* At most `1000` calls will be made to `book`.


<br>

### Hints

- Store the events as a sorted list of intervals.  If none of the events conflict, then the new event can be added.

<br>

### Solution

**O(n^2)**

```cpp
class MyCalendar {
  public:
    std::vector <std::pair <int, int>> entries;
  
    MyCalendar () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    bool book (int start, int end) {
      --end;
      for (auto &[x, y]: entries) {
        if (x <= end and start <= y)
          return false;
      }
      entries.emplace_back(start, end);
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```

**O(n.log(n))**

```cpp
class MyCalendar {
  public:
    std::map <int, int> entries;
  
    MyCalendar () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    bool book (int start, int end) {
      --end;
      auto lb = entries.lower_bound(start);
      if (lb != entries.end() and lb->second <= end)
        return false;
      entries[end] = start;
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 178646
- total submissions: 318375
- acceptance rate: 56.1%
- likes: 2622
- dislikes: 70

<br>

### Similar Problems

- [My Calendar II](https://leetcode.com/problems/my-calendar-ii) (Medium)
- [My Calendar III](https://leetcode.com/problems/my-calendar-iii) (Hard)
