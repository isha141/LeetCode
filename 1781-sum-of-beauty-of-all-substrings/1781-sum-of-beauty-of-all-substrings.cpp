class Solution {
public:
    int beautySum(string s) {
        int n=s.size(); 
        int ans=0;
        for(int i=0;i<n;++i){
            map<char,int>mp;
            for(int j=i;j<n;++j){
                mp[s[j]]++;
                int mini=INT_MAX;
                int maxi=0;
                for(auto itr: mp){ 
                    // cout<<itr.first<<" "<<itr.second<<endl;
                    maxi=max(maxi,itr.second);
                    mini=min(mini,itr.second);
                }
               ans+=maxi-mini;
            }
        }
        return ans;
    }
};