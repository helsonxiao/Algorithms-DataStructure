class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    @staticmethod
    def HeapAdjust(A, st, ed):
        tmp = A[st]
        child_index = st * 2
        while child_index <= ed:
            if child_index < ed and A[child_index] < A[child_index+1]:
                child_index += 1
            if tmp >= A[child_index]:
                break
            A[st] = A[child_index]
            st = child_index
            child_index *= 2

        A[st] = tmp
            
    
    def sortIntegers(self, A):
        # write your code here
        length = len(A)
        A.insert(0, 0)
        i = length // 2
        while i > 0:
            Solution.HeapAdjust(A, i, length)
            i -= 1
            
        i = length
        while i > 1:
            A[1], A[i] = A[i], A[1]
            Solution.HeapAdjust(A, 1, i-1)
            i -= 1
            
        A.pop(0)


s = Solution()
A = [26, 71, 35, 51, 30, 73, 30, -2, 58, -4, 46, 41, 23, 54, 72, 56, 70, -4, 66, 4, 54, 40, 15, 28, 43, -1, 80, 1, 75, 11, 24, 58, 51, 67, 27, 69, 5, 28, 80, 18,
     68, 43, 54, 47, 72, 36, 71, 19, 19, 80, 40, 25, 66, 51, 35, 70, 27, 35, 44, 60, 72, 40, 53, 37, 26, 3, 75, -8, 53, 52, 16, 60, 18, 14, 22, 67, 9, 12, 60, 60]
s.sortIntegers(A)
print(A)
