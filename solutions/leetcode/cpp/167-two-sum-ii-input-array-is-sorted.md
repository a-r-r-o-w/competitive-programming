# [167] Two Sum II - Input Array Is Sorted

**[array, two-pointers, binary-search]**

### Statement

Given a **1-indexed** array of integers `numbers` that is already ***sorted in non-decreasing order***, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the indices of the two numbers,* `index1` *and* `index2`*, **added by one** as an integer array* `[index1, index2]` *of length 2.*

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.


**Example 1:**

```

**Input:** numbers = [2,7,11,15], target = 9
**Output:** [1,2]
**Explanation:** The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

```

**Example 2:**

```

**Input:** numbers = [2,3,4], target = 6
**Output:** [1,3]
**Explanation:** The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

```

**Example 3:**

```

**Input:** numbers = [-1,0], target = -1
**Output:** [1,2]
**Explanation:** The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

```

**Constraints:**
* `2 <= numbers.length <= 3 * 104`
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in **non-decreasing order**.
* `-1000 <= target <= 1000`
* The tests are generated such that there is **exactly one solution**.


<br>

### Hints

None

<br>

### Solution

**O(n.log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> twoSum (vector <int>& numbers, int target) {
      std::vector <int> ans (2);
      int n = numbers.size();
      
      for (int i = 0; i < n; ++i) {
        int low = i + 1, high = n;
        
        while (low < high) {
          int mid = (low + high) / 2;
          int r = numbers[i] + numbers[mid];
          
          if (r < target)
            low = mid + 1;
          else
            high = mid;
        }
        
        if (low < n and numbers[i] + numbers[low] == target) {
          ans[0] = i + 1;
          ans[1] = low + 1;
          break;
        }
      }
      
      return ans;
    }
};
```

**O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> twoSum (vector <int>& numbers, int target) {
      std::vector <int> ans (2);
      int n = numbers.size();
      int l = 0, r = n - 1;
      
      while (true) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) {
          ans[0] = l + 1;
          ans[1] = r + 1;
          break;
        }
        else if (sum < target)
          ++l;
        else
          --r;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1138107
- total submissions: 1904053
- acceptance rate: 59.8%
- likes: 7094
- dislikes: 1035

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) (Easy)
- [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k) (Easy)
