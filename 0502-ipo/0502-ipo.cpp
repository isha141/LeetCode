class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n=p.size();
        int j=0; 
        vector<pair<int,int>>ds; 
        for(int  i=0;i<n;++i){
            ds.push_back({c[i],p[i]});
        }
        priority_queue<int>pq;
        sort(ds.begin(),ds.end());
        for(int i=0;i<k;++i){
            while(j<n && ds[j].first<=w){
                pq.push(ds[j++].second);
            }
            if(pq.size()==0)
                break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};