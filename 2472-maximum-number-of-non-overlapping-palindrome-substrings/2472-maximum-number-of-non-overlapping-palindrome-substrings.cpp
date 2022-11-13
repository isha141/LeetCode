class Solution {
public:
    int maxPalindromes(string s, int k) { 
        if(k==1)
            return s.size();
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
            dp[i][i]=1;
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1])
                dp[i][i+1]=1;
        }
        for(int i=2;i<n;++i){
            for(int j=0;j<n-i;++j){
                int first=j;
                int last=i+j;
                if(s[first]==s[last] && dp[first+1][last-1]==1){
                    dp[first][last]=1;
                }
            }
        }
        vector<pair<int,int>>in;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dp[i][j] && (j-i+1)>=k)
                    in.push_back({j,i});
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        } 
        if(in.size()==0)
            return 0;
        int a=in.size();
        int c=0;
        sort(in.begin(),in.end());
        int last=in[0].first;
        for(int i=1;i<a;++i){
            if(last>=in[i].second)
                c++;
            else
            last=max(last,in[i].first);
            // cout<<i<<" ";
        }
        return a-c;
    }
};