class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int i=0; 
        vector<int>ds;
        while(i<n){
            if(ds.size()==0 || ds.back()<nums[i]){
                ds.push_back(nums[i]);
            }
            else{
                auto itr=lower_bound(ds.begin(),ds.end(),nums[i])-ds.begin();
                 ds[itr]=nums[i];
            }
            i++;
        }
        return ds.size()>=3;
    }
};