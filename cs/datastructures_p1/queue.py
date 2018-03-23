#!/usr/bin/python

class Queue(object):

        """ Chump's Array (Native Python Primitives """

        def __init__(self):

                self.queue = list()

        def enqueue(self, key):

                self.queue.append(key)

        def dequeue(self):

                return self.queue.pop(0)

class FixedQueue(object):

        """ Badass Implementation using an Array. Logic play """

        def __init__(self, size):

            self.queue = list()
            for i in range(size):
                    self.queue.append(None)

            self.size = size

            # Our used size:
            self.used = 0

            # Pointers to either index end of the queue:
            self.head = 0
            self.tail = 0

        def enqueue(self, key):

            # We still have room?:
            if self.used != self.size:

                # Insert:
                self.queue[self.tail] = key

                # Increment and roll head:
                self.tail = (self.tail + 1) % self.size

                # Used one more slot:
                self.used = self.used + 1

            else:
                print "OVERFLOW"
                #raise IndexError

        def dequeue(self):

            # We have stuff left in the queue:?
            if self.used != 0:

                # Grab our value:
                retval = self.queue[self.head]

                # Move head up and roll back to zero if required:
                self.head = (self.head + 1) % self.size

                self.used = self.used - 1
                return retval

            else:
                print "UNDERFLOW"
                #raise IndexError

def test_fixed_queue_overflow():

        queue = FixedQueue(4)

        for s in ["jubilat", "blue as blue", "immersion trench reverie", "old apline pang", "god alone"]:
            queue.enqueue(s)
            print queue.queue
            print "Head: %s ; Tail: %s" % (queue.head, queue.tail)

        print "DEQUEUE TIME"
        print "DEQUEUE TIME"
        print "DEQUEUE TIME"

        for i in range(6):
            print queue.dequeue()
            print queue.queue
            print "Head: %s ; Tail: %s" % (queue.head, queue.tail)

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

