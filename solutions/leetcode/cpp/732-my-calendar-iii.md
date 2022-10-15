# [732] My Calendar III

**[binary-search, design, segment-tree, ordered-set]**

### Statement

A `k`-booking happens when `k` events have some non-empty intersection (i.e., there is some time that is common to all `k` events.)

You are given some events `[start, end)`, after each given event, return an integer `k` representing the maximum `k`-booking between all the previous events.

Implement the `MyCalendarThree` class:

* `MyCalendarThree()` Initializes the object.
* `int book(int start, int end)` Returns an integer `k` representing the largest integer such that there exists a `k`-booking in the calendar.


**Example 1:**

```

**Input**
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
**Output**
[null, 1, 1, 2, 3, 3, 3]

**Explanation**
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1, The first event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
myCalendarThree.book(50, 60); // return 1, The second event can be booked and is disjoint, so the maximum k-booking is a 1-booking.
myCalendarThree.book(10, 40); // return 2, The third event [10, 40) intersects the first event, and the maximum k-booking is a 2-booking.
myCalendarThree.book(5, 15); // return 3, The remaining events cause the maximum K-booking to be only a 3-booking.
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3

```

**Constraints:**
* `0 <= start < end <= 109`
* At most `400` calls will be made to `book`.


<br>

### Hints

- Treat each interval [start, end) as two events "start" and "end", and process them in sorted order.

<br>

### Solution

```cpp
class MyCalendarThree {
  std::map <int, int> calendar;
  
  public:
    MyCalendarThree () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    int book (int start, int end) {
      calendar[start] += 1;
      calendar[end] -= 1;
      
      int sum = 0, max = 0;
      
      for (auto &[x, y]: calendar) {
        sum += y;
        max = std::max(max, sum);
      }
      
      return max;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
```

<br>

### Statistics

- total accepted: 53101
- total submissions: 77184
- acceptance rate: 68.8%
- likes: 1104
- dislikes: 186

<br>

### Similar Problems

- [My Calendar I](https://leetcode.com/problems/my-calendar-i) (Medium)
- [My Calendar II](https://leetcode.com/problems/my-calendar-ii) (Medium)
- [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals) (Hard)
