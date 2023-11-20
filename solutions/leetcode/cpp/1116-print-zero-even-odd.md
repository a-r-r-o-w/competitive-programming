# [1116] Print Zero Even Odd

**[concurrency]**

### Statement

You have a function `printNumber` that can be called with an integer parameter and prints it to the console.

* For example, calling `printNumber(7)` prints `7` to the console.



You are given an instance of the class `ZeroEvenOdd` that has three functions: `zero`, `even`, and `odd`. The same instance of `ZeroEvenOdd` will be passed to three different threads:

* **Thread A:** calls `zero()` that should only output `0`'s.
* **Thread B:** calls `even()` that should only output even numbers.
* **Thread C:** calls `odd()` that should only output odd numbers.



Modify the given class to output the series `"010203040506..."` where the length of the series must be `2n`.

Implement the `ZeroEvenOdd` class:

* `ZeroEvenOdd(int n)` Initializes the object with the number `n` that represents the numbers that should be printed.
* `void zero(printNumber)` Calls `printNumber` to output one zero.
* `void even(printNumber)` Calls `printNumber` to output one even number.
* `void odd(printNumber)` Calls `printNumber` to output one odd number.


**Example 1:**

```

**Input:** n = 2
**Output:** "0102"
**Explanation:** There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.

```

**Example 2:**

```

**Input:** n = 5
**Output:** "0102030405"

```

**Constraints:**
* `1 <= n <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class ZeroEvenOdd {
  private:
    int n;
    int value;
    bool is_zero;
    std::mutex m;
    std::condition_variable cv;

  public:
    ZeroEvenOdd (int n) {
      this->n = n;
      value = 1;
      is_zero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero (function <void(int)> printNumber) {
      while (true) {
        std::unique_lock <std::mutex> lock (m);
        while (value <= n) {
          if (is_zero)
            break;
          cv.wait(lock);
        }
        if (value > n)
          break;
        printNumber(0);
        is_zero = false;
        cv.notify_all();
      }
    }

    void even (function <void(int)> printNumber) {
      while (true) {
        std::unique_lock <std::mutex> lock (m);
        while (value <= n) {
          if (not is_zero and value % 2 == 0)
            break;
          cv.wait(lock);
        }
        if (value > n)
          break;
        printNumber(value);
        is_zero = true;
        ++value;
        cv.notify_all();
      }
    }

    void odd (function <void(int)> printNumber) {
      while (true) {
        std::unique_lock <std::mutex> lock (m);
        while (value <= n) {
          if (not is_zero and value % 2 == 1)
            break;
          cv.wait(lock);
        }
        if (value > n)
          break;
        printNumber(value);
        is_zero = true;
        ++value;
        cv.notify_all();
      }
    }
};
```

<br />

### Statistics

- total accepted: 38159
- total submissions: 63171
- acceptance rate: 60.4%
- likes: 402
- dislikes: 282

<br />

### Similar Problems

- [Print FooBar Alternately](https://leetcode.com/problems/print-foobar-alternately) (Medium)
- [Fizz Buzz Multithreaded](https://leetcode.com/problems/fizz-buzz-multithreaded) (Medium)
