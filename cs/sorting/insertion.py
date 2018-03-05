#!/usr/bin/python

def insertion_sort(a):

    # Loop from second index to end of list
    for i in range(1, len(a)):
        current_value = a[i]
        
        # Descend now, comparing i-1 and i
        j = i
        while j > 0 and a[j - 1] > current_value:
            (a[j - 1], a[j]) = (a[j], a[j - 1])
            j = j - 1

def improved_insertion_sort(a):

    # Loop from second index to end of list
    for i in range(1, len(a)):
        current_value = a[i]
        
        # Descend now, comparing i-1 and i
        j = i
        # Slightly improved efficiency of sliding a[i] into the array:
        while j > 0 and a[j - 1] > current_value:
            a[j] = a[j - 1]
            j = j - 1

        a[j] = current_value

if __name__ == "__main__":
    a = [13, 154, 23, 66, 145, 22, 555]
    print a
    improved_insertion_sort(a)
    print a
    
    b = [1, 19, 254, 11, 25, 43, 12, 3]
    print b
    improved_insertion_sort(b)
    print b
