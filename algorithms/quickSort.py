def quick_sort(arr):
	if len(arr) < 2:
		return arr

	pivot = arr[0]
	less = [i for i in arr[1:] if i <= pivot]
	greater = [i for i in arr[1:] if i > pivot]

	return quick_sort(less) + [pivot] + quick_sort(greater)



arr = [4, 2, 6, 3, 1]
print quick_sort(arr)
