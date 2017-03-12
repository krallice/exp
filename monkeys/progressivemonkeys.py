#!/usr/bin/python

import string
import random

def random_string(size):

	count = 0
	rnd_string = ''
	while count < size:
		rnd_string += random.choice(string.ascii_lowercase + ' ')
		count += 1
	return rnd_string

def compare_string(target, attempt):

	i = 0
	score = 0
	while i < len(target):
		if target[i] == attempt[i]:
			score = score + 1
		else:
			pass

		i = i + 1
	return score

# only generate new characters for those that do not match:
def improve_string(target, attempt):

	t = list(target)
	a = list(attempt)

	i = 0
	score = 0
	while i < len(t):
		if t[i] == a[i]:
			pass
		else:
			a[i] = random_string(1)

		i = i + 1

	return a

def main():

	# Our Target:
	t = list("i chase parading ghosts in burning memory through empty shells of stolen moments " )
	t_score = len(t)
	
	# Set Vars:
	finished = 0
	total_iter = 0
	high_score = 0

	# Init go:
	init_attempt = random_string(len(t))
	score = compare_string(t, init_attempt)

	print "Target:", "".join(t)
	print "Target Score:", t_score
	print
	print "Initial Attempt:", init_attempt
	print "Initial Score:", score

	if score == len(t):
		finished = 1

	a = init_attempt

	while finished == 0:

		a = improve_string(t, a)
		score = compare_string(t, a)

		if score == len(t):
			finished = 1
			
		total_iter = total_iter + 1

		print "Attempt:", "".join(a)
		print "Score:", score, "/", t_score
		print

	print "Total Iterations:", total_iter

if __name__ == "__main__":
	main()
