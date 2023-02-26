int dp[505][505];
class Solution { 
    private:  
    int n,m;
    int solve(int i,int j,string &w1,string &w2){ 
        if(i>=n && j>=m){
            return 0;
        }
        if(j>=m){
             return n-i;
        }
        if(i>=n ){
             return m-j;
        }  
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(w1[i]==w2[j])
            return dp[i][j]=solve(i+1,j+1,w1,w2);
        return dp[i][j]=1+min(solve(i,j+1,w1,w2),min(solve(i+1,j,w1,w2),solve(i+1,j+1,w1,w2)));
        // return min(ins,min(del,rep));
    }
public:
    int minDistance(string w1, string w2) {
            n=w1.size();
            m=w2.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,w1,w2);
    }
};