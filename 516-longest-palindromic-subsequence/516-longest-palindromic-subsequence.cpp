class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        int n=s.size();
        reverse(s.begin(),s.end());
        vector<int>prev(n+1);
        for(int i=0;i<=n;++i){
            prev[i]=0;
        } 
        int ans=0;
        for(int i=1;i<=n;++i){ 
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;++j){
                if(s[i-1]==t[j-1])
                {
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else
                    curr[j]=max(prev[j],curr[j-1]);
            } 
            prev=curr;
        }
        return ans;
    }
};