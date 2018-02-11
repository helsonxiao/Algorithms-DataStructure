# What is D&C(Divide and Conquer)?
# 1.find base case
# 2.find recursive case then narrow down the problem

# use D&C to find the biggest number in [2, 4, 6]

def find_big_brother(bros):
	if len(bros) == 2:  # base case
		return bros[0] if bros[0] > bros[1] else bros[1]

	# recursive case
	sub_max=find_big_brother(bros[1:])
	return bros[0] if bros[0] > sub_max else sub_max

bros = [2, 4, 6]
print find_big_brother(bros)
