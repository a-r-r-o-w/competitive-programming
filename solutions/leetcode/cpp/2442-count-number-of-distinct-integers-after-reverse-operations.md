# [2442] Count Number of Distinct Integers After Reverse Operations



### Statement

You are given an array `nums` consisting of **positive** integers.

You have to take each integer in the array, **reverse its digits**, and add it to the end of the array. You should apply this operation to the original integers in `nums`.

Return *the number of **distinct** integers in the final array*.


**Example 1:**

```

**Input:** nums = [1,13,10,12,31]
**Output:** 6
**Explanation:** After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
```

**Example 2:**

```

**Input:** nums = [2,2,2]
**Output:** 1
**Explanation:** After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 106`


<br>

### Hints

- What data structure allows us to insert numbers and find the number of distinct numbers in it?
- Try using a set, insert all the numbers and their reverse into it, and return its size.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countDistinctIntegers (vector <int>& nums) {
      auto reverse = [] (int x) {
        int r = 0;
        while (x) {
          r = r * 10 + x % 10;
          x /= 10;
        }
        return r;
      };
      
      std::unordered_set <int> have;
      
      for (int i: nums) {
        have.insert(i);
        have.insert(reverse(i));
      }
      
      return have.size();
    }
};
```

<br>

### Statistics

- total accepted: 15643
- total submissions: 19995
- acceptance rate: 78.2%
- likes: 89
- dislikes: 6

<br>

### Similar Problems

- [Reverse Integer](https://leetcode.com/problems/reverse-integer) (Medium)
