# [838] Push Dominoes

**[two-pointers, string, dynamic-programming]**

### Statement

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string `dominoes` representing the initial state where:

* `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,
* `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and
* `dominoes[i] = '.'`, if the `ith` domino has not been pushed.



Return *a string representing the final state*.


**Example 1:**

```

**Input:** dominoes = "RR.L"
**Output:** "RR.L"
**Explanation:** The first domino expends no additional force on the second domino.

```

**Example 2:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

```

**Input:** dominoes = ".L.R...LR..L.."
**Output:** "LL.RR.LLRRLL.."

```

**Constraints:**
* `n == dominoes.length`
* `1 <= n <= 105`
* `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string pushDominoes (string dominoes) {
      int n = dominoes.length();
      std::vector <int> force (n);
      
      int f = 0;
      for (int i = 0; i < n; ++i) {
        if (dominoes[i] == 'R')
          f = n;
        else if (dominoes[i] == 'L')
          f = 0;
        else
          f = std::max(0, f - 1);
        force[i] += f;
      }
      
      f = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (dominoes[i] == 'L')
          f = n;
        else if (dominoes[i] == 'R')
          f = 0;
        else
          f = std::max(0, f - 1);
        force[i] -= f;
      }
      
      for (int i = 0; i < n; ++i)
        dominoes[i] = force[i] > 0 ? 'R' : force[i] < 0 ? 'L' : '.';
      
      return dominoes;
    }
};
```

<br>

### Statistics

- total accepted: 86858
- total submissions: 155425
- acceptance rate: 55.9%
- likes: 2538
- dislikes: 160

<br>

### Similar Problems

None
