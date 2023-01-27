# [384] Shuffle an Array

**[array, math, randomized]**

### Statement

Given an integer array `nums`, design an algorithm to randomly shuffle the array. All permutations of the array should be **equally likely** as a result of the shuffling.

Implement the `Solution` class:

* `Solution(int[] nums)` Initializes the object with the integer array `nums`.
* `int[] reset()` Resets the array to its original configuration and returns it.
* `int[] shuffle()` Returns a random shuffling of the array.


**Example 1:**

```

**Input**
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
**Output**
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

**Explanation**
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]


```

**Constraints:**
* `1 <= nums.length <= 50`
* `-106 <= nums[i] <= 106`
* All the elements of `nums` are **unique**.
* At most `104` calls **in total** will be made to `reset` and `shuffle`.


<br>

### Hints

- The solution expects that we always use the original array to shuffle() else some of the test cases fail. (Credits; @snehasingh31)

<br>

### Solution

STL

```cpp
class Solution {
    std::vector <int> original;
    std::mt19937 rng { std::random_device {}() };

  public:
    Solution (vector <int>& nums) {
      original = nums;
    }
    
    vector <int> reset () {
      return original;
    }
    
    vector <int> shuffle () {
      auto v = original;
      std::shuffle(v.begin(), v.end(), rng);
      return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```

Fisher-Yates Algorithm

```cpp
class Solution {
    std::vector <int> original;
    std::mt19937 rng { std::random_device {}() };

  public:
    Solution (vector <int>& nums) {
      original = nums;
    }
    
    vector <int> reset () {
      return original;
    }
    
    vector <int> shuffle () {
      auto v = original;
      int n = v.size();

      for (int i = 0; i < n; ++i)
        std::swap(v[i], v[std::uniform_int_distribution <> (0, i) (rng)]);

      return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```

<br>

### Statistics

- total accepted: 294837
- total submissions: 510134
- acceptance rate: 57.8%
- likes: 1080
- dislikes: 825

<br>

### Similar Problems

None
