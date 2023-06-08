class Solution {
public:
    long long maxScore(vector<int>& n1, vector<int>& n2, int k) {
          long long ans=0;
           int n=n1.size(); 
          long long sum=0; 
         vector<pair<long,long>>ds;
          for(int i=0;i<n;++i){
              ds.push_back({n2[i],i});
          } 
          sort(ds.begin(),ds.end());
          priority_queue<long,vector<long>,greater<long>>pq; 
           for(int i=n-1;i>=0;--i){
                  int ind=ds[i].second;
                   sum+=n1[ind];
                   pq.push(n1[ind]); 
               if(pq.size()==k){
                   ans=max(ans,ds[i].first*sum);
                     sum-=pq.top();
                    pq.pop();
               }
           } 
        return ans;
    }
};