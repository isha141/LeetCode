int dp[50005];
class Solution {
    private:
    int n;
    int solve(int ind,vector<int>&s){
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int takeone=s[ind]-solve(ind+1,s); 
        int taketwo=INT_MIN,takethree=INT_MIN;
        if(ind+1<n)
         taketwo=s[ind]+s[ind+1]-solve(ind+2,s);
        if(ind+2<n)
            takethree=s[ind]+s[ind+1]+s[ind+2]-solve(ind+3,s);
        return dp[ind]=max(takeone,max(taketwo,takethree));
    }
public:
    string stoneGameIII(vector<int>& s) {
        n=s.size(); 
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,s);
        if(ans==0)
             return "Tie";
        if(ans<0)
            return "Bob";
        return "Alice";
    }
};