class Solution:
    """
    @param: n: a positive integer
    @return: n x 3 matrix
    """

    def consistentHashing(self, n):
        # write your code here
        results = [[0, 359, 1]]
        for i in range(1, n):
            max_index = 0
            for j in range(1, i):
                if results[j][1] - results[j][0] > \
                        results[max_index][1] - results[max_index][0]:
                        max_index = j

            x, y = results[max_index][0], results[max_index][1]
            size = (y + 1 - x) / 2
            results[max_index][1] = int(x + size - 1)
            results.append([x+size, x+2*size-1, i + 1])
        return results

s = Solution()
print(s.consistentHashing(9))
