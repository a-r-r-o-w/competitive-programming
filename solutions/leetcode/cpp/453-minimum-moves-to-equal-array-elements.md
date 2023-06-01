# [453] Minimum Moves to Equal Array Elements

**[array, math]**

### Statement

Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.

In one move, you can increment `n - 1` elements of the array by `1`.


**Example 1:**

```

**Input:** nums = [1,2,3]
**Output:** 3
**Explanation:** Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

```

**Example 2:**

```

**Input:** nums = [1,1,1]
**Output:** 0

```

**Constraints:**
* `n == nums.length`
* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* The answer is guaranteed to fit in a **32-bit** integer.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int minMoves (vector <int>& nums) {
      int64_t sum = 0, min = 1LL << 60;
      for (int i: nums) {
        min = std::min <int64_t> (min, i);
        sum += i;
      }
      return sum - (int64_t)nums.size() * min;
    }
};
```

<br />

### Statistics

- total accepted: 151573
- total submissions: 270582
- acceptance rate: 56.0%
- likes: 2209
- dislikes: 1827

<br />

### Similar Problems

- [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii) (Medium)
- [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers) (Hard)
- [Pour Water Between Buckets to Make Water Levels Equal](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal) (Medium)
- [Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill) (Medium)
