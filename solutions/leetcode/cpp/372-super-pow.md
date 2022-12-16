# [372] Super Pow

**[math, divide-and-conquer]**

### Statement

Your task is to calculate `ab` mod `1337` where `a` is a positive integer and `b` is an extremely large positive integer given in the form of an array.


**Example 1:**

```

**Input:** a = 2, b = [3]
**Output:** 8

```

**Example 2:**

```

**Input:** a = 2, b = [1,0]
**Output:** 1024

```

**Example 3:**

```

**Input:** a = 1, b = [4,3,3,8,5,2]
**Output:** 1

```

**Constraints:**
* `1 <= a <= 231 - 1`
* `1 <= b.length <= 2000`
* `0 <= b[i] <= 9`
* `b` does not contain leading zeros.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int superPow (int a, vector <int>& b) {
      const int64_t mod = 1337;
      
      auto pow = [] (auto self, int64_t a, int64_t b) -> int64_t {
        if (b == 0)
          return 1;
        auto r = self(self, a, b / 2);
        r = r * r % mod;
        if (b & 1)
          r = r * a % mod;
        return r;
      };
      
      int n = b.size();
      int64_t ans = 1;
      
      for (int i = 0; i < n; ++i)
        ans = pow(pow, ans, 10) * pow(pow, a, b[i]) % mod;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 54587
- total submissions: 147067
- acceptance rate: 37.1%
- likes: 606
- dislikes: 1218

<br>

### Similar Problems

- [Pow(x, n)](https://leetcode.com/problems/powx-n) (Medium)
