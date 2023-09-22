class Solution {
public:
    double myPow(double x, int n) {
         double res=1;
          bool flag=0;
        if(x<0){
            x*=-1;
            flag=1;
        }
          long long n1=n;
          n1=abs(n);
        double ans=1;
         while(n1>0){
             if(n1 &1){  
                 // 
                 n1-=1;
                 res*=x;
             }
             else{
                 x*=x;
                 n1/=2;
             }
         }
        if(flag && (n%2)){
            res*=-1;
        }
        if(n<0){
            return 1/(double)res;
        }
         else
             return res;
    }
};