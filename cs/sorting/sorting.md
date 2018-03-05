### Insertion Sort:

Insertion sort works by considering the first index as sorted. Then, from the second index -> end of array:

+ look at array[i]:
	+ inner loop j = i; while j > 0 and out of order:
		+ descend in comparisons from j & (j - 1). If out of order, swap.
		+ decrement j

Complexity = O(n^2) (Same as bubble == bad)
Incremental approach to Algorithms.

### Merge Sort:

The merge sort algorithm closely follows the divide-and-conquer paradigm (based on recursion). Intuitively,it operates as follows.

+ Divide: Divide the n-element sequence to be sorted into two subsequences of n=2 elements each.
+ Conquer: Sort the two subsequences recursively using merge sort.
+ Combine: Merge the two sorted subsequences to produce the sorted answer.

+ if array.size > 1:
	+ calculate midpoint
	+ divide array into 2 slices around the midpoint
	+ recursively call function on each slice (left and right)
	+ while not run out of indexes in right or left slice (which has been sorted in recursive call):
		+ copy the smaller of the two into our master array
	+ depleted either left or right, copy the rest of the remaining pile to our master array

Complexity = O(n log n)
