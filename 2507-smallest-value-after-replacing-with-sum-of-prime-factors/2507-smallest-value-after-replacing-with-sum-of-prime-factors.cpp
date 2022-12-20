class Solution {
public:
    int smallestValue(int n) {
        bool flag=1; 
        int c=0; 
        if(n==2 || n==3 || n==4 || n==7 || n==5 || n==1) {
            return n;
        }
        // int c=0;
        while(n){
            int temp=n;
            long ans=0;
            for(long i=2;i<=sqrt(n);++i){
                while(n%i==0){
                    ans+=i;
                    n/=i;
                }
            }
            if(n>1)
                ans +=n;
            if(temp==ans)
                break;
            n=ans;
        }
        return n;
    }
};