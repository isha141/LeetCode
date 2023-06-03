class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cr, vector<string>& id, vector<int>& views) {
         vector<vector<string>>ans; 
         int n=cr.size();
         map<string,long long>mp; 
         long long maxi=0;
         map<string,pair<long,string>>ids;
         for(int i=0;i<n;++i){
             if(mp.find(cr[i])==mp.end()){
                 mp[cr[i]]=views[i];
             }
             else{
                 mp[cr[i]]+=views[i];
             } 
             maxi=max(maxi,mp[cr[i]]);
             if(ids.find(cr[i])==ids.end()){
                 ids[cr[i]]={views[i],id[i]};
             }
             else
             {
                 if(ids[cr[i]].first<views[i]){
                  ids[cr[i]]={views[i],id[i]};
             }
             else if(ids[cr[i]].first==views[i]  && ids[cr[i]].second>id[i]){
                  ids[cr[i]]={views[i],id[i]};
             }
             }
         }
        for(auto itr: mp){
            if(itr.second==maxi){
                ans.push_back({itr.first,ids[itr.first].second});
            }
        }
      return ans;
    }
};