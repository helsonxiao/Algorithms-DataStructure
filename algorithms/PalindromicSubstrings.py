class Solution:
    """
    @param str: s string
    @return: return an integer, denote the number of the palindromic substrings
    """

    def countPalindromicSubstrings(self, str):
        # write your code here
        length = len(str)
        count = 0
        for l in range(2 * length - 1):
            left = right = l // 2
            if l % 2 != 0:
                right += 1
            while left >= 0 and right < length and str[left] == str[right]:
                count += 1
                left -= 1
                right += 1

        return count

    def dp(self, str):
        l = len(str)
        t = [[False for col in range(l)] for row in range(l)]
        for i in range(l):
            t[i][i] = True
            if i + 1 < l and str[i] == str[i + 1]:
                t[i][i + 1] = True

        sub_l = 3
        while sub_l <= l:
            i = 0
            while i < (l - sub_l + 1):
                j = i + sub_l - 1
                if t[i + 1][j - 1] and str[i] == str[j]:
                    t[i][j] = True
                i += 1
            sub_l += 1

        count = 0
        for i in range(l):
            for j in range(i, l):
                if t[i][j] == True:
                    count += 1
        return count

    def countSubstrings(self, str):
        def manachers(str):
            A = '@#' + '#'.join(str) + '#$'
            Z = [0] * len(A)
            center = right = 0
            for i in range(1, len(A) - 1):
                if i < right:
                    Z[i] = min(right - i, Z[2 * center - i])
                while A[i + Z[i] + 1] == A[i - Z[i] - 1]:
                    Z[i] += 1
                if i + Z[i] > right:
                    center, right = i, i + Z[i]
            return Z

        return sum((v + 1) // 2 for v in manachers(str))

    def findLongestPalindromicString(self, str):
        N = len(str)
        if N == 0:
            return
            
        N = 2 * N + 1  # Position (insert separator)
        L = [0] * N
        L[1] = 1  # the first character has one length in the start
        C = 1  # centerPosition
        R = 2  # centerRightPosition
        for i in range(2, N):  # i is currentRightPosition
            iMirror = 2 * C - i
            diff = R - i
            if L[iMirror] <= diff:
                L[i] = L[iMirror]
            else:
                L[i] = diff

            try:
                # character will do compare, seperator just add ONE directly
                while ((i + L[i]) < N and (i - L[i]) > 0) and \
                        (((i + L[i] + 1) % 2 == 0) or
                            (str[(i + L[i] + 1) // 2] == str[(i - L[i] - 1) // 2])):
                    L[i] += 1
            except:
                pass

            if i + L[i] > R:
                C, R = i, i + L[i]

        return sum([(l + 1) // 2 for l in L])

s = Solution()
print(s.findLongestPalindromicString("aaaa"))
