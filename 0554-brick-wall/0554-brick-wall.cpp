class Solution {
public:
    int leastBricks(vector<vector<int>>& w) {
        map<int,int>mp;
        int n=w.size();
        for(auto itr: w){
            int sum=0;
            for(auto i=0;i<itr.size()-1;++i){
                 sum+=itr[i];
                mp[sum]++;
            }
        }
        int ans=0;
        for(auto itr: mp){
            ans=max(ans,itr.second);
        }
        return n-ans;
    }
};