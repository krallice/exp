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

	#print "Target:", target
	#print "Attempt:", attempt

	i = 0
	score = 0
	while i < len(target):
		if target[i] == attempt[i]:
			score = score + 1
		else:
			pass

		i = i + 1
	return score

def main():

	# Target String:
	t = "best beer"
	t_score = len(t)
	attempts = 100000

	finished = 0
	total_iter = 0
	
	overall_high_score = 0

	print "Target:", t
	print "Target Score:", t_score
	print

	while finished == 0:

		high_score = 0
		i = 0
		print "Iteration starting:", total_iter
		while i < attempts and finished == 0:
		
			a = random_string(len(t))
			score = compare_string(t, a)
			if score > high_score:
				high_score = score
				best_attempt = a
			if score == len(t):
				finished = 1
				
			i = i + 1
			total_iter = total_iter + 1
		
		if high_score > overall_high_score:
			overall_high_score = high_score
			overall_best_attempt = best_attempt

		print "High Score of Block:", high_score, " (Previous High Score: ", overall_high_score, ")"
		print "Best Attempt of Block:", best_attempt, " (Previous Best Attempt: ", overall_best_attempt, ")"
		print

	print "Total Iterations:", total_iter

	#print random_string(27)
	#print random_string(27)
	#print random_string(27)

if __name__ == "__main__":
	main()
