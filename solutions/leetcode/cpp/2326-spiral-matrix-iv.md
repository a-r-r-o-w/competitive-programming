# [2326] Spiral Matrix IV

**[array, linked-list, matrix, simulation]**

### Statement

You are given two integers `m` and `n`, which represent the dimensions of a matrix.

You are also given the `head` of a linked list of integers.

Generate an `m x n` matrix that contains the integers in the linked list presented in **spiral** order **(clockwise)**, starting from the **top-left** of the matrix. If there are remaining empty spaces, fill them with `-1`.

Return *the generated matrix*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/05/09/ex1new.jpg)

```

**Input:** m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
**Output:** [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
**Explanation:** The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/05/11/ex2.jpg)

```

**Input:** m = 1, n = 4, head = [0,1,2]
**Output:** [[0,1,2,-1]]
**Explanation:** The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
```

**Constraints:**
* `1 <= m, n <= 10^5`
* `1 <= m * n <= 10^5`
* The number of nodes in the list is in the range `[1, m * n]`.
* `0 <= Node.val <= 1000`


<br />

### Hints

- First, generate an m x n matrix filled with -1s.
- Navigate within the matrix at (i, j) with the help of a direction vector ⟨di, dj⟩. At (i, j), you need to decide if you can keep going in the current direction.
- If you cannot keep going, rotate the direction vector clockwise by 90 degrees.

<br />

### Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
  public:
    vector <vector <int>> spiralMatrix (int m, int n, ListNode *head) {
      std::vector <std::vector <int>> ans (m, std::vector <int> (n, -1));
      bool is_horizontal = true, is_up = false, is_left = false;
      int l = 0, r = n - 1, u = 0, d = m - 1, i = 0, j = 0;

      while (head != nullptr) {
        for (int i = l; i <= r and head != nullptr; ++i) {
          ans[u][i] = head->val;
          head = head->next;
        }
        for (int i = u + 1; i <= d and head != nullptr; ++i) {
          ans[i][r] = head->val;
          head = head->next;
        }
        for (int i = r - 1; i >= l and head != nullptr; --i) {
          ans[d][i] = head->val;
          head = head->next;
        }
        for (int i = d - 1; i > u and head != nullptr; --i) {
          ans[i][l] = head->val;
          head = head->next;
        }
        ++l;
        --r;
        ++u;
        --d;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 24843
- total submissions: 33246
- acceptance rate: 74.7%
- likes: 430
- dislikes: 18

<br />

### Similar Problems

- [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) (Medium)
- [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii) (Medium)
- [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii) (Medium)
