class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int> ans;
        int prev=-1;
        int n=s.size(); 
        map<char,int>mp;
        for(int i=0;i<n;++i){
            mp[s[i]]=i;
        }  
        // for(auto itr: mp)
            // cout<<itr.first<<" "<<itr.second<<endl;
        // cout<<"isha"; 
        // cout<<endl;
        for(int i=0;i<n;){
            int maxi=mp[s[i]];
            for(int j=i;j<=maxi;++j){
                maxi=max(maxi,mp[s[j]]);
                // cout<<maxi<<" ";
            } 
            ans.push_back(maxi-prev);
            prev=maxi; 
            // cout<<prev<<" ";
            i=maxi+1; 
          // cout<<prev<<" "<<i<<endl;
        }
        return ans;
    }
};