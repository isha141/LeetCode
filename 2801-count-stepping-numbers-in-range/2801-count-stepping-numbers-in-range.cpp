int dp[102][2][2][10];
class Solution {
    private:
    int mod=1e9+7;
    int solve(int pos,string &a,bool tight,bool zero, int prev){
        if(pos>=a.size()){
            if(!zero)
            return 1;
            return 0;
        }
        if(dp[pos][tight][zero][prev]!=-1)
            return dp[pos][tight][zero][prev];
        int limits=(tight)?(a[pos]-'0'):9;
        int ans=0;
        for(int d=0;d<=limits;++d){
            int newtight=(d==(a[pos]-'0'))?(tight):0;
            if(zero && d==0){
                ans=(ans+solve(pos+1,a,newtight,zero,d));
            } 
           else if(zero || abs(prev-d)==1){
               ans=(ans%mod+solve(pos+1,a,newtight,0,d)%mod)%mod;
           }
        }
       return dp[pos][tight][zero][prev]=ans%mod;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int ans1=solve(0,low,1,1,0);
        memset(dp,-1,sizeof(dp));
        int ans2=solve(0,high,1,1,0);
        cout<<ans1<<" "<<ans2<<endl;
         int rem=(ans2-ans1)%mod;
         bool flag=1;
         if(low.size()==1){
             flag=1;
         }
         for(int i=1;i<low.size();++i){
             int last=low[i-1]-'0';
             int curr=low[i]-'0';
             if(abs(curr-last)!=1){
                 flag=0;
                 break;
             }
         }
          if(flag){
               rem=(rem+1)%mod;
          }
         return rem<0?(rem+mod):(rem%mod);
    }
};