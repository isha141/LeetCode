int dp[101][101][27][101];
class Solution { 
    string str;
    private: 
    int solve(int i,int k,char ch,int count){
        if(k<0)
            return 1e9;  
        
        if(i>=str.size())
               return 0;  
        if(dp[i][k][ch-'a'][count]!=-1)
            return dp[i][k][ch-'a'][count];
        int take=0;
        int del=solve(i+1,k-1,ch,count); 
        if(str[i]==ch)
        {
            if(count==1 || count==9 || count==99)
                  take+=1;
             take=take+solve(i+1,k,ch,count+1);
        }
        else{
        take=1+solve(i+1,k,str[i],1);
        }
        return dp[i][k][ch-'a'][count]=min(take,del);
            
        
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.size();
         char ch='z'; 
        str=s; 
        if(k==s.size())
            return 0; 
        memset(dp,-1,sizeof(dp));
        return solve(0,k,ch,0); 
    }
};