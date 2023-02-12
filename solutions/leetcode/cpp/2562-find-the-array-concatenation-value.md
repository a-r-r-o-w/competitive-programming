# [2562] Find the Array Concatenation Value



### Statement

You are given a **0-indexed** integer array `nums`.

The **concatenation** of two numbers is the number formed by concatenating their numerals.

* For example, the concatenation of `15`, `49` is `1549`.



The **concatenation value** of `nums` is initially equal to `0`. Perform this operation until `nums` becomes empty:

* If there exists more than one number in `nums`, pick the first element and last element in `nums` respectively and add the value of their concatenation to the **concatenation value** of `nums`, then delete the first and last element from `nums`.
* If one element exists, add its value to the **concatenation value** of `nums`, then delete it.



Return *the concatenation value of the `nums`*.


**Example 1:**

```

**Input:** nums = [7,52,2,4]
**Output:** 596
**Explanation:** Before performing any operation, nums is [7,52,2,4] and concatenation value is 0.
 - In the first operation:
We pick the first element, 7, and the last element, 4.
Their concatenation is 74, and we add it to the concatenation value, so it becomes equal to 74.
Then we delete them from nums, so nums becomes equal to [52,2].
 - In the second operation:
We pick the first element, 52, and the last element, 2.
Their concatenation is 522, and we add it to the concatenation value, so it becomes equal to 596.
Then we delete them from the nums, so nums becomes empty.
Since the concatenation value is 596 so the answer is 596.

```

**Example 2:**

```

**Input:** nums = [5,14,13,8,12]
**Output:** 673
**Explanation:** Before performing any operation, nums is [5,14,13,8,12] and concatenation value is 0.
 - In the first operation:
We pick the first element, 5, and the last element, 12.
Their concatenation is 512, and we add it to the concatenation value, so it becomes equal to 512.
Then we delete them from the nums, so nums becomes equal to [14,13,8].
 - In the second operation:
We pick the first element, 14, and the last element, 8.
Their concatenation is 148, and we add it to the concatenation value, so it becomes equal to 660.
Then we delete them from the nums, so nums becomes equal to [13].
 - In the third operation:
nums has only one element, so we pick 13 and add it to the concatenation value, so it becomes equal to 673.
Then we delete it from nums, so nums become empty.
Since the concatenation value is 673 so the answer is 673.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 10^4`


.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}


<br />

### Hints

- Consider simulating the process to calculate the answer
- iterate until the array becomes empty. In each iteration, concatenate the first element to the last element and add their concatenation value to the answer.
- Don’t forget to handle cases when one element is left in the end, not two elements.

<br />

### Solution

```cpp
class Solution {
  public:
    long long findTheArrayConcVal (vector <int>& nums) {
      int64_t sum = 0;
      int n = nums.size();
      
      for (int i = 0; i < n / 2; ++i)
        sum += std::stoi(std::to_string(nums[i]) + std::to_string(nums[n - i - 1]));
      if (n & 1)
        sum += nums[n / 2];
      
      return sum;
    }
};
```

<br />

### Statistics

- total accepted: 16759
- total submissions: 24448
- acceptance rate: 68.5%
- likes: 59
- dislikes: 2

<br />

### Similar Problems

None
