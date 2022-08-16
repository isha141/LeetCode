class Solution {   
    int dp[700][105][105];
    private:  
    int count(string &s,int m)
    {
        int zero=0;
        for(auto itr:s){
            if(itr=='0')
                zero++;
        }
        return zero;
    }
    int solve(int i,vector<string>& strs, int m, int n,int len)
    {
        if(i>=len)
            return 0; 
        if(m<0 || n<0)
            return 0; 
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int zero=count(strs[i],m);
        int one=strs[i].size()-zero; 
        int pick=0; 
        int not_pick=solve(i+1,strs,m,n,len);
        if((m-zero)>=0 && (n-one)>=0)
         pick=1+solve(i+1,strs,m-zero,n-one,len);
        return dp[i][m][n]=max(pick,not_pick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();  
        memset(dp,0,sizeof(dp));
        for(int i=strs.size()-1;i>=0;--i){
            for(int j=0;j<=m;++j){
                for(int k=0;k<=n;++k){
                    int zero=count(strs[i],j);
                    int one=strs[i].size()-zero;
                    int not_pick=dp[i+1][j][k];
                    int pick=0;
                    if((j-zero)>=0 && (k-one)>=0){
                        pick=1+dp[i+1][j-zero][k-one];
                    }
                dp[i][j][k]=max(pick,not_pick);
                }
            }
        }
        return dp[0][m][n];
    }
};