class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0000;
        long t;
        if(n<0){
            t=-1*(long)n;
        }
        // cout<<t<<" ";
        else
            t=n;
        while(t){
            if(t%2){
                ans=ans*x;
                t-=1;
            }
            else{
                x=x*x;
                t/=2;
            }
        }
        if(n<0){
            return (double) 1/(double)ans;
        }
        return ans;
    }
};