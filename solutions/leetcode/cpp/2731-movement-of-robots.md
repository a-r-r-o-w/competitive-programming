# [2731] Movement of Robots



### Statement

Some robots are standing on an infinite number line with their initial coordinates given by a **0-indexed** integer array `nums` and will start moving once given the command to move. The robots will move a unit distance each second.

You are given a string `s` denoting the direction in which robots will move on command. `'L'` means the robot will move towards the left side or negative side of the number line, whereas `'R'` means the robot will move towards the right side or positive side of the number line.

If two robots collide, they will start moving in opposite directions.

Return *the sum of distances between all thepairs of robots* `d` *seconds afterthe command.* Since the sum can be very large, return it modulo `10^9 + 7`.

**Note:** 
* For two robots at the index `i` and `j`, pair `(i,j)` and pair `(j,i)` are considered the same pair.
* When robots collide, they **instantly change** their directions without wasting any time.
* Collision happenswhen two robots share the same place in amoment.
	+ For example, if a robot is positioned in 0 going to the right and another is positioned in 2 going to the left, the next second they'll be both in 1 and they will change direction and the next second the first one will be in 0, heading left, and another will be in 2, heading right.
	+ For example,if a robot is positioned in 0 going to the right and another is positioned in 1going to the left, the next second the first one will be in 0, heading left, and another will be in 1, heading right.


**Example 1:**

```

**Input:** nums = [-2,0,2], s = "RLL", d = 3
**Output:** 8
**Explanation:** 
After 1 second, the positions are [-1,-1,1]. Now, the robot at index 0 will move left, and the robot at index 1 will move right.
After 2 seconds, the positions are [-2,0,0]. Now, the robot at index 1 will move left, and the robot at index 2 will move right.
After 3 seconds, the positions are [-3,-1,1].
The distance between the robot at index 0 and 1 is abs(-3 - (-1)) = 2.
The distance between the robot at index 0 and 2 is abs(-3 - 1) = 4.
The distance between the robot at index 0 and 1 is abs(-1 - 1) = 2.
The sum of the pairs of all distances = 2 + 4 + 2 = 8.

```

**Example 2:**

```

**Input:** nums = [1,0], s = "RL", d = 2
**Output:** 5
**Explanation:** 
After 1 second, the positions are [2,-1].
After 2 seconds, the positions are [3,-2].
The distance between the two robots is abs(-2 - 3) = 5.

```

**Constraints:**
* `2 <= nums.length <= 10^5`
* `-2 * 10^9<= nums[i] <= 2 * 10^9`
* `0 <= d <= 10^9`
* `nums.length == s.length`
* `s` consists of 'L' and 'R' only
* `nums[i]`will be unique.


<br />

### Hints

- Observe that if you ignore collisions, the resultant positions of robots after d seconds would be the same.
- After d seconds, sort the ending positions and use prefix sum to calculate the distance sum.

<br />

### Solution

```cpp
class Solution {
  public:
    int sumDistance (vector <int>& nums, string s, int d) {
      int n = nums.size();
      std::vector <int64_t> num (n);
      
      for (int i = 0; i < n; ++i) {
        num[i] = nums[i];
        if (s[i] == 'L')
          num[i] -= d;
        else
          num[i] += d;
      }
      std::sort(num.begin(), num.end());
      
      const int mod = 1000000007;
      int64_t ans = 0, sum = 0;
      
      for (int i = 1; i < n; ++i) {
        int64_t d = num[i] - num[0];
        sum += d;
        sum %= mod;
      }
      ans += sum;
      for (int i = 1; i < n; ++i) {
        sum -= int64_t(n - i) * (num[i] - num[i - 1]) % mod;
        sum = (sum + mod) % mod;
        ans = (ans + sum) % mod;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 6137
- total submissions: 24156
- acceptance rate: 25.4%
- likes: 192
- dislikes: 64

<br />

### Similar Problems

- [Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank) (Medium)
