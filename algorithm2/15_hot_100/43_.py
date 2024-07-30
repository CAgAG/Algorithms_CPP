

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return nums[0]

        dp = [0 for _ in range(n + 1)]
        dp2 = [0 for _ in range(n + 1)]
        ret = nums[0]

        dp[0] = nums[0]
        dp2[0] = nums[0]

        for i in range(1, n):
            cur_num = nums[i]
            dp[i] = max(cur_num, dp[i - 1] * cur_num, dp2[i - 1] * cur_num)
            dp2[i] = min(cur_num, dp[i - 1] * cur_num, dp2[i - 1] * cur_num)
            ret = max(ret, dp[i], dp2[i])
        return ret


if __name__ == '__main__':
    so = Solution()
    print(so.maxProduct([2, -1, 1, 1]))