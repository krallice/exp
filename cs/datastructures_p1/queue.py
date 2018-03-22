#!/usr/bin/python

class Queue(object):

        def __init__(self):

                self.queue = list()

        def enqueue(self, key):

                self.queue.append(key)

        def dequeue(self):

                return self.queue.pop(0)

class FixedQueue(object):

        """ Primitive Implementation using an Array. Logic play """

        def __init__(self, size):

                self.queue = list()
                for i in range(size+1):
                        self.queue.append(None)

                self.size = size
                self.head = 0
                self.tail = 0

        def enqueue(self, key):

                if ((self.head + 1) % (self.size)) != self.tail:

                        self.queue[self.head] = key

                        self.head = self.head + 1

                        if self.head == self.size - 1:
                                self.head = 0

                else:
                        # Overflow
                        print "Overflow!!"
                        raise IndexError

        def dequeue(self):

                if self.tail != self.head:

                        retval = self.queue[self.tail]
                        self.tail = self.tail + 1
                        # Wrap Around:
                        if self.tail == self.size - 1:
                                self.tail = 0
                        return retval

                else:
                        # Underflow:
                        print "Underflow!!"
                        raise IndexError

def test_fixed_queue_overflow():

        queue = FixedQueue(4)
        print queue.queue

        queue.enqueue("dog")
        queue.enqueue("rat")
        queue.enqueue("mat")
        queue.enqueue("red")
        print queue.queue
        print queue.dequeue()
        print queue.dequeue()
        queue.enqueue("green")
        queue.enqueue("yellow")
        queue.enqueue("wibblewobbly")
        print queue.queue


def test_fixed_queue_one():

        queue = FixedQueue(4)

        queue.enqueue("dog")
        queue.enqueue("rat")
        queue.enqueue("mat")
        print queue.queue
        print queue.dequeue()
        print queue.dequeue()
        print queue.dequeue()
        queue.enqueue("red")
        queue.enqueue("green")
        print queue.queue
        print queue.dequeue()
        print queue.dequeue()
        queue.enqueue("yellow")
        print queue.queue
        print queue.dequeue()

def test_vanilla_queue():

        queue = Queue()

        queue.enqueue("cat")
        queue.enqueue("dog")

        print "Popping: %s" % (queue.dequeue())

        for i in range(0, 10):
                queue.enqueue((i*3)+7)

        for i in range(0, 5):
                print "Popping: %s" % (queue.dequeue())


if __name__ == "__main__":

        #test_fixed_queue_one()
        test_fixed_queue_overflow()

        #test_vanilla_queue()

