class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
         int n=nums.size();
         int ans=1e9;
         long long  sum=0; 
         deque<pair<long long,long long>>q;
         for(int i=0;i<n;++i){
             sum+=nums[i];
             if(sum>=k){
                 ans=min(ans,i+1);
             }
             while(q.size() && (sum-q.front().first)>=k){
                   auto itr=q.front();
                   q.pop_front();
                   int ind=itr.second;
                   int total=itr.first;
                   ans=min(ans,i-ind);

             }
             while(q.size() && sum<=q.back().first){
                   q.pop_back();
             }
             q.push_back({sum,i});
         }
        return ans==1e9?-1:ans;
    }
};