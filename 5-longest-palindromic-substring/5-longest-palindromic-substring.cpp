class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(); 
        int start=0;
        int end;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            dp[i][i]=1; 
            start=i;
            end=1;
        }
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1; 
                start=i;
                end=2;
            }
        }
        for(int i=2;i<n;++i){
            for(int j=0;j<=n-i;++j){ 
                int first=j;
                int last=i+j;
                if(s[first]==s[last] && dp[first+1][last-1]==1)
                {
                    dp[first][last]=1;
                    start=first;
                    end=i+1;
                }
            }
        }
        return s.substr(start,end);
    }
};