class Solution {  
    private:
    int n,m; 
    vector<vector<long long>>dp;
    long long solve(int i,vector<int>&days,vector<int>&cost,long d){
        if(i>=n || d>365) return 0;
        long long one=1e9;
        long long seven=1e9;
        long long thirty=1e9; 
        if(d<=365 && dp[i][d]!=-1) 
            return dp[i][d];
        one=cost[0]+solve(i+1,days,cost,days[i]); 
        if(d>days[i]) 
             return solve(i+1,days,cost,d);
        else{
        seven=cost[1]+solve(i+1,days,cost,days[i]+7);
        thirty=cost[2]+solve(i+1,days,cost,days[i]+30); 
        }
        return dp[i][d]=min(one,min(seven,thirty));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& c) {
        n=days.size();
        m=c.size(); 
        long long d=0; 
        dp.resize(n,vector<long long>(366,-1));
        return solve(0,days,c,d);       
    }
};