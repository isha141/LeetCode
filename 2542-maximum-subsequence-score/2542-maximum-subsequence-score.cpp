class Solution {
public:
    long long maxScore(vector<int>& n1, vector<int>& n2, int k) {
        int n=n1.size();
        long long ans=0; 
        vector<pair<int,int>>ds;
        for(int i=0;i<n;++i){
            ds.push_back({n2[i],n1[i]});
        }
        sort(ds.begin(),ds.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int sum=0;
        for(int i=n-1;i>=0;--i){
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            sum+=ds[i].second;
            pq.push(ds[i].second);
            if(pq.size()==k){
                ans=max(ans,sum*ds[i].first);
            }
        }
        return ans;
    }
};