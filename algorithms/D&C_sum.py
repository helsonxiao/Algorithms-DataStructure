# What is D&C(Divide and Conquer)?
# 1.find base case
# 2.narrow down the problem

# use D&C to compute the sum of [2, 4, 6]

def sum(arr):
	if arr == []:  # base case
		return 0

	return arr[0] + sum(arr[1:])

arr = [2, 4, 6]
print sum(arr)
