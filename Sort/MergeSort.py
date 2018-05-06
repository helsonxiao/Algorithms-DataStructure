class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    @staticmethod
    def Merge(new_ast, ast, st, md, ed):
        i = st
        j = md + 1
        k = st
        while i <= md and j <= ed:
            if new_ast[i] < new_ast[j]:
                ast[k] = new_ast[i]
                i += 1
            else:
                ast[k] = new_ast[j]
                j += 1

            k += 1

        if i <= md:
            offset = 0
            while i + offset <= md:
                ast[k+offset] = new_ast[i+offset]
                offset += 1

        if j <= ed:
            offset = 0
            while j + offset <= ed:
                ast[k+offset] = new_ast[j+offset]
                offset += 1

    @staticmethod
    def MSort(data, ast, st, ed):
        new_ast = [-1] * 2048

        if st == ed:
            ast[st] = data[st]
        else:
            md = (st + ed) // 2
            Solution.MSort(data, new_ast, st, md)
            Solution.MSort(data, new_ast, md+1, ed)
            Solution.Merge(new_ast, ast, st, md, ed)

    def sortIntegers(self, A):
        # write your code here
        Solution.MSort(A, A, 0, len(A)-1)


s = Solution()
A = [3, 2, 1, 4, 5]
s.sortIntegers(A)
print(A)
