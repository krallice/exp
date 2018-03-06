## Heaps
### Basic Heaps

The (binary) heap data structure is an array object that we can view as a
nearly complete binary tree. Each node of the tree corresponds to an element of the array. The tree is completely filled on all levels except possibly the lowest, which is filled from the left up to a point. An array A that represents a heap is an object with two attributes:

+ A:length, which (as usual) gives the number of elements in the array, and 
+ A:heap-size, which represents how many elements in the heap are stored within array A. That is, although A:length may contain numbers, only the elements
in A:heap-size, where 0 <= A:heap-size <= A:length, are valid elements of the heap. The root of the tree is A[1], and given the index i of a node, we can easily compute the indices of its parent, left child, and right child:

![alt text](https://i1.wp.com/algorithms.tutorialhorizon.com/files/2015/02/Max-Heap.png "Max Heap")
