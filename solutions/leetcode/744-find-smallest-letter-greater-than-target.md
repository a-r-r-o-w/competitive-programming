# [744] Find Smallest Letter Greater Than Target

**[array, binary-search]**

### Statement

Given a characters array `letters` that is sorted in **non-decreasing** order and a character `target`, return *the smallest character in the array that is larger than* `target`.

**Note** that the letters wrap around.

* For example, if `target == 'z'` and `letters == ['a', 'b']`, the answer is `'a'`.


**Example 1:**

```

**Input:** letters = ["c","f","j"], target = "a"
**Output:** "c"

```

**Example 2:**

```

**Input:** letters = ["c","f","j"], target = "c"
**Output:** "f"

```

**Example 3:**

```

**Input:** letters = ["c","f","j"], target = "d"
**Output:** "f"

```

**Constraints:**
* `2 <= letters.length <= 104`
* `letters[i]` is a lowercase English letter.
* `letters` is sorted in **non-decreasing** order.
* `letters` contains at least two different characters.
* `target` is a lowercase English letter.


<br>

### Hints

- Try to find whether each of 26 next letters are in the given string array.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    char nextGreatestLetter (vector <char>& letters, char target) {
      int low = 0, high = letters.size();
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (letters[mid] <= target)
          low = mid + 1;
        else
          high = mid;
      }
      
      if (low == (int)letters.size())
        return letters[0];
      return letters[low];
    }
};
```

<br>

### Statistics

- total accepted: 221655
- total submissions: 495579
- acceptance rate: 44.7%
- likes: 1941
- dislikes: 1756

<br>

### Similar Problems

- [Count Elements With Strictly Smaller and Greater Elements ](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements) (Easy)
