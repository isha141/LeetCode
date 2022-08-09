int dp[30][30][301];
class Solution { 
    private: 
    int ans=0; 
    int cost(char from ,char to)
    {
        if(from=='[')
            return 0;
        return abs((from-'A')/6 - (to-'A')/6) + abs((from-'A')%6 - (to-'A')%6);
    }
    int solve(int k,char i,char j,string &word)
    {
        if(k>=word.size())
            return 0;
        if(dp[i-'A'][j-'A'][k]!=-1) 
            return dp[i-'A'][j-'A'][k];
        int temp1=cost(i,word[k])+solve(k+1,word[k],j,word);
        int temp2=cost(j,word[k])+solve(k+1,i,word[k],word);
        return  dp[i-'A'][j-'A'][k]=min(temp1,temp2);
    }
public:
    int minimumDistance(string word) { 
        memset(dp,-1,sizeof(dp));
        return solve(0,'[','[',word);
    }
};