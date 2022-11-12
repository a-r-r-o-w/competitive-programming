# [295] Find Median from Data Stream

**[two-pointers, design, sorting, heap-priority-queue, data-stream]**

### Statement

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

* For example, for `arr = [2,3,4]`, the median is `3`.
* For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.



Implement the MedianFinder class:

* `MedianFinder()` initializes the `MedianFinder` object.
* `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
* `double findMedian()` returns the median of all elements so far. Answers within `10-5` of the actual answer will be accepted.


**Example 1:**

```

**Input**
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
**Output**
[null, null, null, 1.5, null, 2.0]

**Explanation**
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

```

**Constraints:**
* `-105 <= num <= 105`
* There will be at least one element in the data structure before calling `findMedian`.
* At most `5 * 104` calls will be made to `addNum` and `findMedian`.


**Follow up:**
* If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?
* If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?


<br>

### Hints

None

<br>

### Solution

Using GNU PBDS

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T, null_type, std::less <T>, rb_tree_tag, tree_order_statistics_node_update>;

auto init = [] () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return true;
} ();

class MedianFinder {
  private:
    int count;
    ordered_set <std::pair <int, int>> have;
  
  public:
    MedianFinder ()
      : count (0)
    { }
    
    void addNum (int num) {
      ++count;
      have.insert({num, count});
    }
    
    double findMedian () {
      if (count & 1)
        return have.find_by_order(count / 2)->first;
      
      double first = have.find_by_order(count / 2 - 1)->first;
      double second = have.find_by_order(count / 2)->first;
      
      return (first + second) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

Using two sets

```cpp
auto init = [] () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return true;
} ();

class MedianFinder {
  private:
    int count;
    std::multiset <int> smaller, bigger;
  
  public:
    MedianFinder ()
      : count (0),
        smaller (),
        bigger ()
    { }
    
    void addNum (int num) {
      ++count;
      
      if (smaller.empty())
        smaller.insert(num);
      else if (num > *smaller.rbegin()) {
        bigger.insert(num);
        
        if (bigger.size() > smaller.size()) {
          smaller.insert(*bigger.begin());
          bigger.erase(bigger.begin());
        }
      }
      else {
        smaller.insert(num);
        
        if (smaller.size() - bigger.size() > 1) {
          bigger.insert(*smaller.rbegin());
          smaller.erase(smaller.find(*smaller.rbegin()));
        }
      }
    }
    
    double findMedian () {
      if (count & 1)
        return *smaller.rbegin();
      
      double first = *smaller.rbegin();
      double second = *bigger.begin();
      
      return (first + second) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

Using two priority queues

```cpp
auto init = [] () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return true;
} ();

class MedianFinder {
  private:
    int count;
    std::priority_queue <int> smaller;
    std::priority_queue <int, std::vector <int>, std::greater <int>> bigger;
  
  public:
    MedianFinder ()
      : count (0),
        smaller (),
        bigger ()
    { }
    
    void addNum (int num) {
      ++count;
      
      if (smaller.empty())
        smaller.push(num);
      else if (num > smaller.top()) {
        bigger.push(num);
        
        if (bigger.size() - smaller.size() > 0) {
          smaller.push(bigger.top());
          bigger.pop();
        }
      }
      else {
        smaller.push(num);
        
        if (smaller.size() - bigger.size() > 1) {
          bigger.push(smaller.top());
          smaller.pop();
        }
      }
    }
    
    double findMedian () {
      if (count & 1)
        return smaller.top();
      
      double first = smaller.top();
      double second = bigger.top();
      
      return (first + second) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

<br>

### Statistics

- total accepted: 550851
- total submissions: 1076337
- acceptance rate: 51.2%
- likes: 8686
- dislikes: 164

<br>

### Similar Problems

- [Sliding Window Median](https://leetcode.com/problems/sliding-window-median) (Hard)
- [Finding MK Average](https://leetcode.com/problems/finding-mk-average) (Hard)
- [Sequentially Ordinal Rank Tracker](https://leetcode.com/problems/sequentially-ordinal-rank-tracker) (Hard)
