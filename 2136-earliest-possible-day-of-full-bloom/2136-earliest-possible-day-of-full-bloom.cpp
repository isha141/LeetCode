class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>>ds,arr;
        int n=p.size();
        for(int i=0;i<n;++i){
            ds.push_back({g[i],p[i]}); 
            // arr.push_back({g[i],p[i]});
        }
        // sort(arr.rbegin(),arr.rend());
        sort(ds.rbegin(),ds.rend()); 
        // for(auto itr: ds){
        //     cout<<itr.first<<" "<<itr.second<<endl;
        // }
        // cout<<"&&&"<<endl;
        // for(auto itr: arr){
        //     cout<<itr.first<<" "<<itr.second<<endl;
        // }
        int ans=0;
        int plant=0;
        for(int i=0;i<n;++i){
            plant=max(plant,ds[i].second+plant); 
            ans=max(ans,plant+ds[i].first);
        }
        return ans;
    }
};