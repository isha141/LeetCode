class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>>ans; 
        int n=p.size();
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        for(int i=0;i<n;++i){
            int x=p[i][0];
            int y=p[i][1];
            int ans=pow(x,2)+pow(y,2);
            double dis=sqrt(ans);
            pq.push({dis,i});
        }
        while(k--){
            ans.push_back(p[pq.top().second]);
            pq.pop();
        }
        return ans;
        
    }
};