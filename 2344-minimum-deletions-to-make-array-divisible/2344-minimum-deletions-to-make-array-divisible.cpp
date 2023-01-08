class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nd) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
       for(auto itr: nums)
           pq.push(itr);
         int ans=0;
        int gcd1=nd[0];
        for(auto itr: nd){
            gcd1=__gcd(itr,gcd1);
        }
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            if(gcd1%itr==0)
                return ans;
            ans++;
        }
        return -1;
    }
};