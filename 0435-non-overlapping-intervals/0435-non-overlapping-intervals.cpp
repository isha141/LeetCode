class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
          int n=in.size();
          int c=0;
          vector<pair<int,int>>ds;
         for(int i=0;i<n;++i)
         ds.push_back({in[i][1],in[i][0]});
          sort(ds.begin(),ds.end());
        int last=ds[0].first;
        for(int i=1;i<n;++i){
            if(last>ds[i].second)
                c++;
            else 
                last=max(last,ds[i].first);
        }
        return c;
        
    } 
};