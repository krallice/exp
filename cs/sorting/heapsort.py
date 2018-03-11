#!/usr/bin/python

def get_parent_index(i):
    
    return ((i - 1) / 2)

def get_left_index(i):

    return ((2 * i) + 1)

def get_right_index(i):

    return ((2 * i) + 2)

def max_heapify(a, i):

    # Build a heap from the starting index of i:

    l = get_left_index(i)
    r = get_right_index(i)

    largest = 0

    # If left is within bounds, and larger than our initial value,
    # It is now our largest:
    if l < len(a) and a[l] > a[i]:
        largest = l
    # Else stick with our index:
    else:
        largest = i

    # Check if right is within bounds, and our largest?:
    if r < len(a) and a[r] > a[largest]:
        largest = r
    
    # If our parent node (aka i) is not the largest,
    # Place our largest into the parent node,
    # And rerun the algo at the old largest index:
    if largest != i:
        (a[i], a[largest]) = (a[largest], a[i])
        max_heapify(a, largest)

def build_max_heap(a):

    # Start at the halfway point of the array, and work back to index 0:
    for i in range(((len(a) - 1)/ 2), -1, -1):
        print i
        max_heapify(a, i)

if __name__ == "__main__":
    a = [13, 154, 66, 145, 77, 22, 555]
    print a
    build_max_heap(a)
    print a
