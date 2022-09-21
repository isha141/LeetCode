class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>ans;  
        int n=q.size();
        int sum=0;
        for(auto itr: nums){
            if(itr%2==0)
                sum+=itr;
        }
        for(int i=0;i<n;++i){
            int ind=q[i][1];
            int val=q[i][0];
            if(nums[ind]%2==0){
                sum-=nums[ind];
            }
            nums[ind]+=val;
            if(nums[ind]%2==0)
                sum+=nums[ind];
        ans.push_back(sum);
        }
    return ans;
    }
};
