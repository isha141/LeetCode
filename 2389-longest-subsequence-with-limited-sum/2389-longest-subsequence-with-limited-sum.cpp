class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        int m=q.size();
        vector<int>ans(m);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;++i){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<m;++i){
            ans[i]=upper_bound(nums.begin(),nums.end(),q[i])-nums.begin();
        }
        return ans;
    }
};