int dp[2003][10000];
class Solution { 
    private:
    int n; 
    map<int,int>mp;
     int solve(int ind,int last,vector<int>&s){
         if(ind>=n) 
             return 0;
         if(ind==n-1)
              return 1; 
         bool left=0,right=0,up=0; 
         if(dp[ind][last]!=-1)
              return dp[ind][last];
         if(last!=1 && mp.find(s[ind]+last-1)!=mp.end()){
             left=solve(mp[s[ind]+last-1],last-1,s);
         }
          if(mp.find(s[ind]+last)!=mp.end()){
             right=solve(mp[s[ind]+last],last,s);
         }
          if(mp.find(s[ind]+last+1)!=mp.end()){
             up=solve(mp[s[ind]+last+1],last+1,s);
         }
          return dp[ind][last]=(left | right| up );
     }
public:
    bool canCross(vector<int>& stones) {
         n=stones.size();
         if(stones[1]!=1) 
             return 0;
        memset(dp,-1,sizeof(dp));
        for(auto i=0;i<n;++i){
            mp[stones[i]]=i;
        }
         return solve(1,1,stones);
    }
};