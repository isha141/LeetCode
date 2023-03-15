class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(),e.end() ,[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])
                 return a[1]<b[1];
            return a[1]<b[1];
        });
        set<int>s;
        for(int i=1;i<=100000;++i)
            s.insert(i);
        int ans=0;
        for(auto itr: e){
            int start=itr[0];
            int end=itr[1];
            auto it=s.lower_bound(start);
            if(it==s.end() || (*it)>end) continue;
            ans++;
            s.erase((*it));
        }
        return ans;
    }
};