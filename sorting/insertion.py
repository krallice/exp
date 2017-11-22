#!/usr/bin/python

def insertionSort(l):

	print "\n%s\n" % l

	for i in range(1, len(l)):

		currentValue = l[i]
		print "Current Value: %s" % l[i]

		j = i
		while j > 0 and l[j-1] > currentValue:
			print "Swapping %s and %s" % (l[j], l[j-1])
			l[j] = l[j-1]
			print l
			j = j - 1

		print "Inserting currentValue %s into index 0" % currentValue
		l[j] = currentValue

		print "End of pass: %s\n" % l

	print "End of algo: %s" % l


if __name__ == "__main__":

	l = [256, 128, 16, 32, 4096, 2]
	insertionSort(l)
