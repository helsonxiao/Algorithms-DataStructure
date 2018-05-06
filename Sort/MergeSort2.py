class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    @staticmethod
    def Merge(SR, TR, i, m, n):
        j = m + 1
        k = i
        while i <= m and j <= n:
            if SR[i] < SR[j]:
                TR[k] = SR[i]
                i += 1
            else:
                TR[k] = SR[j]
                j += 1

            k += 1

        if i <= m:
            offset = 0
            while i + offset <= m:
                TR[k+offset] = SR[i+offset]
                offset += 1

        if j <= n:
            offset = 0
            while j + offset <= n:
                TR[k+offset] = SR[j+offset]
                offset += 1

    @staticmethod
    def MergePass(SR, TR, s, n):
        i = 0
        while i <= n - 2 * s + 1:
            Solution.Merge(SR, TR, i, i + s - 1, i + 2 * s - 1)
            i = i + 2 * s

        if i < n - s + 1:
            Solution.Merge(SR, TR, i, i + s - 1, n)
        else:
            j = i
            while j <= n:
                TR[j] = SR[j]
                j += 1

    def sortIntegers(self, A):
        # write your code here
        if A == []:
            return []

        length = len(A)
        TR = [-1] * length
        k = 1
        while k < length:
            Solution.MergePass(A, TR, k, length - 1)
            k = 2 * k
            Solution.MergePass(TR, A, k, length - 1)
            k = 2 * k


s = Solution()
A = [3, 2, 1, 4, 5]
s.sortIntegers(A)
print(A)
