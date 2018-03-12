#!/usr/bin/python

class MaxHeap(object):

    def __init__(self, a):

        # Our unsorted list:
        self.a = a
        self.heap_size = len(a) - 1

        self.__build_max_heap()

    def max_heapify(self, i):

        left = self.__get_left_index(i)
        right = self.__get_right_index(i)

        largest_index = 0

        if left <= self.heap_size and self.a[left] > self.a[i]:
            largest_index = left
        else:
            largest_index = i

        if right <= self.heap_size and self.a[right] > self.a[largest_index]:
            largest_index = right

        if largest_index != i:
            (self.a[i], self.a[largest_index]) = (self.a[largest_index], self.a[i])
            self.max_heapify(largest_index)

    def heapsort(self):

        heap_size = self.heap_size

        for i in range(self.heap_size, 0, -1):

            (self.a[0], self.a[i]) = (self.a[i], self.a[0])
            self.heap_size = self.heap_size - 1
            self.max_heapify(0)

        self.heap_size = heap_size

    def __build_max_heap(self):

        for i in range((self.heap_size / 2), -1, -1):
                self.max_heapify(i)
        
    def __get_left_index(self, i):
        return ((2 * i) + 1)

    def __get_right_index(self, i):
        return ((2 * i) + 2)

    def __get_parent_index(self, i):
        return ((i - 1) / 2)

    def __str__(self):
        return str(self.a)

if __name__ == "__main__":
    mh = MaxHeap([13, 154, 66, 145, 77, 22, 555, 25, 24, 21, 88, 12])
    print mh
    mh.heapsort()
    print mh
