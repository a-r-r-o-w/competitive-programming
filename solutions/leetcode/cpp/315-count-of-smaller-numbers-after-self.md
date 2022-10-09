# [315] Count of Smaller Numbers After Self

**[array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set]**

### Statement

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.


**Example 1:**

```

**Input:** nums = [5,2,6,1]
**Output:** [2,1,1,0]
**Explanation:**
To the right of 5 there are **2** smaller elements (2 and 1).
To the right of 2 there is only **1** smaller element (1).
To the right of 6 there is **1** smaller element (1).
To the right of 1 there is **0** smaller element.

```

**Example 2:**

```

**Input:** nums = [-1]
**Output:** [0]

```

**Example 3:**

```

**Input:** nums = [-1,-1]
**Output:** [0,0]

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`


<br>

### Hints

None

<br>

### Solution

**Segment Tree**

```cpp
namespace arrow {
  enum class tree_memory_layout {
    binary,
    euler_tour
  };

  template <
    class Type,
    tree_memory_layout impl_type = tree_memory_layout::binary
  >
  class segment_tree {
    private:
      std::vector <Type> tree;
      
      int base_size;
      const std::vector <Type>& base_ref;

      Type (*combine) (const Type&, const Type&);

    public:
      segment_tree (int base_size, const std::vector <Type>& base, Type (*combine) (const Type&, const Type&))
        : base_size (base_size),
          base_ref (base),
          combine (combine) {
        if constexpr (impl_type == tree_memory_layout::binary)
          tree.resize(4 * base_size, Type{});
        else
          tree.resize(2 * base_size, Type{});
        _build_impl(0, 0, base_size - 1);
      }

      void point_update (int position, const Type& value)
      { _point_update_impl(0, 0, base_size - 1, position, value); }

      Type point_query (int position)
      { return _point_query_impl(0, 0, base_size - 1, position); }

      Type range_query (int l, int r)
      { return _range_query_impl(0, 0, base_size - 1, l, r); }

      template <typename... ParamTypes>
      void custom_point_update (int position, const ParamTypes&... params)
      { _custom_point_update_impl(0, 0, base_size - 1, position, params...); }

      template <typename ReturnType, typename... ParamTypes>
      ReturnType custom_query (const ParamTypes&... params)
      { return _custom_query_impl <ReturnType> (0, 0, base_size - 1, params...); }

    private:
      int _get_leftchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
        if constexpr (impl_type == tree_memory_layout::binary)
          return 2 * v + 1;
        else
          return v + 1;
      }

      int _get_rightchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
        if constexpr (impl_type == tree_memory_layout::binary)
          return 2 * v + 2;
        else {
          int tm = (tl + tr) / 2;
          int node_count = tm - tl + 1;
          return v + 2 * node_count;
        }
      }

      void _build_impl (int v, int tl, int tr) {
        if (tl == tr) {
          tree[v] = base_ref[tl];
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        _build_impl(lchild, tl, tm);
        _build_impl(rchild, tm + 1, tr);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      void _point_update_impl (int v, int tl, int tr, int position, const Type& value) {
        if (tl == tr) {
          tree[v] += value;
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);
        
        if (position <= tm)
          _point_update_impl(lchild, tl, tm, position, value);
        else
          _point_update_impl(rchild, tm + 1, tr, position, value);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      Type _point_query_impl (int v, int tl, int tr, int position) {
        if (tl == tr)
          return tree[v];
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);
        
        if (position <= tm)
          return _point_query_impl(lchild, tl, tm, position);
        else
          return _point_query_impl(rchild, tm + 1, tr, position);
      }

      Type _range_query_impl (int v, int tl, int tr, int l, int r) {
        if (l > r)
          return {};
        
        if (tl == l and tr == r)
          return tree[v];
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        Type lval = _range_query_impl(lchild, tl, tm, l, std::min(r, tm));
        Type rval = _range_query_impl(rchild, tm + 1, tr, std::max(l, tm + 1), r);
        
        return combine(lval, rval);
      }

      void _custom_point_update_impl (int v, int tl, int tr, int position) {
        if (tl == tr) {
          throw std::runtime_error("undefined implementation");
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        if (position <= tm)
          _custom_point_update_impl(lchild, tl, tm, position);
        else
          _custom_point_update_impl(rchild, tm + 1, tr, position);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      template <typename ReturnType>
      ReturnType _custom_query_impl (int v, int tl, int tr) {
        if (tl == tr) {
          throw std::runtime_error("undefined implementation");
          return ReturnType{};
        }
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        if (true)
          return _custom_query_impl <ReturnType> (lchild, tl, tm);
        else
          return _custom_query_impl <ReturnType> (rchild, tm + 1, tr);
      }
  };
};

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> countSmaller (vector <int>& nums) {
      const int max = 20000 + 1;
      const int offset = 10000;
      int n = nums.size();
      std::vector <int> ans (n);
      
      for (int i = 0; i < n; ++i)
        nums[i] += offset;
      
      arrow::segment_tree <int, arrow::tree_memory_layout::euler_tour> tree (max, std::vector <int> (max), [] (auto &l, auto &r) {
        return l + r;
      });
      
      for (int i = n - 1; i >= 0; --i) {
        ans[i] = tree.range_query(0, nums[i] - 1);
        tree.point_update(nums[i], 1);
      }
      
      return ans;
    }
};
```

**Merge Sort**

```cpp
class Solution {
  public:
    vector <int> countSmaller (vector <int>& nums) {
      using pair = std::pair <int, int>;
      
      int n = nums.size();
      std::vector <int> ans (n);
      std::vector <pair> values (n);
      
      for (int index = 0; auto &[x, y]: values) {
        x = nums[index];
        y = index;
        ++index;
      }
      
      auto merge_sort = [&] (auto self, int l, int r) -> void {
        if (l >= r)
          return;
        
        int m = (l + r) / 2;
        
        self(self, l, m);
        self(self, m + 1, r);
        
        for (int i = l, j = m + 1; i <= m; ++i) {
          while (j <= r && values[j].first < values[i].first)
            ++j;
          ans[values[i].second] += j - m - 1;
        }
        
        std::inplace_merge(values.begin() + l, values.begin() + m + 1, values.begin() + r + 1);
      };
      
      merge_sort(merge_sort, 0, n - 1);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 260898
- total submissions: 610566
- acceptance rate: 42.7%
- likes: 6930
- dislikes: 191

<br>

### Similar Problems

- [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum) (Hard)
- [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height) (Medium)
- [Reverse Pairs](https://leetcode.com/problems/reverse-pairs) (Hard)
- [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number) (Easy)
- [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array) (Hard)
