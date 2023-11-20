# [138] Copy List with Random Pointer

**[hash-table, linked-list]**

### Statement

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return *the head of the copied linked list*.

The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

* `val`: an integer representing `Node.val`
* `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.



Your code will **only** be given the `head` of the original linked list.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

```

**Input:** head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
**Output:** [[7,null],[13,0],[11,4],[10,2],[1,0]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/12/18/e2.png)

```

**Input:** head = [[1,1],[2,1]]
**Output:** [[1,1],[2,1]]

```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2019/12/18/e3.png)**

```

**Input:** head = [[3,null],[3,0],[3,null]]
**Output:** [[3,null],[3,0],[3,null]]

```

**Constraints:**
* `0 <= n <= 1000`
* `-10^4 <= Node.val <= 10^4`
* `Node.random` is `null` or is pointing to some node in the linked list.


<br />

### Hints

- Just iterate the linked list and create copies of the nodes on the go. Since a node can be referenced from multiple nodes due to the random pointers, ensure you are not making multiple copies of the same node.
- You may want to use extra space to keep old_node ---> new_node mapping to prevent creating multiple copies of the same node.
- We can avoid using extra space for old_node ---> new_node mapping by tweaking the original linked list. Simply interweave the nodes of the old and copied list. For example:
Old List: A --> B --> C --> D
InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
- The interweaving is done using next</b> pointers and we can make use of interweaved structure to get the correct reference nodes for random</b> pointers.

<br />

### Solution

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* copyRandomList(Node *head) {
      Node base(-1), *node_original = head, *node_new = &base;
      std::vector <Node*> v;
      std::map <Node*, int> map;
      int index = 0;

      while (node_original != nullptr) {
        Node *node_next = new Node(node_original->val);
        v.emplace_back(node_next);
        map[node_original] = index;
        ++index;
        node_new->next = node_next;
        node_new = node_next;
        node_original = node_original->next;
      }
      
      index = 0;
      node_original = head;

      while (node_original != nullptr) {
        if (map.count(node_original->random))
          v[index]->random = v[map[node_original->random]];
        node_original = node_original->next;
        ++index;
      }

      return base.next;
    }
};
```

<br />

### Statistics

- total accepted: 1022943
- total submissions: 1933659
- acceptance rate: 52.9%
- likes: 12170
- dislikes: 1247

<br />

### Similar Problems

- [Clone Graph](https://leetcode.com/problems/clone-graph) (Medium)
- [Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer) (Medium)
- [Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree) (Medium)
