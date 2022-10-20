class Solution {  
//     struct cmp{
    
//         bool operator(pair<int,int>&a,pair<int,int>&b){
//             if(a.first==a.)
//         }
        
        
//     }
    private: 
    int n;
    int solve(int i,vector<pair<int,int>>&ds,int prev,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0; 
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int take=0;
        int not_take=0;
        if(prev==-1 ||  ds[i].second>=ds[prev].second){
            take=ds[i].second+solve(i+1,ds,i,dp);
        }
        not_take=solve(i+1,ds,prev,dp);
        return dp[i][prev+1]=max(take,not_take);
    }
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
         n=s.size();
        vector<pair<int,int>>ds;
        for(int i=0;i<n;++i){
            ds.push_back({a[i],s[i]});
        }
        sort(ds.begin(),ds.end()); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
        for(int i=n-1;i>=0;--i){ 
            for(int prev=i;prev>=-1;--prev){
                 int take=0;
                 int not_take=0;
                 if(prev==-1 || ds[i].second>=ds[prev].second)
                    take=ds[i].second+dp[i+1][i+1];
                not_take=dp[i+1][prev+1];
                dp[i][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};