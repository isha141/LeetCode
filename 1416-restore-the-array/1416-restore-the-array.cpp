int dp[1000003];
class Solution { 
    private:
    int mod=1e9+7;
    int n;
    int solve(int i,string &s,int l){
        if(i>=n)
             return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
             return dp[i];
        long long num=0;
        long long ans=0;
        for(int k=i;k<s.size();++k){
            num=num*10+s[k]-'0'; 
            if(num>l)
                break;
            ans=(ans+solve(k+1,s,l)) % mod;
        }
        return dp[i]=ans % mod;
    }
public:
    int numberOfArrays(string s, int k) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,s,k);
    }
};