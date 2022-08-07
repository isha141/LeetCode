class Solution { 
    private:
    int solve(int i,string &s,int &k,char &prev,vector<vector<int>>&dp)
    {
        if(i>=s.size())
            return 0;
        int l=0;
        int r=0; 
        if(dp[i][prev]!=-1) 
            return dp[i][prev];
        if(abs(s[i]-prev)<=k || prev=='\0')
            l=solve(i+1,s,k,s[i],dp)+1; 
            r=solve(i+1,s,k,prev,dp);
        return  dp[i][prev]=max(l,r);
    }
public:
    int longestIdealString(string s, int k) {  
        char prev='\0';  
        int n=s.size();  
        vector<int>dp(26,0); 
        dp[s[n-1]-'a']=1;
        for(int i=n-2;i>=0;--i){
          int lb=max(0,(s[i]-'a') -k);
            int ub=min(25,(s[i]-'a') +k);
            int ans=0; 
            // cout<<lb<<" "<<ub<<endl;
            for(int j=lb;j<=ub;++j){
                ans=max(ans,dp[j]);
            }
            dp[s[i]-'a']=max(dp[s[i]-'a'],ans+1);
        }
        int res=0; 
        // for(auto itr: dp) cout<<itr<<" ";
        for(auto itr: dp)
            res=max(res,itr);
        return res;
    }
};