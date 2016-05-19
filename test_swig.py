# Tests the swig created module of bro_array

import sys
import numpy as np

# Fails if so_much_swig doesn't exist
import so_much_swig

# Set up the bros
bro1 = so_much_swig.bro_array()
bro2 = so_much_swig.bro_array("Dude")

# The array to work with
arr = np.array(range(1,6), dtype=np.float32)

print "\nTests, high five bro!"

print "\nBro1 says:"
print bro1.say("sup")

print "\nBro2 says:"
print bro2.say("sup")

print "\nShowing everything"
bro2.show_array(arr)

print "\nTopless"
bro2.show_array(arr, 3)

print "\nToo big"
try:
	bro2.show_array(arr, 6);

except ValueError as e:

	print e

print "\nToo small"
try:

	bro2.show_array(arr, -1);

except ValueError as e:

	print e

print "\nAddition!"
print bro2.sum_array(arr)
