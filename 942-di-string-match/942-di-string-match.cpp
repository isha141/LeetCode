class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size(); 
       vector<int>ans(n+1,0);
        int k=0;
        for(int i=0;i<n;++i){
            if(s[i]=='I')
                ans[i]=k++;
        }
        ans[n]=k++;
        // cout<<"hy";
        for(int i=n-1;i>=0;--i){
            if(s[i]=='D')
                ans[i]=k++;
        }
        return ans;

    }
};