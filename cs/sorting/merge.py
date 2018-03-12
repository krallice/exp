#!/usr/bin/python

def merge_sort(a):

    # If we are not already sorted:
    if len(a) > 1:

        print "Splitting: " + str(a)

        # Slice our array into two halves:
        mid_point = len(a) / 2
        left_half = a[:mid_point]
        right_half = a[mid_point:]

        # Recursively call the function:
        merge_sort(left_half)
        merge_sort(right_half)

        print "\tReturned: " + str(a)

        left_index = 0
        right_index = 0
        our_index = 0

        # Once we get to this point, the deeper recusive calls have
        # already sorted our left_half and right_half lists.

        # Assuming they are sorted, lefts combine them back into <a>

        # While either of our left or right piles are not exhausted:
        while left_index < len(left_half) and right_index < len(right_half):

            # Copy the smallest value to our new sorted pile <a>
            if left_half[left_index] < right_half[right_index]:
                a[our_index] = left_half[left_index]
                left_index = left_index + 1
            else:
                a[our_index] = right_half[right_index]
                right_index = right_index + 1

            our_index = our_index + 1

        # One of our piles has been exhausted, lets just copy the rest of the
        # cards onto <a>

        while left_index < len(left_half):
            a[our_index] = left_half[left_index]
            left_index = left_index + 1
            our_index = our_index + 1

        while right_index < len(right_half):
            a[our_index] = right_half[right_index]
            right_index = right_index + 1
            our_index = our_index + 1
            
        print "\t\tDone: " + str(a)

        # Return, it is likely at this point that we are returning to
        # a higher level caller, who will perform this process all over
        # to our newly sorted list

if __name__ == "__main__":
    a = [13, 154, 23, 66, 145, 77, 22, 555]
    print a
    merge_sort(a)
    print a
