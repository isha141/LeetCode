class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
            int maxi=nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<n;++i){
            while(i-pq.top().second>k) pq.pop();
            maxi=nums[i]+pq.top().first;
            pq.push({maxi,i});
        }
        return maxi;
    }
};