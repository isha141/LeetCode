class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
         int n=s.size();
        vector<int> ans(n,1e9);
        int prev=INT_MAX;
        for(int i=0;i<n;++i){
            if(s[i]==c){
                prev=i;
            }
            ans[i]=abs(i-prev);
        }
        prev=INT_MAX/2;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c){
                prev=i;
            }
            ans[i]=min(ans[i],prev-i);
        }
        return ans;
    }
};