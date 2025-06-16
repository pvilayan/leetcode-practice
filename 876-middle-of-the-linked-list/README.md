# 876. Middle of the Linked List

## 🧠 Intuition
The problem asks for the middle node of a singly linked list.  
My first thought was to count the total number of nodes, find the middle index, and then traverse again to that index to return the middle node.

## 🔍 Approach
1. Traverse the list once to count the total number of nodes.
2. Calculate the middle index as `counter / 2`.
3. Traverse the list a second time, stopping at the middle index.
4. Return the pointer to the middle node.

Since we are returning a pointer to the node, the output will include that node and all the nodes after it.

## ⏱️ Complexity
- **Time complexity:** $$O(n)$$  
  We traverse the list twice — once to count, once to find the middle — which is still linear.

- **Space complexity:** $$O(1)$$  
  We only use two pointers and one integer counter. No extra memory is used.

## 💻 Code
See [`solution.cpp`](./solution.cpp)
