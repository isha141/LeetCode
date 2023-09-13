class Solution {
public:
    int countOrders(int n) {
          if(n==1){
               return 1;
          }
         int mod=1e9+7;
         long long  ans=1;
         for(int i=2;i<=n;++i){
             int space=((i-1)*2+1)%mod;
             int temp=(space*(space+1))/2;
             ans=(1ll*ans%mod *temp%mod)%mod;
         }
        return ans;
    }
};