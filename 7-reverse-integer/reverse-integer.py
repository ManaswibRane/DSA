class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg=False
        num=0
        if x<0:
            x=-x
            neg=True
        while x>0:
            k=x%10
            num=num*10+k
            x=x/10
        if neg :
            num=-num 
        if num < -2**31 or num > 2**31 - 1:
            return 0       
        return num
        