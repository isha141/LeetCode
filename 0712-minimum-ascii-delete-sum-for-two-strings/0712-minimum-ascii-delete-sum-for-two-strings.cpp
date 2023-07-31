int dp[1002][1002];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,string &a,string &b){
        if(i<0 && j<0)
            return 0;
        else if(j<0){
            int ans=0;
            for(int k=i;k>=0;--k){
                ans+=int(a[k]);
            }
            return ans;
        }
        else if(i<0){
            int ans=0;
            for(int k=j;k>=0;--k){
                ans+=int(b[k]);
            }
            return ans;
        } 
        if(dp[i][j]!=-1)
             return dp[i][j];
        int take=1e9;
        int not_take=1e9;
        if(a[i]==b[j]){
            take=solve(i-1,j-1,a,b);
        }
        else {
            not_take=min(int(a[i])+solve(i-1,j,a,b),int(b[j])+solve(i,j-1,a,b));
        }
        return dp[i][j]=min(take,not_take);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size(); 
        memset(dp,-1,sizeof(dp));
         return solve(n-1,m-1,s1,s2);
    }
};