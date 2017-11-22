#!/usr/bin/python

class Beast(object):
	def __init__(self):
		pass

class Dog(Beast):
	def __init__(self):
		pass

	def __str__(self):
		return "I am DAWG"

class Cat(Beast):
	def __init__(self):
		pass

	def __str__(self):
		return "I am a whack cat"

class BeastFactory(object):
	def __new__(self, beast):
		if beast == "dog":
			return Dog()
		elif beast == "cat":
			return Cat()
		else:
			raise Exception()

if __name__ == "__main__":
	b = BeastFactory("dog")
	print b
