class Solution { 
    private:
    int helper(int i,int j,vector<vector<int>>&dp,string &s,int &start,int &len){
        if(i>j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
            dp[i][j]=helper(i+1,j-1,dp,s,start,len);
        else
            dp[i][j]=0;
        if(dp[i][j]==1){
            if(len<j-i+1){
                len=j-i+1;
                start=i;
            }
        }
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        int start=0;
        int len=1;  
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                helper(i,j,dp,s,start,len);
            }
        }
        return s.substr(start,len);
    }
};