class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto itr: nums){
            pq.push(itr);
        }
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};