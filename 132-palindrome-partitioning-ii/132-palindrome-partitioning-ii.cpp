class Solution {  
    private:
    bool ispalin(string &s)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
    private:
    int solve(int i,string &s,int n,vector<int>&dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int min_cost=1e9;
        for(int k=i;k<n;++k){
            temp+=s[k];
            if(ispalin(temp)){
                int cost=1+solve(k+1,s,n,dp); 
                min_cost=min(min_cost,cost);
            }
        }
        return dp[i]=min_cost;
    }
public:
    int minCut(string s) { 
        vector<int>dp(s.size(),-1);
        return solve(0,s,s.size(),dp)-1;
    }
};