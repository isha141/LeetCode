int dp[25][2][2][205];
class Solution {
    private:
    int mod=1e9+7;
    int solve(int i,string &a,bool tight,bool zero,int mini,int maxi,int sum){
        if(i>=a.size()){
            if(sum>=mini && sum<=maxi){ 
                 return 1;
            }
            return 0;
        }
        if(dp[i][tight][zero][sum]!=-1)
              return dp[i][tight][zero][sum]%mod;
        int limits=(tight)?(a[i]-'0'):9;
        int  ans=0;
        for(int d=0;d<=limits;d++){
             int newtight=(d==(a[i]-'0'))?(tight):0;
            if(zero && d==0){
                  ans=(ans%mod+solve(i+1,a,newtight,1,mini,maxi,sum)%mod)%mod;
                ans%=mod;
            } 
            else{
                ans=(ans%mod+solve(i+1,a,newtight,0,mini,maxi,sum+d)%mod)%mod;
                ans%=mod;
            }
        }
         return  dp[i][tight][zero][sum]=(ans%mod);
    }
public:
    int count(string num1, string num2, int mini, int maxi) {
          memset(dp,-1,sizeof(dp));
        int  ans1=solve(0,num1,1,1,mini,maxi,0)%mod;
         memset(dp,-1,sizeof(dp)); 
        int ans2=solve(0,num2,1,1,mini,maxi,0)%mod;
        int rem=((ans2%mod)-(ans1%mod))%mod;
        cout<<ans1<<";;"<<ans2<<endl;
        long sum=0;
        for(auto itr: num1){
            sum+=(itr-'0');
        }
         if(sum>=mini && sum<=maxi){
             rem=(rem+1)%mod;
         } 
         return (rem<0)?(rem+mod):rem%mod;
    }
};