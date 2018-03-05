### Insertion Sort:

Insertion sort works by considering the first index as sorted. Then, from the second index -> end of array:

+ look at array[i]:
	+ inner loop j = 1; while j > 0 and out of order:
		+ descend in comparisons from j & (j - 1) -> 1 & 0. If out of order, swap them.
		+ decrement j
