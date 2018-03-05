### Insertion Sort:

Insertion sort works by considering the first index as sorted. Then, from the second index -> end of array:

+ look at array[i]:
	+ inner loop j = i; while j > 0 and out of order:
		+ descend in comparisons from j & (j - 1). If out of order, swap.
		+ decrement j

Complexity = O(n^2) (Same as bubble == bad)
