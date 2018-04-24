class Solution:
    """
    @param str: The input string
    @param k: The repeated times
    @return: The answer
    """

    @staticmethod
    def longestRepeatingSubsequenceII(str, k):
        # Write your code here
        n = len(str)
        count = {}
        for i in range(n):
            hashValue = 0
            for j in range(i, n):
                hashValue = (31 * hashValue +
                             ord(str[j]) - ord('a')) % 1000000007
                if (hashValue, j - i + 1) in count:
                    count[(hashValue, j - i + 1)] += 1
                else:
                    count[(hashValue, j - i + 1)] = 1
        ans = 0
        for key, value in count.items():
            if value >= k:
                ans = max(ans, key[1])
        return ans


data = "aaa"
ans = Solution.longestRepeatingSubsequenceII(str=data, k=2)
print(ans)