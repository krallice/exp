#!/usr/bin/python

def partition(a, lo, hi):

    pivot = a[hi]
    print "Pivot: " + str(pivot)
    print "List: " + str(a[lo:hi+1])

    index = lo - 1

    for j in range(lo, hi):

        if a[j] < pivot:
            index = index + 1
            (a[j], a[index]) = (a[index], a[j])

    (a[index + 1], a[hi]) = (a[hi], a[index + 1])
    print "Pivoted: " + str(a)
    return index + 1

def quick_sort(a, lo, hi):

    if (lo < hi):

        p = partition(a, lo, hi)
        print p
        quick_sort(a, lo, p - 1 )
        quick_sort(a, p + 1, hi)
        print a
    

if __name__ == "__main__":

    a = [13, 154, 23, 66, 145, 77, 22, 555]

    print a
    quick_sort(a, 0, (len(a) - 1))
    print a
