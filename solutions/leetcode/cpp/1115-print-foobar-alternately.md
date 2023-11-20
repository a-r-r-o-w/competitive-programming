# [1115] Print FooBar Alternately

**[concurrency]**

### Statement

Suppose you are given the following code:


```

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}

```


The same instance of `FooBar` will be passed to two different threads:

* thread `A` will call `foo()`, while
* thread `B` will call `bar()`.



Modify the given program to output `"foobar"` `n` times.


**Example 1:**

```

**Input:** n = 1
**Output:** "foobar"
**Explanation:** There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

```

**Example 2:**

```

**Input:** n = 2
**Output:** "foobarfoobar"
**Explanation:** "foobar" is being output 2 times.

```

**Constraints:**
* `1 <= n <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class FooBar {
private:
    int n;
    std::mutex m1, m2;

public:
    FooBar (int n) {
      this->n = n;
      m2.lock();
    }

    void foo (function <void()> printFoo) {
      for (int i = 0; i < n; i++) {
        m1.lock();
        printFoo();
        m2.unlock();
      }
    }

    void bar (function <void()> printBar) {
      for (int i = 0; i < n; i++) {
        m2.lock();
        printBar();
        m1.unlock();
      }
    }
};
```

<br />

### Statistics

- total accepted: 62924
- total submissions: 101102
- acceptance rate: 62.2%
- likes: 562
- dislikes: 46

<br />

### Similar Problems

- [Print in Order](https://leetcode.com/problems/print-in-order) (Easy)
- [Print Zero Even Odd](https://leetcode.com/problems/print-zero-even-odd) (Medium)
