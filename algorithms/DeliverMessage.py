class Solution:
    """
    @param t: the time of each employee to pass a meeage
    @param subordinate: the subordinate of each employee
    @return: the time of the last staff recieve the message
    """

    def deliverMessage(self, t, subordinate):
        # Write your code here
        visited = []
        for i in range(len(t)):
            visited.append(-1)
        visited[0] = 0

        queue = []
        queue.append(0)

        ans = 0

        while len(queue):
            cur = queue.pop(0)
            
            for s in subordinate[cur]:
                if (visited[s] == -1 and s != -1):
                    visited[s] = visited[cur] + t[cur]
                    if visited[s] > ans:
                        ans = visited[s]
                    queue.append(s)

        return ans

    def deliverMessage2(self, t, subordinate):
        from collections import deque

        que = deque()
        que.append(0)
        inf = sum(t)
        ans = [inf for i in t]
        vis = [0 for i in t]
        vis[0] = 1
        ans[0] = 0
        res = 0
        while len(que):
            h = que.popleft()
            for x in subordinate[h]:
                if x != -1 and vis[x] == 0:
                    que.append(x)
                    ans[x] = min(ans[x], ans[h] + t[h])
        for x in ans:
            res = max(res, x)
        return res


t = [13, 30, 21, 18, 20, 22, 22, 5, 3, 26]
subordinate = [[3, 7], [8], [-1], [5, 1],
               [-1], [4], [-1], [2, 6, 9], [-1], [-1]]

solution = Solution()
print(solution.deliverMessage2(t, subordinate))
