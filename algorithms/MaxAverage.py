class Solution:
    def findMaxAverage(self, nums, k):
        N = len(nums)
        res = nums[0]
        for i in range(1, k):
            res += nums[i]
        i = k - 1
        s = res
        while i + 1 < N:
            s = s + nums[i+1] - nums[i-k+1]
            res = max(s, res)
            i += 1
        return res/k

    def findMaxAverage2(self, nums, k):
        N = len(nums)
        i, res = 0, 0
        while i + k - 1 < N:
            s = nums[i]
            kk = 1
            while kk < k:
                s += nums[i + kk]
                kk += 1
            res = max(s, res)
            i += 1
        return res / k


s = Solution()
print(s.findMaxAverage2([4, 2, 1, 3, 3], 2))
