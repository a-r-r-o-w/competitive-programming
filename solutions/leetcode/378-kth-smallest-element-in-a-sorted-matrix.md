# [378] Kth Smallest Element in a Sorted Matrix

**[array, binary-search, sorting, heap-priority-queue, matrix]**

### Statement

Given an `n x n` `matrix` where each of the rows and columns is sorted in ascending order, return *the* `kth` *smallest element in the matrix*.

Note that it is the `kth` smallest element **in the sorted order**, not the `kth` **distinct** element.

You must find a solution with a memory complexity better than `O(n2)`.


**Example 1:**

```

**Input:** matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
**Output:** 13
**Explanation:** The elements in the matrix are [1,5,9,10,11,12,13,**13**,15], and the 8th smallest number is 13

```

**Example 2:**

```

**Input:** matrix = [[-5]], k = 1
**Output:** -5

```

**Constraints:**
* `n == matrix.length == matrix[i].length`
* `1 <= n <= 300`
* `-109 <= matrix[i][j] <= 109`
* All the rows and columns of `matrix` are **guaranteed** to be sorted in **non-decreasing order**.
* `1 <= k <= n2`


**Follow up:**
* Could you solve the problem with a constant memory (i.e., `O(1)` memory complexity)?
* Could you solve the problem in `O(n)` time complexity? The solution may be too advanced for an interview but you may find reading [this paper](http://www.cse.yorku.ca/~andy/pubs/X+Y.pdf) fun.


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
  
    int kthSmallest (vector <vector <int>>& matrix, int k) {
      int n = matrix.size();
      std::vector <int> indices (n);
      int min, index;
      
      for (int i = 0; i < k; ++i) {
        min = 1 << 30;
        index = -1;
        
        for (int j = 0; j < n; ++j) {
          if (indices[j] < n and matrix[j][indices[j]] < min) {
            min = matrix[j][indices[j]];
            index = j;
          }
        }
        
        ++indices[index];
      }
      
      return min;
    }
};
```

<br>

### Statistics

- total accepted: 434668
- total submissions: 716383
- acceptance rate: 60.7%
- likes: 7055
- dislikes: 259

<br>

### Similar Problems

- [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums) (Medium)
- [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table) (Hard)
- [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance) (Hard)
- [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction) (Medium)
