# [2433] Find The Original Array of Prefix Xor

**[array, bit-manipulation]**

### Statement

You are given an **integer** array `pref` of size `n`. Find and return *the array* `arr` *of size* `n` *that satisfies*:

* `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]`.



Note that `^` denotes the **bitwise-xor** operation.

It can be proven that the answer is **unique**.


**Example 1:**

```

**Input:** pref = [5,2,0,3,1]
**Output:** [5,7,2,3,2]
**Explanation:** From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.

```

**Example 2:**

```

**Input:** pref = [13]
**Output:** [13]
**Explanation:** We have pref[0] = arr[0] = 13.

```

**Constraints:**
* `1 <= pref.length <= 105`
* `0 <= pref[i] <= 106`


<br>

### Hints

- Consider the following equation: x ^ a = b. How can you find x?
- Notice that arr[i] ^ pref[i-1] = pref[i]. This is the same as the previous equation.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> findArray (vector <int>& pref) {
      int x = 0;
      
      for (int &i: pref) {
        int t = i;
        i ^= x;
        x = t;
      }
      
      return pref;
    }
};
```

<br>

### Statistics

- total accepted: 21970
- total submissions: 25711
- acceptance rate: 85.4%
- likes: 246
- dislikes: 11

<br>

### Similar Problems

- [Single Number III](https://leetcode.com/problems/single-number-iii) (Medium)
- [Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor) (Medium)
- [Decode XORed Array](https://leetcode.com/problems/decode-xored-array) (Easy)
