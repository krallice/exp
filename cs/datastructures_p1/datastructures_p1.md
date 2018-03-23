## Stacks

A stack is a basic data structure that can be logically thought as linear structure represented by a real physical stack or pile, a structure where insertion and deletion of items takes place at one end called top of the stack. The stack implements a last-in, first-out, or **LIFO**, policy. Can be implemented through linked lists or arrays.


#### Defined Methods:
```
Push - adds an element to the collection
Pop - removes the most recently added element from the top.
Peek - check value (at the 'top') without removing the value
isEmpty? isFull?
```

![alt text](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png "Stack")
'

## Linked Lists
### Basic Linked Lists

A linked list is a linear collection of data elements, in which linear order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of data and a reference (in other words, a link) to the next node in the sequence.

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/408px-Singly-linked-list.svg.png "Linked List")

## Heaps
### Basic Heaps

The (binary) heap data structure is an array object that we can view as a
nearly complete binary tree. Each node of the tree corresponds to an element of the array. The tree is completely filled on all levels except possibly the lowest, which is filled from the left up to a point. An array A that represents a heap is an object with two attributes:

+ A:length, which (as usual) gives the number of elements in the array, and 
+ A:heap-size, which represents how many elements in the heap are stored within array A. That is, although A:length may contain numbers, only the elements
in A:heap-size, where 0 <= A:heap-size <= A:length, are valid elements of the heap. The root of the tree is A[1], and given the index i of a node, we can easily compute the indices of its parent, left child, and right child:

![alt text](https://i1.wp.com/algorithms.tutorialhorizon.com/files/2015/02/Max-Heap.png "Max Heap")

There are two kinds of binary heaps: max-heaps and min-heaps. In both kinds,the values in the nodes satisfy a heap property, the specifics of which depend onthe kind of heap. In a *max-heap*, the max-heap property is that for every node other than the root:
```
A[PARENT(i)] >= A[i]
```
Thus, the largest element in a max-heap is stored at the root, and the subtree rooted at a node contains values no larger than that contained at the node itself. A min-heap is organized in the opposite way.
