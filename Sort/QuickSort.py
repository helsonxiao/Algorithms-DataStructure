class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    @staticmethod
    def Partition(L, low, high):
        pivot_key = L[low]
        while (low < high):
            while low < high and L[high] >= pivot_key:
                high -= 1
            L[low], L[high] = L[high], L[low]

            while low < high and L[low] <= pivot_key:
                low += 1
            L[low], L[high] = L[high], L[low]

        return low

    @staticmethod
    def QSort(L, low, high):
        if low < high:
            pivot = Solution.Partition(L, low, high)
            Solution.QSort(L, low, pivot)
            Solution.QSort(L, pivot+1, high)

    def sortIntegers(self, A):
        # write your code here
        if A == []:
            return []
        Solution.QSort(A, 0, len(A)-1)

s = Solution()
A = [3, 2, 1, 4, 5]
s.sortIntegers(A)
print(A)
