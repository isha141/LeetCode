int dp[102][27];
class Solution {
    private:
    int n;
    int solve(int i,int num,string &s){
        if(i>=n){ 
            if(num%25==0)
             return 0;
            return 1e9;
        }
        if(dp[i][num]!=-1)
             return dp[i][num];
        int digit=s[i]-'0';
        int take=0;
        int not_take=0;
        take=1+solve(i+1,num,s);
        not_take=solve(i+1,(num*10+digit)%25,s);
        return dp[i][num]=min(take,not_take);
    }
public:
    int minimumOperations(string num) {
         n=num.size(); 
         memset(dp,-1,sizeof(dp));
         return solve(0,0,num);
    }
};