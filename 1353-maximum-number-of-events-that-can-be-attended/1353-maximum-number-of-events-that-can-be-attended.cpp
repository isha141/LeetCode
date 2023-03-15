class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
       int n=e.size();
        int ans=0;
        vector<pair<int,int>>ds;
        for(auto itr: e){
            ds.push_back({itr[0],itr[1]});
        }
        sort(ds.begin(),ds.end(),[&](pair<int,int>&a,pair<int,int>&b){ 
            if(a.second!=b.second)
            return a.second<b.second; 
            return a.first<b.first;
        }); 
        set<int>s;
        for(int i=1;i<=100000;++i){
            s.insert(i);
        }
        for(auto itr: ds){
            int start=itr.first;
            int end=itr.second;
            auto itt=s.lower_bound(start);
            if(itt==s.end() || (*itt)>end) continue;
            // cout<<start<<"::"<<(*itt)<<endl;
            s.erase(*(itt));
            ans++;
          } 
        return ans;
    }
};