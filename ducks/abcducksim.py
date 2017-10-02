#!/usr/bin/python

import abc

### Flying Class ###
class FlyBehavior(object):
	__metaclass__ = abc.ABCMeta

	@abc.abstractmethod
	def fly(self):
		"""Implement Flying"""
		pass

class FlyWithWings(FlyBehavior):

	def fly(self):
		print "Im Flying!!"

class FlyNoWay(FlyBehavior):

	def fly(self):
		print "I cant fly brazz"

### Quacks ###
class QuackBehavior(object):
	__metaclass__ = abc.ABCMeta

	@abc.abstractmethod
	def quack(self):
		"""Implement Quacking"""
		pass

class Quack(QuackBehavior):

	def quack(self):
		print "Quack"

class MuteQuack(QuackBehavior):
	
	def quack(self):
		print "Silence..."

class Squeak(QuackBehavior):

	def quack(self):
		print "SQUEAK"

### Duck ###
class Duck(object):
	
	def __init__(self):
		self.flyBehavior = FlyBehavior()
		self.quackBehavior = QuackBehavior()

	def performQuack(self):
		self.quackBehavior.quack()

	def performFly(self):
		self.flyBehavior.fly()

	def setFlyBehavior(self, fb):
		self.flyBehavior = fb

	def setQuackBehavior(self, qb):
		self.quackBehavior = qb

	def swim(self):
		print "All ducks float, even decoys"

class MallardDuck(Duck):

	def __init__(self):
		self.quackBehavior = Quack()
		self.flyBehavior = FlyWithWings()

class ModelDuck(Duck):

	def __init__(self):
		self.quackBehavior = Quack()
		self.flyBehavior = FlyNoWay()

### Main ###
if __name__ == "__main__":
	print "Strategy"
	md = MallardDuck()
	md.performFly()
	md.performQuack()
	
	print "Model Duck"
	model = ModelDuck()
	model.performFly()

	print "Model Duck"
	model.setFlyBehavior(FlyWithWings())
	model.performFly()
