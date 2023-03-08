class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size(); 
        priority_queue<int>pq;
        int mini=1e9;
        for(auto itr: nums){
            if(itr%2){
                itr=itr*2;
            }
                mini=min(mini,itr);
               pq.push(itr);
        }
        int ans=1e9;
        while(pq.top()%2!=1){
            auto itr=pq.top();
             // pq.pop();
              ans=min(ans,pq.top()-mini);
            mini=min(mini,itr/2);
            pq.pop();
            pq.push(itr/2);
        }
        return min(ans,pq.top()-mini);
    }
};