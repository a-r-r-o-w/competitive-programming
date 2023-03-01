# [912] Sort an Array

**[array, divide-and-conquer, sorting, heap-priority-queue, merge-sort, bucket-sort, radix-sort, counting-sort]**

### Statement

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.


**Example 1:**

```

**Input:** nums = [5,2,3,1]
**Output:** [1,2,3,5]
**Explanation:** After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

```

**Example 2:**

```

**Input:** nums = [5,1,1,2,0,0]
**Output:** [0,0,1,1,2,5]
**Explanation:** Note that the values of nums are not necessairly unique.

```

**Constraints:**
* `1 <= nums.length <= 5 * 10^4`
* `-5 * 10^4 <= nums[i] <= 5 * 10^4`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> sortArray (vector <int>& nums) {
      auto merge = [] (std::vector <int> &a, int l, int r) -> void {
        int mid = (l + r) / 2;
        int n = mid - l + 1, m = r - mid;

        std::vector <int> p (n), q (m);

        for (int i = 0; i < n; ++i)
          p[i] = a[l + i];
        for (int i = 0; i < m; ++i)
          q[i] = a[mid + 1 + i];
        
        int i = 0, j = 0;

        while (i < n and j < m) {
          if (p[i] < q[j])
            a[l++] = p[i++];
          else
            a[l++] = q[j++];
        }
        while (i < n)
          a[l++] = p[i++];
        while (j < m)
          a[l++] = q[j++];
      };

      auto merge_sort = [&] (auto self, std::vector <int> &a, int l, int r) -> void {
        if (l < r) {
          int mid = (l + r) / 2;
          self(self, a, l, mid);
          self(self, a, mid + 1, r);
          merge(a, l, r);
        }
      };

      merge_sort(merge_sort, nums, 0, nums.size() - 1);
      return nums;
    }
};
```

<br />

### Statistics

- total accepted: 368488
- total submissions: 629576
- acceptance rate: 58.5%
- likes: 3483
- dislikes: 622

<br />

### Similar Problems

None
