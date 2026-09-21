class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        def fun(c):
            day=1
            sum=0
            for i in weights:
                if sum+i<=c:
                    sum=sum+i
                elif sum+i>c:
                    day+=1
                    sum=i
            return day<=days
        l=max(weights)
        r=sum(weights)
        m=0
        while l<=r:
            mid=(l+r)//2
            if fun(mid):
                m=mid
                r=mid-1
            else:
                l=mid+1
        return m            