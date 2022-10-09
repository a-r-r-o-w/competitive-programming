# [307] Range Sum Query - Mutable

**[array, design, binary-indexed-tree, segment-tree]**

### Statement

Given an integer array `nums`, handle multiple queries of the following types:

1. **Update** the value of an element in `nums`.
2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.



Implement the `NumArray` class:

* `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
* `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
* `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).


**Example 1:**

```

**Input**
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
**Output**
[null, 9, null, 8]

**Explanation**
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

```

**Constraints:**
* `1 <= nums.length <= 3 * 104`
* `-100 <= nums[i] <= 100`
* `0 <= index < nums.length`
* `-100 <= val <= 100`
* `0 <= left <= right < nums.length`
* At most `3 * 104` calls will be made to `update` and `sumRange`.


<br>

### Hints

None

<br>

### Solution

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
          tree[v] = value;
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

class NumArray {
  public:
    using tree_type = arrow::segment_tree <int, arrow::tree_memory_layout::euler_tour>;
    
    tree_type* tree;
      
    NumArray (vector <int>& nums) {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      
      tree = new tree_type (nums.size(), nums, [] (auto l, auto r) {
        return l + r;
      });
    }
  
    ~NumArray () {
      delete tree;
    }
    
    void update (int index, int val) {
      tree->point_update(index, val);
    }
    
    int sumRange (int left, int right) {
      return tree->range_query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

<br>

### Statistics

- total accepted: 188919
- total submissions: 484986
- acceptance rate: 39.0%
- likes: 2930
- dislikes: 150

<br>

### Similar Problems

- [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable) (Easy)
- [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable) (Hard)
