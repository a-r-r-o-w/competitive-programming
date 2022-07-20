# [412] Fizz Buzz

**[math, string, simulation]**

### Statement

Given an integer `n`, return *a string array* `answer` *(**1-indexed**) where*:

* `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
* `answer[i] == "Fizz"` if `i` is divisible by `3`.
* `answer[i] == "Buzz"` if `i` is divisible by `5`.
* `answer[i] == i` (as a string) if none of the above conditions are true.


**Example 1:**

```
**Input:** n = 3
**Output:** ["1","2","Fizz"]

```
**Example 2:**

```
**Input:** n = 5
**Output:** ["1","2","Fizz","4","Buzz"]

```
**Example 3:**

```
**Input:** n = 15
**Output:** ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

```

**Constraints:**
* `1 <= n <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> fizzBuzz (int n) {
      std::string fizz = "Fizz";
      std::string buzz = "Buzz";
      std::string fizzbuzz = "FizzBuzz";
      std::vector <std::string> ans;
      ans.reserve(n);
      
      for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0)
          ans.push_back(fizzbuzz);
        else if (i % 3 == 0)
          ans.push_back(fizz);
        else if (i % 5 == 0)
          ans.push_back(buzz);
        else
          ans.push_back(std::to_string(i));
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 675461
- total submissions: 1000691
- acceptance rate: 67.5%
- likes: 632
- dislikes: 105

<br>

### Similar Problems

- [Fizz Buzz Multithreaded](https://leetcode.com/problems/fizz-buzz-multithreaded) (Medium)
