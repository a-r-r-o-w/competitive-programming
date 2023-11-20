# [1670] Design Front Middle Back Queue

**[array, linked-list, design, queue, data-stream]**

### Statement

Design a queue that supports `push` and `pop` operations in the front, middle, and back.

Implement the `FrontMiddleBack` class:

* `FrontMiddleBack()` Initializes the queue.
* `void pushFront(int val)` Adds `val` to the **front** of the queue.
* `void pushMiddle(int val)` Adds `val` to the **middle** of the queue.
* `void pushBack(int val)` Adds `val` to the **back** of the queue.
* `int popFront()` Removes the **front** element of the queue and returns it. If the queue is empty, return `-1`.
* `int popMiddle()` Removes the **middle** element of the queue and returns it. If the queue is empty, return `-1`.
* `int popBack()` Removes the **back** element of the queue and returns it. If the queue is empty, return `-1`.


**Notice** that when there are **two** middle position choices, the operation is performed on the **frontmost** middle position choice. For example:

* Pushing `6` into the middle of `[1, 2, 3, 4, 5]` results in `[1, 2, 6, 3, 4, 5]`.
* Popping the middle from `[1, 2, 3, 4, 5, 6]` returns `3` and results in `[1, 2, 4, 5, 6]`.


**Example 1:**

```

**Input:**
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
**Output:**
[null, null, null, null, null, 1, 3, 4, 2, -1]

**Explanation:**
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)

```

**Constraints:**
* `1 <= val <= 10^9`
* At most`1000`calls will be made to`pushFront`,`pushMiddle`,`pushBack`, `popFront`, `popMiddle`, and `popBack`.


<br />

### Hints

- The constraints are low enough for a brute force, single array approach.
- For an O(1) per method approach, use 2 double-ended queues: one for the first half and one for the second half.

<br />

### Solution

```cpp
class FrontMiddleBackQueue {
    std::deque <int> dq;

  public:
    FrontMiddleBackQueue () {
        
    }
    
    void pushFront (int val) {
      dq.push_front(val);
    }
    
    void pushMiddle (int val) {
      dq.insert(dq.begin() + dq.size() / 2, val);
    }
    
    void pushBack (int val) {
      dq.push_back(val);
    }
    
    int popFront () {
      if (dq.empty())
        return -1;
      int val = dq.front();
      dq.pop_front();
      return val;
    }
    
    int popMiddle () {
      if (dq.empty())
        return -1;
      int val = dq[((int)dq.size() - 1) / 2];
      dq.erase(dq.begin() + ((int)dq.size() - 1) / 2);
      return val;
    }
    
    int popBack () {
      if (dq.empty())
        return -1;
      int val = dq.back();
      dq.pop_back();
      return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
```

<br />

### Statistics

- total accepted: 20121
- total submissions: 35024
- acceptance rate: 57.4%
- likes: 590
- dislikes: 85

<br />

### Similar Problems

- [Design Circular Deque](https://leetcode.com/problems/design-circular-deque) (Medium)
- [Design Circular Queue](https://leetcode.com/problems/design-circular-queue) (Medium)
