class Solution {
public:
    int countSubstrings(string s) {
         int n=s.size(); 
        // cout<<s[n]<<" ,";
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1])
                dp[i][i+1]=1;
        }
        for(int i=2;i<n;++i){
            for(int j=0;j<n-i;++j){
                int first=j;
                int last=j+i;
                // cout<<i<<" "<<j<<" "<<last<<endl;
                // if(last==n){
                    // cout<<"isha"<<", "<<s[last]<<endl;
                // }
                if(s[first]==s[last] && dp[first+1][last-1]==1){
                    dp[first][last]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dp[i][j])
                    c++;
            }
        }
        return c;
    }
};