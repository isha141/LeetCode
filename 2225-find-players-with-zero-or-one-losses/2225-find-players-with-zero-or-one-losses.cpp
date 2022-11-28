class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        int n=m.size();
         vector<vector<int>>ans;
        map<int,int>mp,mp1;
        int maxi=0;
        for(auto itr: m){
            mp[itr[1]]++;
            maxi=max(maxi,itr[0]);
        }
      vector<int>win,loss;
        for(auto itr: mp){
            if(itr.second==1){
                loss.push_back(itr.first);
            }
        }
        for(auto itr: m){
            mp1[itr[0]]++;
        }
        for(int i=1;i<=maxi;++i){
            if(mp.find(i)==mp.end() && mp1.find(i)!=mp1.end())
                 win.push_back(i);
        }
        return {win,loss};
    }
};