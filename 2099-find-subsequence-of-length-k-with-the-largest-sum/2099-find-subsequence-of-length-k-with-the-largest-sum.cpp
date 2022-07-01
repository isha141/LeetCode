class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        for(i=0;i<k;++i){
            ans.push_back(nums[i]);
        }
        for(int j=i;j<n;++j){
            int mini=min_element(ans.begin(),ans.end())-ans.begin();
            if(ans[mini]<nums[j]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};