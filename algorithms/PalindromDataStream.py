class Solution:
    # def getStream(self, s):
    #     def isPalindrome(N):
    #         N += 1
    #         left = N // 2 - 1
    #         right = N // 2
    #         if N % 2 != 0:
    #             right += 1
    #         flag = True
    #         while left >= 0 and right < N:
    #             if s[left] != s[right]:
    #                 flag = False
    #                 break
    #             left -= 1
    #             right += 1
    #         return flag

    #     N = len(s)
    #     res = [0] * N
    #     for i in range(N):
    #         if isPalindrome(i):
    #             res[i] = 1
    #         else:
    #             res[i] = 0

    #     return res

    def getStream(self, s):
        ans = []
        alphabet = [0 for i in range(26)]
        cnt = 0
        for i in s:
            if (alphabet[ord(i) - ord('a')] & 1):
                cnt -= 1
            else:
                cnt += 1
            alphabet[ord(i) - ord('a')] += 1
            if (cnt > 1):
                ans.append(0)
            else:
                ans.append(1)
        return ans

s = Solution()
# test = "fdfeceedaaddafcdbffffbbfabcdeebfdefccddaccbfdefefdbaceedfafafaaaffdabedebccfbfbbdcbeecdcbfbdfdfaeecebbcebfeefeaddbccdbefddbbbdeebdcaaaacbddfdbddebcffdedfcdaccdaeebdabadefcfceaeeadecdfdfddbeee"
stream = "aabaacaabaa"
print(s.getStream(list(stream)))
# ans = [1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
# print(ans[len(ans) - 1])
# print(test[:len(ans)-1])
