class Solution {
public:
    string restoreString(string s, vector<int>& ind) {
        int n=ind.size();
        string ans(n,',');
        for(int i=0;i<n;++i){
            int temp=ind[i];
            ans[temp]=s[i];
            // =ch;
        }
        return ans;
    }
};