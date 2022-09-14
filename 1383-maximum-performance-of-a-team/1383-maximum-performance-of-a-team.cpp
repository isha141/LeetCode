class Solution { 
    private:
    int mod=1e9+7;
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>>ds;
        for(int i=0;i<n;++i){
            ds.push_back({e[i],s[i]});
        }
        sort(ds.rbegin(),ds.rend());
        long long  ans=0; 
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto&[x,y]: ds){
            sum+=y;
            pq.push(y);
            if(pq.size()>k){ 
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*x);
        }
        return ans% mod;
    }
};