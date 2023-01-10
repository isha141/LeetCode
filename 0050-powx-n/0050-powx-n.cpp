class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        bool flag=0;
        int temp1=n;
        if(x<0){
            flag=1;
            x*=-1;
        } 
        bool flag1=0;
        long long temp=n;
        if(n<0){
            flag1=1;
            temp*=-1;
        }
        while(temp>0){
            if(temp%2==0){
                x=x*x;
                temp/=2;
            }
            else{
                ans*=x;
                temp-=1;
            }
        }
        if(flag){
            if(temp1%2)
                ans*=-1;
        }
        if(flag1){
            return 1/(ans);
        }
        return ans;
        
    }
};