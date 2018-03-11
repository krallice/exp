#!/usr/bin/python

def get_parent_index(i):
    
    return ((i - 1) / 2)

def get_left_index(i):

    return ((2 * i) + 1)

def get_right_index(i):

    return ((2 * i) + 2)

def max_heapify(a, size, i):

    # Build a heap from the starting index of i:

    l = get_left_index(i)
    r = get_right_index(i)

    largest = 0

    # If left is within bounds, and larger than our initial value,
    # It is now our largest:
    if l < size and a[l] > a[i]:
        largest = l
    # Else stick with our index:
    else:
        largest = i

    # Check if right is within bounds, and our largest?:
    if r < size and a[r] > a[largest]:
        largest = r
    
    # If our parent node (aka i) is not the largest,
    # Place our largest into the parent node,
    # And rerun the algo at the old largest index:
    if largest != i:
        (a[i], a[largest]) = (a[largest], a[i])
        max_heapify(a, size, largest)

def build_max_heap(a):

    # Start at the halfway point of the array, and work back to index 0:
    for i in range(((len(a) - 1)/ 2), -1, -1):
        max_heapify(a, len(a), i)

def heapsort(a):

    #build_max_heap(a)

    heap_size = len(a)

    # Working down from the end of the array to the second index (i = 1)
    for i in range((len(a) - 1), 0, -1):

        # After max_heapify is run, a[0] will always be the top of the heap
        # Swap our current value (near the end of the array) with the highest value in heap (a[0]):
        (a[0], a[i]) = (a[i], a[0])
        
        # Reorganize heap with (length - i) so that largest values placed at
        # end of array are ignored.
        heap_size = heap_size - 1
        max_heapify(a, heap_size, 0)

if __name__ == "__main__":
    a = [13, 154, 66, 145, 77, 22, 555, 25, 24, 21, 88, 12]
    print "Original: " + str(a)
    build_max_heap(a)
    print "Max Heap: " + str(a)
    heapsort(a)
    print "HeapSort: " + str(a)
