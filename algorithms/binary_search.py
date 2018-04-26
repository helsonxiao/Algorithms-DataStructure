#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math

def binary_search(bucket, egg):
	low = 0
	high = len(bucket) - 1

	while low <= high:
		middle_egg_index = (low + high) / 2
		middle_egg = bucket[middle_egg_index]
		if middle_egg == egg:
			return middle_egg_index
		if middle_egg > egg:
			high = middle_egg_index - 1
		else:
			low = middle_egg_index + 1

	return 'no such egg'

a = [13,25,37,49,57,61,79]
b = [5,18,27,34,49,55,61,70]

result_a = binary_search(a, 61)
result_b = binary_search(b, 55)
result_t = binary_search(a, 5)

print [result_a, result_b, result_t]