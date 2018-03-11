## O(n^2) -- The Worst
### Insertion Sort:

Insertion sort works by considering the first index as sorted. Then, from the second index -> end of array:

```
for i = second_index -> end_of_array:
    look at array[i]:
    inner loop j = i; while j > 0 and out of order:
        descend in comparisons from j & (j - 1). If out of order, swap.
        decrement j
```
Complexity = O(n^2) (Same as bubble == bad). Represents an incremental approach to Algorithms.

Why even use:

+ Simple
+ More efficient than other O(n^2)s
+ Online - can sort a list as it receives it
+ Adaptive - efficient for data sets that are already substantially sorted
+ In-place - only requires a constant amount O(1) of additional memory space

- - -

## O(n log n) -- Getting better now!
### Merge Sort:
```
Type: Comparitive Sort.
Time Complexity: O(n log n) in worst.
```

The merge sort algorithm closely follows the divide-and-conquer paradigm (based on recursion). Intuitively, it operates as follows:

+ Divide: Divide the n-element sequence to be sorted into two subsequences of n=2 elements each.
+ Conquer: Sort the two subsequences recursively using merge sort.
+ Combine: Merge the two sorted subsequences to produce the sorted answer.

```
if array.size > 1:
    calculate midpoint
    divide array into 2 slices (2 subarrays) around the midpoint
    recursively call same function on each slice (left and right)
	
    // descending up the recursion:
    track an index for the right and left arrays; and while not run out of indexes in right or left slice (which has been sorted in recursive call):
        copy the smaller of the two into our master array
        depleted either left or right, copy the rest of the remaining pile to our master array
```
Complexity = O(n log n)

Out of Place

- - -

### Quick Sort:
```
Type: Comparitive Sort. Exchange Sort like Bubble, Comb.
Time Complexity: O(n log n) on average. *O(n^2) in worst*
```

Quicksort, in Chapter 7, also sorts n numbers in place, but its worst-case running time is O(n^2). Its expected running time is O(n log n), however, and it generally outperforms heapsort in practice. Like insertion sort, quicksort has tight code, and so the hidden constant factor in its running time is small. It is a popular algorithm for sorting large input arrays.

+ Pick an element, called a pivot, from the array.
+ Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
+ Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.

Pseudocode:

```
quick(array, lo, hi)
    if low < high:
        p = partition(array, lo, hi)
        quick(array, low, p - 1)
        quick(array, p + 1, hi)

partition(array, lo, hi)
    pivot = array[hi]
    i = lo - 1
    // If our array slice element is less than our pivot value, 
    // slam it down the start of the array (i will always be lesser or equal to j):
    for j = lo --> high:
        if array[j] < pivot:
            increment i
            swap array[i] and array[j]

    // At this stage a[0..i] < pivot_value;
    // Now set a[i+1] = pivot_value, and return this index
    swap array[i+1] and array[hi]
    return i+1
```
Complexity = O(n log n)

In place and generally faster than Merge sort

- - -

### Heap Sort:
```
Type: Comparitive Sort
Time Complexity: O(n log n) in worst.
```
The heapsort algorithm starts by using BUILD-MAX-HEAP to build a max-heap on the input array a[1..n], where n = a.length. Since the maximum element of the array is stored at the root a[1], we can put it into its correct final position by exchanging it with a[n]. If we now discard node n from the heap (and we can do so by simply decrementing a.heapsize) — we observe that the children of the root remain max-heaps, but the new root element might violate the max-heap property. All we need to do to restore the max-heap property, however, is call MAX-HEAPIFY(a, 1), which leaves a max-heap in a(1 ..n-1). The heapsort algorithm then repeats this process for the max-heap of size n-1 down to a heap of size 2.

Indexed Array | Left() | Right() | Parent()
--- | --- | --- | ---
1 indexed | 2i | 2i + 1 | i / 2
0 indexed | 2i + 1 | 2i + 2 | (i + 1) / 2 

```
HEAPSORT(a):
    BUILD-MAX-HEAP(a)
    for i = a.Length to 2
    exchange a[i] with a[1]
    a.heap_size--
    MAX-HEAPIFY(a, 1)
    
BUILD-MAX-HEAP(a):
    a.heap_size = a.length
    for i = (a.length) / 2 downto 1:
        MAX-HEAPIFY(a, i)
    
MAX-HEAPIFY(a, i):
    l = LEFT(i)
    r = RIGHT(i)
    if l < a.heap_size and a[l] > a[i]:
        largest = l
    else largest = i
    if r < a.heap_size and a[r] > a[largest]:
        largest = r
    if largest != i:
        exchange a[i] with a[largest]
	MAX-HEAPIFY(a, i)
``` 
Usually beaten by quicksort
