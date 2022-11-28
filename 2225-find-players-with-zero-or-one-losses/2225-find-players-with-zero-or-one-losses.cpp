class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        int n=m.size();
         vector<vector<int>>ans;
        map<int,int>mp,mp1;
        int maxi=0;
        for(auto itr: m){ 
            if(!mp.count(itr[0])) mp[itr[0]]=0;
            mp[itr[1]]++;
            // maxi=max(maxi,itr[0]);
        }
      vector<int>win,loss;
        for(auto itr: mp){
            if(itr.second==1){
                loss.push_back(itr.first);
            }
             if(itr.second==0){
                win.push_back(itr.first);
            }
        }
        return {win,loss};
    }
};