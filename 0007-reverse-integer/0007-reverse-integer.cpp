class Solution {
public:
    int reverse(int x) { 
        bool flag=0; 
        long long temp=x;
        if(x<0){
            flag=1;
            temp=-1ll*x;
        }
        int ans=0;
        while(temp){
            int rem=temp%10;
            if(ans>INT_MAX || ans>INT_MAX/10)
                  return 0;
            ans=ans*10+rem;
            temp/=10;
        }
         if(flag){
             ans*=-1;
         }
         return ans;
    }
};