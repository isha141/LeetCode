class Solution { 
    private:
    int getnext(int n)
    {
        int ans=0;
        while(n!=0)
        {
            int rem=n%10;
            ans+=rem*rem;
            n=n/10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=getnext(n);
        while(fast!=1 && slow !=fast)
        {
            slow=getnext(slow);
            fast=getnext(getnext(fast));
        }
        return fast==1;
        
    }
};