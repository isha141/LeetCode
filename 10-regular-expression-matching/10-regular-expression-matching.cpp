class Solution { 
    private: 
    int prev=-1;
    bool solve(int i,int j,string &p,string &s,vector<vector<int>>&dp) 
    {
            if(i<0 && j<0) 
                return 1;
            if(j==-1 && p[i]=='*')
              return dp[i+1][j+1]= solve(i-2,j,p,s,dp);  
        if(i<0 || j<0)  
            return 0;  
        if(dp[i+1][j+1]!=-1)  
            return dp[i+1][j+1];
         if(p[i] =='.' || p[i]==s[j])
               return dp[i+1][j+1]=solve(i-1,j-1,p,s,dp);
        
        else if(p[i]=='*'){ 
         if(i-1>=0 && p[i-1]==s[j] || p[i-1]=='.')
             return dp[i+1][j+1]=(solve(i,j-1,p,s,dp)|| solve(i-2,j,p,s,dp));
            else{
                return dp[i+1][j+1]=solve(i-2,j,p,s,dp);
            }
        } 
        else 
            return dp[i+1][j+1]=0;
    }
public:
    bool isMatch(string s, string p) { 
        int ans=0;  
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return solve(n-1,m-1,p,s,dp); 
    }
};