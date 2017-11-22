#!/usr/bin/python

def swap(a, b):

	temp = a
	a = b
	b = temp

	return (a, b)

def bubbleSort(l):

	print "%s\n" % l

	for iterNum in range(len(l)-1, 0, -1):
		print "iterNum is %s" % iterNum
		
		for i in range(iterNum):
			print "Comparing %s with %s" % (l[i], l[i+1])
			if l[i] > l[i+1]:
				print "Swapping"
				(l[i], l[i+1]) = swap(l[i], l[i+1])
				print l

		print "End of iter list: %s\n" % l

	print "End of Algorithm: %s" % l


if __name__ == "__main__":

	#l = [100, 30, 10, 20]
	#bubbleSort(l)

	#print "\n\n\n"
	l = [256, 128, 16, 32, 4096, 2]
	bubbleSort(l)
