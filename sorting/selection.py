#!/usr/bin/python

def swap(a, b):

	temp = a
	a = b
	b = temp

	return (a, b)

def cleanSelectionSort(l):

	for selectedSlot in range(len(l)-1, 0, -1):
		maxIndex = selectedSlot

		for i in range(selectedSlot):
			if l[i] > l[maxIndex]:
				maxIndex = i

		if maxIndex != selectedSlot:
			(l[maxIndex], l[selectedSlot]) = swap(l[maxIndex], l[selectedSlot])

def selectionSort(l):

	print "%s\n" % l

	for selectedSlot in range(len(l)-1, 0, -1):

		maxIndex = selectedSlot
		print "Selected slot: %s, max value: %s" % (selectedSlot, l[selectedSlot])

		for i in range(selectedSlot):

			print "i comparison index: %s, value: %s" % (i, l[i])
			if l[i] > l[maxIndex]:
				maxIndex = i
				print "New maxIndex is %s, value: %s" % (maxIndex, l[maxIndex])

		print "Ultimate maxIndex is %s, value: %s" % (maxIndex, l[maxIndex])
		if maxIndex != selectedSlot:
			print "Swapping %s with %s" % (selectedSlot, maxIndex)
			(l[maxIndex], l[selectedSlot]) = swap(l[maxIndex], l[selectedSlot])

		print "End of selectedSlot: %s\n" % l

	print "End of Algorithm: %s" % l


if __name__ == "__main__":

	l = [256, 128, 16, 32, 4096, 2]
	selectionSort(l)
