class Solution { 
    private:
    int n;
public:
    vector<int> partitionLabels(string s) {
         n=s.size();
        vector<int>ans;
         map<char,int>mp;
        for(int i=0;i<n;++i){
            mp[s[i]]=i;
        }
        int last=0;
        for(int i=0;i<n;){
            int maxi=mp[s[i]];
            for(int j=i;j<=maxi;++j){ 
                // cout<<j<<" "<<mp[s[j]]<<endl;
                maxi=max(maxi,mp[s[j]]);
            } 
            // cout<<maxi<<"::"<<i<<endl;
            ans.push_back(maxi-last+1);
            last=maxi+1;
            i=maxi+1;
        }
        return ans;
    }
};