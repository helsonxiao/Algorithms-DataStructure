class Solution:
    """
    @param A: an integer array
    @return: nothing
    """

    def Partition(self, L, low, high):
        pivot_key = L[low]
        while (low < high):
            while low < high and L[high] >= pivot_key:
                high -= 1
            L[low] = L[high]

            while low < high and L[low] <= pivot_key:
                low += 1
            L[high] = L[low]

        L[low] = pivot_key
        return low

    def QSort(self, L, low, high):
        m = low + (high - low) // 2
        if L[low] > L[high]:
            L[low], L[high] = L[high], L[low]
        if L[m] > L[high]:
            L[m], L[high] = L[high], L[m]
        if L[low] < L[m]:
            L[low], L[m] = L[m], L[low]

        if (high - low) > 7:
            while low < high:
                pivot = self.Partition(L, low, high)
                self.QSort(L, low, pivot)
                low = pivot + 1

            return
        
        self.InsertSort(L)

    def InsertSort(self, L):
        length = len(L)
        i = 1
        while i < length:
            if L[i-1] > L[i]:
                tmp = L[i]
                j = i - 1
                while j >=0 and L[j] > tmp:
                    L[j+1] = L[j]
                    j -= 1
                L[j+1] = tmp

            i += 1
        return

    def sortIntegers(self, A):
        # write your code here
        if A == []:
            return []
        self.QSort(A, 0, len(A)-1)

s = Solution()
A = [3, 2, 1, 4, 5]
s.sortIntegers(A)
print(A)
