class Solution {
    private: 
    int ans=INT_MAX;
    bool solve(int mid,vector<int>&nums,int k){
        int last=-1;
        vector<int>ds;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=mid){
                ds.push_back(nums[i]);
                i++;
            }
        }
        sort(ds.begin(),ds.end()); 
        if(ds.size()<k) return 0; 
        if(mid>=ds[ds.size()-1]){
        ans=min(ans,ds[ds.size()-1]); 
        return 1;
        }
        return 0;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low=1;
        int high=(int)1e9; 
        // int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,nums,k)){
                // ans=mid;
                // cout<<mid<<":::"<<endl;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};